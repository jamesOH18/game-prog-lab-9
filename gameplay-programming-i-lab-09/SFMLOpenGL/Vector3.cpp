/// James o hara
/// </summary>
#include "Vector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
using namespace gpp;

	MyVector3::MyVector3() :
		x{ 0.0 },
		y{ 0.0 },
		z{ 0.0 }
	{
	}

	/// <summary>
	/// default destructor
	/// nothing to release because we only have
	/// primitive type data
	/// </summary>
	MyVector3::~MyVector3()
	{
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
	std::string MyVector3::toString()
	{
		const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
		return output;
	}

	MyVector3::MyVector3(double t_x, double t_y, double t_z)
	{
		x = t_x;
		y = t_y;
		z = t_z;
	}

	/// <summary>
	/// create a vector 3 from an sf::vector3f
	/// </summary>
	/// <param name="t_sfVector">input vector</param>
	MyVector3::MyVector3(sf::Vector3f t_sfVector)
	{
		x = static_cast<float>(t_sfVector.x);
		y = static_cast<float>(t_sfVector.y);
		z = static_cast<float>(t_sfVector.z);
	}

	MyVector3::MyVector3(sf::Vector3i t_sfVector)
	{
		x = static_cast<int>(t_sfVector.x);
		y = static_cast<int>(t_sfVector.y);
		z = static_cast<int>(t_sfVector.z);
	}

	MyVector3::MyVector3(sf::Vector2i t_sfVector)
	{
		x = static_cast<int>(t_sfVector.x);
		y = static_cast<int>(t_sfVector.y);
		z = 0;
	}

	MyVector3::MyVector3(sf::Vector2u t_sfVector)
	{
		x = static_cast<unsigned int>(t_sfVector.x);
		y = static_cast<unsigned int>(t_sfVector.y);
		z = 0;

	}

	MyVector3::MyVector3(sf::Vector2f t_sfVector)
	{
		x = static_cast<float>(t_sfVector.x);
		y = static_cast<float>(t_sfVector.y);
		z = 0;
	}

	MyVector3 MyVector3::operator+(const MyVector3 t_right) const
	{
		return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
	}

	MyVector3 MyVector3::operator-(const MyVector3 t_right) const
	{
		return MyVector3(x - t_right.x, y - t_right.y, z - t_right.x);
	}

	MyVector3 MyVector3::operator*(const double t_scalar) const
	{
		return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
	}

	MyVector3 MyVector3::operator/(const double t_divisor) const
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
	}

	MyVector3 MyVector3::operator+=(const MyVector3 t_right)
	{
		return MyVector3(x += t_right.x, y += t_right.y, z += t_right.z);
	}

	MyVector3 MyVector3::operator-=(const MyVector3 t_right)
	{
		return MyVector3(x -= t_right.x, y -= t_right.y, z -= t_right.z);
	}

	bool MyVector3::operator==(const MyVector3 t_right) const
	{
		if (x == t_right.x && y == t_right.y && z == t_right.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool MyVector3::operator!=(const MyVector3 t_right) const
	{
		if (x == t_right.x && y == t_right.y && z == t_right.z)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	MyVector3 MyVector3::operator-()
	{
		return MyVector3(-x, -y, -z);
	}

	void MyVector3::reverseX()
	{
		x = x * -1;
	}

	void MyVector3::reverseY()
	{
		y = y * -1;
	}

	double MyVector3::length() const
	{
		double length = (x * x) + (y * y) + (z * z);
		double lengthsqrt = sqrt(length);
		return lengthsqrt;
	}

	double MyVector3::lengthSquared() const
	{
		double lengthsquared = (x * x) + (y * y) + (z * z);
		return lengthsquared;
	}

	double MyVector3::dot(const MyVector3 t_other) const
	{

		double dot = (x * t_other.x) + (y * t_other.y) + (z * t_other.z);
		return dot;
	}

	MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
	{
		float vectorX = y * t_other.z - z * t_other.y;
		float vectorY = z * t_other.x - x * t_other.z;
		float vectorZ = x * t_other.y - y * t_other.x;
		return MyVector3(vectorX, vectorY, vectorZ);
	}

	double MyVector3::angleBetween(const MyVector3 t_other) const
	{
		MyVector3 vectors{ x,y,z };
		double dotCal = vectors.dot(t_other);
		double radiansdegrees = acos(dotCal / (vectors.length() * t_other.length()));
		double radians = radiansdegrees * 180 / PI;
		return radians;
	}

	MyVector3 MyVector3::unit() const
	{
		MyVector3 unit{ x,y,z };
		unit = unit / unit.length();
		return MyVector3(unit);
	}

	void MyVector3::normalise()
	{
		MyVector3 normalise{ x, y, z };

		x = x / normalise.length();
		y = y / normalise.length();
		z = z / normalise.length();
	}

	MyVector3 MyVector3::projection(const MyVector3 t_onto) const
	{
		MyVector3 projection{ x,y,z };
		double projectioncal = projection.dot(t_onto) / (t_onto.length() * t_onto.length());
		return MyVector3(projectioncal * t_onto.x, projectioncal * t_onto.y, projectioncal * t_onto.z);
	}

	MyVector3 MyVector3::rejection(const MyVector3 t_onto) const
	{
		MyVector3 vector{ x,y,z };
		MyVector3 rejection = t_onto - vector.projection(t_onto);
		return MyVector3(rejection);
	}

	MyVector3::operator sf::Vector2u()
	{
		return sf::Vector2u{ static_cast<unsigned int>(x),static_cast<unsigned int>(y) };

		if (x < 0)
		{
			x = x * -1;
		}
		if (y < 0)
		{
			y = y * -1;
		}
	}

