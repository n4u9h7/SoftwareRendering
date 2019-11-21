#include "stdafx.h"
#include "Vector.h"

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

Vector3::operator float* ()
{
	return (float * ) &x;
}

Vector3::operator const float* () const
{
	return ( const float * ) &x;
}

Vector3& Vector3::operator += ( const Vector3& vec3 )
{
	x += vec3.x;
	y += vec3.y;
	z += vec3.z;

	return *this;
}

Vector3& Vector3::operator -= ( const Vector3& vec3 )
{
	x -= vec3.x;
	y -= vec3.y;
	z -= vec3.z;

	return *this;
}

Vector3& Vector3::operator *= ( float fValue )
{
	x *= fValue;
	y *= fValue;
	z *= fValue;

	return *this;
}

Vector3& Vector3::operator /= ( float fValue )
{
	float fInv = 1.0f / fValue;

	x *= fInv;
	y *= fInv;
	z *= fInv;

	return *this;
}

Vector3 Vector3::operator + () const
{
	return *this;
}

Vector3 Vector3::operator - () const
{
	return Vector3( -x, -y, -z );
}

Vector3 Vector3::operator + ( const Vector3& vec3 ) const
{
	return Vector3( x + vec3.x, y + vec3.y, z + vec3.z );
}

Vector3 Vector3::operator - ( const Vector3& vec3 ) const
{
	return Vector3( x - vec3.x, y - vec3.y, z - vec3.z );
}

Vector3 Vector3::operator * ( float fValue ) const
{
	return Vector3( x * fValue, y * fValue, z * fValue );
}

Vector3 Vector3::operator / ( float fValue ) const
{
	float fInv = 1.0f / fValue;
	return Vector3( x * fInv, y * fInv, z * fInv );
}

Vector3 operator * ( float fValue, const Vector3& vec3 )
{
	return Vector3( fValue * vec3.x, fValue * vec3.y, fValue * vec3.z );
}

bool Vector3::operator == ( const Vector3& vec3 ) const
{
	return x == vec3.x && y == vec3.y && z == vec3.z;
}

bool Vector3::operator != ( const Vector3& vec3 ) const
{
	return x != vec3.x || y != vec3.y || z != vec3.z;
}