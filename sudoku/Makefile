CC=g++
ARCH=-arch x86_64


# export DYLD_LIBRARY_PATH="/usr/local/Cellar/opencv/2.4.12_2/lib/" # make sure this is setup

OPENCV_DIR=/usr/local/Cellar/opencv/2.4.12_2
# OPENCV_DIR=/usr/local/Cellar/opencv/3.3.1_1

INCLUDE_FLAGS=-I$(OPENCV_DIR)/include

CFLAGS=-c -Wall $(INCLUDE_FLAGS)
LDFLAGS= -L$(OPENCV_DIR)/lib -lopencv_core -lopencv_highgui -lopencv_imgproc

SOURCES=main.cpp Util.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sudoku

all : $(SOURCES) $(EXECUTABLE)

clean :
	rm -f $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) Makefile
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
