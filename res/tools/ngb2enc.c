
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "compress.h"

#define OUT_BUF_SIZE 65535

int fsize(FILE *f)
{
	int temp;
	fseek(f, 0, SEEK_END);
	temp = ftell(f);
	fseek(f, 0, SEEK_SET);
	return temp;
}

int main(int argc, const char *argv[])
{
	FILE *i_file, *o_file;
	int i_filesize, o_filesize;
	void *inptr;
	void *outptr;

	if (argc == 3)
	{
		if (!(i_file = fopen(argv[1], "rb")))
		{
			printf(" Error loading file: %s\n", argv[1]);
			return 1;
		}
		i_filesize = fsize(i_file);
		inptr = malloc(i_filesize);
		fread(inptr, 1, i_filesize, i_file);

		outptr = malloc(OUT_BUF_SIZE);

		o_filesize = pack(inptr, i_filesize, outptr, 0);
		o_file = fopen(argv[2], "wb");
		fwrite(outptr, 1, o_filesize, o_file);

		fclose(o_file);
		free(outptr);

		fclose(i_file);
		free(inptr);

	}
	else printf("encode: <file.exe> <input.file> <output.file>");
	return 0;
}
