#pragma once
#include "baseinc.h"
#include "vector.h"

struct Matrix44
{
	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float _m[16];
		float m[4][4];
	};

	Matrix44() {};
	Matrix44(const Matrix44& inm) : 
		_11(inm._11), _12(inm._12), _13(inm._13), _14(inm._14),
		_21(inm._21), _22(inm._22), _23(inm._23), _24(inm._24),
		_31(inm._31), _32(inm._32), _33(inm._33), _34(inm._34),
		_41(inm._41), _42(inm._42), _43(inm._43), _44(inm._44) {}

	Matrix44(const float in_11, const float in_12, const float in_13, const float in_14,
		const float in_21, const float in_22, const float in_23, const float in_24,
		const float in_31, const float in_32, const float in_33, const float in_34,
		const float in_41, const float in_42, const float in_43, const float in_44) :
		_11(in_11), _12(in_12), _13(in_13), _14(in_14),
		_21(in_21), _22(in_22), _23(in_23), _24(in_24),
		_31(in_31), _32(in_32), _33(in_33), _34(in_34),
		_41(in_41), _42(in_42), _43(in_43), _44(in_44) {}

	Matrix44(const Vector4& Row0, const Vector4& Row1, const Vector4& Row2, const Vector4& Row3)
	{
		_11 = Row0.x; _12 = Row0.y; _13 = Row0.z; _14 = Row0.w;
		_21 = Row1.x; _22 = Row1.y; _23 = Row1.z; _24 = Row1.w;
		_31 = Row2.x; _32 = Row2.y; _33 = Row2.z; _34 = Row2.w;
		_41 = Row3.x; _42 = Row3.y; _43 = Row3.z; _44 = Row3.w;
	};


	inline const Matrix44& operator = (const Matrix44& inm)
	{
		_11 = inm._11; _12 = inm._12; _13 = inm._13; _14 = inm._14;
		_21 = inm._21; _22 = inm._22; _23 = inm._23; _24 = inm._24;
		_31 = inm._31; _32 = inm._32; _33 = inm._33; _34 = inm._34;
		_41 = inm._41; _42 = inm._42; _43 = inm._43; _44 = inm._44;
		return *this;
	}

	inline bool operator == (const Matrix44& inm) const
	{
		for (int i = 0; i < 16; ++i)
		{
			if (_m[i] != inm._m[i])
			{
				return false;
			}
		}
		return true;
	}

	inline bool operator != (const Matrix44& inm) const
	{
		for (int i = 0; i < 16; ++i)
		{
			if (_m[i] != inm._m[i])
			{
				return true;
			}
		}
		return false;
	}

	inline Matrix44 operator +(const Matrix44& inm) const
	{
		return Matrix44(
			_11 + inm._11, _12 + inm._12, _13 + inm._13, _14 + inm._14,
			_21 + inm._21, _22 + inm._22, _23 + inm._23, _24 + inm._24,
			_31 + inm._31, _32 + inm._32, _33 + inm._33, _34 + inm._34,
			_41 + inm._41, _42 + inm._42, _43 + inm._43, _44 + inm._44);
	}

	inline Matrix44 operator - (const Matrix44& inm) const
	{
		return Matrix44(
			_11 - inm._11, _12 - inm._12, _13 - inm._13, _14 - inm._14,
			_21 - inm._21, _22 - inm._22, _23 - inm._23, _24 - inm._24,
			_31 - inm._31, _32 - inm._32, _33 - inm._33, _34 - inm._34,
			_41 - inm._41, _42 - inm._42, _43 - inm._43, _44 - inm._44);
	}

	inline Matrix44 operator * (const Matrix44& inm) const
	{
		return Matrix44(
			_11 * inm._11 + _12 * inm._21 + _13 * inm._31 + _14 * inm._41,
			_11 * inm._12 + _12 * inm._22 + _13 * inm._32 + _14 * inm._42,
			_11 * inm._13 + _12 * inm._23 + _13 * inm._33 + _14 * inm._43,
			_11 * inm._14 + _12 * inm._24 + _13 * inm._34 + _14 * inm._44,
			_21 * inm._11 + _22 * inm._21 + _23 * inm._31 + _24 * inm._41,
			_21 * inm._12 + _22 * inm._22 + _23 * inm._32 + _24 * inm._42,
			_21 * inm._13 + _22 * inm._23 + _23 * inm._33 + _24 * inm._43,
			_21 * inm._14 + _22 * inm._24 + _23 * inm._34 + _24 * inm._44,
			_31 * inm._11 + _32 * inm._21 + _33 * inm._31 + _34 * inm._41,
			_31 * inm._12 + _32 * inm._22 + _33 * inm._32 + _34 * inm._42,
			_31 * inm._13 + _32 * inm._23 + _33 * inm._33 + _34 * inm._43,
			_31 * inm._14 + _32 * inm._24 + _33 * inm._34 + _34 * inm._44,
			_41 * inm._11 + _42 * inm._21 + _43 * inm._31 + _44 * inm._41,
			_41 * inm._12 + _42 * inm._22 + _43 * inm._32 + _44 * inm._42,
			_41 * inm._13 + _42 * inm._23 + _43 * inm._33 + _44 * inm._43,
			_41 * inm._14 + _42 * inm._24 + _43 * inm._34 + _44 * inm._44);
	}


	inline Matrix44& operator += (const Matrix44& inm)
	{
		_11 += inm._11; _12 += inm._12; _13 += inm._13; _14 += inm._14;
		_21 += inm._21; _22 += inm._22; _23 += inm._23; _24 += inm._24;
		_31 += inm._31; _32 += inm._32; _33 += inm._33; _34 += inm._34;
		_41 += inm._41; _42 += inm._42; _43 += inm._43; _44 += inm._44;
		return *this;
	}

	inline Matrix44& operator -= (const Matrix44& inm)
	{
		_11 -= inm._11; _12 -= inm._12; _13 -= inm._13; _14 -= inm._14;
		_21 -= inm._21; _22 -= inm._22; _23 -= inm._23; _24 -= inm._24;
		_31 -= inm._31; _32 -= inm._32; _33 -= inm._33; _34 -= inm._34;
		_41 -= inm._41; _42 -= inm._42; _43 -= inm._43; _44 -= inm._44;
		return *this;
	}

	inline Matrix44& operator *= (const Matrix44& inm)
	{
		const float r11 = _11 * inm._11 + _12 * inm._21 + _13 * inm._31 + _14 * inm._41;
		const float r12 = _11 * inm._12 + _12 * inm._22 + _13 * inm._32 + _14 * inm._42;
		const float r13 = _11 * inm._13 + _12 * inm._23 + _13 * inm._33 + _14 * inm._43;
		const float r14 = _11 * inm._14 + _12 * inm._24 + _13 * inm._34 + _14 * inm._44;
		const float r21 = _21 * inm._11 + _22 * inm._21 + _23 * inm._31 + _24 * inm._41;
		const float r22 = _21 * inm._12 + _22 * inm._22 + _23 * inm._32 + _24 * inm._42;
		const float r23 = _21 * inm._13 + _22 * inm._23 + _23 * inm._33 + _24 * inm._43;
		const float r24 = _21 * inm._14 + _22 * inm._24 + _23 * inm._34 + _24 * inm._44;
		const float r31 = _31 * inm._11 + _32 * inm._21 + _33 * inm._31 + _34 * inm._41;
		const float r32 = _31 * inm._12 + _32 * inm._22 + _33 * inm._32 + _34 * inm._42;
		const float r33 = _31 * inm._13 + _32 * inm._23 + _33 * inm._33 + _34 * inm._43;
		const float r34 = _31 * inm._14 + _32 * inm._24 + _33 * inm._34 + _34 * inm._44;
		const float r41 = _41 * inm._11 + _42 * inm._21 + _43 * inm._31 + _44 * inm._41;
		const float r42 = _41 * inm._12 + _42 * inm._22 + _43 * inm._32 + _44 * inm._42;
		const float r43 = _41 * inm._13 + _42 * inm._23 + _43 * inm._33 + _44 * inm._43;
		const float r44 = _41 * inm._14 + _42 * inm._24 + _43 * inm._34 + _44 * inm._44;

		_11 = r11; _12 = r12; _13 = r13; _14 = r14;
		_21 = r21; _22 = r22; _23 = r23; _24 = r24;
		_31 = r31; _32 = r32; _33 = r33; _34 = r34;
		_41 = r41; _42 = r42; _43 = r43; _44 = r44;
		return *this;
	}
};


//void MatrixTranspose(Matrix44& outm, const Matrix44 i_matMat);
//void MatrixZero(Matrix44* outm);
//void MatrixIdentity(Matrix44& outm);
//void MatrixScaling(Matrix44& outm, const float i_fX, const float i_fY, const float i_fZ);
//void MatrixScaling(Matrix44& outm, const Vector3& i_vScale);
//void MatrixTranslation(Matrix44& outm, const float i_fX, const float i_fY, const float i_fZ);
//void MatrixTranslation(Matrix44& outm, const Vector3& i_vTranslation);
//void MatrixRotationX(Matrix44& outm, const float i_fRot);
//void MatrixRotationY(Matrix44& outm, const float i_fRot);
//void MatrixRotationZ(Matrix44& outm, const float i_fRot);
//void MatrixRotationYawPitchRoll(Matrix44& outm, const float i_fYaw, const float i_fPitch, const float i_fRoll);
//void MatrixRotationYawPitchRoll(Matrix44& outm, const Vector3& i_vRot);
//void MatrixRotationAxis(Matrix44& outm, const Vector3& i_vAxis, const float i_fRot);
//void MatrixLookAtLH(Matrix44& outm, const Vector3& i_vEye, const Vector3& i_vAt, const Vector3& i_vUp);
//void MatrixLookAtRH(Matrix44& outm, const Vector3& i_vEye, const Vector3& i_vAt, const Vector3& i_vUp);
//void MatrixPerspectiveFovLH(Matrix44& outm, const float i_fFOVY, const float i_fAspect, const float i_fZNear, const float i_fZFar);
//void MatrixPerspectiveFovRH(Matrix44& outm, const float i_fFOVY, const float i_fAspect, const float i_fZNear, const float i_fZFar);