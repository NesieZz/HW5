#include <stdio.h>
#include <stdlib.h>

int HW_5_6(void)
{
	int b[] = { 10,20,30,40 };
	int* bPtr = b;
	int i;
	int offset;

	printf("Array b printed with:\nArray subscript notation\n");
	for (i = 0;i < 4;i++)
	{
		printf("b[%d]=%d\n", i, b[i]);
	}
	printf("\nPointer/offset notation where\n""the pointer is the array name\n");

	for (offset = 0;offset < 4;offset++)
	{
		printf("*(b+%d)=%d\n", offset, *(b + offset));
	}
	printf("\nPointer subscript notation\n");
	for (i = 0;i < 4;i++)
	{
		printf("bPtr[%d]=%d\n", i, bPtr[i]);
	}
	printf("\nPointer/offset notation\n");
	for (offset = 0;offset < 4;offset++)
	{
		printf("*(bPtr+%d)=%d\n", offset, *(bPtr + offset));
	}
	system("pause");
	return 0;
}