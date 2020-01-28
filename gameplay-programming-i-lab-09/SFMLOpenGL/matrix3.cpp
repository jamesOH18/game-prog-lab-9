#include "matrix.h"
#include <string.h>
#define PI		3.14159265358979323846

using namespace gpp;

MyMatrix3::MyMatrix3()
{

}

MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33)
{
	m11 = t_a11;
	m12 = t_a12;
	m13 = t_a13;
	m21 = t_a21;
	m22 = t_a22;
	m23 = t_a23;
	m31 = t_a31;
	m32 = t_a32;
	m33 = t_a33;
}

MyMatrix3::MyMatrix3(const MyVector3 t_row1, const MyVector3 t_row2, const MyVector3 t_row3)
//setsup all rows
{
	m11 = t_row1.x;
	m12 = t_row1.y;
	m13 = t_row1.z;
	m21 = t_row2.x;
	m22 = t_row2.y;
	m23 = t_row2.z;
	m31 = t_row3.x;
	m32 = t_row3.y;
	m33 = t_row3.z;
}

MyMatrix3::~MyMatrix3()
{
}


std::string MyMatrix3::toString()const
//sets up the string for yout test answers
{
	std::string mString = " { " + std::to_string(m11) + " , " + std::to_string(m12) + " , " + std::to_string(m13) + " }\n"
		" { " + std::to_string(m21) + " , " + std::to_string(m22) + " , " + std::to_string(m23) + " }\n"
		" { " + std::to_string(m31) + " , " + std::to_string(m32) + " , " + std::to_string(m33) + " }\n";

	return mString;
}

bool MyMatrix3::operator ==(const MyMatrix3 other)const
//checks if two matrix are equal
{
	if (m11 == other.m11 && m12 == other.m12 && m13 == other.m13 && m21 == other.m21 && m22 == other.m22 && m23 == other.m23 && m31 == other.m31 && m32 == other.m32 && m33 == other.m33)
	{
		return true;
	}
	else
		return false;
}

bool MyMatrix3::operator !=(const MyMatrix3 other)const
//checks if two matrix are not equal
{
	if (m11 != other.m11 && m12 != other.m12 && m13 != other.m13 && m21 != other.m21 && m22 != other.m22 && m23 != other.m23 && m31 != other.m31 && m32 != other.m32 && m33 != other.m33)
	{
		return true;
	}
	else
		return false;

}

MyMatrix3 MyMatrix3::operator +(const MyMatrix3 t_other) const
//this adds two matrix
{
	return MyMatrix3(m11 + t_other.m11, m12 + t_other.m12, m13 + t_other.m13,
		m21 + t_other.m21, m22 + t_other.m22, m23 + t_other.m23,
		m31 + t_other.m31, m32 + t_other.m32, m33 + t_other.m33);
}

MyMatrix3 MyMatrix3::operator -(const MyMatrix3 t_other) const
//this subtarcts two matrix
{
	return MyMatrix3(m11 - t_other.m11, m12 - t_other.m12, m13 - t_other.m13,
		m21 - t_other.m21, m22 - t_other.m22, m23 - t_other.m23,
		m31 - t_other.m31, m32 - t_other.m32, m33 - t_other.m33);
}

MyMatrix3 MyMatrix3::operator *(const MyMatrix3 t_other) const
// this multiplies two matrix
{
	return MyMatrix3(m11 * t_other.m11 + m12 * t_other.m21 + m13 * t_other.m31, m11 * t_other.m12 + m12 * t_other.m22 + m13 * t_other.m32, m11 * t_other.m13 + m12 * t_other.m23 + m13 * t_other.m33,
		m21 * t_other.m11 + m22 * t_other.m21 + m23 * t_other.m31, m21 * t_other.m12 + m22 * t_other.m22 + m23 * t_other.m32, m21 * t_other.m13 + m22 * t_other.m23 + m23 * t_other.m33,
		m31 * t_other.m11 + m32 * t_other.m21 + m33 * t_other.m31, m31 * t_other.m12 + m32 * t_other.m22 + m33 * t_other.m32, m31 * t_other.m13 + m32 * t_other.m23 + m33 * t_other.m33);
}
MyVector3 MyMatrix3::operator *(const MyVector3 t_vector)const
//this multiplies a matrix by a vector
{
	return MyVector3(m11 * t_vector.x + m12 * t_vector.y + m13 * t_vector.z,
		m21 * t_vector.x + m22 * t_vector.y + m23 * t_vector.z,
		m31 * t_vector.x + m32 * t_vector.y + m33 * t_vector.z);
}

MyMatrix3 MyMatrix3::operator *(const double t_scale)const
//this multiplies a matrix by a scale
{
	return MyMatrix3(t_scale * m11, t_scale * m12, t_scale * m13,
		t_scale * m21, t_scale * m22, t_scale * m23,
		t_scale * m31, t_scale * m32, t_scale * m33);
}

MyMatrix3 MyMatrix3::transpose()const
//flips the first row by the column
{
	MyMatrix3 matrixTranspose = { m11,m21,m31
								 ,m12,m22,m32
								 ,m13,m32,m33 };

	return matrixTranspose;
}
double MyMatrix3::determinant() const
//this get the determinant
{
	double determinantMatrix = m11 * (m22 * m33 - m32 * m23) - m21 * (m33 * m12 - m32 * m13) + m31 * (m23 * m12 - m22 * m13);
	return determinantMatrix;
}
MyMatrix3 MyMatrix3::inverse() const
//this gets the inverse of a matrix
{
	MyMatrix3 inverseMatrix = { m33 * m22 - m32 * m23, m32 * m13 - m33 * m12, m23 * m12 - m22 * m13,
								m31 * m23 - m33 * m21, m33 * m11 - m31 * m13, m21 * m13 - m23 * m11,
								m32 * m21 - m31 * m22, m31 * m12 - m32 * m11, m22 * m11 - m21 * m12 };
	return inverseMatrix;
}

MyVector3 MyMatrix3::row(const int t_row)const
//checks whats on each row of a matrix
{
	MyVector3 row = { 0,0,0 };

	if (t_row == 0)
	{
		row = { m11,m12,m13 };
	}
	else if (t_row == 1)
	{
		row = { m21, m22 , m23 };
	}
	else if (t_row == 2)
	{
		row = { m31 , m32 , m33 };
	}
	return row;
}

MyVector3 MyMatrix3::column(const int t_column) const
//this checks whats on each column
{
	MyVector3 col = { 0,0,0 };

	if (t_column == 0)
	{
		col = { m11,m21,m31 };
	}
	else if (t_column == 1)
	{
		col = { m12, m22 , m32 };
	}
	else if (t_column == 2)
	{
		col = { m13 , m23 , m33 };
	}
	return col;
}

MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
//this rotates the x and y
{
	MyMatrix3 rotateZ = { cos(t_angleRadians), -sin(t_angleRadians), 0,sin(t_angleRadians), cos(t_angleRadians), 0,0,0,1 };


	return rotateZ;
}

MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
//this rotates the x and z
{
	MyMatrix3 rotateY = { cos(t_angleRadians), 0 , sin(t_angleRadians),0,1,0,-sin(t_angleRadians), 0,cos(t_angleRadians) };


	return rotateY;
}

MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
//this rotates the z and y
{
	MyMatrix3 rotateX = { 1,0,0, 0 , cos(t_angleRadians),  -sin(t_angleRadians),0 ,sin(t_angleRadians), cos(t_angleRadians) };

	return rotateX;
}

MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
//this translates a vector
{
	MyMatrix3 translationMatrix = { 1 , 0 ,t_displacement.x,
								   0 , 1 ,t_displacement.y,
								   0 , 0 , 1 };

	return translationMatrix;
}

MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
// this scales a matrix by a certain vaule
{
	MyMatrix3 scaleMatrix = { t_scalingfactor , 0 , 0,
							  0 , t_scalingfactor, 0,
							  0 , 0 , t_scalingfactor };

	return scaleMatrix;
}