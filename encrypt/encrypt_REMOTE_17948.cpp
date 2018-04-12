#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define key 412
#define SIZE 1024
#define n 2018

void encrypt(char* read, char* write) {
	char str[SIZE];
	FILE *rf;
	FILE *wf;
	errno_t error;

	if (fopen_s(&rf, read, "rb") != 0) {
		std::cout << "ファイルが見つかりません" << std::endl;
		exit(0);
	} else {
		error = fopen_s(&wf, write, "wb");
		while (1) {
			int l = fread(str, 1, SIZE, rf);
			if (l < 1) break;
			for (int i = 0; i < l; i++) {
				for (int j = 0; j <= n; j++) str[i] = (str[i] ^ key) + n;
				fwrite(&str[i], sizeof(str[i]), 1, wf);
			}
		}
	}

	fclose(rf);
	fclose(wf);
}

//decrypt.exe分割用
void decrypt() {
	char str[SIZE];
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
				fwrite(&str[i], sizeof(str[i]), 1, wf);
			}
		}
	}

	fclose(rf);
	fclose(wf);
}

int main(int argc, char* argv[])
{
	encrypt(argv[1], argv[2]);
	//decrypt();
    return 0;
}
