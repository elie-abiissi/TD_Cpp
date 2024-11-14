#include "headers/tsdata.h"
#include <algorithm>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    vector<double> normalizedSeries = znormalize ? zNormalizeSeries(series) : series;
    data.push_back(normalizedSeries);
    labels.push_back(label);
    maxLength = max(maxLength, static_cast<int>(series.size()));
    numberOfSamples++;
}

const vector<vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

double TimeSeriesDataset::mean(const vector<double>& series) const {
    double sum = 0.0;
    for (double value : series) {
        sum += value;
    }
    return sum / series.size();
}

double TimeSeriesDataset::stddev(const vector<double>& series) const {
    double avg = mean(series);
    double variance = 0.0;
    for (double value : series) {
        variance += (value - avg) * (value - avg);
    }
    return sqrt(variance / series.size());
}

vector<double> TimeSeriesDataset::zNormalizeSeries(const vector<double>& series) const {
    vector<double> normalizedSeries;
    double avg = mean(series);
    double stdDev = stddev(series);
    for (double value : series) {
        normalizedSeries.push_back((value - avg) / stdDev);
    }
    return normalizedSeries;
}

double TimeSeriesDataset::euclidean_distance(const vector<double>& x, const vector<double>& y) {
    double distance = 0.0;
    size_t len = min(x.size(), y.size());
    for (size_t i = 0; i < len; ++i) {
        distance += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return sqrt(distance);
}

double TimeSeriesDataset::dtw_distance(const vector<double>& x, const vector<double>& y) {
    size_t n = x.size();
    size_t m = y.size();
    vector<vector<double>> dtw(n + 1, vector<double>(m + 1, INFINITY));
    dtw[0][0] = 0.0;
    
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            double cost = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            dtw[i][j] = cost + min({dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1]});
        }
    }
    return sqrt(dtw[n][m]);
}
