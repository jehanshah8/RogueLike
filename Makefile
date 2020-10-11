# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = src/main.o src/XMLHanlder.o src/Dungeon.o src/ObjectDisplayGrid.o \
   src/Displayable.o src/Structure.o src/Creature.o src/Item.o src/Magic.o \
   src/Room.o src/Passage.o \
   src/Player.o src/Monster.o \
   src/Scroll.o src/Armor.o src/Sword.o 
   

CXX = g++ -std=c++11 
INCLUDE = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/include/
LIBS = /home/jehanshah8/xerces-c-3.1.1-x86_64-linux-gcc-3.4/lib/ 
CXXFLAGS = -Wall -g
EXECUTABLE = RogueLike
COMMANDLINE =

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean RogueLike

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) -I $(INCLUDE) -L $(LIBS)

%.o : %.c 
	$(CXX) $(CXXFLAGS) -c $@ $(INCLUDE) $(LIBS)

OUT=main
%.xml: $(OUT)
 ./$(OUT) xmlfiles/$@

clean :
	rm $(EXECUTABLE) ${OBJS} 
