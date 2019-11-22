#ifndef __VECTOR__
#define __VECTOR__

template< typename T >
class Vector2
{
public:
	Vector2(){};
	Vector2( const T* pVec2 )
	{
		x = pVec2[0];
		y = pVec2[1];
	}
	Vector2( const Vector2& rhs )
	{
		x = rhs.x;
		y = rhs.y;
	}
	Vector2( T x, T y )
	{
		this->x = x;
		this->y = y;
	}

	operator T* ()
	{
		return ( T* ) &x;
	}
	operator const T* () const
	{
		return( const T * ) &x;
	}

	Vector2& operator += ( const Vector2& vec2 )
	{
		x += vec2.x;
		y += vec2.y;
	}

	Vector2& operator -= ( const Vector2& vec2 )
	{
		x -= vec2.x;
		y -= vec2.y;
	}

	Vector2& operator *= ( T fValue )
	{
		x *= fValue;
		y *= fValue;

		return *this;
	}

	Vector2& operator /= ( T fValue )
	{
		x /= fValue;
		y /= fValue;
	}

	Vector2 operator + () const
	{
		return *this;
	}

	Vector2 operator - () const
	{
		return Vector2( -x, -y );
	}

	Vector2 operator + ( const Vector2& vec2 ) const
	{
		return Vector2( x + vec2.x, y + vec2.y );
	}

	Vector2 operator - ( const Vector2& vec2 ) const
	{
		return Vector2( x - vec2.x, y - vec2.y );
	}

	Vector2 operator * ( T fValue ) const
	{
		return Vector2( x * fValue, y * fValue );
	}

	Vector2 operator / ( T fValue ) const
	{
		return Vector2( x / fValue, y / fValue );
	}

	friend Vector2 operator * ( T fValue, const Vector2& vec2 )
	{
		return Vector2( fValue * vec2.x, fValue * vec2.y );
	}

	bool operator == ( const Vector2& vec2 ) const
	{
		return x == vec2.x && y == vec2.y;
	}

	bool operator != ( const Vector2& vec2 ) const
	{
		return x != vec2.x || y != vec2.y;
	}

public:
	union
	{
		struct  
		{
			T x;
			T y;
		};

		T raw[2];
	};

};

typedef Vector2< int > vector2;

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
	Vector3 operator ^ ( const Vector3& vec3 ) const;
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

class Vector4
{
public:
	Vector4(){};
	Vector4( const float* );
	Vector4( const Vector4& );
	Vector4( float x, float y, float z, float w );

	operator float* ();
	operator const float* () const;

	Vector4& operator += ( const Vector4& vec4 );
	Vector4& operator -= ( const Vector4& vec4 );
	Vector4& operator *= ( float fValue );
	Vector4& operator /= ( float fValue );

	Vector4 operator + () const;
	Vector4 operator - () const;

	Vector4 operator + ( const Vector4& vec4 ) const;
	Vector4 operator - ( const Vector4& vec4 ) const;
	Vector4 operator * ( float fValue ) const;
	Vector4 operator / ( float fValue ) const;

	friend Vector4 operator * ( float fValue, const Vector4& vec4 );

	bool operator == ( const Vector4& vec4 ) const;
	bool operator != ( const Vector4& vec4 ) const;
public:

	union 
	{
		struct 
		{
			float x;
			float y;
			float z;
			float w;
		};

		float raw[4];
	};
};

#endif