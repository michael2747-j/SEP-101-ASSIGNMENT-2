#include "RainfallGauge.h"
#include <iostream>
#include <iomanip>

//constructor intializing currentRainfall to zero
RainfallGauge::RainfallGauge() : currentRainfall(0.0) {}

//Getter method to retrieve the current rainfall value
float RainfallGauge::getRainfall() const {
    return currentRainfall;
}

//setter method to set the rainfall value
void RainfallGauge::setRainfall(float rainfall) {
    currentRainfall = rainfall;
}

//method to reset the current rainfall value to zero
void RainfallGauge::resetRainfall() {
    currentRainfall = 0.0;
}

//method to display the current rainfall value
void RainfallGauge::displayRainfall() const {
    std::cout << "Current rainfall: " << std::fixed << std::setprecision(2)
        << currentRainfall << " mm." << std::endl;
}
