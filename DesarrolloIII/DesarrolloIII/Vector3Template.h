#pragma once
#include <math.h>


template<class TYPE> class Vector3Template
{
public:
	TYPE x, y, z;

	// Constructors ----------------------------------------------
	Vector3Template() 
	{
		x = y = z = 0;
	};

	Vector3Template(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3Template(const Vector3Template<TYPE>& given_vector)
	{
		this->x = given_vector.x;
		this->y = given_vector.y;
		this->z = given_vector.z;
	}


	//Destructor -------------------------------------------------
	~Vector3Template() {}


	//Operators --------------------------------------------------
	Vector3Template operator - (const Vector3Template &given_vector) const
	{
		Vector3Template result_vector;

		result_vector.x = x - given_vector.x;
		result_vector.y = y - given_vector.y;
		result_vector.z = z - given_vector.z;

		return(result_vector)
	}

	Vector3Template operator + (const Vector3Template &given_vector) const
	{
		Vector3Template result_vector;

		result_vector.x = x + given_vector.x;
		result_vector.y = y + given_vector.y;
		result_vector.z = z + given_vector.z;

		return(result_vector);
	}

	const Vector3Template& operator -= (const Vector3Template &given_vector)
	{
		x -= given_vector.x;
		y -= given_vector.y;
		z -= given_vector.z;

		return(*this);
	}

	const Vector3Template& operator += (const Vector3Template &given_vector)
	{
		x += given_vector.x;
		y += given_vector.y;
		z += given_vector.z;

		return(*this);
	}

	bool operator == (const Vector3Template &given_vector) const
	{
		return(x == given_vector.x && y == given_vector.y && z == given_vector.z);
	}

	bool operator != (const Vector3Template &given_vector) const
	{
		return(x != given_vector.x || y != given_vector.y || z != given_vector.z);
	}


	//Utils ------------------------------------------------------
	Vector3Template& Create(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

		return(*this);
	}

	bool isZero()
	{
		return(x == 0 && y == 0 && z == 0);
	}

	Vector3Template& SetToZero()
	{
		x = y = z = 0;

		return(*this);
	}

	Vector3Template& Negate()
	{
		x = -x;
		y = -y;
		z = -z;

		return(*this);
	}

	TYPE DistanceTo(const Vector3Template& given_vector) const
	{
		TYPE fx = x - given_vector.x;
		TYPE fy = y - given_vector.y;
		TYPE fz = z - given_vector.z;

		return(sqrtf((fx*fx) + (fy*fy) + (fz*fz)));
	}
};