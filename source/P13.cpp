#include <stdlib.h>
#include <stdio.h>

void cubeByReference(int &nPtr);

int HW_5_4()
{
	int number = 5;
	printf("The original value of number is %d", number);

	cubeByReference(number);

	printf("\nThe new value of number is %d\n", number);
	system("Pause");
	return 0;
}

void cubeByReference(int &nPtr)
{
	nPtr = nPtr * nPtr * nPtr;
}