/*
   Copyright (C) 2014  absurdworlds

   License LGPLv3-only:
   GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_Vector2d_
#define _hrengin_Vector2d_

#include <hrengin/common/types.h>
#include <hrengin/common/math.h>

namespace hrengin {

//! Represents positions and directions in 2D space
template <typename T>
class Vector2d {
public:
	T X;
	T Y;

public:
	Vector2d() 
		: X(0), Y(0) 
	{
	}

	Vector2d(T x, T y) 
		: X(x), Y(y) 
	{
	}
	
	//! Construct vector with same both coordinates 
	explicit Vector2d(T v) 
		: X(v), Y(v) 
	{
	}

	//! Copy constructor
	Vector2d(Vector2d<T> const& other) 
		: X(other.X), Y(other.Y)
	{
	}

	Vector2d<T>& operator = (Vector2d<T> const& other)
	{
		X = other.X; 
		Y = other.Y; 
		return *this; 
	}

	Vector2d<T> operator - () const 
	{
		return Vector2d<T>(-X, -Y);
	}

	
	Vector2d<T> operator + (Vector2d<T> const& other) const 
	{
		return Vector2d<T>(X + other.X, Y + other.Y);
	}

	Vector2d<T>& operator += (Vector2d<T> const& other) 
	{
		X += other.X; 
		Y += other.Y; 
		return *this; 
	}

	Vector2d<T> operator - (Vector2d<T> const& other) const 
	{ 
		return Vector2d<T>(X - other.X, Y - other.Y); 
	}

	Vector2d<T>& operator -= (Vector2d<T> const& other) 
	{ 
		X-=other.X; 
		Y-=other.Y; 
		return *this; 
	}

	Vector2d<T> operator - (T const v) const 
	{ 
		return Vector2d<T>(X - v, Y - v); 
	}

	Vector2d<T>& operator -= (T const v) 
	{ 
		X-=v; 
		Y-=v; 
		return *this; 
	}

	Vector2d<T> operator * (Vector2d<T> const& other) const 
	{ 
		return Vector2d<T>(X * other.X, Y * other.Y); 
	}

	Vector2d<T>& operator *= (Vector2d<T> const& other) 
	{ 
		X*=other.X; 
		Y*=other.Y; 
		return *this; 
	}

	Vector2d<T> operator * (const T v) const
	{ 
		return Vector2d<T>(X * v, Y * v);
	}

	Vector2d<T>& operator *= (const T v) 
	{
		X*=v; 
		Y*=v; 
		return *this; 
	}

	Vector2d<T> operator / (Vector2d<T> const& other) const 
	{
		return Vector2d<T>(X / other.X, Y / other.Y); 
	}

	Vector2d<T>& operator /= (Vector2d<T> const& other)
	{
		X/=other.X; 
		Y/=other.Y; 
		return *this;
	}

	Vector2d<T> operator / (const T v) const 
	{
		return Vector2d<T>(X / v, Y / v); 
	}

	Vector2d<T>& operator /= (const T v) 
	{
		X/=v; 
		Y/=v; 
		return *this;
	}

	//! Get length of the vector.
	T length() const 
	{
		return math::sqrt( X*X + Y*Y ); 
	}

	//! Get squared length of the vector.
	T squareLength() const 
	{
		return X*X + Y*Y; 
	}
	
	//! Get distance from another point. 
	T getDistance(Vector2d<T> const& other) const
	{
		return Vector2d<T>(X - other.X, Y - other.Y).length();
	}

	//! Get squared distance from another point.
	T getSquaredDistance(Vector2d<T> const& other) const
	{
		return Vector2d<T>(X - other.X, Y - other.Y).squareLength();
	}

	//! Get the dot product of this vector with another
	T dot(Vector2d<T> const& other) const
	{
		return X*other.X + Y*other.Y;
	}
	
	//! Calculates angle of the vector
	T getAngle() const
	{
		T yaw = T(atan2((f64)X, (f64)Y) * math::RADTODEG64);
		
		if (yaw <= -math::PI64) {
			yaw += math::DOUBLE_PI64;
		} else if (yaw > math::PI64) {
			yaw -= math::DOUBLE_PI64;
		}

		return yaw * math::RADTODEG64;
	}

	//! Make the vector of unit length
	Vector2d<T>& normalize()
	{
		f32 length = squareLength();
		if ( length == 0 ) {
			return *this;
		}
		length = math::invSqrt(length);
		X = (T)(X * length);
		Y = (T)(Y * length);
		return *this;
	}
};

//! Linear interpolation of two vectors
template<typename T>
Vector2d<T> lerp (Vector2d<T> const& v0, Vector2d<T> const& v1, f64 t)
{
	return (1.0-t)*v0 + t*v1;
}

} // namespace hrengin

#endif // _hrengin_Vector2d_
