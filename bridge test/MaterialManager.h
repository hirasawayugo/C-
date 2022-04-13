#pragma once
#include "Material.h"

class MaterialManager
{
public:
	MaterialManager();
	virtual ~MaterialManager();
public:
	Material* getMaterial( int num );
};

