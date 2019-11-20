#include "stdafx.h"
#include "cVector.h"

Vector3::Vector3( const float* pVec3 )
{
	x = pVec3[0];
	y = pVec3[1];
	z = pVec3[2];
}

Vector3::Vector3( const Vector3& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

Vector3::Vector3( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}