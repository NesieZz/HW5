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
	char str[100]; // 安砞程﹃ 99 才

	printf("叫块﹃");
	if (fgets(str, sizeof(str), stdin) != NULL) {
		// 奔传︽才狦Τ杠
		size_t len = strlen(str);
		if (len > 0 && str[len - 1] == '\n') {
			str[len - 1] = '\0';
		}

		stringReverse(str);
		putchar('\n'); // ゴ传︽才
	}

	return 0;
}
