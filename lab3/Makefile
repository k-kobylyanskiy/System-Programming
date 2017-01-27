COMP=gcc
TARGET=wc
CFLAGS=-ansi -pedantic -Wall -Werror
CK=-c
LDK=-o
SRC=src
MAIN=$(SRC)/wc.c
OFILES=wc.o
BUILDDIR=build

all: wc clean

wc:$(OFILES)
	$(COMP) $(LDK) $(BUILDDIR)/$(TARGET) $(CFLAGS) $(OFILES)

wc.o:
	$(COMP) $(CK) $(MAIN)

clean: 
	rm -f $(TARGET) $(OFILES)
