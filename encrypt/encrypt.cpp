#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define X 13

void encrypt(char *str) {
	int i;
	int len;
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + X) % 26 + 'a';
		return;
	}
}


int main()
{
	char str[256];
	std::cout << "数値データ入力" << std::endl;
	std::cin >> str;

	while (NULL != fgets(str, sizeof(str), stdin)) {
		encrypt(str);
		printf("%s", str);
	}

	std::cout << "データ" << str << std::endl;
	std::cin >> str;

    return 0;
}

