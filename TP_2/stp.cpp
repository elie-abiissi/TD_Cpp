#include "headers/stp.h"
#include <cstdlib>
using namespace std;

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.push_back(0);

    srand(seed);
    for (int i = 1; i < size; ++i) {
        double randomValue = rand() / static_cast<double>(RAND_MAX);
        if (randomValue < 0.5) {
            series.push_back(series.back());
        } else {
            series.push_back(rand() % 101);
        }
    }

    return series;
}
