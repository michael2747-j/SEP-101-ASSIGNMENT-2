#pragma once


#ifndef AWSSYSTEM_H
#define AWSSYSTEM_H

#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "WindSensor.h"
#include "RainfallGauge.h"
#include <string>

class AWSSystem {
private:
    // Data members for temperature, humidity, wind speed, and rainfall sensors
    TemperatureSensor temperatureSensor;
    HumiditySensor humiditySensor;
    WindSensor windSensor;
    RainfallGauge rainfallGauge;

    //arrays to store data for the last 30 days
    float temperatureData[30];
    int humidityData[30];
    float windSpeedData[30];
    float rainfallData[30];

public:

    //construtors 
    AWSSystem();  
    AWSSystem(const std::string& filename) {  
        readTemperatureDataFromFile(filename);
        readHumidityDataFromFile(filename);
        readWindSpeedDataFromFile(filename);
        readRainfallDataFromFile(filename);
    }

    // Methods for reading data from files
    void readTemperatureDataFromFile(const std::string& filename);
    void readHumidityDataFromFile(const std::string& filename);
    void readWindSpeedDataFromFile(const std::string& filename);
    void readRainfallDataFromFile(const std::string& filename);

    // Methods for calculating statistics
    float calculateAverageTemperature() const;
    float  calculateAverageHumidity() const;
    float calculateTotalRainfall() const;
    float calculateAverageWindSpeed() const;

    // Method for inferring the season
    std::string inferSeason() const;
};

#endif // AWSSYSTEM_H
