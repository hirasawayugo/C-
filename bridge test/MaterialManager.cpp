#include "MaterialManager.h"
#include "Grass.h"
#include "Rock.h"
#include "Soil.h"

MaterialManager::MaterialManager()
{
}

MaterialManager::~MaterialManager()
{
}

Material* MaterialManager::getMaterial(int num)
{
	Material* material = new Material();
	switch ( num )
	{
	case 0:
		material = new Grass();
		break;
	case 1:
		material = new Rock();
		break;
	case 2:
		material = new Soil();
		break;
	}
	return material;
}
