SHELL = /bin/sh

srcdir = .

.SUFFIXES:
.SUFFIXES: .hpp .cpp .o
CXX=g++ -O

LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/
INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/

CXXFLAGS=-std=c++11 -Wall -g -I $(INCLUDE)
CLASSES = XMLHandler.cpp Displayable.cpp \
	Creature.cpp Monster.cpp Player.cpp \
	Item.cpp Scroll.cpp Armor.cpp Sword.cpp \
	Structure.cpp Room.cpp Passage.cpp Dungeon.cpp \
	#GridChar.cpp #ObjectDisplayGrid

#XMLHandler.cpp ObjectDisplayGrid.cpp GridChar.cpp KeyboardListeners.cpp \
	Displayable.cpp \
	Structures.cpp Dungeon.cpp Room.cpp Passage.cpp \
	Creature.cpp Monster.cpp Player.cpp \
	Item.cpp Scroll.cpp Armor.cpp Sword.cpp \

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
	ZIP=zip -r

%.xml : $(EXECUTABLE)
	./$(EXECUTABLE) $@

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -L $(LIBS) -o $(EXECUTABLE) $(OBJECTS) -lxerces-c 
	#$(CXX) -g $(CXXFLAGS) -L $(LIBS) -o $(EXECUTABLE) $(OBJECTS) $(CURSES) -lxerces-c 

VPATH = src src/Structures src/Creatures src/Items src/Magic src/Actions src/Actions/CreateActions src/Actions/ItemActions

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
