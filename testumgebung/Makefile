CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -c  
OBJECTS = main.o DS18B20.o
PROJECTNAME = tempsens
HEADERFILES = DS18B20.h bool.h

all: compile clean

compile: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECTNAME)

main.o: main.c $(HEADERFILES)
	$(CC) $(CFLAGS) main.c

DS18B20.o: DS18B20.c DS18B20.h bool.h
	$(CC) $(CFLAGS) DS18B20.c

clean:
	rm -rf *.o