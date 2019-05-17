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

#warehouse
$(BUILD)/warehouse.o: $(BUILD)/tire.o $(BUILD)/battery.o $(BUILD)/engine.o $(SRC)/warehouse.cpp $(INCLUDE)/warehouse.h 
	g++ $(CPPFLAGS) -c $(SRC)/warehouse.cpp -o $(BUILD)/warehouse.o

#factories
$(BUILD)/car_factory.o: $(BUILD)/factory.o $(SRC)/car_factory.cpp $(INCLUDE)/car_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/car_factory.cpp -o $(BUILD)/car_factory.o

$(BUILD)/tire_factory.o: $(BUILD)/factory.o $(SRC)/tire_factory.cpp $(INCLUDE)/tire_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/tire_factory.cpp -o $(BUILD)/tire_factory.o

$(BUILD)/engine_factory.o: $(BUILD)/factory.o $(SRC)/engine_factory.cpp $(INCLUDE)/engine_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/engine_factory.cpp -o $(BUILD)/engine_factory.o

$(BUILD)/battery_factory.o: $(BUILD)/factory.o $(SRC)/battery_factory.cpp $(INCLUDE)/battery_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/battery_factory.cpp -o $(BUILD)/batter_factory.o

$(BUILD)/factory.o: $(SRC)/factory.cpp $(INCLUDE)/factory.h
	g++ $(CPPFLAGS) -c $(SRC)/factory.cpp -o $(BUILD)/factory.o

#car

#parts
$(BUILD)/tire.o: $(BUILD)/part.o $(SRC)/tire.cpp $(INCLUDE)/tire.h
	g++ $(CPPFLAGS) -c $(SRC)/tire.cpp -o $(BUILD)/tire.o

$(BUILD)/engine.o: $(BUILD)/part.o $(SRC)/engine.cpp $(INCLUDE)/engine.h
	g++ $(CPPFLAGS) -c $(SRC)/engine.cpp -o $(BUILD)/engine.o

$(BUILD)/battery.o: $(BUILD)/part.o $(SRC)/battery.cpp $(INCLUDE)/battery.h
	g++ $(CPPFLAGS) -c $(SRC)/battery.cpp -o $(BUILD)/battery.o

$(BUILD)/part.o: $(SRC)/part.cpp $(INCLUDE)/part.h
	g++ $(CPPFLAGS) -c $(SRC)/part.cpp -o $(BUILD)/part.o


#factories


#####CLEAN#####
clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/main
	rm -f $(BIN)/test
