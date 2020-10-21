SHELL = /bin/sh

srcdir = .

.SUFFIXES:
.SUFFIXES: .hpp .cpp .o
CXX=g++ -O

LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/
INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/

CXXFLAGS=-std=c++11 -Wall -g -I $(INCLUDE)
CLASSES = XMLHandler.cpp 
HEADERS = $(CLASSES:%.cpp=%.hpp)
SOURCES = RogueLike.cpp $(CLASSES)
OBJDIR = bin
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
EXECUTABLE = RogueLike

CURSES=-lncurses
	# Have to include threads on linux
	CXXFLAGS += -pthread
	# running -f means it does not error on missing files
	RM=rm -f
	# Linux needs the zip command to do zip files, install using apt-get
	ZIP=zip

%.xml : $(EXECUTABLE)
	./$(EXECUTABLE) $@

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) $(OBJECTS) -L $(LIBS) -o $(EXECUTABLE) -lxerces-c 

VPATH = src src/Structures src/Creatures src/Items \
src/Actions/CreateActions src/Actions/ItemActions src/Magic 
$(OBJDIR)/%.o : %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Clean the project
.PHONY: clean
clean:
	$(RM) *.o 
	$(RM) $(OBJDIR)/*.o 
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(EXECUTABLE).zip

# Clean then build
.PHONY: rebuild
rebuild: clean $(EXECUTABLE)