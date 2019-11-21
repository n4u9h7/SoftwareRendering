#pragma once

float		Vec3Length( const Vector3* pV1 );
float		Vec3Dot( const Vector3* pV1, const Vector3* pV2 );
float		Vec3DotAngle( const Vector3* pV1, const Vector3* pV2 );
Vector3*	Vec3Sub( Vector3* pOut, const Vector3* pV1, const Vector3* pV2 );
Vector3*	Vec3Cross( Vector3* pOut, const Vector3* pV1, const Vector3* pV2 );
Vector3*	Vec3Norml( Vector3* pOut, const Vector3* pV1 );

