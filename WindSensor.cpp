
#include "WindSensor.h"
#include <iostream>
#include <iomanip>

WindSensor::WindSensor() : currentWindSpeed(0.0) {}

float WindSensor::getWindSpeed() const {
    return currentWindSpeed;
}

void WindSensor::setWindSpeed(float windSpeed) {
    currentWindSpeed = windSpeed;
}

void WindSensor::displayWindSpeed() const {
    std::cout << "Current wind speed: " << std::fixed << std::setprecision(2)
        << currentWindSpeed << " km/h." << std::endl;
}
