#include "stdafx.h"
#include "Pixel.h"
#include <limits>

Pixel::Pixel( int width, int height, UINT bytesPerScanline, UINT bytesPerPixel, BYTE* pBits )
: m_Color( 255, 255, 255 )
{
	m_width = width;
	m_height = height;
	m_bytesPerScanline = bytesPerScanline;
	m_bytesPerPixel = bytesPerPixel;
	m_pBits = pBits;
}

Pixel::~Pixel()
{
}

void Pixel::DrawPixel( int x, int y )
{
	int offset = ( y * m_bytesPerScanline ) + ( x * m_bytesPerPixel );
	int maxOffset = m_bytesPerScanline * ( m_height - 1 ) + ( m_width - 1 ) * m_bytesPerPixel;

	if( offset < 0 || offset > maxOffset ) 
	{
		return;
	}

	*(m_pBits + offset + 0) = m_Color.GetB();
	*(m_pBits + offset + 1) = m_Color.GetG();
	*(m_pBits + offset + 2) = m_Color.GetR();
}

void Pixel::DrawLine( int x0, int y0, int x1, int y1, Color color )
{
	m_Color = color;

	bool steep = false;

	if( abs( x0 - x1 ) < abs( y0 - y1 ) )
	{
		swap( x0, y0 );
		swap( x1, y1 );

		steep = true;
	}

	if( x0 > x1 )
	{
		swap( x0, x1 );
		swap( y0, y1 );
	}

	for( int x = x0; x <= x1; x++ )
	{
		float t = ( x - x0 ) / ( float )( x1 - x0 );

		int y = y0 * ( 1.0f - t ) + y1 * t;

		if( steep )
		{
			DrawPixel( y, x );
		}
		else
		{
			DrawPixel( x, y );
		}
	}
}

void Pixel::DrawTriangle( vector3f *pts, float *zBuffer, Color color )
{
	m_Color = color;
	vector2f bboxmin( std::numeric_limits<float>::max(),  std::numeric_limits<float>::max() );
	vector2f bboxmax(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max() );
	vector2f clamp( WIN_SIZE_X - 1, WIN_SIZE_Y - 1);

	for( int i = 0; i < 3; i++ )
	{
		for (int j = 0; j < 2; j++ )
		{
			bboxmin[j] = std::max(0.0f,      std::min(bboxmin[j], pts[i][j] ) );
			bboxmax[j] = std::min(clamp[j],	 std::max(bboxmax[j], pts[i][j] ) );
		}
	}

	vector3f P;
	for( P.x = bboxmin.x; P.x <= bboxmax.x; P.x++ )
	{
		for( P.y = bboxmin.y; P.y <= bboxmax.y; P.y++ )
		{
			vector3f bc_screen = barycentric( pts[0], pts[1], pts[2], P );
			
			if( bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0 ) continue;
			P.z = 0;
			
			for( int i = 0; i < 3; i++ ) 
			{
				P.z += pts[i][2] * bc_screen[i];
			}
			
			if( zBuffer[ int( P.x + P.y * WIN_SIZE_X ) ] < P.z ) 
			{
				zBuffer[ int( P.x + P.y * WIN_SIZE_X ) ] = P.z;

				DrawPixel( WIN_SIZE_X - P.x, WIN_SIZE_Y - P.y );
			}
		}
	}
}

vector3f Pixel::barycentric( vector3f A, vector3f B, vector3f C, vector3f P )
{
	vector3f s[2];
	
	for( int i = 2; i--; )
	{
		s[i][0] = C[i]-A[i];
		s[i][1] = B[i]-A[i];
		s[i][2] = A[i]-P[i];
	}

	vector3f u = cross( s[0], s[1] );

	if( abs( u[2] ) > 1e-2 )
	{
		return vector3f( 1.0f - ( u.x + u.y ) / u.z, u.y / u.z, u.x / u.z );
	}

	return vector3f( -1, 1, 1 );
}