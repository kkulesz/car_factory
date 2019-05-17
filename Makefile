CPPFLAGS := -Wall -g -Iinclude -Isrc

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

.DEFAULT_GOAL :=  $(BIN)/main

$(BIN)/main: $(BUILD) $(BIN) $(BUILD)/main.o 
	g++ $(BUILD)/main.o -o $(BIN)/main

$(BUILD):
	$(MKDIR_P) $(BUILD)

$(BIN):
	$(MKDIR_P) $(BIN)

$(BUILD)/main.o: $(SRC)/main.cpp
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o

#parts
$(BUILD)/part.o: $(SRC)/part.cpp $(INCLUDE)/part.h
	g++ $(CPPFLAGS) -c $(SRC)/part.cpp -o $(BUILD)/part.o

$(BUILD)/tire.o: $(BUILD)/part.o $(SRC)/tire.cpp $(INCLUDE)/tire.h
	g++ $(CPPFLAGS) -c $(SRC)/tire.cpp -o $(BUILD)/tire.o

$(BUILD)/engine.o: $(BUILD)/part.o $(SRC)/engine.cpp $(INCLUDE)/engine.h
	g++ $(CPPFLAGS) -c $(SRC)/engine.cpp -o $(BUILD)/engine.o

$(BUILD)/battery.o: $(BUILD)/part.o $(SRC)/battery.cpp $(INCLUDE)/battery.h
	g++ $(CPPFLAGS) -c $(SRC)/battery.cpp -o $(BUILD)/battery.o

#factories


#####CLEAN#####
clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/main
	rm -f $(BIN)/test
