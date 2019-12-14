#ifndef __PIXEL__
#define	__PIXEL__

#include "Color.h"
#include "Vector.h"

//using namespace std;

class Pixel
{
public:
	Pixel( int width, int height, UINT bytesPerScanline, UINT bytesPerPixel, BYTE* pBits );
	~Pixel();

	void		SetColor( Color Color ) { m_Color = Color; }
	void		DrawPixel( int x, int y );
	void		DrawLine( int x0, int y0, int x1, int y1, Color color );
	void		DrawTriangle( vector3f *pts, float *zBuffer, Color color );
	
	vector3f	barycentric( vector3f A, vector3f B, vector3f C, vector3f P );
	
private:
	Color	m_Color;
	
	int		m_width;
	int		m_height;
	UINT	m_bytesPerPixel;
	UINT	m_bytesPerScanline;
	BYTE*	m_pBits;
};

#endif
