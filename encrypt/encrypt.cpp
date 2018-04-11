#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define key 412
#define SIZE 1024
#define n 2018

void encrypt(char* file) {
	char str[SIZE];
	int sft;
	FILE *rf;
	FILE *wf;
	errno_t error;
	if (fopen_s(&rf, file, "rb") != 0) {
		std::cout << "ファイルが見つかりません" << std::endl;
		exit(0);
	} else {
		error = fopen_s(&wf, "encrypted.jpg", "wb");
		while (1) {
			int l = fread(str, 1, SIZE, rf);
			if (l < 1) break;
			for (int i = 0; i < l; i++) {
				for (int j = 0; j <= n; j++) str[i] = (str[i] ^ key) + n;
				putc(str[i], wf);
			}
		}
	}

	fclose(rf);
	fclose(wf);
}

void decrypt() {
	char str[SIZE];
	int sft;
	FILE *rf;
	FILE *wf;
	errno_t error;
	if (fopen_s(&rf, "encrypted.jpg", "rb") != 0) {
		std::cout << "ファイルが見つかりません" << std::endl;
		exit(0);
	} else {
		error = fopen_s(&wf, "decrypted.jpg", "wb");
		while (1) {
			int l = fread(str, 1, SIZE, rf);
			if (l < 1) break;
			for (int i = 0; i < l; i++) {
				for (int j = 0; j <= n; j++) str[i] = (str[i] - n) ^ key;
				putc(str[i], wf);
			}
		}
	}

	fclose(rf);
	fclose(wf);
}

int main(int argc, char* argv[])
{
	encrypt(argv[1]);
	decrypt();
    return 0;
}