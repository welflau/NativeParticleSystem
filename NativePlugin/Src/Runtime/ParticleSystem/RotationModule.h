#ifndef SHURIKENMODULEROTATION_H
#define SHURIKENMODULEROTATION_H

#include "ParticleSystemModule.h"
#include "ParticleSystemCurves.h"

class RotationModule : public ParticleSystemModule
{
public:
	RotationModule();

    void Init(ParticleSystemInitState* initState);
	void Update (const ParticleSystemInitState& initState, const ParticleSystemState& state, ParticleSystemParticles& ps, const size_t fromIndex, const size_t toIndex);
	void UpdateProcedural (const ParticleSystemState& state, ParticleSystemParticles& ps);
	void CheckConsistency() {};

	inline MinMaxCurve& GetCurve() { return m_Curve; }
	
private:
	MinMaxCurve m_Curve;
};

#endif // SHURIKENMODULEROTATION_H
