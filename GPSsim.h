#pragma once
#include "GPSdata.h"
#include <random>

class GPSsim {
public:
	GPSsim();
	GPSdata getCurrentData() const;
	void updateData();

	GPSsim(const GPSsim&) = delete;
	GPSsim operator=(const GPSsim&) = delete;

	GPSsim(GPSsim&&) noexcept = default;
	GPSsim& operator=(GPSsim&&) noexcept = default;

private:
	GPSdata currentData;
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> latitudeDist;
	std::uniform_real_distribution<> longitudeDist;
	std::uniform_int_distribution<> altitudeDist;
};