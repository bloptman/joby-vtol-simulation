CC = g++
COMPILER_FLAG = -std=c++11

joby-simulation: main.o Simulation.o Charger.o Aircraft.o Battery.o Utility.o
	$(CC) main.o Simulation.o Charger.o Aircraft.o Battery.o Utility.o -o -v joby-simulation

clean:
	rm *.o

main.o: main.cpp Simulation.h
	$(CC) $(COMPILER_FLAG) -c main.cpp

Simulation.o: Simulation.h Simulation.cpp Charger.h Charger.cpp
	$(CC) $(COMPILER_FLAG) -c Simulation.cpp

Charger.o: Charger.h Charger.cpp Aircraft.h Aircraft.cpp
	$(CC) $(COMPILER_FLAG) -c Charger.cpp

Aircraft.o: Aircraft.h Aircraft.cpp Charger.h Charger.cpp AircraftDataStructs.h Constants.h Battery.h Battery.cpp
	$(CC) $(COMPILER_FLAG) -c Aircraft.cpp

Battery.o: Battery.h Battery.cpp
	$(CC) $(COMPILER_FLAG) -c Battery.cpp

Constants.o: Constants.h Utility.h Utility.cpp AircraftDataStructs.h
	$(CC) $(COMPILER_FLAG) -c Constants.h Utility.cpp

AircraftDataStructs.o: AircraftDataStructs.h
	$(CC) $(COMPILER_FLAG) -c AircraftDataStruts.h

Utility.o: Utility.h Utility.cpp Constants.h AircraftDataStructs.h
	$(CC) $(COMPILER_FLAG) -c Utility.cpp
