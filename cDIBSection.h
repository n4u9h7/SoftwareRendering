#ifndef __DIBSECTION__
#define __DIBSECTION__

#include "cSingleton.h"
#include "cColor.h"

static const UINT BYTES_PER_PIXEL	= 3;					// RGB
static const UINT BITS_PER_PIXEL 	= 8 * BYTES_PER_PIXEL;	// 8bit * 3color(RGB)

class cDIBSection
{
private:
	cDIBSection();
	~cDIBSection();
	
	SINGLETON( cDIBSection );
	
public:
	bool		Initialize( HWND hWnd, HINSTANCE hInstance );
	void		Draw( void );
	void		DrawTempToMemory( void );
	void		DrawMemoryToTemp( void );
	void		Clear( void );
	void		TempClear( void );
	
	UINT		GetBytesPerScanline()	{ return m_bytesPerScanline; }
	UINT		GetBytesPerPixel()		{ return BYTES_PER_PIXEL; }
	BYTE*		GetBits()				{ return m_pBits; }
	
private:
	void		Release( void );
		
private:

	HDC			m_mainDC;
	HDC			m_memoryDC;
	HDC			m_tempDC;
		
	HBITMAP		m_DIBitmap;
	HBITMAP		m_OldBitmap;
	HBITMAP		m_TempBitmap;
	HBITMAP		m_TempOldBitmap;
		
	BYTE*		m_pBits;
	BYTE*		m_pTempBits;
		
	UINT		m_bytesPerScanline;
	
	HWND		m_hWnd;
	HINSTANCE	m_hInstance;
	
	cColor		m_Color;
};

#endif
