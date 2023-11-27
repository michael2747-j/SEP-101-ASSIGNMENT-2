
#include "AWSSystem.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>  /
#include <vector>

// Constructor


AWSSystem::AWSSystem()
    : temperatureSensor(), humiditySensor(), windSensor(), rainfallGauge() {
    // Initialize your sensors or any other necessary setup in the constructor

    // Assuming you have appropriate methods in your sensor classes to set initial values,
    // you can set initial values for your sensors here if needed.
    // Example:
    temperatureSensor.setTemperature(0.0);
    humiditySensor.setHumidity(0);
    windSensor.setWindSpeed(0.0);
    rainfallGauge.setRainfall(0.0);

    // Initialize your data arrays here
    for (int i = 0; i < 30; ++i) {
        temperatureData[i] = 0.0;
        humidityData[i] = 0;
        windSpeedData[i] = 0.0;
        rainfallData[i] = 0.0;
    }
}


 // Add this include for string stream





void AWSSystem::readTemperatureDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; i < 30 && std::getline(file, line); ++i) {
            // Assuming temperature data is in the format DayX:Temperature, ...
            size_t colonPos = line.find(':');
            if (colonPos == std::string::npos) {
                // Handle invalid data format (no colon found)
                std::cerr << "Invalid temperature data format in file: " << filename << std::endl;
                return;
            }

            std::istringstream iss(line.substr(colonPos + 1));  // Skip the part before colon
            std::string token;

            // Use a vector to store the parsed values
            std::vector<float> temperatureValues;

            while (std::getline(iss, token, ',')) {
                try {
                    float temperature = std::stof(token);
                    temperatureSensor.setTemperature(temperature);
                    temperatureValues.push_back(temperature);
                }
                catch (const std::invalid_argument& e) {
                    // Handle invalid input (e.g., non-numeric value)
                    std::cerr << "Invalid temperature data in file: " << filename << std::endl;
                    // You might want to log the error or handle it according to your needs
                    return;
                }
            }

            // Assuming the file has consistent data structure, you can access values like this
            if (!temperatureValues.empty()) {
                temperatureData[i] = temperatureValues[0];
            }
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


void AWSSystem::readHumidityDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; i < 30 && std::getline(file, line); ++i) {
            std::istringstream iss(line);
            std::string token;

            // Use a vector to store the parsed values
            std::vector<int> humidityValues;

            for (int j = 0; j < 4 && std::getline(iss, token, ','); ++j) {
                if (j == 1) { // The second value in the line is humidity
                    try {
                        int humidity = std::stoi(token);
                        humiditySensor.setHumidity(humidity);
                        humidityValues.push_back(humidity);
                    }
                    catch (const std::invalid_argument& e) {
                        // Handle invalid input (e.g., non-numeric value)
                        std::cerr << "Invalid humidity data in file: " << filename << " at line " << i + 1 << std::endl;
                        std::cerr << "Token: " << token << std::endl;
                        return;
                    }
                }
            }

            // Assuming the file has consistent data structure, you can access values like this
            if (humidityValues.size() >= 1) {
                humidityData[i] = humidityValues[0];
            }
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}



void AWSSystem::readWindSpeedDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; i < 30 && std::getline(file, line); ++i) {
            std::istringstream iss(line);
            std::string token;

            // Use a vector to store the parsed values
            std::vector<float> windSpeedValues;

            for (int j = 0; j < 4 && std::getline(iss, token, ','); ++j) {
                if (j == 2) { // The third value in the line is wind speed
                    try {
                        float windSpeed = std::stof(token);
                        windSensor.setWindSpeed(windSpeed);
                        windSpeedValues.push_back(windSpeed);
                    }
                    catch (const std::invalid_argument& e) {
                        // Handle invalid input (e.g., non-numeric value)
                        std::cerr << "Invalid wind speed data in file: " << filename << " at line " << i + 1 << std::endl;
                        std::cerr << "Token: " << token << std::endl;
                        return;
                    }
                }
            }

            // Assuming the file has consistent data structure, you can access values like this
            if (windSpeedValues.size() >= 1) {
                windSpeedData[i] = windSpeedValues[0];
            }
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}






void AWSSystem::readRainfallDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        for (int i = 0; i < 30 && std::getline(file, line); ++i) {
            std::istringstream iss(line);
            std::string token;

            // Use a vector to store the parsed values
            std::vector<float> rainfallValues;

            for (int j = 0; j < 5 && std::getline(iss, token, ','); ++j) {
                if (j == 3) { // The fourth value in the line is rainfall
                    try {
                        float rainfall = std::stof(token);
                        rainfallGauge.setRainfall(rainfall);
                        rainfallValues.push_back(rainfall);
                    }
                    catch (const std::invalid_argument& e) {
                        // Handle invalid input (e.g., non-numeric value)
                        std::cerr << "Invalid rainfall data in file: " << filename << " at line " << i + 1 << std::endl;
                        std::cerr << "Token: " << token << std::endl;
                        return;
                    }
                }
            }

            // Assuming the file has consistent data structure, you can access values like this
            if (rainfallValues.size() >= 1) {
                rainfallData[i] = rainfallValues[0];
            }
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}






// Method for calculating the average temperature
float AWSSystem::calculateAverageTemperature() const {
    float sumTemperature = 0.0;
    for (int i = 0; i < 30; ++i) {
        sumTemperature += temperatureData[i];
    }
    return sumTemperature / 30.0;
}

float AWSSystem::calculateAverageHumidity() const {
    float sumHumidity = 0;
    for (int i = 0; i < 30; ++i) {
        sumHumidity += humidityData[i];
    }
    return sumHumidity / 30.0;
}

float AWSSystem::calculateTotalRainfall() const {
    float totalRainfall = 0.0;
    for (int i = 0; i < 30; ++i) {
        totalRainfall += rainfallData[i];
    }
    return totalRainfall;
}

float AWSSystem::calculateAverageWindSpeed() const {
    float sumWindSpeed = 0.0;
    for (int i = 0; i < 30; ++i) {
        sumWindSpeed += windSpeedData[i];
    }
    return sumWindSpeed / 30.0;
}

// Method for inferring the season

std::string AWSSystem::inferSeason() const {
    // Get the average temperature
    float avgTemperature = calculateAverageTemperature();

    // Infer the season based on temperature ranges
    if (avgTemperature < 10.0) {
        return "Winter";
    }
    else if (avgTemperature >= 10.0 && avgTemperature < 23.0) {
        return "Fall";
    }
    else if (avgTemperature >= 24.0 && avgTemperature < 28.0) {
        return "Spring";
    }
    else {
        return "Summer";
    }
}
