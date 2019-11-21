#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
: m_mainWnd( NULL ), m_mainInstance( NULL ), m_Pixel( NULL ), m_drawState( DRAW_NONE ), m_drawType( DRAW_BRE_LINE ),
  m_startX( 0 ), m_startY( 0 )
{
	
}

GameManager::~GameManager()
{
	Release();
}

bool GameManager::Initialize( HWND hWnd, HINSTANCE hInstance )
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
	
	//m_Pixel = new Pixel( WIN_SIZE_X, WIN_SIZE_Y, RENDER_MGR->GetBytesPerScanline(), RENDER_MGR->GetBytesPerPixel(), RENDER_MGR->GetBits() );


	m_Model = new Model( "obj/african_face.obj" );
		
//	SetTimer( m_mainWnd, 1, 10, NULL );
	
//	SendMessage( m_mainWnd, WM_TIMER, 1, 0 );
	
	return true;
}

void GameManager::Update( void )
{
	//InvalidateRect( m_mainWnd, NULL, FALSE );
}

void GameManager::Render()
{
	RENDER_MGR->Draw();

	m_Model->Draw();

}

WPARAM GameManager::MessageLoop( void )
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

LRESULT GameManager::MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam )
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
			case VK_F5:
				m_drawType = DRAW_DDA_LINE;		
				break;
			case VK_F6:
				m_drawType = DRAW_BRE_LINE;
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

void GameManager::LButtonDownProcess( int x, int y )
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
		else if( m_drawType == DRAW_BRE_LINE )
		{
			m_startX = x;
			m_startY = y;
		}
	}
	
	m_drawState = DRAW_LBTN_DOWN;
}

void GameManager::MouseMoveProcess( int x, int y )
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
			m_Pixel->SetColor( Color( 255, 255, 0 ) );
			m_Pixel->DrawLineDDA( m_startX, m_startY, x, y );
		}
		else if( m_drawType == DRAW_BRE_LINE )
		{
			m_Pixel->SetColor( Color( 255, 0, 255 ) );
			m_Pixel->DrawBresenhamsLine2( m_startX, m_startY, x, y );
		}
	}
}

void GameManager::LButtonUpProcess( int x, int y )
{
	m_drawState = DRAW_NONE;
	
	RENDER_MGR->DrawMemoryToTemp();
}

void GameManager::Release( void )
{
}
