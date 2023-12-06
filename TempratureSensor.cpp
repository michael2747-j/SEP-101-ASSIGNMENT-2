#include "TemperatureSensor.h"

#include "TemperatureSensor.h"
#include <iostream>
#include <iomanip>

//constructor initializing currentTemperature to zero
TemperatureSensor::TemperatureSensor() : currentTemperature(0.0) {}

// getter method to retrieve current temperature value
float TemperatureSensor::getTemperature() const {
    return currentTemperature;
}

// setter method to set temperature value
void TemperatureSensor::setTemperature(float temperature) {
    currentTemperature = temperature;
}

// method to display the current temperature value
void TemperatureSensor::displayTemperature() const {
    std::cout << "Current temperature: " << std::fixed << std::setprecision(2)
        << currentTemperature << " degrees Celsius." << std::endl;
}
