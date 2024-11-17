#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int HW_5_8() {
    int results[13] = { 0 };  // 用來儲存每種點數出現的次數，索引 0 和 1 不使用
    int dice1, dice2, sum;
    int rolls = 36000;  // 模擬投擲次數

    srand(time(0));  // 設定隨機數生成器的種子

    // 模擬投擲骰子
    for (int i = 0; i < rolls; i++) {
        dice1 = rand() % 6 + 1;  // 投擲第一顆骰子，點數範圍 1-6
        dice2 = rand() % 6 + 1;  // 投擲第二顆骰子，點數範圍 1-6
        sum = dice1 + dice2;     // 計算兩顆骰子的點數總和
        results[sum]++;          // 累加該點數的出現次數
    }

    // 印出結果
    printf("點數\t出現次數\t機率\n");
    for (int i = 2; i <= 12; i++) {
        printf("%d\t%d\t\t%.2f%%\n", i, results[i], (results[i] / (float)rolls) * 100);
    }

    return 0;
}
