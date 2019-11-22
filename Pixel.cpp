#include "stdafx.h"
#include "Pixel.h"

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

void Pixel::DrawLine( Vector2 p0, Vector2 p1 )
{
	bool bSteep = false;

	if( abs( p0.x - p1.x ) < abs( p0.y - p1.y ) )
	{
		swap( p0.x, p0.y );
		swap( p1.x, p1.y );

		bSteep = true;
	}

	if( p0.x > p1.x )
	{
		swap( p0, p1 );
	}

	for( int x = p0.x; x < p1.x; x++ )
	{
		float t = ( x - p0.x ) / ( float )( p1.x - p0.x );

		int y = p0.y * ( 1.0f - t ) + p1.y * t;

		if( bSteep )
		{
			DrawPixel( y, x );
		}
		else
		{
			DrawPixel( x, y );
		}
	}
}

void Pixel::DrawLineDDA( int startX, int startY, int endX, int endY )
{
	if ((startX == endX) && (startY == endY)) return;

	float deltaX = (float)(endX - startX);	
	float deltaY = (float)(endY - startY);	
	float fM = deltaY / deltaX;
	float iTempX = (float)startX;
	float iTempY = (float)startY;

	DrawPixel(startX, startY);
	DrawPixel(endX, endY);

	if (fM <= 1.0f && fM >= -1.0f)
	{
		if (startX > endX)
		{
			SWAP(startX, endX);
			SWAP(startY, endY);
		}
		deltaX = (float)(endX - startX);
		deltaY = (float)(endY - startY);
		fM = deltaY / deltaX;
		iTempY = (float)startY;

		for (int iX = startX; iX < endX; iX++)
		{
			DrawPixel(iX, (int)(iTempY + 0.5f));
			iTempY += fM;						
		}
	}
	else
	{
		if (startY > endY)
		{
			SWAP(startX, endX);
			SWAP(startY, endY);
		}
		deltaX = (float)(endX - startX);
		deltaY = (float)(endY - startY);
		fM = deltaX / deltaY;
		iTempX = (float)startX;


		for (int iY = startY; iY < endY; iY++)
		{
			DrawPixel((int)(iTempX + 0.5f), iY);
			iTempX += fM;
		}
	}
}

void Pixel::DrawRectangle( int startX, int startY, int endX, int endY )
{
	if( ( startX == endX ) && ( startY == endY ) ) return;
}

void Pixel::DrawBresenhamsLine( int startX, int startY, int endX, int endY )
{
	int x = startX;	
	int y = startY;	

	int dX = 0;
	int dY = 0;

	int d = 0;
	int e = 0;
	int nE = 0;

	DrawPixel( startX, startY );
	DrawPixel( endX, endY );

	if( x <= endX && y <= endY )
	{
		dX = endX - startX;
		dY = endY - startY;

		if( dX > dY )
		{
			d = ( 2* dY ) - dX;
			e = 2 * dY;
			nE = 2 * ( dY - dX );

			while( x < endX )
			{
				if( d <= 0 )
				{
					d += e;
					x++;
				}
				else
				{
					d += nE;
					x++;
					y++;
				}

				DrawPixel( x, y );
			}
		}
		else
		{
			d = ( 2 * dX ) - dY;
			e = 2 * dX;
			nE = 2 * ( dX - dY );

			while( y < endY )
			{
				if( d <= 0 )
				{
					d += e;
					y++;
				}
				else
				{
					d += nE;
					x++;
					y++;
				}

				DrawPixel( x, y );
			}
		}
	}
	else if( x >= endX && y >= endY )
	{
		dX = endX - startX;
		dY = endY - startY;

		if( dX < dY )
		{
			d = ( 2 * dY ) - dX;
			e = 2 * dY;
			nE = 2 * ( dY - dX );

			while( x > endX )
			{
				if( d <= 0 )
				{
					d -= e;
					x--;
				}
				else
				{
					d -= nE;
					x--;
					y--;
				}

				DrawPixel( x, y );
			}
		}
		else
		{
			d = ( 2 * dX ) - dY;
			e = 2 * dX;
			nE = 2* ( dX - dY );

			while( y > endY )
			{
				if( d <= 0 )
				{
					d -= e;
					y--;
				}
				else
				{
					d -= nE;
					x--;
					y--;
				}

				DrawPixel( x, y );
			}
		}
	}
	else if( x <= endX && y >= endY )
	{
		dX = abs( endX - startX );
		dY = abs( endY - startY );

		if( dX > dY )
		{
			d = ( 2 * dY ) - dX;
			e = 2 * dY;
			nE = 2 * ( dY - dX );

			while( x < endX )
			{
				if( d <= 0 )
				{
					d += e;
					x++;
				}
				else
				{
					d += nE;
					x++;
					y--;
				}

				DrawPixel( x, y );
			}
		}
		else
		{
			d = ( 2 * dX ) - dY;
			e = 2 * dX;
			nE = 2 * ( dX - dY );

			while( y > endY )
			{
				if( d <= 0 )
				{
					d += e;
					y--;
				}
				else
				{
					d += nE;
					x++;
					y--;
				}

				DrawPixel( x, y );
			}
		}
	}
	else if( x >= endX && y <= endY )
	{
		dX = abs( endX - startX );
		dY = abs( endY - startY );

		if( dX > dY )
		{
			d = ( 2* dY ) - dX;
			e = 2 * dY;
			nE = 2 * ( dY - dX );

			while( x > endX )
			{
				if( d <= 0 )
				{
					d += e;
					x--;
				}
				else
				{
					d += nE;
					x--;
					y++;
				}

				DrawPixel( x, y );
			}
		}
		else
		{
			d = ( 2 * dX ) - dY;
			e = 2 * dX;
			nE = 2 * ( dX - dY );

			while( y < endY )
			{
				if( d <= 0 )
				{
					d += e;
					y++;
				}
				else
				{
					d += nE;
					x--;
					y++;
				}

				DrawPixel( x, y );
			}
		}
	}
}

void Pixel::DrawBresenhamsLine2( int startX, int startY, int endX, int endY )
{
	bool bSteep = false;

	if( Abs( startX - endX ) < Abs( startY - endY ) )
	{
		SWAP( startX, startY );
		SWAP( endX, endY );

		bSteep = true;
	}

	if( startX > endX )
	{
		SWAP( startX, endX );
		SWAP( startY, endY );
	}

	int dX = endX - startX;
	int dY = endY - startY;
	int d = Abs( dY ) * 2;
	int e = 0;
	int y = startY;

	for( int x = startX; x <= endX; x++ )
	{
		if( bSteep == TRUE )
		{
			DrawPixel( y, x );
		}
		else
		{
			DrawPixel( x, y );
		}

		e += d;

		if( e > dX )
		{
			y += ( endY > startY ? 1 : -1 );
			{
				e -= dX * 2;
			}
		}
	}
}

void Pixel::DrawTriangle( Vector2* pOut, Color color )
{
	m_Color = color;

	Vector2 bBoxMin( WIN_SIZE_X - 1, WIN_SIZE_Y - 1 );
	Vector2 bBoxMax( 0, 0 );
	Vector2 clamp( WIN_SIZE_X - 1, WIN_SIZE_Y - 1 );

	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 2; j++ )
		{
			bBoxMin[j] = max( 0, min( bBoxMin[j], pOut[i][j] ) );
			bBoxMax[j] = min( clamp[j], max(bBoxMax[j], pOut[i][j] ) );
		}
	}

	Vector2 P;

	for( P.x = bBoxMin.x; P.x <= bBoxMax.x; P.x++ )
	{
		for( P.y = bBoxMin.y; P.y <= bBoxMax.y; P.y++ )
		{
			Vector3 bc_screen = Barycentric( pOut, P );

			if( bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0 )
			{
				continue;
			}

			DrawPixel( WIN_SIZE_X - P.x, WIN_SIZE_Y - P.y );
		}
	}
}

Vector3	Pixel::Barycentric( Vector2* pOut, Vector2 pV1 )
{
	Vector3 u;
	Vector3 v = Vector3( pOut[2][0] - pOut[0][0], pOut[1][0] - pOut[0][0], pOut[0][0] - pV1[0] );
	Vector3 w = Vector3( pOut[2][1] - pOut[0][1], pOut[1][1] - pOut[0][1], pOut[0][1] - pV1[1] );

	Vec3Cross( &u, &v, &w );

	if( abs( u[2] ) < 1 )
	{
		return Vector3( -1, 1, 1 );
	}

	return Vector3( 1.0f - ( u.x + u.y ) / u.z, u.y / u.z, u.x / u.z );
}