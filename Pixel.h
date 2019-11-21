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
	void	DrawLine( Vector2 p0, Vector2 p1 );
	void 	DrawLineDDA( int startX, int startY, int endX, int endY );
	void	DrawRectangle( int startX, int startY, int endX, int endY );
	void	DrawBresenhamsLine( int startX, int startY, int endX, int endY );
	void	DrawBresenhamsLine2( int startX, int startY, int endX, int endY );
	void	DrawTriangle( Vector2* pOut, Color color );

	Vector3	Barycentric( Vector2* pOut, Vector2 pV1 );
	
private:
	Color	m_Color;
	
	int		m_width;
	int		m_height;
	UINT	m_bytesPerPixel;
	UINT	m_bytesPerScanline;
	BYTE*	m_pBits;
};

#endif
