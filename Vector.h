#ifndef __VECTOR__
#define __VECTOR__

class Vector2
{
public:
	Vector2(){};
	Vector2( const float* );
	Vector2( const Vector2& );
	Vector2( float x, float y );

	operator float* ();
	operator const float* () const;

	Vector2& operator += ( const Vector2& vec2 );
	Vector2& operator -= ( const Vector2& vec2 );
	Vector2& operator *= ( const Vector2& vec2 );
	Vector2& operator /= ( const Vector2& vec2 );

	Vector2 operator + () const;
	Vector2 operator - () const;

	Vector2 operator + ( const Vector2& vec2 ) const;
	Vector2 operator - ( const Vector2& vec2 ) const;
	Vector2 operator * ( float fValue ) const;
	Vector2 operator / ( float fValue ) const;

	friend Vector2 operator * ( float fValue, const Vector2& vec2 );

	bool operator == ( const Vector2& vec2 ) const;
	bool operator != ( const Vector2& vec2 ) const;

public:
	union
	{
		struct  
		{
			float x;
			float y;
		};

		float raw[2];
	};

};

class Vector3
{
public:
	Vector3(){};
	Vector3( const float* );
	Vector3( const Vector3& );
	Vector3( float x, float y, float z );

	operator float* ();
	operator const float* () const;

	Vector3& operator += ( const Vector3& vec3 );
	Vector3& operator -= ( const Vector3& vec3 );
	Vector3& operator *= ( float fValue );
	Vector3& operator /= ( float fValue );

	Vector3 operator + () const;
	Vector3 operator - () const;

	Vector3 operator + ( const Vector3& vec3 ) const;
	Vector3 operator - ( const Vector3& vec3 ) const;
	Vector3 operator * ( float fValue ) const;
	Vector3 operator / ( float fValue ) const;

	friend Vector3 operator * ( float fValue, const Vector3& vec3 );

	bool operator == ( const Vector3& vec3 ) const;
	bool operator != ( const Vector3& vec3 ) const;
public:
	
	union 
	{
		struct 
		{
			float x;
			float y;
			float z;
		};

		float raw[3];
	};
};

#endif