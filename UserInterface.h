#pragma once
#include "FlightControl.h"
#include "SensorSim.h"

class UserInterface {
public:
	void displayMenu() const;
	void handleInput(FlightControl& fc, SensorSim& ss);
};