#include <stdlib.h>
#include <stdio.h>
#include "Vector3Template.h"
//#include "Vector3.h"


int main(int argc, char* args[])
{
	Vector3Template<int> new_vector;

	new_vector.Create(2, 4, 7);
	printf("New_vector (%i, %i, %i)\n\n\n", new_vector.x, new_vector.y, new_vector.z);
	new_vector.Set(5, 1, NULL);
	printf("New_vector (%i, %i, %i)\n\n\n", new_vector.x, new_vector.y, new_vector.z);
	system("pause");
	return(0);
}