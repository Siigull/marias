EXE = app

CC = g++
LD = g++

ifeq ($(DEBUG), 1)
    CFLAGS = -g -DDEBUG
else
    CFLAGS = -g
endif
DEPFLAGS = -MMD -MP
LDFLAGS = 
LDLIBS = 

BIN = bin
OBJ = obj
SRC = src

SOURCES := $(wildcard $(SRC)/*.cpp)

OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(wildcard $(SRC)/*.cpp))

DEPENDS := $(OBJECTS:.o=.d)

COMPILE.cpp = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@

LINK.o = $(LD) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

.DEFAULT_GOAL = all

.PHONY: all
all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC) $(OBJ) $(BIN) $(OBJECTS)
	$(LINK.o)	

$(SRC):
	mkdir -p $(SRC)

$(OBJ):
	mkdir -p $(OBJ)

$(BIN):
	mkdir -p $(BIN)

$(OBJ)/%.o:$(SRC)/%.cpp
	$(COMPILE.cpp) $<

.PHONY: run
run: $(BIN)/$(EXE)
	./$(BIN)/$(EXE)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
	$(RM) $(BIN)/$(EXE)

.PHONY: reset
reset:
	$(RM) -r $(OBJ)
	$(RM) -r $(BIN)

-include $(DEPENDS)
