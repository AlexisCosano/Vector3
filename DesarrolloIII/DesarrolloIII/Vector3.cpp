#include <math.h>
#include "Vector3.h"

//Constructors ---------------------------------------------
Vector3::Vector3() 
{
	x, y, z = 0;
};

Vector3::Vector3(const Vector3& given_vector) 
{
	this->x = given_vector.x;
	this->y = given_vector.y;
	this->z = given_vector.z;
};

Vector3::Vector3(const int& x, const int& y, const int& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
};


//Destructor -----------------------------------------------
Vector3::~Vector3() {};


//Operators ------------------------------------------------
Vector3 Vector3::operator - (const Vector3 &given_vector) 
{
	Vector3 result_vector;

	result_vector.x = x - given_vector.x;
	result_vector.y = y - given_vector.y;
	result_vector.z = z - given_vector.z;

	return(result_vector);
};

Vector3 Vector3::operator + (const Vector3 &given_vector) 
{
	Vector3 result_vector;

	result_vector.x = x + given_vector.x;
	result_vector.y = y + given_vector.y;
	result_vector.z = z + given_vector.z;

	return(result_vector);
};

const Vector3& Vector3::operator -= (const Vector3 &given_vector) 
{
	x -= given_vector.x;
	y -= given_vector.y;
	z -= given_vector.z;

	return(*this);
};

const Vector3& Vector3::operator += (const Vector3 &given_vector) 
{
	x += given_vector.x;
	y += given_vector.y;
	z += given_vector.z;

	return(*this);
};

bool Vector3::operator == (const Vector3 &given_vector) 
{
	return(x == given_vector.x && y == given_vector.y && z == given_vector.z);
};

bool Vector3::operator != (const Vector3 &given_vector) 
{
	return(x != given_vector.x || y != given_vector.y || z != given_vector.z);
};


//Utility --------------------------------------------------
Vector3 Vector3::Create(const int& x, const int& y, const int& z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return(*this);
};

Vector3& Vector3::Negate() 
{
	x = -x;
	y = -y;
	z = -z;

	return(*this);
};

bool Vector3::IsZero() 
{
	return(x == 0 && y == 0 && z == 0);
};

Vector3& Vector3::SetToZero() 
{
	x = y = z = 0;

	return(*this);
};