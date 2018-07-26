#ifndef __COLOR__
#define __COLOR__

class cColor
{
public:
	cColor();
	cColor( unsigned char _r, unsigned char _g, unsigned char _b );
	~cColor();
	
	void 			SetColor( unsigned char _r, unsigned char _g, unsigned char _b );
	void 			SetColor( unsigned long _color );
	
	unsigned long 	GetColor();
	
	void 			SetR( unsigned char _r );
	void 			SetG( unsigned char _g );
	void 			SetB( unsigned char _b );
	
	unsigned char 	GetR() const;
	unsigned char	GetG() const;
	unsigned char	GetB() const;
	
private:
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};

inline void cColor::SetColor( unsigned char _r, unsigned char _g, unsigned char _b )
{
	r = _r;
	g = _g;
	b = _b;
}

inline void cColor::SetColor( unsigned long _color )
{
	b = ( unsigned char ) ((( _color ) & 0x00ff0000 ) >> 16 );
	g = ( unsigned char ) ((( _color ) & 0x0000ff00 ) >> 8 );
	r = ( unsigned char ) ((( _color ) & 0x000000ff ) );
}

inline unsigned long cColor::GetColor()
{
	return( b << 16 ) | ( g << 8 ) | r;
}

inline void cColor::SetR( unsigned char _r ) { r = _r; }
inline void cColor::SetG( unsigned char _g ) { g = _g; }
inline void cColor::SetB( unsigned char _b ) { b = _b; }
inline unsigned char cColor::GetR() const { return r; }
inline unsigned char cColor::GetG() const { return g; }
inline unsigned char cColor::GetB() const { return b; }

#endif
