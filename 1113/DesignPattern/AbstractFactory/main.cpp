#include <stdio.h>
#include "GPUFactory.h"


void main()
{
	GPUFactory GpuFactory;
	GPUBase* pGeForce = GpuFactory.Create(GPUFactory::GEFORCE);
	GPUBase* pRadeon = GpuFactory.Create(GPUFactory::RADEON);
}