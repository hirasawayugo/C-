#pragma once

class Material
{
public:
	Material();
	virtual ~Material( );
protected:
	const char* name;
public:
	const char* getName();

};

