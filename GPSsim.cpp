#include "GPSsim.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp> // For JSON parsing
#include <iostream>

using json = nlohmann::json;

// Callback function to write data from the curl request
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

GPSsim::GPSsim() : apiUrl("https://overpass-api.de/api/interpreter?data=[out:json];node[highway=traffic_signals](50.6,7.0,50.8,7.3);out;") {
    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }
}

GPSdata GPSsim::getCurrentData() const {
    return currentData;
}

void GPSsim::updateData() {
    if (!curl) {
        throw std::runtime_error("CURL not initialized");
    }

    CURLcode res;
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
        return;
    }

    parseResponse(response);
}

void GPSsim::parseResponse(const std::string& response) {
    try {
        auto jsonResponse = json::parse(response);

        currentData.latitude = jsonResponse["latitude"].get<double>();
        currentData.longitude = jsonResponse["longitude"].get<double>();
        currentData.altitude = jsonResponse["altitude"].get<double>();
    }
    catch (const json::exception& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    }
}

GPSsim::~GPSsim() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
}
