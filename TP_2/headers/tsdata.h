#ifndef TSDATA_H
#define TSDATA_H

#include"ts.h"
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    vector<double> zNormalizeSeries(const vector<double>& series) const;
    double mean(const vector<double>& series) const;
    double stddev(const vector<double>& series) const;

public:
    TimeSeriesDataset(bool znormalize = true, bool isTrain = true);
    void addTimeSeries(const vector<double>& series, int label=-1);
    const vector<vector<double>>& getData() const;
    const vector<int>& getLabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;
    static double euclidean_distance(const vector<double>& x, const vector<double>& y);
    static double dtw_distance(const vector<double>& x, const vector<double>& y);
};

#endif
