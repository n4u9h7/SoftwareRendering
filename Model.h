#ifndef __MODEL__
#define __MODEL__

#include <vector>
#include "Math.h"
#include "Pixel.h"

using namespace std;

class Model
{
public:
	Model( const char* fineName );
	~Model();

	bool				Init();
	void				Draw();

	vector3f			GetVertex( int idx );
	vector<int>			GetFace( int idx );

	int					GetCountVertex();
	int					GetCountFace();

private:
	vector<vector3f>	vVertexces;	// Vertex Vector
	vector<vector<int>>	vFaces;		// Faces Vector

	Pixel*				m_Pixel;
};

#endif