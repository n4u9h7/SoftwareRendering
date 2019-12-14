#include "stdafx.h"
#include "Model.h"

Model::Model( const char* fileName )
: vVertexces(), vFaces()
{
	if( Init() == false )
	{
		return;
	}

	std::ifstream in;
	in.open( fileName, ifstream::in );

	if( in.fail() )
	{
		return;
	}

	string line;

	while( !in.eof() )
	{
		getline( in, line );
		istringstream iss( line.c_str() );

		char trash;
		
		if( !line.compare( 0, 2, "v " ) )
		{
			iss >> trash;
			vector3f v;

			for( int i = 0; i < 3; i++ )
			{
				iss >> v[i];
			}

			vVertexces.push_back( v );
		}
		else if( !line.compare( 0, 2, "f " ) )
		{
			vector<int> f;

			int itrash, idx;

			iss >> trash;

			while( iss >> idx >> trash >> itrash >> trash >> itrash )
			{
				idx--;
				f.push_back( idx );
			}

			vFaces.push_back( f );
		}
	}
}

Model::~Model()
{
	SAFE_DELETE( m_Pixel );
}

bool Model::Init()
{
	m_Pixel = new Pixel( WIN_SIZE_X, WIN_SIZE_Y, RENDER_MGR->GetBytesPerScanline(), RENDER_MGR->GetBytesPerPixel(), RENDER_MGR->GetBits() );

	if( m_Pixel == NULL )
	{
		return false;
	}

	return true;
}

void Model::Draw()
{
	float *zBuffer = new float[ WIN_SIZE_X * WIN_SIZE_Y ];

	for( int i = WIN_SIZE_X * WIN_SIZE_Y; i--; zBuffer[i] = -std::numeric_limits<float>::max() );

	for( int i = 0; i < GetCountFace(); i++ )
	{
		vector<int> face = GetFace(i);

		vector3f pts[3];

		for( int j = 0; j < 3; j++ )
		{
			pts[j] = worldToscreen( GetVertex( face[j] ) );
		}

		m_Pixel->DrawTriangle( pts, zBuffer, Color( rand()%255, rand()%255, rand()%255 ) );
	}
}

vector3f Model::worldToscreen( vector3f v )
{
	return vector3f( int( ( v.x + 1.0f ) * WIN_SIZE_X / 2.0f + 0.5f ), int( ( v.y + 1.0f ) * WIN_SIZE_Y / 2.0f + 0.5f ), v.z );
}

vector3f Model::GetVertex( int idx )
{
	return vVertexces[ idx ];
}

vector<int> Model::GetFace( int idx )
{
	return vFaces[ idx ];
}

int	Model::GetCountVertex()
{
	return ( int )vVertexces.size();
}

int	Model::GetCountFace()
{
	return ( int )vFaces.size();
}
