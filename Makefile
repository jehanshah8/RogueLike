EXECUTABLE = RogueLike

# List of classes, have a cpp and a h file
CLASSES = src/Magic/XMLHandler.cpp #Dungeon.cpp src/ObjectDisplayGrid.cpp src/Displayable.cpp

# List of all source files to compile
SOURCES = src/RogueLike.cpp $(CLASSES)

# List of header files to watch
HEADERS = $(CLASSES:.cpp=.hpp)

# List of object files for building
OBJECTS = RogueLike.o XMLHandler.o #$(SOURCES:.cpp=.o)

INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/

LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/

# Compiler to use
CXX=g++

# Extra compilation arguments
CXXFLAGS=-std=c++11 -Wall -g -I $(INCLUDE)

# Check if building on Windows or Linux
ifeq ($(OS),Windows_NT)
	# use PDCurses library archive when building on windows
	CURSES = lib\pdcurses.lib
	CXXFLAGS += -I./include
	# by running rm within cmd, it does not error on missing files
	RM=cmd /c del
	# Windows introduced the tar command that can make zip files
	ZIP=tar -acvf
else
	# use ncurses library when building on linux/mac
	# Linux install using "sudo apt-get install libncurses5-dev libncursesw5-dev"
	# Mac install using "brew install ncurses"
	CURSES=-lncurses
	# Have to include threads on linux
	CXXFLAGS += -pthread
	# running -f means it does not error on missing files
	RM=rm -f
	# Linux needs the zip command to do zip files, install using apt-get
	ZIP=zip
endif

# Build then run
run: $(EXECUTABLE)
	./$(EXECUTABLE)
.PHONY: run

%.xml: $(EXECUTABLE)
	./$(EXECUTABLE) $@

# Build the project, default command
$(EXECUTABLE): $(OBJECTS)
	#$(CXX) -g $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) 
	$(CXX) -g $(CXXFLAGS) -L $(LIBS) -o $(EXECUTABLE) $(OBJECTS) -lxerces-c 
	
# Compile .o files
# Cannot think of a good way to watch only the required headers for each .o file
%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@ 

# Clean the project
clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(EXECUTABLE).zip

# Clean then build
rebuild: clean $(EXECUTABLE)
.PHONY: rebuild

# Create a zip file with all relevant files to build the project
ZIPFILES=$(SOURCES) $(HEADERS) Makefile lib/* include/* pdcurses.dll \
	PDCursesExample.sln PDCursesExample.vcxproj PDCursesExample.vcxproj.filters
zip: $(ZIPFILES)
	$(ZIP) $(EXECUTABLE).zip $(ZIPFILES)
.PHONY: zip