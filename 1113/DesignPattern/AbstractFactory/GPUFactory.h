#ifndef GPUFACTORY_H
#define GPUFACTORY_H

class GPUBase
{
public:
	GPUBase() {};
	~GPUBase() {};
};

class Radeon : public GPUBase
{
public:
	Radeon() {};
	~Radeon() {};

};

class GeForce : public GPUBase
{
public:
	GeForce() {};
	~GeForce() {};
};

class GPUFactory
{
public:
	enum Type
	{
		RADEON,
		GEFORCE
	};

	GPUFactory();
	~GPUFactory();

	GPUBase* Create(Type _type);
};


#endif
