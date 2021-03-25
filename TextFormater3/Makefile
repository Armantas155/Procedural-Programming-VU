all: 3prog run

3prog: 3prog.c
	gcc -o 3prog 3prog.c

run: 3prog
	./3prog duom.txt rez.txt

.PHONY: all 3prog run