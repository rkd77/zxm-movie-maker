makevideozxm: makevideozxm.c
	$(CC) $(CFLAGS) -o makevideozxm makevideozxm.c

%.scr: %.png
	scrplus -i=$< -o=$@

PNGS = $(wildcard *.png)

SRCS = $(PNGS:.png=.scr)

%.zxm: $(SRCS)
	./makevideozxm $@
