#include <stdio.h>
#include <stdlib.h> // 用於 malloc 和 free 函數

int recursiveMaximum(int arr[], int size) {
	// 基本情況：如果陣列只有一個元素，返回該元素
	if (size == 1) {
		return arr[0];
	}

	// 遞迴查找陣列剩下部分的最大值
	int maxInRest = recursiveMaximum(arr, size - 1);

	// 比較陣列最後一個元素和其餘部分的最大值
	if (arr[size - 1] > maxInRest) {
		return arr[size - 1];
	}
	else {
		return maxInRest;
	}
}

int HW_5_11() {
	int size;

	// 提示使用者輸入陣列的大小
	printf("Enter the number of elements in the array: ");
	scanf_s("%d", &size);

	// 使用 malloc 動態配置陣列
	int* arr = (int*)malloc(size * sizeof(int)); // 配置陣列的記憶體

	if (arr == NULL) {
		// 如果記憶體分配失敗，顯示錯誤訊息並退出程式
		printf("Memory allocation failed.\n");
		return 1;
	}

	// 提示使用者輸入陣列的元素
	printf("輸入陣列元素數目:\n", size);
	for (int i = 0; i < size; i++) {
		printf("元素 %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// 呼叫遞迴函式找出最大值並顯示結果
	int max = recursiveMaximum(arr, size);
	printf("陣列中最大的元素是: %d\n", max);

	// 釋放動態分配的記憶體
	free(arr);

	return 0;
}
