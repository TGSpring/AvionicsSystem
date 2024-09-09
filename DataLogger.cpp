#include "DataLogger.h"
#include <iostream>

DataLogger::DataLogger(const std::string& filename) {
	logFile.open(filename, std::ios::app);
	if (!logFile.is_open()) {
		std::cerr << "Failed to open log file: " << filename << std::endl;
	}
}

DataLogger::~DataLogger() {
	if (logFile.is_open()) {
		logFile.close();
	}
}

void DataLogger::logSensorData(const std::string& data) {
	if (logFile.is_open()) {
		logFile << "Sensor Data: " << data << std::endl;
	}
}

void DataLogger::logGPSData(const std::string& data) {
	if (logFile.is_open()) {
		logFile << "GPS Data: " << data << std::endl;
	}
}

void DataLogger::logWeatherData(const std::string& data) {
	if (logFile.is_open()) {
		logFile << "Weather Data: " << data << std::endl;
	}
}
