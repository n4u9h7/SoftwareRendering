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

template < typename T >
class Vector3
{
public:
	Vector3(){};
	Vector3( const T* pVec3 )
	{
		x = pVec3[0];
		y = pVec3[1];
		z = pVec3[2];
	}

	Vector3( const Vector3& rhs )
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}

	Vector3( T x, T y, T z )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	operator T* ()
	{
		return ( T * ) &x;
	}

	operator const T* () const
	{
		return ( const T * ) &x;
	}

	Vector3& operator += ( const Vector3& vec3 )
	{
		x += vec3.x;
		y += vec3.y;
		z += vec3.z;

		return *this;
	}

	Vector3& operator -= ( const Vector3& vec3 )
	{
		x -= vec3.x;
		y -= vec3.y;
		z -= vec3.z;

		return *this; 
	}

	Vector3& operator *= ( T fValue )
	{
		x *= fValue;
		y *= fValue;
		z *= fValue;

		return *this;
	}

	Vector3& operator /= ( T fValue )
	{
		x /= fValue;
		y /= fValue;
		z /= fValue;

		return *this;
	}

	Vector3 operator + () const
	{
		return *this;
	}

	Vector3 operator - () const
	{
		return Vector3( -x, -y, -z );
	}

	Vector3 operator + ( const Vector3& vec3 ) const
	{
		return Vector3( x + vec3.x, y + vec3.y, z + vec3.z );
	}

	Vector3 operator - ( const Vector3& vec3 ) const
	{
		return Vector3( x - vec3.x, y - vec3.y, z - vec3.z );
	}

	Vector3 operator ^ ( const Vector3& vec3 ) const
	{
		return Vector3( y * vec3.z - z * vec3.y, z * vec3.x - x * vec3.z, x * vec3.y - y * vec3.x );
	}

	Vector3 operator * ( T fValue ) const
	{
		return Vector3( x * fValue, y * fValue, z * fValue );
	}

	Vector3 operator / ( T fValue ) const
	{
		return Vector3( x / fValue, y / fValue, z / fValue );
	}
	

	friend Vector3 operator * ( T fValue, const Vector3& vec3 )
	{
		return Vector3( fValue * vec3.x, fValue * vec3.y, fValue * vec3.z );
	}

	bool operator == ( const Vector3& vec3 ) const
	{
		return x == vec3.x && y == vec3.y && z == vec3.z;
	}

	bool operator != ( const Vector3& vec3 ) const
	{
		return x != vec3.x || y != vec3.y || z != vec3.z;
	}
public:
	
	union 
	{
		struct 
		{
			T x;
			T y;
			T z;
		};

		T raw[3];
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

typedef Vector2< int >		vector2i;
typedef Vector2< float >	vector2f;
typedef Vector3< int >		vector3i;
typedef Vector3< float >	vector3f;

#endif