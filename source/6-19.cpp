#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int HW_5_8() {
    int results[13] = { 0 };  // �Ψ��x�s�C���I�ƥX�{�����ơA���� 0 �M 1 ���ϥ�
    int dice1, dice2, sum;
    int rolls = 36000;  // �������Y����

    srand(time(0));  // �]�w�H���ƥͦ������ؤl

    // �������Y��l
    for (int i = 0; i < rolls; i++) {
        dice1 = rand() % 6 + 1;  // ���Y�Ĥ@����l�A�I�ƽd�� 1-6
        dice2 = rand() % 6 + 1;  // ���Y�ĤG����l�A�I�ƽd�� 1-6
        sum = dice1 + dice2;     // �p�������l���I���`�M
        results[sum]++;          // �֥[���I�ƪ��X�{����
    }

    // �L�X���G
    printf("�I��\t�X�{����\t���v\n");
    for (int i = 2; i <= 12; i++) {
        printf("%d\t%d\t\t%.2f%%\n", i, results[i], (results[i] / (float)rolls) * 100);
    }

    return 0;
}
