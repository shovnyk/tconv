# tconv

#author
AUTHOR = $(shell whoami)

# tconv version (get this from git?)
VERSION = 0.0.1

# compilation date
DATE = $(shell date "+%B %Y")

# installation details
FINAL_BINARY = tconv
FINAL_BIN_LOC := /usr/bin/$(FINAL_BINARY)
MANDIR := /usr/share/man/man1
FINAL_MAN_LOC := $(MANDIR)/$(FINAL_BINARY).1

# compiler
CC = /usr/bin/gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -I.

# make 
tconv: tconv.o main.o tconv.h
	$(CC) $(CFLAGS) -o $(FINAL_BINARY) main.o tconv.o 

main.o: main.c tconv.h
	$(CC) $(CFLAGS) -c -o main.o main.c

tconv.o: tconv.c
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" -c -o tconv.o tconv.c

manual: tconv.md
	sed -i "s/VERSION/$(VERSION)/; s/AUTHOR/$(AUTHOR)/; s/DATE/$(DATE)/" tconv.md 
	pandoc -s -t man -o $(FINAL_BINARY).1 tconv.md

clean:
	rm -fv *.o

purge:
	rm -fv *.o $(FINAL_BINARY) tconv.1

install: purge tconv manual
	sudo cp $(FINAL_BINARY) $(FINAL_BIN_LOC)
	sudo chmod -v 755 $(FINAL_BIN_LOC)
	sudo cp $(FINAL_BINARY).1 $(FINAL_MAN_LOC)
	sudo gzip $(FINAL_MAN_LOC)

install_no_man: purge tconv
	sudo cp $(FINAL_BINARY) $(FINAL_BIN_LOC)
	sudo chmod -v 755 $(FINAL_BIN_LOC) 

uninstall: purge 
	rm -fv $(FINAL_BIN_LOC)
	rm -fv $(FINAL_MAN_LOC).gz

# check:
# 	echo install >/dev/null
# 	echo sudo cp -t $(FINAL_BIN_LOC) $(FINAL_BINARY)  >/dev/null
# 	echo sudo chmod -v 755 $(FINAL_BIN_LOC) >/dev/null
# 	echo sudo cp -t $(FINAL_MAN_LOC) $(FINAR_BINARY).1 		 >/dev/null
# 	echo sudo gzip $(FINAL_MAN_LOC) >/dev/null
# 	echo uninstall  >/dev/null
# 	echo rm -fv $(FINAL_BIN_LOC) >/dev/null
# 	echo rm -fv $(FINAL_MAN_LOC) >/dev/null
