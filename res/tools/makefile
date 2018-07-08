CC=gcc

all: ngb2dec ngb2enc

ngb2dec: ngb2dec.o compress.o
	$(CC) -o ngb2dec ngb2dec.o compress.o

ngb2enc: ngb2enc.o compress.o
	$(CC) -o ngb2enc ngb2enc.o compress.o
