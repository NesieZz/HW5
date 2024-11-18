#include <stdio.h>
#include <stdlib.h> // �Ω� malloc �M free ���

int recursiveMaximum(int arr[], int size) {
	// �򥻱��p�G�p�G�}�C�u���@�Ӥ����A��^�Ӥ���
	if (size == 1) {
		return arr[0];
	}

	// ���j�d��}�C�ѤU�������̤j��
	int maxInRest = recursiveMaximum(arr, size - 1);

	// ����}�C�̫�@�Ӥ����M��l�������̤j��
	if (arr[size - 1] > maxInRest) {
		return arr[size - 1];
	}
	else {
		return maxInRest;
	}
}

int HW_5_11() {
	int size;

	// ���ܨϥΪ̿�J�}�C���j�p
	printf("Enter the number of elements in the array: ");
	scanf_s("%d", &size);

	// �ϥ� malloc �ʺA�t�m�}�C
	int* arr = (int*)malloc(size * sizeof(int)); // �t�m�}�C���O����

	if (arr == NULL) {
		// �p�G�O������t���ѡA��ܿ��~�T���ðh�X�{��
		printf("Memory allocation failed.\n");
		return 1;
	}

	// ���ܨϥΪ̿�J�}�C������
	printf("��J�}�C�����ƥ�:\n", size);
	for (int i = 0; i < size; i++) {
		printf("���� %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// �I�s���j�禡��X�̤j�Ȩ���ܵ��G
	int max = recursiveMaximum(arr, size);
	printf("�}�C���̤j�������O: %d\n", max);

	// ����ʺA���t���O����
	free(arr);

	return 0;
}
