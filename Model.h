#ifndef __MODEL__
#define __MODEL__

#include <vector>
#include "Vector.h"
#include "Pixel.h"

using namespace std;

class Model
{
public:
	Model( const char* fineName );
	~Model();

	bool				Init();
	void				Draw();

	Vector3				GetVertex( int idx );
	vector<int>			GetFace( int idx );

	int					GetCountVertex();
	int					GetCountFace();

private:
	vector<Vector3>		vVertexces;	// Vertex Vector
	vector<vector<int>>	vFaces;		// Faces Vector

	Pixel*				m_Pixel;
};

#endif