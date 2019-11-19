#include "stdafx.h"
#include "Utility.h"

/*
	
*/
void _TRACE( LPCSTR szFormat, ... )
{
	char szData[ 4096 ];

	va_list vl;
	va_start( vl, szFormat );
	vsprintf_s( szData, szFormat, vl );
	va_end( vl );

	OutputDebugStringA( szData );
}