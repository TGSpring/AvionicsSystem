#pragma once
#include <string>
#include "FlightControl.h"
#include "SensorSim.h"
#include "GPSsim.h"
#include "WeatherSim.h"

class UserInterface {
public:
    void displayMenu() const;
    void handleInput(FlightControl& fc, SensorSim& ss, GPSsim& gps, WeatherSim& weather);

private:
    void logData(const FlightControl& fc, const SensorSim& ss, const std::string& logType) const;
    double getValidAngle(const std::string& prompt) const;
    void displayGPSData(const GPSsim& gps) const;
    void displayWeatherData(const WeatherSim& weather) const;
};
