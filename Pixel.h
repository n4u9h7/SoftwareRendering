#ifndef __PIXEL__
#define	__PIXEL__

#include "Color.h"
#include "Vector.h"

class Pixel
{
public:
	Pixel( int width, int height, UINT bytesPerScanline, UINT bytesPerPixel, BYTE* pBits );
	~Pixel();

	void	SetColor( Color Color ) { m_Color = Color; }
	void	DrawPixel( int x, int y );
	void	DrawLine( vector2 p0, vector2 p1 );
	void 	DrawLineDDA( int startX, int startY, int endX, int endY );
	void	DrawRectangle( int startX, int startY, int endX, int endY );
	void	DrawBresenhamsLine( int startX, int startY, int endX, int endY );
	void	DrawBresenhamsLine2( int startX, int startY, int endX, int endY );
	void	DrawTriangle( vector2* pOut, Color color );
	void	DrawTriangle( vector2 t0, vector2 t1, vector2 t2, Color color );

	Vector3	Barycentric( vector2* pOut, vector2 pV1 );
	
private:
	Color	m_Color;
	
	int		m_width;
	int		m_height;
	UINT	m_bytesPerPixel;
	UINT	m_bytesPerScanline;
	BYTE*	m_pBits;
};

#endif
