#include "stdafx.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////////
/*
	Vector2
*/
//////////////////////////////////////////////////////////////////////////
// Vector2::Vector2( const float* pVec2 )
// {
// 	x = pVec2[0];
// 	y = pVec2[1];
// }
// 
// Vector2::Vector2( const Vector2& rhs )
// {
// 	x = rhs.x;
// 	y = rhs.y;
// }
// 
// Vector2::Vector2( float x, float y )
// {
// 	this->x = x;
// 	this->y = y;
// }
// 
// Vector2::operator float* ()
// {
// 	return (float * ) &x;
// }
// 
// Vector2::operator const float* () const
// {
// 	return ( const float * ) &x;
// }
// 
// Vector2& Vector2::operator += ( const Vector2& vec2 )
// {
// 	x += vec2.x;
// 	y += vec2.y;
// 
// 	return *this;
// }
// 
// Vector2& Vector2::operator -= ( const Vector2& vec2 )
// {
// 	x -= vec2.x;
// 	y -= vec2.y;
// 
// 	return *this;
// }
// 
// Vector2& Vector2::operator *= ( float fValue )
// {
// 	x *= fValue;
// 	y *= fValue;
// 
// 	return *this;
// }
// 
// Vector2& Vector2::operator /= ( float fValue )
// {
// 	float fInv = 1.0f / fValue;
// 
// 	x *= fInv;
// 	y *= fInv;
// 
// 	return *this;
// }
// 
// Vector2 Vector2::operator + () const
// {
// 	return *this;
// }
// 
// Vector2 Vector2::operator - () const
// {
// 	return Vector2( -x, -y );
// }
// 
// Vector2 Vector2::operator + ( const Vector2& vec2 ) const
// {
// 	return Vector2( x + vec2.x, y + vec2.y );
// }
// 
// Vector2 Vector2::operator - ( const Vector2& vec2 ) const
// {
// 	return Vector2( x - vec2.x, y - vec2.y );
// }
// 
// Vector2 Vector2::operator * ( float fValue ) const
// {
// 	return Vector2( x * fValue, y * fValue );
// }
// 
// Vector2 Vector2::operator / ( float fValue ) const
// {
// 	float fInv = 1.0f / fValue;
// 	return Vector2( x * fInv, y * fInv );
// }
// 
// Vector2 operator * ( float fValue, const Vector2& vec2 )
// {
// 	return Vector2( fValue * vec2.x, fValue * vec2.y );
// }
// 
// bool Vector2::operator == ( const Vector2& vec2 ) const
// {
// 	return x == vec2.x && y == vec2.y;
// }
// 
// bool Vector2::operator != ( const Vector2& vec2 ) const
// {
// 	return x != vec2.x || y != vec2.y;
// }

//////////////////////////////////////////////////////////////////////////
/*
	Vector3
*/
//////////////////////////////////////////////////////////////////////////
// Vector3::Vector3( const float* pVec3 )
// {
// 	x = pVec3[0];
// 	y = pVec3[1];
// 	z = pVec3[2];
// }
// 
// Vector3::Vector3( const Vector3& rhs )
// {
// 	x = rhs.x;
// 	y = rhs.y;
// 	z = rhs.z;
// }
// 
// Vector3::Vector3( float x, float y, float z )
// {
// 	this->x = x;
// 	this->y = y;
// 	this->z = z;
// }
// 
// Vector3::operator float* ()
// {
// 	return (float * ) &x;
// }
// 
// Vector3::operator const float* () const
// {
// 	return ( const float * ) &x;
// }
// 
// Vector3& Vector3::operator += ( const Vector3& vec3 )
// {
// 	x += vec3.x;
// 	y += vec3.y;
// 	z += vec3.z;
// 
// 	return *this;
// }
// 
// Vector3& Vector3::operator -= ( const Vector3& vec3 )
// {
// 	x -= vec3.x;
// 	y -= vec3.y;
// 	z -= vec3.z;
// 
// 	return *this;
// }
// 
// Vector3& Vector3::operator *= ( float fValue )
// {
// 	x *= fValue;
// 	y *= fValue;
// 	z *= fValue;
// 
// 	return *this;
// }
// 
// Vector3& Vector3::operator /= ( float fValue )
// {
// 	float fInv = 1.0f / fValue;
// 
// 	x *= fInv;
// 	y *= fInv;
// 	z *= fInv;
// 
// 	return *this;
// }
// 
// Vector3 Vector3::operator + () const
// {
// 	return *this;
// }
// 
// Vector3 Vector3::operator - () const
// {
// 	return Vector3( -x, -y, -z );
// }
// 
// Vector3 Vector3::operator + ( const Vector3& vec3 ) const
// {
// 	return Vector3( x + vec3.x, y + vec3.y, z + vec3.z );
// }
// 
// Vector3 Vector3::operator - ( const Vector3& vec3 ) const
// {
// 	return Vector3( x - vec3.x, y - vec3.y, z - vec3.z );
// }
// 
// Vector3 Vector3::operator ^ ( const Vector3& vec3 ) const
// {
// 	return Vector3( y * vec3.z - z * vec3.y, z * vec3.x - x * vec3.z, x * vec3.y - y * vec3.x );
// }
// 
// Vector3 Vector3::operator * ( float fValue ) const
// {
// 	return Vector3( x * fValue, y * fValue, z * fValue );
// }
// 
// Vector3 Vector3::operator / ( float fValue ) const
// {
// 	float fInv = 1.0f / fValue;
// 	return Vector3( x * fInv, y * fInv, z * fInv );
// }
// 
// Vector3 operator * ( float fValue, const Vector3& vec3 )
// {
// 	return Vector3( fValue * vec3.x, fValue * vec3.y, fValue * vec3.z );
// }
// 
// bool Vector3::operator == ( const Vector3& vec3 ) const
// {
// 	return x == vec3.x && y == vec3.y && z == vec3.z;
// }
// 
// bool Vector3::operator != ( const Vector3& vec3 ) const
// {
// 	return x != vec3.x || y != vec3.y || z != vec3.z;
// }

//////////////////////////////////////////////////////////////////////////
/*
	Vector4
*/
//////////////////////////////////////////////////////////////////////////
//Vector4::Vector4( const float* pVec4 )
//{
//	x = pVec4[0];
//	y = pVec4[1];
//	z = pVec4[2];
//	w = pVec4[3];
//}
//
//Vector4::Vector4( const Vector4& rhs )
//{
//	x = rhs.x;
//	y = rhs.y;
//	z = rhs.z;
//	w = rhs.w;
//}
//
//Vector4::Vector4( float x, float y, float z, float w )
//{
//	this->x = x;
//	this->y = y;
//	this->z = z;
//	this->w = w;
//}
//
//Vector4::operator float* ()
//{
//	return (float * ) &x;
//}
//
//Vector4::operator const float* () const
//{
//	return ( const float * ) &x;
//}
//
//Vector4& Vector4::operator += ( const Vector4& vec4 )
//{
//	x += vec4.x;
//	y += vec4.y;
//	z += vec4.z;
//	w += vec4.w;
//
//	return *this;
//}
//
//Vector4& Vector4::operator -= ( const Vector4& vec4 )
//{
//	x -= vec4.x;
//	y -= vec4.y;
//	z -= vec4.z;
//	w -= vec4.w;
//
//	return *this;
//}
//
//Vector4& Vector4::operator *= ( float fValue )
//{
//	x *= fValue;
//	y *= fValue;
//	z *= fValue;
//	w *= fValue;
//
//	return *this;
//}
//
//Vector4& Vector4::operator /= ( float fValue )
//{
//	float fInv = 1.0f / fValue;
//
//	x *= fInv;
//	y *= fInv;
//	z *= fInv;
//	w *= fInv;
//
//	return *this;
//}
//
//Vector4 Vector4::operator + () const
//{
//	return *this;
//}
//
//Vector4 Vector4::operator - () const
//{
//	return Vector4( -x, -y, -z, -w );
//}
//
//Vector4 Vector4::operator + ( const Vector4& vec4 ) const
//{
//	return Vector4( x + vec4.x, y + vec4.y, z + vec4.z, w + vec4.w );
//}
//
//Vector4 Vector4::operator - ( const Vector4& vec4 ) const
//{
//	return Vector4( x - vec4.x, y - vec4.y, z - vec4.z, w - vec4.w );
//}
//
//Vector4 Vector4::operator * ( float fValue ) const
//{
//	return Vector4( x * fValue, y * fValue, z * fValue, w * fValue );
//}
//
//Vector4 Vector4::operator / ( float fValue ) const
//{
//	float fInv = 1.0f / fValue;
//	return Vector4( x * fInv, y * fInv, z * fInv, w * fInv );
//}
//
//Vector4 operator * ( float fValue, const Vector4& vec4 )
//{
//	return Vector4( fValue * vec4.x, fValue * vec4.y, fValue * vec4.z, fValue * vec4.w );
//}
//
//bool Vector4::operator == ( const Vector4& vec4 ) const
//{
//	return x == vec4.x && y == vec4.y && z == vec4.z && w == vec4.w;
//}
//
//bool Vector4::operator != ( const Vector4& vec4 ) const
//{
//	return x != vec4.x || y != vec4.y || z != vec4.z || w != vec4.w;
//}