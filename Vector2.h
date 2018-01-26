#pragma once

#include <math.h>
#include <cmath>

class Vector2
{

public:
	double x, y;

// ---------------------------------------------------------------------------------------------------- //

public:
	inline Vector2() {}

	inline Vector2(const double x, const double y) : x(x), y(y) {}

	inline Vector2(const Vector2 &v) : x(v.x), y(v.y) {}

// ---------------------------------------------------------------------------------------------------- //

	inline bool operator==(const Vector2 &v) const
	{
		const double EPSILON = 0.000000000000001;
		return abs(x - v.x) < EPSILON && abs(y - v.y) < EPSILON;
	}

	inline bool operator!=(const Vector2 &v) const
	{
		return x != v.x || y != v.y;
	}

	inline Vector2 operator+(const Vector2 &v) const
	{
		return Vector2(x+v.x, y+v.y);
	}

	inline Vector2 & operator+=(const Vector2 &v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	inline Vector2 operator-(const Vector2 &v) const
	{
		return Vector2(x-v.x, y-v.y);
	}

	inline Vector2 & operator-=(const Vector2 &v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	inline Vector2 operator*(const double s) const
	{
		return Vector2(x*s, y*s);
	}

	inline Vector2 & operator*=(const double s)
	{
		x *= s;
		y *= s;
		return *this;
	}

	inline Vector2 operator/(const double s) const
	{
		double f = 1.0 / s;
		return Vector2(x*f, y*f);
	}

	inline Vector2 & operator/=(const double s)
	{
		double f = 1.0 / s;
		x *= f;
		y *= f;
		return *this;
	}

	inline Vector2 operator-() const
	{
		return Vector2(-x, -y);
	}

};