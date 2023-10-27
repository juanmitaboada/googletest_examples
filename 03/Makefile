CC 		= gcc

TARGET		= shatest

DIRBASE		= .
DIROBJ		= $(DIRBASE)/obj
DIRBIN		= $(DIRBASE)/bin
DIRLIB		= $(DIRBASE)/lib
DIRSRC		= $(DIRBASE)/src
DIRTESTS	= $(DIRBASE)/tests
GNULIB		= /usr/share/gnulib/lib

CC_FLAGS 	= -Wall -O2 -I/usr/local/include -I/usr/include -I$(GNULIB) -I.
LD_FLAGS  	= -L$(DIRBASE)/lib -L/usr/local/lib -L/usr/lib -L/lib -l$(TARGET)

default:
	make compile
	make lib
	make link
	make launch
	-################################### Finished ###################################

compile:
	-################################# Compiling files ##############################
	$(CC) $(CC_FLAGS) -c $(DIRSRC)/sha1.c -o $(DIROBJ)/sha1.o
	$(CC) $(CC_FLAGS) -c $(DIRSRC)/shatest.c -o $(DIROBJ)/shatest.o

lib: $(DIROBJ)/*
	-############################### Making libraries ###############################
	ar -vrs $(DIRLIB)/lib$(TARGET).a $(DIROBJ)/*

link:
	-################################### Linking ####################################
	$(CC) -static $(DIROBJ)/shatest.o  -o $(DIRBIN)/$(TARGET) $(LD_FLAGS)

launch:
	$(DIRBIN)/$(TARGET)

test:
	-################################### Testing #####################################
	-rm $(DIRTESTS)/Google_Tests_run
	cmake $(DIRTESTS)/CMakeLists.txt
	make -C $(DIRTESTS)
	./$(DIRTESTS)/Google_Tests_run

clean:
	-################################### Cleaning ####################################
	-rm -f $(DIRBIN)/$(TARGET)
	-rm -f $(DIRLIB)/lib$(TARGET).a
	-rm -f $(DIROBJ)/*
	-rm -R $(DIRTESTS)/CMakeFiles
	-rm $(DIRTESTS)/Google_Tests_run
	-rm $(DIRTESTS)/CMakeCache.txt $(DIRTESTS)/cmake_install.cmake $(DIRTESTS)/Makefile

