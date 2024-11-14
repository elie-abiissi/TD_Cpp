#ifndef STP_H
#define STP_H

#include "ts.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    StepGenerator(int seed);
    vector<double> generateTimeSeries(int size) override;
};

#endif
