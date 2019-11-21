#include "stdafx.h"
#include "Math.h"

float Vec3Length( const Vector3* pV1 )
{
	return sqrt( powf( pV1->x, 2 ) + powf( pV1->y, 2 ) + powf( pV1->z, 2 ) );
}

float Vec3Dot( const Vector3* pV1, const Vector3* pV2 )
{
	return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z + pV2->z;
}

float Vec3DotAngle( const Vector3* pV1, const Vector3* pV2 )
{
	return acosf( Vec3Dot( pV1,pV2 ) );
}

Vector3* Vec3Sub( Vector3* pOut, const Vector3* pV1, const Vector3* pV2 )
{
	if( pOut == NULL || pV1 == NULL || pV2 == NULL )
	{
		return NULL;
	}

	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;
	
	return pOut;
}

Vector3* Vec3Cross( Vector3* pOut, const Vector3* pV1, const Vector3* pV2 )
{
	pOut->x = (pV1->y * pV2->z) - (pV1->z * pV2->y);
	pOut->y = (pV1->z * pV2->x) - (pV1->x * pV2->z);
	pOut->z = (pV1->x * pV2->y) - (pV1->y * pV2->x);
	
	return pOut;
}

Vector3* Vec3Norml( Vector3* pOut, const Vector3* pV1 )
{
	float fLength = Vec3Length( pV1 );

	pOut->x = pV1->x / fLength;
	pOut->y = pV1->y / fLength;
	pOut->z = pV1->z / fLength;

	return pOut;
}