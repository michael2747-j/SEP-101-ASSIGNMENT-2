#include "TemperatureSensor.h"

#include "TemperatureSensor.h"
#include <iostream>
#include <iomanip>

TemperatureSensor::TemperatureSensor() : currentTemperature(0.0) {}

float TemperatureSensor::getTemperature() const {
    return currentTemperature;
}

void TemperatureSensor::setTemperature(float temperature) {
    currentTemperature = temperature;
}

void TemperatureSensor::displayTemperature() const {
    std::cout << "Current temperature: " << std::fixed << std::setprecision(2)
        << currentTemperature << " degrees Celsius." << std::endl;
}
