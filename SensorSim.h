#pragma once

class SensorSim {

public:
	SensorSim();

	double getAltitude() const;
	double getAirspeed() const;
	double getOrientation() const;
	void updateSensor();

private:
	double altitude;
	double airspeed;
	double orientaion;
};