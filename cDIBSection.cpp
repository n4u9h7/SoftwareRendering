#include "stdafx.h"
#include "cDIBSection.h"

cDIBSection::cDIBSection()
: m_hWnd( NULL ), m_hInstance( NULL ), m_mainDC( NULL ), m_memoryDC( NULL ), 
  m_DIBitmap( NULL ), m_pBits( NULL ), m_bytesPerScanline( 0 ), m_Color( 0, 0, 0 )
{
}

cDIBSection::~cDIBSection()
{
	Release();
}

bool cDIBSection::Initialize( HWND hWnd, HINSTANCE hInstance )
{
	if( hWnd == NULL || hInstance == NULL ) return false;
	
	m_hWnd = hWnd;
	m_hInstance = hInstance;
	
	m_mainDC = GetDC( m_hWnd );
	m_memoryDC = CreateCompatibleDC( m_mainDC );
	m_tempDC = CreateCompatibleDC( m_mainDC );
		
	m_bytesPerScanline = ( WIN_SIZE_X * BYTES_PER_PIXEL + 3 ) & ~3;
	
	// Setting DIBSection
	BITMAPINFO bm;
	ZeroMemory( &bm, sizeof( BITMAPINFO ) );
	
	bm.bmiHeader.biSize			= sizeof(BITMAPINFOHEADER);
	bm.bmiHeader.biWidth		= WIN_SIZE_X;
	bm.bmiHeader.biHeight		= -WIN_SIZE_Y;
	bm.bmiHeader.biPlanes		= 1;
	bm.bmiHeader.biBitCount		= BITS_PER_PIXEL;
	bm.bmiHeader.biCompression	= BI_RGB;
	
	// Create DIBSection
	m_DIBitmap = CreateDIBSection( m_memoryDC, &bm, DIB_RGB_COLORS, (LPVOID*)&m_pBits, NULL, NULL );
	m_OldBitmap = (HBITMAP)SelectObject( m_memoryDC, m_DIBitmap );
	
	m_TempBitmap = CreateDIBSection( m_tempDC, &bm, DIB_RGB_COLORS, (LPVOID*)&m_pTempBits, NULL, NULL );
	m_TempOldBitmap = (HBITMAP)SelectObject( m_tempDC, m_TempBitmap );
	
	return true;
}
		
void cDIBSection::Draw( void )
{
	BitBlt( m_mainDC, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, m_memoryDC, 0, 0, SRCCOPY );
}

void cDIBSection::DrawTempToMemory( void )
{
	BitBlt( m_memoryDC, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, m_tempDC, 0, 0, SRCCOPY );
}

void cDIBSection::DrawMemoryToTemp( void )
{
	BitBlt( m_tempDC, 0, 0, WIN_SIZE_X, WIN_SIZE_Y, m_memoryDC, 0, 0, SRCCOPY );
}

void cDIBSection::Clear( void )
{
	UINT offset = 0;
	
	while( offset < m_bytesPerScanline )
	{
		*((DWORD*)( m_pBits + offset )) = m_Color.GetColor();
		offset += BYTES_PER_PIXEL;
	}
	
	offset = m_bytesPerScanline;
	
	for( int i = 0; i < WIN_SIZE_Y - 1; i++ )
	{
		memcpy( m_pBits + offset, m_pBits, m_bytesPerScanline );
		offset += m_bytesPerScanline;
	}
}

void cDIBSection::TempClear( void )
{
		UINT offset = 0;
	
	while( offset < m_bytesPerScanline )
	{
		*((DWORD*)( m_pTempBits + offset )) = m_Color.GetColor();
		offset += BYTES_PER_PIXEL;
	}
	
	offset = m_bytesPerScanline;
	
	for( int i = 0; i < WIN_SIZE_Y - 1; i++ )
	{
		memcpy( m_pTempBits + offset, m_pTempBits, m_bytesPerScanline );
		offset += m_bytesPerScanline;
	}	
}

void cDIBSection::Release( void )
{
	SelectObject( m_tempDC, m_TempOldBitmap );
	DeleteDC( m_tempDC );
	DeleteObject( m_TempOldBitmap );
	DeleteObject( m_TempBitmap );
	
	SelectObject( m_memoryDC, m_OldBitmap );
	DeleteDC( m_memoryDC );
	DeleteObject( m_OldBitmap );
	DeleteObject( m_DIBitmap );
	
	ReleaseDC( m_hWnd, m_mainDC );
}
