#pragma once
#include "stdafx.h"

template <class T>
class Vector2D
{
public:
	Vector2D() :x(0), y(0) {}
	Vector2D(T _x, T _y) : x(_x), y(_y) {}
	Vector2D(const Vector2D& v) : x(v.X()), y(v.Y()) {}
	Vector2D& operator= (const Vector2D& v) = default;

	T Magnitude() const { return T(std::sqrt(x * x + y * y)); }

	T Magnitude2() const{ return x * x + y * y; }

	Vector2D Normalized() const {
		T r = 1 / Magnitude(); return Vector2D(x * r, y * r);
	}

	T Dot(const Vector2D& rhs) const {
		return this->x * rhs.x + this->y * rhs.y;
	}
	T cross(const Vector2D& rhs) const {return this->x * rhs.y - this->y * rhs.x; }

	Vector2D  operator +  (const Vector2D& rhs) const { return Vector2D(this->x + rhs.x, this->y + rhs.y); }
	Vector2D  operator -  (const Vector2D& rhs) const { return Vector2D(this->x - rhs.x, this->y - rhs.y); }
	Vector2D  operator *  (const T& rhs)           const { return Vector2D(this->x * rhs, this->y * rhs); }
	Vector2D  operator /  (const T& rhs)           const { return Vector2D(this->x / rhs, this->y / rhs); }
	void X(T x) { this->x = x; }
	void Y(T y) { this->y = y; }
	T X() const { return x; }
	T Y() const { return y; }

	Vector2D& operator += (const Vector2D& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
	Vector2D& operator -= (const Vector2D& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
	Vector2D& operator *= (const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
	Vector2D& operator /= (const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }

	bool operator == (const Vector2D& rhs) const { return (this->x == rhs.x && this->y == rhs.y); }
	bool operator != (const Vector2D& rhs) const { return (this->x != rhs.x || this->y != rhs.y); }

	const std::string str() const { return std::string("(") + std::to_string(this->x) + "," + std::to_string(this->y) + ")"; }
	friend std::ostream& operator << (std::ostream& os, const Vector2D& rhs) { os << rhs.str(); return os; }


	operator Vector2D<Uint32>() const { return { static_cast<Uint32>(this->x), static_cast<Uint32>(this->y) }; }
	operator Vector2D<Sint32>() const { return { static_cast<Sint32>(this->x), static_cast<Sint32>(this->y) }; }
	operator Vector2D<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; }
	operator Vector2D<double>() const { return { static_cast<double>(this->x), static_cast<double>(this->y) }; }

private:
	T x;
	T y;
};
typedef Vector2D<Sint32> Vector2Di_T;
typedef Vector2D<Uint32> Vector2Du_t;
typedef Vector2D<float> Vector2Df_t;
typedef Vector2D<double> Vector2Dd_t;