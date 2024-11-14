#include "headers/gau.h"
#include <cmath>
#include <cstdlib>

GaussianGenerator::GaussianGenerator() : mean(0.0), stddev(1.0) {}

GaussianGenerator::GaussianGenerator(int seed, double mean, double stddev)
    : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series;
    srand(seed);

    for (int i = 0; i < size; ++i) {
        double u1 = rand() / static_cast<double>(RAND_MAX);
        double u2 = rand() / static_cast<double>(RAND_MAX);
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        series.push_back(mean + z0 * stddev);
    }

    return series;
}
