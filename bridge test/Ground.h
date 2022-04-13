#pragma once
#include "Material.h"
#include "MaterialManager.h"

class Ground
{
public:
	Ground( int mate_num );
	virtual ~Ground();
public:
	Material* getMaterial();
private:
	Material* material;
};

