#ifndef __BASE_DEFINES_H__
#define	__BASE_DEFINES_H__

////////////////////////////////////////////////////////////////////////////////////////////////
// ������ ũ�� 
#define WIN_SIZE_X	1024
#define WIN_SIZE_Y	1024

////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ���� ��ũ��
#define SAFE_DELETE(x) 			{ if( NULL != x ) { delete x; x = NULL; } } 
#define SAFE_DELETE_ARRAY(x)	{ if( NULL != x ) { delete [] x; x = NULL; } }
#define SAFE_RELEASE(x)			{ if( NULL != x ) { x->Release(); x = NULL; } }

////////////////////////////////////////////////////////////////////////////////////////////////
// ��Ÿ ��ũ��
#define SWAP(a, b)				{ (a) ^= (b); (b) ^= (a); (a) ^= (b); }
#define SWAP_TYPE(type, a, b)   { type __swap_temp; __swap_temp = (b); (b) = (a); (a) = __swap_temp; }
#define DEBUG_ONLY(f)			((void)0)
#define ASSERT(f)				DEBUG_ONLY((void) ((f) || !::AfxAssertFailedLine(THIS_FILE, __LINE__) || (AfxDebugBreak(), 0)))
#define TRACE _TRACE
#define Abs(x)					((x)>0 ? (x) : -(x))
#define Max(a,b)				(((a) > (b) ) ? (a) : (b) )
#define Min(a,b)				(((a) < (b) ) ? (a) : (b) )

////////////////////////////////////////////////////////////////////////////////////////////////
// �Ŵ��� ����
#include "GameManager.h"
#include "DIBSection.h"
#include "Pixel.h"

#define GAME_MGR	Singleton<GameManager>::GetInstance()
#define RENDER_MGR	Singleton<DIBSection>::GetInstance()
#define PIXEL_MGR	Singleton<Pixel>::GetInstance()
 
 ////////////////////////////////////////////////////////////////////////////////////////////////
 // ��Ÿ ���� ��� ��� 
 
 
#endif
