#ifndef TS_H
#define TS_H

using namespace std;

#include <vector>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int size) = 0;
    static void printTimeSeries(const vector<double>& series);
};

#endif
