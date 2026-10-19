CXX ?= g++
SRC ?= main.cpp
OUT ?= main

.PHONY: all clean us run

all: us run

us: $(SRC)
	@$(CXX) -o $(OUT) $(SRC)

run: us
	@./$(OUT)

clean:
	@rm -f $(OUT)