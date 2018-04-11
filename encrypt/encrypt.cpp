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

	if (fopen_s(&rf, read, "rb") != 0 || write == NULL) {
		std::cout << "ƒtƒ@ƒCƒ‹‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ" << std::endl;
		exit(0);
	} else {
		error = fopen_s(&wf, write, "wb");
		while (1) {
			int l = fread(str, 1, SIZE, rf);
			if (l < 1) break;
			for (int i = 0; i < l; i++) {
				for (int j = 0; j <= n; j++) str[i] = (str[i] ^ key) + n;
				//putc(str[i], wf);
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
    return 0;
}