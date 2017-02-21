#pragma once
#include "baseinc.h"

struct Vector2
{

	float x, y;
	
	Vector2() {}
	Vector2(const Vector2& v) : x(v.x), y(v.y){}
	Vector2(const float inx, const float iny) : x(inx), y(iny){}

	static const Vector2 ZeroVector;

	static const Vector2 UnitVector;

	inline Vector2& operator = (const Vector2& v)
	{
		x = v.x; y = v.y;
		return *this;
	}

	inline bool operator == (const Vector2& v) const
	{
		return x == v.x && y == v.y;
	}

	inline bool operator != (const Vector2& v) const
	{
		return x != v.x || y != v.y;
	}

	inline Vector2 operator - () const
	{
		return Vector2(-x, -y);
	}

	inline Vector2 operator + (const Vector2& v) const
	{
		return Vector2(x + v.x, y + v.y);
	}

	inline Vector2 operator - (const Vector2& v) const
	{
		return Vector2(x - v.x, y - v.y);
	}

	inline Vector2 operator * (const float scale) const
	{
		return Vector2(x * scale, y * scale);
	}

	inline Vector2 operator / (const float scale) const
	{
		float inv = 1.0f / scale;
		return Vector2(x * inv, y * inv);
	}

	inline Vector2 & operator += (const Vector2 & v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	inline Vector2 & operator -= (const Vector2 & v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	inline Vector2 & operator *= (const float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	inline Vector2 & operator /= (const float scale)
	{
		float inv = 1.0f / scale;
		x *= inv;
		y *= inv;
		return *this;
	}

	inline void Zero() { x = y = 0.0f; }

	inline float Length() const
	{
		return sqrt(x * x + y * y);
	}
	
	inline float LengthSquared() const
	{
		return x * x + y * y;
	}

	inline Vector2& Normalize()
	{
		*this /= Length();
		return *this;
	}

	static inline float Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	static inline float Distance(const Vector2& v1, const Vector2& v2)
	{
		auto v3 = v1 - v2;
		return v3.Length();
	}

	inline std::string ToString() const
	{
		return strformat::format("X={0} Y={1}", x, y);
	}
};

struct Vector3
{
	union
	{
		struct { float x, y, z; };
		struct { float r, g, b; };
		struct { Vector2 xy; float align; };
	};

	Vector3() {}
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
	Vector3(const Vector2& v, const float inz) : x(v.x), y(v.y), z(inz) {}
	Vector3(const float inx, const float iny, const float inz) : x(inx), y(iny), z(inz) {}

	static const Vector3 ZeroVector;

	static const Vector3 UpVector;

	static const Vector3 ForwardVector;

	static const Vector3 RightVector;

	inline Vector3& operator = (const Vector3& v)
	{
		
		x = v.x; y = v.y; z = v.z;
		return *this;
	}

	inline bool operator == (const Vector3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	inline bool operator != (const Vector3& v) const
	{
		return x != v.x || y != v.y || z != v.z;
	}

	inline Vector3 operator - () const
	{
		return Vector3(-x, -y, -z);
	}

	inline Vector3 operator + (const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline Vector3 operator - (const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator * (const float scale) const
	{
		return Vector3(x * scale, y * scale, z * scale);
	}

	inline Vector3 operator / (const float scale) const
	{
		float inv = 1.0f / scale;
		return Vector3(x * inv, y * inv, z * inv);
	}

	inline Vector3 & operator += (const Vector3 & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	inline Vector3 & operator -= (const Vector3 & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	inline Vector3 & operator *= (const float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	inline Vector3 & operator /= (const float scale)
	{
		float inv = 1.0f / scale;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}

	inline void Zero() { x = y = z = 0.0f; }

	inline float Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline float LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	inline Vector3& Normalize()
	{
		*this /= Length();
		return *this;
	}

	static inline float Dot(const Vector3& v1, const Vector3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static inline Vector3 Cross(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		);
	}

	static inline float Distance(const Vector3& v1, const Vector3& v2)
	{
		auto v3 = v1 - v2;
		return v3.Length();
	}

	inline std::string ToString() const
	{
		return strformat::format("X={0} Y={1} Z={2}", x, y, z);
	}
};


struct Vector4
{
	union
	{
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
		struct { Vector2 xy; float align1, align2; };
		struct { Vector3 xyz; float align3; };
		struct { Vector3 rgb; float align4; };
	};

	Vector4() {}
	Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
	Vector4(const Vector3& v, const float inw = 1.0f) : x(v.x), y(v.y), z(v.z), w(inw) {}
	Vector4(const float inx, const float iny, const float inz, const float inw = 1.0f) : x(inx), y(iny), z(inz), w(inw) {}

	inline Vector4& operator = (const Vector4& v)
	{
		x = v.x; y = v.y; z = v.z, w = v.w;
		return *this;
	}

	inline bool operator == (const Vector4& v) const
	{
		return x == v.x && y == v.y && z == v.z && w == v.w;
	}

	inline bool operator != (const Vector4& v) const
	{
		return x != v.x || y != v.y || z != v.z || w != v.w;
	}

	inline Vector4 operator + (const Vector4& v) const
	{
		return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	inline Vector4 operator - (const Vector4& v) const
	{
		return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	inline Vector4 operator * (const float scale) const
	{
		return Vector4(x * scale, y * scale, z * scale, w * scale);
	}

	inline Vector4 operator / (const float scale) const
	{
		float inv = 1.0f / scale;
		return Vector4(x * inv, y * inv, z * inv, w * inv);
	}

	inline Vector4 & operator += (const Vector4 & v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}
	inline Vector4 & operator -= (const Vector4 & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}
	inline Vector4 & operator *= (const float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		w *= scale;
		return *this;
	}

	inline Vector4 & operator /= (const float scale)
	{
		float inv = 1.0f / scale;
		x *= inv;
		y *= inv;
		z *= inv;
		w *= inv;
		return *this;
	}

	inline float Length3() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline float LengthSquared3() const
	{
		return x * x + y * y + z * z;
	}

	inline Vector4& Normalize3()
	{
		*this /= Length3();
		w = 0.0;
		return *this;
	}

	static inline float Dot3(const Vector4& v1, const Vector4& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static inline Vector3 Cross3(const Vector4& v1, const Vector4& v2)
	{
		return Vector3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		);
	}

	static inline float Distance3(const Vector4& v1, const Vector4& v2)
	{
		auto v3 = v1 - v2;
		return v3.Length3();
	}

	inline std::string ToString() const
	{
		return strformat::format("X={0} Y={1} Z={2} W={3}", x, y, z, w);
	}
};
