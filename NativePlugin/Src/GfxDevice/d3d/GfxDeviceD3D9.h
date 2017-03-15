#pragma once

#include "GfxDevice/GfxDevice.h"
#include <map>
#include "D3D9Includes.h"

class ChannelAssigns;

class GfxDeviceD3D9 : public GfxThreadableDevice
{
public:
	struct DeviceBlendStateD3D9 : public DeviceBlendState
	{
		UInt8		renderTargetWriteMask;
	};

	struct DeviceDepthStateD3D9 : public DeviceDepthState
	{
		D3DCMPFUNC depthFunc;
	};

	struct DeviceStencilStateD3D9 : public DeviceStencilState
	{
		D3DCMPFUNC		stencilFuncFront;
		D3DSTENCILOP	stencilFailOpFront;
		D3DSTENCILOP	depthFailOpFront;
		D3DSTENCILOP	depthPassOpFront;
		D3DCMPFUNC		stencilFuncBack;
		D3DSTENCILOP	stencilFailOpBack;
		D3DSTENCILOP	depthFailOpBack;
		D3DSTENCILOP	depthPassOpBack;
	};


	typedef std::map< GfxBlendState, DeviceBlendStateD3D9, memcmp_less<GfxBlendState> > CachedBlendStates;
	typedef std::map< GfxDepthState, DeviceDepthStateD3D9, memcmp_less<GfxDepthState> > CachedDepthStates;
	typedef std::map< GfxStencilState, DeviceStencilStateD3D9, memcmp_less<GfxStencilState> > CachedStencilStates;
	typedef std::map< GfxRasterState, DeviceRasterState, memcmp_less<GfxRasterState> > CachedRasterStates;

public:
	GfxDeviceD3D9();
	GFX_API ~GfxDeviceD3D9();

	GFX_API GfxBuffer* CreateVertexBuffer();
	GFX_API void UpdateBuffer(GfxBuffer* buffer, GfxBufferMode mode, GfxBufferLabel label, size_t size, const void* data, UInt32 flags);

	GFX_API const DeviceBlendState* CreateBlendState(const GfxBlendState& state);
	GFX_API const DeviceDepthState* CreateDepthState(const GfxDepthState& state);
	GFX_API const DeviceStencilState* CreateStencilState(const GfxStencilState& state);
	GFX_API const DeviceRasterState* CreateRasterState(const GfxRasterState& state);

	GFX_API void SetBlendState(const DeviceBlendState* state);
	GFX_API void SetRasterState(const DeviceRasterState* state);
	GFX_API void SetDepthState(const DeviceDepthState* state);
	GFX_API void SetStencilState(const DeviceStencilState* state, int stencilRef);

	GFX_API void BeforeDrawCall();

	GFX_API void* BeginBufferWrite(GfxBuffer* buffer, size_t offset = 0, size_t size = 0);
	GFX_API void EndBufferWrite(GfxBuffer* buffer, size_t bytesWritten);
	GFX_API void DeleteBuffer(GfxBuffer* buffer);

	GFX_API void DrawBuffers(GfxBuffer* indexBuf,
		const VertexStreamSource* vertexStreams, int vertexStreamCount,
		const DrawBuffersRange* drawRanges, int drawRangeCount,
		VertexDeclaration* vertexDecl, const ChannelAssigns& channels);

protected:
	GFX_API DynamicVBO*	CreateDynamicVBO();

private:
	DeviceBlendStateD3D9*	m_CurrBlendState;
	DeviceDepthStateD3D9*	m_CurrDepthState;
	const DeviceStencilStateD3D9*	m_CurrStencilState;
	DeviceRasterState*		m_CurrRasterState;

	CachedBlendStates	m_CachedBlendStates;
	CachedDepthStates	m_CachedDepthStates;
	CachedStencilStates	m_CachedStencilStates;
	CachedRasterStates	m_CachedRasterStates;
};