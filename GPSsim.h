#pragma once
#include "GPSdata.h"
#include <random>
#include <string>
#include <curl/curl.h>

class GPSsim {
public:
    GPSsim();
    ~GPSsim();  // Declare the destructor here
    GPSdata getCurrentData() const;
    void updateData();

    GPSsim(const GPSsim&) = delete;
    GPSsim operator=(const GPSsim&) = delete;

    GPSsim(GPSsim&&) noexcept = default;
    GPSsim& operator=(GPSsim&&) noexcept = default;

private:
    GPSdata currentData;
    std::string apiUrl;
    CURL* curl;

    void parseResponse(const std::string& response);
};

