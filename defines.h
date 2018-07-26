#ifndef __BASE_DEFINES_H__
#define	__BASE_DEFINES_H__

////////////////////////////////////////////////////////////////////////////////////////////////
// 윈도우 크기 
#define WIN_SIZE_X	1024
#define WIN_SIZE_Y	768

////////////////////////////////////////////////////////////////////////////////////////////////
// 안전 해제 매크로
#define SAFE_DELETE(x) 			{ if( NULL != x ) { delete x; x = NULL; } } 
#define SAFE_DELETE_ARRAY(x)	{ if( NULL != x ) { delete [] x; x = NULL; } }
#define SAFE_RELEASE(x)			{ if( NULL != x ) { x->Release(); x = NULL; } }

////////////////////////////////////////////////////////////////////////////////////////////////
// 기타 매크로 
#define SWAP(a, b)				{ (a) ^= (b); (b) ^= (a); (a) ^= (b); }
#define SWAP_TYPE(type, a, b)   { type __swap_temp; __swap_temp = (b); (b) = (a); (a) = __swap_temp; }

////////////////////////////////////////////////////////////////////////////////////////////////
// 매니저 관련
#include "cGameManager.h"
#include "cDIBSection.h"
#include "cPixel.h"

#define GAME_MGR	cSingleton<cGameManager>::GetInstance()
#define RENDER_MGR	cSingleton<cDIBSection>::GetInstance()
#define PIXEL_MGR	cSingleton<cPixel>::GetInstance()
 
 ////////////////////////////////////////////////////////////////////////////////////////////////
 // 기타 공용 사용 헤더 
 
 
#endif
