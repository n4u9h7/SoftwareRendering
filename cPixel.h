#ifndef __PIXEL__
#define	__PIXEL__

#include "cColor.h"

class cPixel
{
public:
	cPixel( int width, int height, UINT bytesPerScanline, UINT bytesPerPixel, BYTE* pBits );
	~cPixel();
	
	void	SetColor( cColor Color ) { m_Color = Color; }
	void	DrawPixel( int x, int y );
	void 	DrawLineDDA( int startX, int startY, int endX, int endY );
	void	DrawRectangle( int startX, int startY, int endX, int endY );
	void	DrawBresenhamsLine( int startX, int startY, int endX, int endY );
	
private:
	cColor	m_Color;
	
	int		m_width;
	int		m_height;
	UINT	m_bytesPerPixel;
	UINT	m_bytesPerScanline;
	BYTE*	m_pBits;
};

#endif
