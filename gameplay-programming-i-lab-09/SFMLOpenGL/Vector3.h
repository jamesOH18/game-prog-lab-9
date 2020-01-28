#ifndef MYVECTOR3 
#define MYVECTOR3


/// <summary>
/// james o hara
/// 

#include <iostream>
#include <SFML/Graphics.hpp>

namespace gpp
{

	class MyVector3
	{
	public:
		double x;
		double y;
		double z;

		MyVector3();
		~MyVector3();
		std::string toString();



		MyVector3(double x, double y, double z);//sets up x y z
		MyVector3(sf::Vector3f t_sfVector);//sets up vector 3f
		MyVector3(sf::Vector3i t_sfVector);//sets up vector 3i
		MyVector3(sf::Vector2i t_sfVector);//set up vector 2i
		MyVector3(sf::Vector2u t_sfVector);//sets up vector 2u
		MyVector3(sf::Vector2f t_sfVector);// sets up vector 2f


		MyVector3 operator +(const MyVector3 t_right) const;//adds two vectors together
		MyVector3 operator -(const MyVector3 t_right) const;// subtracts two vectors from eachother
		MyVector3 operator *(const double t_scalar) const;//multiplies a vector by a number
		MyVector3 operator /(const double t_divisor) const;//divides a vector by a number
		MyVector3 operator +=(const MyVector3 t_right);//adds then equals to a vector
		MyVector3 operator -=(const MyVector3 t_right);//subtracts then equals to a vector

		bool operator == (const MyVector3 t_right) const;//checks if two vectors are equal to eachother
		bool operator != (const MyVector3 t_right) const;//checks if two vectors are not equal to each other

		// negative of a vector 
		MyVector3 operator -();  // this changes the vector//makes a vector a negative
		//new methods for bouncing off sides of table in billiards
		void reverseX(); // this negates the x element of the vector
		void reverseY();  // this negates the y element of the vector

		double length()const;//sets up the length
		double lengthSquared()const;//sets up the lentgh squared
		double dot(const MyVector3 t_other) const;// sets up the dot product
		MyVector3 crossProduct(const MyVector3 t_other)const;//sets up the crossproduct
		double angleBetween(const MyVector3 t_other)const;  //finds the angle between two vectors
		MyVector3 unit() const;  // sets up the unit vector
		void normalise(); // vector changes and will have length 1 
		MyVector3 projection(const MyVector3 t_onto)const;
		// projection onto the other vector so answer will parallel to other vector.
		MyVector3 rejection(const MyVector3 t_onto)const;//sets up rejection


		operator sf::Vector2f() { return sf::Vector2f{ static_cast<float>(x),static_cast<float>(y) }; }; // {2.4,-2.6,3.0} ->  {2.4~,-2.6~}
		operator sf::Vector2i() { return sf::Vector2i{ static_cast<int>(x),static_cast<int>(y) }; };// {2.4,-2.6,3.0} ->  {2,-3}
		operator sf::Vector2u();// {2.4,-2.6,3.0} ->  {2,3}  needs more space than an inline
		operator sf::Vector3i() { return sf::Vector3i{ static_cast<int>(x),static_cast<int>(y),static_cast<int>(z) }; };// {2.4,-2.6,3.0} ->  {2,-3,3}
		operator sf::Vector3f() { return sf::Vector3f{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(z) }; };// {2.4,-2.6,3.0} ->  {2.4~,-2.6~, 3.0}

	};
}



#endif // !MYVECTOR3