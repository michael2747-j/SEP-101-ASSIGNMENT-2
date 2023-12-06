
#include "WindSensor.h"
#include <iostream>
#include <iomanip>

//constructor intializing currentWinspeed to zero
WindSensor::WindSensor() : currentWindSpeed(0.0) {}

//getter method to retrieve the currentWindSpeed value
float WindSensor::getWindSpeed() const {
    return currentWindSpeed;
}

//setter method to set the windSpeed value
void WindSensor::setWindSpeed(float windSpeed) {
    currentWindSpeed = windSpeed;
}

//method to display the current wind speed value
void WindSensor::displayWindSpeed() const {
    std::cout << "Current wind speed: " << std::fixed << std::setprecision(2)
        << currentWindSpeed << " km/h." << std::endl;
}
