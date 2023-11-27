#include "RainfallGauge.h"
#include <iostream>
#include <iomanip>

RainfallGauge::RainfallGauge() : currentRainfall(0.0) {}

float RainfallGauge::getRainfall() const {
    return currentRainfall;
}

void RainfallGauge::setRainfall(float rainfall) {
    currentRainfall = rainfall;
}

void RainfallGauge::resetRainfall() {
    currentRainfall = 0.0;
}

void RainfallGauge::displayRainfall() const {
    std::cout << "Current rainfall: " << std::fixed << std::setprecision(2)
        << currentRainfall << " mm." << std::endl;
}
