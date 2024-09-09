#pragma once
#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <string>
#include <fstream>

class DataLogger {
public:
	DataLogger(const std::string& filename);
	~DataLogger();

	void logSensorData(const std::string& data);
	void logGPSData(const std::string& data);
	void logWeatherData(const std::string& data);

private:
	std::ofstream logFile;
	void openLogFile();
	void closeLogFile();
};

#endif //DATA_LOGGER_H