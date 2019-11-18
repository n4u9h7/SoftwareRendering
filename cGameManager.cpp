#include "stdafx.h"
#include "cGameManager.h"

cGameManager::cGameManager()
: m_mainWnd( NULL ), m_mainInstance( NULL ), m_Pixel( NULL ), m_drawType( DRAW_DDA_LINE ),
  m_startX( 0 ), m_startY( 0 )
{
	
}

cGameManager::~cGameManager()
{
	Release();
}

bool cGameManager::Initialize( HWND hWnd, HINSTANCE hInstance )
{
	if( hWnd == NULL || hInstance == NULL )
	{
		return false;
	}
	 
	m_mainWnd		= hWnd;
	m_mainInstance	= hInstance;
	
	if( RENDER_MGR->Initialize( m_mainWnd, m_mainInstance ) == false )
	{
		return false;
	}
	
	m_Pixel = new cPixel( WIN_SIZE_X, WIN_SIZE_Y, RENDER_MGR->GetBytesPerScanline(), RENDER_MGR->GetBytesPerPixel(), RENDER_MGR->GetBits() );
		
//	SetTimer( m_mainWnd, 1, 10, NULL );
	
//	SendMessage( m_mainWnd, WM_TIMER, 1, 0 );
	
	return true;
}

void cGameManager::Update( void )
{
	//InvalidateRect( m_mainWnd, NULL, FALSE );
}

void cGameManager::Render()
{
	RENDER_MGR->Draw();
}

WPARAM cGameManager::MessageLoop( void )
{
	MSG Message;
	
	while( true )
	{
		if( PeekMessage( &Message, NULL, 0, 0, PM_REMOVE ) )
		{
			if( Message.message == WM_QUIT )
			{
				break;
			}
			
			TranslateMessage( &Message );
			
			DispatchMessage( &Message );
		}
		
		Update();
		Render();
	}
	
	return Message.wParam;
}

LRESULT cGameManager::MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam )
{
    switch( iMessage )
    {
    case WM_LBUTTONDOWN:
       	{
    		LButtonDownProcess( LOWORD(lParam), HIWORD(lParam) );
    	}
    	break;
    case WM_MOUSEMOVE:
    	{
    		MouseMoveProcess( LOWORD(lParam), HIWORD(lParam) );
    	}
    	break;
    case WM_LBUTTONUP:
    	{
    		LButtonUpProcess( LOWORD(lParam), HIWORD(lParam) );
    	}
    	break;
    case WM_KEYDOWN:
    	{
    		switch( wParam )
    		{
    		case VK_ESCAPE:
    			PostQuitMessage( 0 );
    			break;
			}
    		break;
    	}
    case WM_DESTROY:
    	{
        	PostQuitMessage( 0 );
        }
        return 0;
    }
	return ( DefWindowProc( hWnd, iMessage, wParam, lParam ) );
}

void cGameManager::LButtonDownProcess( int x, int y )
{
	if( m_drawState == DRAW_NONE ) 
	{
		if( m_drawType == DRAW_PIXEL )		
		{
			m_Pixel->DrawPixel( x, y );
		}
		else if( m_drawType == DRAW_DDA_LINE )
		{
			m_startX = x; 
			m_startY = y;
		}
	}
	
	m_drawState = DRAW_LBTN_DOWN;
}

void cGameManager::MouseMoveProcess( int x, int y )
{
	RENDER_MGR->DrawTempToMemory();
	
	if( m_drawState == DRAW_LBTN_DOWN ) 
	{
		if( m_drawType == DRAW_PIXEL )		
		{
			m_Pixel->DrawPixel( x, y );
			RENDER_MGR->DrawMemoryToTemp();
		}
		else if( m_drawType == DRAW_DDA_LINE )	
		{
			//m_Pixel->DrawLineDDA( m_startX, m_startY, x, y );
			m_Pixel->DrawBresenhamsLine( m_startX, m_startY, x, y );
		}
	}
}

void cGameManager::LButtonUpProcess( int x, int y )
{
	m_drawState = DRAW_NONE;
	
	RENDER_MGR->DrawMemoryToTemp();
}

void cGameManager::Release( void )
{
}
