PROJECT = roguelike
BUILD   = g++
MAKEDIR = rsync -rup --delete assets/*
REMOVE  = rm -rf
OUT_DIR = bin
OUTPUT  = ./$(OUT_DIR)/$(PROJECT)

DBGFLAGS = -g
CFLAGS  = -flto -I./include -std=c++14
LDFLAGS = -flto -L. -l:lib/pdcurses.a

EXCLUDE = catch.cpp
TARGETS = main.cpp tests.cpp
ALLSRCS = $(wildcard *.cpp)
SOURCES = $(filter-out $(TARGETS) $(EXCLUDE),$(ALLSRCS))
OBJECTS = $(SOURCES:.cpp=.o)

.SECONDEXPANSION:
.PHONY: all cov test debug build list clean $(OUT_DIR)

all: build clean

list:
	@echo -e "Targets: $(TARGETS)\nSources: $(SOURCES)\nObjects: $(OBJECTS)"

cov: CFLAGS = -fprofile-arcs -ftest-coverage
cov: LDFLAGS += -fprofile-arcs -ftest-coverage
cov: test
	@$(OUTPUT)
	@gcov main.cpp | head

# test: CFLAGS += $(DBGFLAGS)
test: SOURCES += catch.cpp
test: $(OUT_DIR) catch.o tests

debug: CFLAGS += $(DBGFLAGS)
debug: build

build: $(OUT_DIR) main


$(OUT_DIR):
	$(MAKEDIR) $(OUT_DIR)

$(TARGETS:.cpp=): $(OBJECTS) $$(@).o
	$(BUILD) -o $(OUTPUT) $(OBJECTS) $(@).o $(LDFLAGS)
# $(BUILD) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(BUILD) -o $@ -c $< $(CFLAGS)

clean:
	$(REMOVE) *.o *.gc*
