#include "stdafx.h"
#include "cPixel.h"

cPixel::cPixel( int width, int height, UINT bytesPerScanline, UINT bytesPerPixel, BYTE* pBits )
: m_Color( 255, 255, 255 )
{
	m_width = width;
	m_height = height;
	m_bytesPerScanline = bytesPerScanline;
	m_bytesPerPixel = bytesPerPixel;
	m_pBits = pBits;
}

cPixel::~cPixel()
{
}
	
void cPixel::DrawPixel( int x, int y )
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

void cPixel::DrawLineDDA( int startX, int startY, int endX, int endY )
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

void cPixel::DrawRectangle( int startX, int startY, int endX, int endY )
{
	if( ( startX == endX ) && ( startY == endY ) ) return;
}

void cPixel::DrawBresenhamsLine( int startX, int startY, int endX, int endY )
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

void cPixel::DrawBresenhamsLine2( int startX, int startY, int endX, int endY )
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