#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 11

void bubbleSort2(int arr[], int size);//6.33
int binarySearch(int arr[], int low, int high, int key);//6.33

int HW_5_9()
{
	int results[SIZE];  // �Ψ��x�s�C���I�ƥX�{�����ơA����0�����I��2
	int dice1, dice2, sum;
	int rolls = 36000;  // �������Y����
	int i, key, index;

	// ��l��results�}�C
	for (i = 0; i < SIZE; i++) {
		results[i] = 0;
	}

	srand(time(0));  // �]�w�H���ƥͦ������ؤl

	// �������Y��l
	for (i = 0; i < rolls; i++) {
		dice1 = rand() % 6 + 1;  // ���Y�Ĥ@����l�A�I�ƽd�� 1-6
		dice2 = rand() % 6 + 1;  // ���Y�ĤG����l�A�I�ƽd�� 1-6
		sum = dice1 + dice2;     // �p�������l���I���`�M
		results[sum - 2]++;      // �֥[���I�ƪ��X�{���ơA���ޱq0�}�l
	}

	// ��results�}�C�i��Ƨ�
	bubbleSort2(results, SIZE);

	// �L�X�Ƨǫ᪺���G
	printf("�Ƨǫ᪺�X�{���ơG\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", results[i]);
	}
	printf("\n");

	// �i��G���j�M
	printf("�п�J�n�j�M���X�{���ơG");
	scanf_s("%d", &key);

	index = binarySearch(results, 0, SIZE - 1, key);

	if (index != -1) {
		printf("�X�{���� %d �o�{�b���� %d�C\n", key, index);
	}
	else {
		printf("�X�{���� %d ���b�}�C�����C\n", key);
	}

	return 0;
}

void bubbleSort2(int arr[], int size) //P6.33
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int binarySearch(int arr[], int low, int high, int key) //P6.33
{
	if (low > high) {
		return -1; // �����
	}
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid; // ���A��^����
		}
		else if (arr[mid] > key) {
			return binarySearch(arr, low, mid - 1, key);
		}
		else {
			return binarySearch(arr, mid + 1, high, key);
		}
	}
}