DESTDIR	=	/usr
PREFIX	=	/local
CC	=	gcc
SRC	=	mpl115a2.c
LIBS	=	-lwiringPi -lm

all:		mpl115a2
mpl115a2:	$(SRC)
		@echo [make mpl115a2]
		@$(CC) -o mpl115a2 $(SRC) $(LIBS)
clean:
	@echo "[Clean]"
	@rm -f *~ core *.bak

install:
	@echo "[Install]"
	@cp mpl115a2		$(DESTDIR)$(PREFIX)/bin
