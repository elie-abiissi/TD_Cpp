#include "headers/ts.h"
#include <iostream>

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (double value : series) {
        cout << value << " ";
    }
    cout << endl;
}
