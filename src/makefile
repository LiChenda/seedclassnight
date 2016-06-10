CC = cc
CFLAGS = -Wall

encrypt: encrypt.o ReadBmp.o
	$(CC) $(CFLAGS) encrypt.o ReadBmp.o -o ../encrypt

decode: decode.o ReadBmp.o
	$(CC) $(CFLAGS) decode.o ReadBmp.o -o ../decode

decode.o: ../include/decode.h ../include/types.h ../include/ReadBmp.h \
	decode.c ReadBmp.c
	$(CC) $(CTAGS) -c decode.c ReadBmp.c

encrypt.o: ../include/encrypt.h ../include/types.h ../include/ReadBmp.h \
	encrypt.c ReadBmp.c
	$(CC) $(CTAGS) -c encrypt.c ReadBmp.c

all: decode encrypt

.PHONY: all

.PHONY: clean
clean:
	-rm ./decode.o ./ReadBmp.o ./encrypt.o
	-rm ../decode ../encrypt
