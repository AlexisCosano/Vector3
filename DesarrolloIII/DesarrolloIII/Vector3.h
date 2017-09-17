#pragma once

class Vector3
{
public:
	int x, y, z;

	//Constructors ---------------------------------------------
	Vector3();
	Vector3(const Vector3& given_vector);
	Vector3(const int& x, const int& y, const int& z);

	//Destructor -----------------------------------------------
	~Vector3();

	//Operators ------------------------------------------------
	Vector3 operator - (const Vector3 &given_vector);
	Vector3 operator + (const Vector3 &given_vector);
	const Vector3& operator -= (const Vector3 &given_vector);
	const Vector3& operator += (const Vector3 &given_vector);
	bool operator == (const Vector3 &given_vector);
	bool operator != (const Vector3 &given_vector);

	//Utility --------------------------------------------------
	Vector3 Create(const int& x, const int& y, const int& z);
	Vector3& Negate();
	bool IsZero();
	Vector3& SetToZero();
};