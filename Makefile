DESTDIR	=	/usr
PREFIX	=	/local
CC	=	gcc
SRC	=	getMPL115A2.c
OBJ	=	getMPL115A2
LIBS	=	-lwiringPi -lm

all:		getMPL115A2
getMPL115A2:	$(SRC)
		@echo [make getMPL115A2]
		@$(CC) -o $(OBJ) $(SRC) $(LIBS)
clean:
	@echo "[Clean]"
	@rm -f *~ core *.bak

install:
	@echo "[Install]"
	@cp $(OBJ)		$(DESTDIR)$(PREFIX)/bin
