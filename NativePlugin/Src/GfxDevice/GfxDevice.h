#pragma once

//@TODO: remove me
#define GFX_API virtual
#define GFX_PURE = 0

class GfxDevice
{
public:
	GfxDevice();
	GFX_API ~GfxDevice();
};

class GfxThreadableDevice : public GfxDevice
{
public:
};

GfxDevice& GetGfxDevice();
void SetGfxDevice(GfxDevice* device);