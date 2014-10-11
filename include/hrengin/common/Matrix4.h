/*
   Copyright (C) 2014  absurdworlds

   License LGPLv3-only:
   GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_Matrix4_
#define _hrengin_Matrix4_

#include <hrengin/common/Vector3d.h>
#include <hrengin/common/Vector4d.h>

namespace hrengin {

//! Represents a 4x4 matrix, which has a column-major layout
template<typename T>
class Matrix4 {
public:
	typedef Vector4d<T> col_type;

	Matrix4 ()
	{
	}

	Matrix4 (Matrix4 const& other)
	{
		col_[0].set(other[0]);
		col_[1].set(other[1]);
		col_[2].set(other[2]);
		col_[3].set(other[3]);
	}
	
	/*! Construct matrix from individual values
	   \note Arguments here appear in row-major order
	*/
	Matrix4 (T const a11, T const a21, T const a31, T const a41,
		 T const a12, T const a22, T const a32, T const a42,
		 T const a13, T const a23, T const a33, T const a43,
		 T const a14, T const a24, T const a34, T const a44)
	{
		set (a11, a21, a31, a41,
		     a12, a22, a32, a42,
		     a13, a23, a33, a43,
		     a14, a24, a34, a44);
	}

	/*! Set each componenet of the matrix
	   \note Arguments here appear in row-major order
	*/
	void set (T const a11, T const a21, T const a31, T const a41,
		  T const a12, T const a22, T const a32, T const a42,
		  T const a13, T const a23, T const a33, T const a43,
		  T const a14, T const a24, T const a34, T const a44)
	{
		col_[0].set(a11, a12, a13, a14);
		col_[1].set(a21, a22, a23, a24);
		col_[2].set(a31, a32, a33, a34);
		col_[3].set(a41, a42, a43, a44);
	}

	//! Set matrix to identity
	Matrix4<T>& setIdentity ()
	{
		set(T(1),T(0),T(0),T(0),
		    T(0),T(1),T(0),T(0),
		    T(0),T(0),T(1),T(0),
		    T(0),T(0),T(0),T(1));
		return *this;
	}

	//! Matrix multiplication
	Matrix4<T> operator * (Matrix4<T> const& B) const
	{
		Matrix4<T> C;
		
		C[0] = col_[0]*B[0][0] + col_[1]*B[0][1] + col_[2]*B[0][2] + col_[3]*B[0][3];
		C[1] = col_[0]*B[1][0] + col_[1]*B[1][1] + col_[2]*B[1][2] + col_[3]*B[1][3];
		C[2] = col_[0]*B[2][0] + col_[1]*B[2][1] + col_[2]*B[2][2] + col_[3]*B[2][3];
		C[3] = col_[0]*B[3][0] + col_[1]*B[3][1] + col_[2]*B[3][2] + col_[3]*B[3][3];
		
		return C;
	}
	
	//! Multiply matrix by scalar
	Matrix4<T> operator * (T const& S) const
	{
		Matrix4<T> M(*this);
		M[0] *= S;
		M[1] *= S;
		M[2] *= S;
		M[3] *= S;
		
		return M;
	}

	//! Multiply matrix by scalar
	Matrix4<T>& operator *= (T const& S)
	{
		col_[0]  *= S;
		col_[1]  *= S;
		col_[2]  *= S;
		col_[3]  *= S;
		
		return *this;
	}
	
	//! Divide matrix by scalar
	Matrix4<T> operator / (T const& S) const
	{
		Matrix4<T> M(*this);
		M[0] /= S;
		M[1] /= S;
		M[2] /= S;
		M[3] /= S;
		
		return M;
	}

	//! Divide matrix by scalar
	Matrix4<T>& operator /= (T const& S)
	{
		col_[0]  /= S;
		col_[1]  /= S;
		col_[2]  /= S;
		col_[3]  /= S;
		
		return *this;
	}

	//! Get transopsed matrix
	Matrix4<T> getTransposed () const
	{
		Matrix4<T> M;
		
		M[0].set(col_[0][0], col_[1][0], col_[2][0], col_[3][0]);
		M[0].set(col_[0][1], col_[1][1], col_[2][1], col_[3][1]);
		M[0].set(col_[0][2], col_[1][2], col_[2][2], col_[3][2]);
		M[0].set(col_[0][3], col_[1][3], col_[2][3], col_[3][3]);
		
		return M;
	}
	
	/*! Get matrix inverse of this matrix
	    \return True if inverse matrix exists, flase otherwise.
	*/
	bool getInverse (Matrix4<T>& M) const
	{
		T det = determinant();

		if(math::equals(det, T(0.0))) {
			return false;
		}
		
		M[0][0] = col_[2][1]*col_[3][2]*col_[1][3] - col_[3][1]*col_[2][2]*col_[1][3] +
			  col_[3][1]*col_[1][2]*col_[2][3] - col_[1][1]*col_[3][2]*col_[2][3] -
			  col_[2][1]*col_[1][2]*col_[3][3] + col_[1][1]*col_[2][2]*col_[3][3];
		M[0][1] = col_[3][1]*col_[2][2]*col_[0][3] - col_[2][1]*col_[3][2]*col_[0][3] -
			  col_[3][1]*col_[0][2]*col_[2][3] + col_[0][1]*col_[3][2]*col_[2][3] +
			  col_[2][1]*col_[0][2]*col_[3][3] - col_[0][1]*col_[2][2]*col_[3][3];
		M[0][2] = col_[1][1]*col_[3][2]*col_[0][3] - col_[3][1]*col_[1][2]*col_[0][3] +
			  col_[3][1]*col_[0][2]*col_[1][3] - col_[0][1]*col_[3][2]*col_[1][3] -
			  col_[1][1]*col_[0][2]*col_[3][3] + col_[0][1]*col_[1][2]*col_[3][3];
		M[0][3] = col_[2][1]*col_[1][2]*col_[0][3] - col_[1][1]*col_[2][2]*col_[0][3] -
			  col_[2][1]*col_[0][2]*col_[1][3] + col_[0][1]*col_[2][2]*col_[1][3] +
			  col_[1][1]*col_[0][2]*col_[2][3] - col_[0][1]*col_[1][2]*col_[2][3];
		M[1][0] = col_[3][0]*col_[2][2]*col_[1][3] - col_[2][0]*col_[3][2]*col_[1][3] -
			  col_[3][0]*col_[1][2]*col_[2][3] + col_[1][0]*col_[3][2]*col_[2][3] +
			  col_[2][0]*col_[1][2]*col_[3][3] - col_[1][0]*col_[2][2]*col_[3][3];
		M[1][1] = col_[2][0]*col_[3][2]*col_[0][3] - col_[3][0]*col_[2][2]*col_[0][3] +
			  col_[3][0]*col_[0][2]*col_[2][3] - col_[0][0]*col_[3][2]*col_[2][3] -
			  col_[2][0]*col_[0][2]*col_[3][3] + col_[0][0]*col_[2][2]*col_[3][3];
		M[1][2] = col_[3][0]*col_[1][2]*col_[0][3] - col_[1][0]*col_[3][2]*col_[0][3] -
			  col_[3][0]*col_[0][2]*col_[1][3] + col_[0][0]*col_[3][2]*col_[1][3] +
			  col_[1][0]*col_[0][2]*col_[3][3] - col_[0][0]*col_[1][2]*col_[3][3];
		M[1][3] = col_[1][0]*col_[2][2]*col_[0][3] - col_[2][0]*col_[1][2]*col_[0][3] +
			  col_[2][0]*col_[0][2]*col_[1][3] - col_[0][0]*col_[2][2]*col_[1][3] -
			  col_[1][0]*col_[0][2]*col_[2][3] + col_[0][0]*col_[1][2]*col_[2][3];
		M[2][0] = col_[2][0]*col_[3][1]*col_[1][3] - col_[3][0]*col_[2][1]*col_[1][3] +
			  col_[3][0]*col_[1][1]*col_[2][3] - col_[1][0]*col_[3][1]*col_[2][3] -
			  col_[2][0]*col_[1][1]*col_[3][3] + col_[1][0]*col_[2][1]*col_[3][3];
		M[2][1] = col_[3][0]*col_[2][1]*col_[0][3] - col_[2][0]*col_[3][1]*col_[0][3] -
			  col_[3][0]*col_[0][1]*col_[2][3] + col_[0][0]*col_[3][1]*col_[2][3] +
			  col_[2][0]*col_[0][1]*col_[3][3] - col_[0][0]*col_[2][1]*col_[3][3];
		M[2][2] = col_[1][0]*col_[3][1]*col_[0][3] - col_[3][0]*col_[1][1]*col_[0][3] +
			  col_[3][0]*col_[0][1]*col_[1][3] - col_[0][0]*col_[3][1]*col_[1][3] -
			  col_[1][0]*col_[0][1]*col_[3][3] + col_[0][0]*col_[1][1]*col_[3][3];
		M[2][3] = col_[2][0]*col_[1][1]*col_[0][3] - col_[1][0]*col_[2][1]*col_[0][3] -
			  col_[2][0]*col_[0][1]*col_[1][3] + col_[0][0]*col_[2][1]*col_[1][3] +
			  col_[1][0]*col_[0][1]*col_[2][3] - col_[0][0]*col_[1][1]*col_[2][3];
		M[3][0] = col_[3][0]*col_[2][1]*col_[1][2] - col_[2][0]*col_[3][1]*col_[1][2] -
			  col_[3][0]*col_[1][1]*col_[2][2] + col_[1][0]*col_[3][1]*col_[2][2] +
			  col_[2][0]*col_[1][1]*col_[3][2] - col_[1][0]*col_[2][1]*col_[3][2];
		M[3][1] = col_[2][0]*col_[3][1]*col_[0][2] - col_[3][0]*col_[2][1]*col_[0][2] +
			  col_[3][0]*col_[0][1]*col_[2][2] - col_[0][0]*col_[3][1]*col_[2][2] -
			  col_[2][0]*col_[0][1]*col_[3][2] + col_[0][0]*col_[2][1]*col_[3][2];
		M[3][2] = col_[3][0]*col_[1][1]*col_[0][2] - col_[1][0]*col_[3][1]*col_[0][2] -
			  col_[3][0]*col_[0][1]*col_[1][2] + col_[0][0]*col_[3][1]*col_[1][2] +
			  col_[1][0]*col_[0][1]*col_[3][2] - col_[0][0]*col_[1][1]*col_[3][2];
		M[3][3] = col_[1][0]*col_[2][1]*col_[0][2] - col_[2][0]*col_[1][1]*col_[0][2] +
			  col_[2][0]*col_[0][1]*col_[1][2] - col_[0][0]*col_[2][1]*col_[1][2] -
			  col_[1][0]*col_[0][1]*col_[2][2] + col_[0][0]*col_[1][1]*col_[2][2];

		M /= det;
		
		return true;
	}

	T determinant() const
	{
		T const det = 
			col_[0][3]*col_[1][2]*col_[3][0]*col_[2][1] -
			col_[0][3]*col_[1][2]*col_[2][0]*col_[3][1] -
			col_[0][3]*col_[2][2]*col_[3][0]*col_[1][1] +
			col_[0][3]*col_[2][2]*col_[1][0]*col_[3][1] +
			col_[0][3]*col_[3][2]*col_[2][0]*col_[1][1] -
			col_[0][3]*col_[3][2]*col_[1][0]*col_[2][1] -
			col_[1][3]*col_[0][2]*col_[3][0]*col_[2][1] +
			col_[1][3]*col_[0][2]*col_[2][0]*col_[3][1] +
			col_[1][3]*col_[2][2]*col_[3][0]*col_[0][1] -
			col_[1][3]*col_[2][2]*col_[0][0]*col_[3][1] -
			col_[1][3]*col_[3][2]*col_[2][0]*col_[0][1] +
			col_[1][3]*col_[3][2]*col_[0][0]*col_[2][1] +
			col_[2][3]*col_[0][2]*col_[3][0]*col_[1][1] -
			col_[2][3]*col_[0][2]*col_[1][0]*col_[3][1] -
			col_[2][3]*col_[1][2]*col_[3][0]*col_[0][1] +
			col_[2][3]*col_[1][2]*col_[0][0]*col_[3][1] +
			col_[2][3]*col_[3][2]*col_[1][0]*col_[0][1] -
			col_[2][3]*col_[3][2]*col_[0][0]*col_[1][1] -
			col_[3][3]*col_[0][2]*col_[2][0]*col_[1][1] +
			col_[3][3]*col_[0][2]*col_[1][0]*col_[2][1] +
			col_[3][3]*col_[1][2]*col_[2][0]*col_[0][1] -
			col_[3][3]*col_[1][2]*col_[0][0]*col_[2][1] -
			col_[3][3]*col_[2][2]*col_[1][0]*col_[0][1] +
			col_[3][3]*col_[2][2]*col_[0][0]*col_[1][1];
		return det;
	}

	//! Access an element by its index
	T& operator () (size_t col, size_t row)
	{
		return col_[col][row];
	}

	//! Access an element by its index
	T const& operator () (size_t col, size_t row) const
	{
		return col_[col][row];
	}

	//! Access colums of the matrix by subscript
	Vector4d<T>& operator [] (size_t col)
	{
		return col_[col];
	}
	
	//! Access colums of the matrix by subscript
	Vector4d<T> const& operator [] (size_t col) const
	{
		return col_[col];
	}
private:
	col_type col_[4];
};

template<typename T>
Matrix4<T> operator * (Matrix4<T> const& A, Matrix4<T> const& B)
{
	return A * B;
}

//! Vector-matrix multiplication
template<typename T>
Matrix4<T> operator * (Matrix4<T> const& m, Vector3d<T> const& v)
{
	return Vector3d<T>(
		m(0,0) * v[0] + m(1,0) * v[1] + m(2,0) * v[2] + m(3,0) * 1,
		m(0,1) * v[0] + m(1,1) * v[1] + m(2,1) * v[2] + m(3,1) * 1,
		m(0,2) * v[0] + m(1,2) * v[1] + m(2,2) * v[2] + m(3,2) * 1,
		m(0,3) * v[0] + m(1,3) * v[1] + m(2,3) * v[2] + m(3,3) * 1);
}

template<typename T>
Matrix4<T> operator * (Matrix4<T> const& m, Vector4d<T> const& v)
{
	return Vector4d<T>(
		m(0,0) * v[0] + m(1,0) * v[1] + m(2,0) * v[2] + m(3,0) * v[3],
		m(0,1) * v[0] + m(1,1) * v[1] + m(2,1) * v[2] + m(3,1) * v[3],
		m(0,2) * v[0] + m(1,2) * v[1] + m(2,2) * v[2] + m(3,2) * v[3],
		m(0,3) * v[0] + m(1,3) * v[1] + m(2,3) * v[2] + m(3,3) * v[3]);
}

} // namespace hrengin

#endif //_hrengin_Matrix4_