#include "SensorSim.h"
#include <cstdlib> // for rand()

SensorSim::SensorSim() : altitude(1000.0), airspeed(250.0), orientaion(0.0) {}

double SensorSim::getAltitude() const {
	return altitude;
}

double SensorSim::getAirspeed() const {
	return airspeed;
}

double SensorSim::getOrientation() const {
	return orientaion;
}

void SensorSim::updateSensor() {
	//Simulate sensor udpates with random changes

	altitude += (rand() % 20 - 10); //Random changes between -10 and 10
	airspeed += (rand() % 10 - 5); //Random changes between -5 and 5
	orientaion += (rand() % 6 - 3); //Random changes between -3 and 3
}