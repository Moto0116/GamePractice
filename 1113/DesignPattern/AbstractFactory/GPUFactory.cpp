#include "GPUFactory.h"



GPUFactory::GPUFactory()
{
}


GPUFactory::~GPUFactory()
{
}

GPUBase* GPUFactory::Create(Type _type)
{
	GPUBase* pGPU;
	switch (_type)
	{
	case GPUFactory::RADEON:
		pGPU = new Radeon;
		break;
	case GPUFactory::GEFORCE:
		pGPU = new GeForce();
		break;
	default:
		pGPU = nullptr;
		break;
	}

	return pGPU;
}
