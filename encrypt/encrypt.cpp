#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define key 123
#define SIZE 16


int main(int argc, char* argv[])
{
	int i;
	char str[SIZE];
	FILE *fp;
	FILE *file;
	errno_t error;
	if (fopen_s(&fp, argv[1], "rb") != 0) {
		std::cout << "ƒtƒ@ƒCƒ‹‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ" << std::endl;
		exit(0);
	} else {
		error = fopen_s(&file, "encrypted.jpg", "wb");	
		while (1) {
			int n = fread(str, 1, SIZE, fp);
			if (n < 1) break;
			for (i = 0; i < n; i++) {
				putc(str[i] ^ key, file);
			}
		}
	}

	fclose(fp);
	fclose(file);
    return 0;
}

