#include "stdafx.h"
#include "cColor.h"

cColor::cColor()
: r( 255 ), g( 255 ), b( 255 )
{
}

cColor::cColor( unsigned char _r, unsigned char _g, unsigned char _b )
: r( _r ), g( _g ), b( _b )
{
}

cColor::~cColor()
{
}
