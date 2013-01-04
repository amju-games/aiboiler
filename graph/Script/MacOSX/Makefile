SOURCE=../../Source/
BUILD=../../../Build/graph/Mac
LIBS=-framework OpenGL -framework GLUT -lm -lstdc++
CC=gcc
CFLAGS=-I$(SOURCE)
DEPS = AStar.h
ODIR=$(BUILD)

SOURCES	:= $(SOURCE)

CPPFILES        :=      $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))


OFILES   :=      $(addsuffix .o,$(BINFILES)) \
                                        $(addsuffix .o,$(TPLFILES)) \
                                        $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) \
                                        $(MFILES:.m=.o) \
                                        $(sFILES:.s=.o) $(SFILES:.S=.o)

OBJ = $(patsubst %,$(ODIR)/%,$(OFILES))

$(ODIR)/%.o: $(SOURCE)/%.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD)/graph: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BUILD)/graph

run:
	$(BUILD)/graph

