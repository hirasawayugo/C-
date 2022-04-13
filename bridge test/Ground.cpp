#include "Ground.h"

Ground::Ground( int mate_num )
{
	MaterialManager* mate_mana = new MaterialManager();
	material = mate_mana->getMaterial( mate_num );
}

Ground::~Ground()
{
}

Material* Ground::getMaterial()
{
	return material;
}
