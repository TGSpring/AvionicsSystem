#include "GPSsim.h"
#include <random>

GPSsim::GPSsim()
	: gen(rd()),
	latitudeDist(37.7749, 37.7849),
	longitudeDist(-122.419, -122.4049),
	altitudeDist(30000, 31000) {
	updateData();
}



GPSdata GPSsim::getCurrentData() const {
	return currentData;
}

void GPSsim::updateData() {
	currentData.latitude = latitudeDist(gen);
	currentData.longitude = longitudeDist(gen);
	currentData.altitude = altitudeDist(gen);

}