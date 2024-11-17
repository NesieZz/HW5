#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 11

void bubbleSort2(int arr[], int size);//6.33
int binarySearch(int arr[], int low, int high, int key);//6.33

int HW_5_9()
{
	int results[SIZE];  // 用來儲存每種點數出現的次數，索引0對應點數2
	int dice1, dice2, sum;
	int rolls = 36000;  // 模擬投擲次數
	int i, key, index;

	// 初始化results陣列
	for (i = 0; i < SIZE; i++) {
		results[i] = 0;
	}

	srand(time(0));  // 設定隨機數生成器的種子

	// 模擬投擲骰子
	for (i = 0; i < rolls; i++) {
		dice1 = rand() % 6 + 1;  // 投擲第一顆骰子，點數範圍 1-6
		dice2 = rand() % 6 + 1;  // 投擲第二顆骰子，點數範圍 1-6
		sum = dice1 + dice2;     // 計算兩顆骰子的點數總和
		results[sum - 2]++;      // 累加該點數的出現次數，索引從0開始
	}

	// 對results陣列進行排序
	bubbleSort2(results, SIZE);

	// 印出排序後的結果
	printf("排序後的出現次數：\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", results[i]);
	}
	printf("\n");

	// 進行二分搜尋
	printf("請輸入要搜尋的出現次數：");
	scanf_s("%d", &key);

	index = binarySearch(results, 0, SIZE - 1, key);

	if (index != -1) {
		printf("出現次數 %d 發現在索引 %d。\n", key, index);
	}
	else {
		printf("出現次數 %d 未在陣列中找到。\n", key);
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
		return -1; // 未找到
	}
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid; // 找到，返回索引
		}
		else if (arr[mid] > key) {
			return binarySearch(arr, low, mid - 1, key);
		}
		else {
			return binarySearch(arr, mid + 1, high, key);
		}
	}
}