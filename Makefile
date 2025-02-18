CC = g++
CFLAGS = 
SRC = main.cpp system.cpp disk.cpp
EXEC = output

ARGS ?= 20 0.05 0.5 20 0
INT ?= 10

Win: Wclean
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)
	.\$(EXEC) $(ARGS)
	py view.py

Unix: Uclean
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)
	./$(EXEC) $(ARGS)
	python3 view.py

Wclean: #For windows systems
	del confs\conf*
	del $(EXEC).exe

Uclean: #For unix systems
	rm -f confs/conf*
	rm -f $(EXEC)