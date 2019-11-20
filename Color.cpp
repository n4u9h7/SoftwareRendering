#include "stdafx.h"
#include "Color.h"

Color::Color()
: r( 255 ), g( 255 ), b( 253 )
{
}

Color::Color( unsigned char _r, unsigned char _g, unsigned char _b )
: r( _r ), g( _g ), b( _b )
{
}

Color::~Color()
{
}
