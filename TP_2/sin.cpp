#include "headers/sin.h"
#include <cmath>
using namespace std;

SinWaveGenerator::SinWaveGenerator() : amplitude(1.0), frequency(1.0), phase(0.0) {}

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series;
    for (int i = 0; i < size; ++i) {
        double value = amplitude * sin(frequency * i + phase);
        series.push_back(value);
    }
    return series;
}
