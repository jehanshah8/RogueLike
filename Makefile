SHELL = /bin/sh

srcdir = .

.SUFFIXES:
.SUFFIXES: .hpp .cpp .o
CXX=g++ -O

LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/
INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/

CDEBUG = -g
CXXFLAGS=-std=c++11 -Wall -g -I $(INCLUDE)

OBJDIR = bin
SOURCES = RogueLike.cpp XMLHandler.cpp Magic.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
OBJDIR = bin
EXECUTABLE = RogueLike

%.xml : $(EXECUTABLE)
	./$(EXECUTABLE) $@

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) $(OBJECTS) -L $(LIBS) -o $(EXECUTABLE) -lxerces-c 

vpath %.cpp = src src/Structures src/Creatures src/Items \
src/Actions/CreateActions src/Actions/ItemActions src/Magic 
#vpath %.o = bin
$(OBJDIR)/%.o : %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) $< -o $@