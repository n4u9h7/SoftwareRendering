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

