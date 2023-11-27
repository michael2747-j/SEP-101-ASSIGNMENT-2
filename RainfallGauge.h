#pragma once

#ifndef RAINFALLGAUGE_H
#define RAINFALLGAUGE_H

class RainfallGauge {
private:
    float currentRainfall;

public:
    RainfallGauge();  // Constructor
    float getRainfall() const;
    void setRainfall(float rainfall);
    void resetRainfall();
    void displayRainfall() const;
};

#endif // RAINFALLGAUGE_H
