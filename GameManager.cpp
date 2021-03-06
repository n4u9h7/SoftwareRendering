#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
: m_mainWnd( NULL ), m_mainInstance( NULL ), m_Pixel( NULL ), m_drawState( DRAW_NONE ), m_drawType( DRAW_BRE_LINE ),
  m_startX( 0 ), m_startY( 0 ), m_Model( NULL )
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
	
	m_Model = new Model( "obj/african_head.obj" );

	if( m_Model == NULL )
	{
		return false;
	}
		
//	SetTimer( m_mainWnd, 1, 10, NULL );
	
//	SendMessage( m_mainWnd, WM_TIMER, 1, 0 );

 	//Vector2 t0[3] = { Vector2( 10, 70 ), Vector2( 50, 160 ), Vector2( 70, 80 ) };
	//m_Pixel->DrawTriangle( t0, Color( 255, 255, 0 ) );
// 	Vector2 t1[3] = { Vector2( 180, 50 ), Vector2( 150, 1 ), Vector2( 70, 180 ) };
// 	Vector2 t2[3] = { Vector2( 180, 150 ), Vector2( 120, 160 ), Vector2( 130, 180 ) };
// 
// 	m_Pixel->DrawTriangle( t0[0], t0[1], t0[2], Color( 255, 255, 0 ) );
// 	m_Pixel->DrawTriangle( t1[0], t1[1], t1[2], Color( 0, 255, 255 ) );
// 	m_Pixel->DrawTriangle( t2[0], t2[1], t2[2], Color( 255, 0, 255 ) );

	m_Model->Draw();
	
	return true;
}

void GameManager::Update( void )
{
	//InvalidateRect( m_mainWnd, NULL, FALSE );
}

void GameManager::Render()
{
	RENDER_MGR->Draw();

	/*m_Model->Draw();*/
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
// 	RENDER_MGR->DrawTempToMemory();
// 	
// 	if( m_drawState == DRAW_LBTN_DOWN ) 
// 	{
// 		if( m_drawType == DRAW_PIXEL )		
// 		{
// // 			m_Pixel->DrawPixel( x, y );
// // 			RENDER_MGR->DrawMemoryToTemp();
// 		}
// 		else if( m_drawType == DRAW_DDA_LINE )	
// 		{
// // 			m_Pixel->SetColor( Color( 255, 255, 0 ) );
// // 			m_Pixel->DrawLineDDA( m_startX, m_startY, x, y );
// 		}
// 		else if( m_drawType == DRAW_BRE_LINE )
// 		{
// // 			m_Pixel->SetColor( Color( 255, 0, 255 ) );
// // 			m_Pixel->DrawBresenhamsLine2( m_startX, m_startY, x, y );
// 		}
// 	}
}

void GameManager::LButtonUpProcess( int x, int y )
{
	m_drawState = DRAW_NONE;
	
	RENDER_MGR->DrawMemoryToTemp();
}

void GameManager::Release( void )
{
	SAFE_DELETE( m_Pixel );
	//SAFE_DELETE( m_Model );
}
