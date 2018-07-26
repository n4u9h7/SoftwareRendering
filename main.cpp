#include "stdafx.h"

using namespace std;

HWND 		g_hWnd;
HINSTANCE	g_hInst;

char g_className[ 256 ]	= "GWAPI";
char g_wndName[ 256 ]	= "GWAPI";

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow )
{
	g_hInst = hInstance;
	
	WNDCLASS wndClass;
	
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = g_hInst;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = g_className;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	
	RegisterClass( &wndClass );
	
	int startX = GetSystemMetrics( SM_CXSCREEN ) / 2 - WIN_SIZE_X / 2;
	int startY = GetSystemMetrics( SM_CYSCREEN ) / 2 - WIN_SIZE_Y / 2; 
	
    g_hWnd = CreateWindow( g_className, g_wndName, WS_OVERLAPPEDWINDOW, startX, startY, WIN_SIZE_X, WIN_SIZE_Y, NULL, NULL, g_hInst, NULL );

    ShowWindow( g_hWnd, nCmdShow );
    
    if( GAME_MGR->Initialize( g_hWnd, hInstance ) == false )
    {
    	return 0;
    }
    
    return (int)GAME_MGR->MessageLoop();
}

 LRESULT CALLBACK WndProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam )
{
    return GAME_MGR->MainProc( hWnd, iMessage, wParam, lParam );//DefWindowProc( hWnd, iMessage, wParam, lParam );
}
