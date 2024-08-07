#pragma once
#include "FlightControl.h"
#include "SensorSim.h"

class UserInterface {
public:
	void displayMenu() const;
	void handleInput(FlightControl& fc, SensorSim& ss);

private:
	void logData(const FlightControl& fc, const SensorSim& ss) const;
};