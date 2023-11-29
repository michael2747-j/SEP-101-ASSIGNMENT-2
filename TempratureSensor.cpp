#include "TemperatureSensor.h"

#include "TemperatureSensor.h"
#include <iostream>
#include <iomanip>

TemperatureSensor::TemperatureSensor() : currentTemperature(0.0) {}

// function to get current rainfall
float TemperatureSensor::getTemperature() const {
    return currentTemperature;
}

// function to set current rainfall
void TemperatureSensor::setTemperature(float temperature) {
    currentTemperature = temperature;
}

// function to display rainfall
void TemperatureSensor::displayTemperature() const {
    std::cout << "Current temperature: " << std::fixed << std::setprecision(2)
        << currentTemperature << " degrees Celsius." << std::endl;
}
