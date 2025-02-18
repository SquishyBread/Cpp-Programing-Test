CC = g++
CFLAGS = 
SRC = main.cpp system.cpp disk.cpp
EXEC = output

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)
	./$(EXEC) 20 0.6 0.5 20
	python3 view.py

Wclean: #For windows systems
	del confs\conf*
	del $(EXEC).exe

Uclean: #For unix systems
	rm -f confs/conf*
	rm -f $(EXEC)