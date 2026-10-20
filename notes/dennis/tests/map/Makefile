CXX ?= g++
SRC ?= main.cpp
OUT ?= main

.PHONY: all clean map run

all: map run

map: $(SRC)
	@$(CXX) -o $(OUT) $(SRC)

run: map
	@./$(OUT)

clean:
	@rm -f $(OUT)