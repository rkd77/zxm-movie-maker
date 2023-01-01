#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char header[256] = {0};
	FILE *fi, *fo;
	char name[100] = {0};
	char *frame;
	int fr = 1;

	int bw = (argc == 3) && (!strcmp(argv[1], "-bw"));

	memcpy (header,"ZXM",3);

	if (!bw) {
		header[18] = 14;
	} else {
		header[18] = 12;
	}
	frame = malloc(6912);
	fo = fopen(bw ? argv[2] : argv[1], "wb");
	fwrite (header, 1, 256, fo);
	memset (header, 0, 256);

	while(1) {
		sprintf (name, "out%09d.scr", fr++);
		fi = fopen (name, "rb");
		if (!fi)
			break;
		if (!bw) {
			fread (frame, 1, 6912, fi);
			fwrite (header, 1, 256, fo);
			fwrite (frame, 1, 6912, fo);
		} else {
			fread (frame, 1, 6144, fi);
			fwrite (frame, 1, 6144, fo);
		}
		fprintf(stderr, "\r%s ", name);
		fclose(fi);
	}
	fclose (fo);
	free(frame);

	return 0;
}
