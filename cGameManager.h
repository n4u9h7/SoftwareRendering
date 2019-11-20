#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "cSingleton.h"
#include "cDIBSection.h"
#include "cPixel.h"

class cGameManager
{
public:
	bool		Initialize( HWND hWnd, HINSTANCE hInstance );
	void		Update( void );
	void		Render();
	WPARAM		MessageLoop( void );
	LRESULT		MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam );
	
	HWND		GetWnd( void );
	HINSTANCE	GetInst( void );
		
private:
	cGameManager();
	~cGameManager();
	
	SINGLETON( cGameManager );
	
	void		LButtonDownProcess( int x, int y );
	void		MouseMoveProcess( int x, int y );
	void		LButtonUpProcess( int x, int y );
	void		Release( void );
	
private:
	enum DRAW_STATE
	{
		DRAW_NONE 			= 0,
		DRAW_LBTN_DOWN 		= 1,
		DRAW_LBTN_DOWNMOVE	= 2,
	};
	
	enum DRAW_TYPE
	{
		DRAW_PIXEL			= 0,
		DRAW_DDA_LINE		= 1,
		DRAW_BRE_LINE		= 2,
	};	
	
	HWND		m_mainWnd;
	HINSTANCE	m_mainInstance;
	
	cPixel*		m_Pixel;

	int			m_drawType;
	int			m_drawState;
	int			m_startX;
	int			m_startY;
};

inline HWND 		cGameManager::GetWnd( void )	{ return m_mainWnd; }
inline HINSTANCE	cGameManager::GetInst( void )	{ return m_mainInstance; }

#endif
