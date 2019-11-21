#include "stdafx.h"
#include "Model.h"

Model::Model( const char* fileName )
:vVertexces(), vFaces()
{
	if( Init() == false )
	{
		return;
	}

	ifstream in;
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
			Vector3 v;

			for( int i = 0; i < 3; i++ )
			{
				iss >> v.raw[i];
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
	for( int i = 0; i < GetCountFace(); i++ )
	{
		vector<int> face = GetFace( i );
		
		for( int j = 0; j < 3; j++ )
		{
			Vector3 v0 = GetVertex( face[j] );
			Vector3 v1 = GetVertex( face[(j+1)%3] );

			int x0 = WIN_SIZE_X - ( v0.x + 1.0f ) * WIN_SIZE_X / 2.0f;
			int y0 = WIN_SIZE_Y - ( v0.y + 1.0f ) * WIN_SIZE_Y / 2.0f;
			int x1 = WIN_SIZE_X - ( v1.x + 1.0f ) * WIN_SIZE_X / 2.0f;
			int y1 = WIN_SIZE_Y - ( v1.y + 1.0f ) * WIN_SIZE_Y / 2.0f;

			m_Pixel->DrawBresenhamsLine2( x0, y0, x1, y1 );
		}
	}
}

Vector3 Model::GetVertex( int idx )
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
