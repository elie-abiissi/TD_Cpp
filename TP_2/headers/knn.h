#ifndef KNN_H
#define KNN_H

using namespace std;

#include "ts.h"
#include "tsdata.h"
#include <vector>
#include <string>

class KNN {
public:
    KNN(int k, const string& similarity_measure);
    int predict(const std::vector<std::vector<double>>& data, const std::vector<int>& labels, const vector<double>& test_series);
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth);

private:
    int k;
    string similarity_measure;
};

#endif
