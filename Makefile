CPPFLAGS := -Wall -g -Iinclude -Isrc

INCLUDE := include
SRC := src
BIN := bin
BUILD := build
MKDIR_P := mkdir -p
TEST:= test

.DEFAULT_GOAL :=  $(BIN)/main

$(BIN)/main: $(BUILD) $(BIN) $(BUILD)/main.o
	g++ $(BUILD)/part.o $(BUILD)/battery.o $(BUILD)/engine.o $(BUILD)/frame.o $(BUILD)/car.o  $(BUILD)/factory.o $(BUILD)/battery_factory.o $(BUILD)/engine_factory.o $(BUILD)/frame_factory.o $(BUILD)/car_factory.o $(BUILD)/warehouse.o $(BUILD)/factory_manager.o $(BUILD)/main.o -o $(BIN)/main
#directories
$(BUILD):
	$(MKDIR_P) $(BUILD)

$(BIN):
	$(MKDIR_P) $(BIN)

#main
$(BUILD)/main.o: $(SRC)/main.cpp $(BUILD)/factory_manager.o
	g++ $(CPPFLAGS) -c $(SRC)/main.cpp -o $(BUILD)/main.o
#manager
$(BUILD)/factory_manager.o: $(BUILD)/battery_factory.o $(BUILD)/engine_factory.o $(BUILD)/frame_factory.o $(BUILD)/car_factory.o $(BUILD)/warehouse.o $(SRC)/factory_manager.cpp $(INCLUDE)/factory_manager.h
	g++ $(CPPFLAGS) -c $(SRC)/factory_manager.cpp -o $(BUILD)/factory_manager.o

#warehouse
$(BUILD)/warehouse.o: $(BUILD)/car.o $(SRC)/warehouse.cpp $(INCLUDE)/warehouse.h 
	g++ $(CPPFLAGS) -c $(SRC)/warehouse.cpp -o $(BUILD)/warehouse.o

#factories
$(BUILD)/car_factory.o: $(BUILD)/frame.o $(BUILD)/engine.o $(BUILD)/battery.o $(SRC)/car_factory.cpp $(INCLUDE)/car_factory.h $(BUILD)/warehouse.o
	g++ $(CPPFLAGS) -c $(SRC)/car_factory.cpp -o $(BUILD)/car_factory.o

$(BUILD)/frame_factory.o: $(BUILD)/factory.o $(SRC)/frame_factory.cpp $(INCLUDE)/frame_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/frame_factory.cpp -o $(BUILD)/frame_factory.o

$(BUILD)/engine_factory.o: $(BUILD)/factory.o $(SRC)/engine_factory.cpp $(INCLUDE)/engine_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/engine_factory.cpp -o $(BUILD)/engine_factory.o

$(BUILD)/battery_factory.o: $(BUILD)/factory.o $(SRC)/battery_factory.cpp $(INCLUDE)/battery_factory.h
	g++ $(CPPFLAGS) -c $(SRC)/battery_factory.cpp -o $(BUILD)/battery_factory.o

$(BUILD)/factory.o: $(SRC)/factory.cpp $(INCLUDE)/factory.h
	g++ $(CPPFLAGS) -c $(SRC)/factory.cpp -o $(BUILD)/factory.o

#car
$(BUILD)/car.o: $(BUILD)/frame.o $(BUILD)/engine.o $(BUILD)/battery.o $(SRC)/car.cpp $(INCLUDE)/car.h
	g++ $(CPPFLAGS) -c $(SRC)/car.cpp -o $(BUILD)/car.o

#parts
$(BUILD)/frame.o: $(BUILD)/part.o $(SRC)/frame.cpp $(INCLUDE)/frame.h
	g++ $(CPPFLAGS) -c $(SRC)/frame.cpp -o $(BUILD)/frame.o

$(BUILD)/engine.o: $(BUILD)/part.o $(SRC)/engine.cpp $(INCLUDE)/engine.h
	g++ $(CPPFLAGS) -c $(SRC)/engine.cpp -o $(BUILD)/engine.o

$(BUILD)/battery.o: $(BUILD)/part.o $(SRC)/battery.cpp $(INCLUDE)/battery.h
	g++ $(CPPFLAGS) -c $(SRC)/battery.cpp -o $(BUILD)/battery.o

$(BUILD)/part.o: $(SRC)/part.cpp $(INCLUDE)/part.h
	g++ $(CPPFLAGS) -c $(SRC)/part.cpp -o $(BUILD)/part.o


#####CLEAN#####
clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/main
	rm -f $(BIN)/test
