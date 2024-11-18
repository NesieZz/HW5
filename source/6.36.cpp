#include <stdio.h>
#include <string.h>

void stringReverse(char* str) {
	if (*str == '\0') {
		return;
	}
	stringReverse(str + 1);
	putchar(*str);
}

int HW_5_10() {
	char str[100]; // ���]�̤j�r����׬� 99 �Ӧr��

	printf("�п�J�@�Ӧr��G");
	if (fgets(str, sizeof(str), stdin) != NULL) {
		// �h������šA�p�G������
		size_t len = strlen(str);
		if (len > 0 && str[len - 1] == '\n') {
			str[len - 1] = '\0';
		}

		stringReverse(str);
		putchar('\n'); // ���L�����
	}

	return 0;
}
