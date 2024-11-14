#include "headers/knn.h"
#include "headers/tsdata.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <iostream>

using namespace std;

KNN::KNN(int k, const string& similarity_measure) : k(k), similarity_measure(similarity_measure) {}

int KNN::predict(const vector<vector<double>>& data, const vector<int>& labels, const vector<double>& test_series) {
    vector<pair<double, int>> distances;

    for (size_t i = 0; i < data.size(); ++i) {
        double distance = 0.0;
        if (similarity_measure == "euclidean_distance") {
            distance = TimeSeriesDataset::euclidean_distance(data[i], test_series);
        } else if (similarity_measure == "dtw") {
            distance = TimeSeriesDataset::dtw_distance(data[i], test_series);
        } else {
            throw invalid_argument("Unknown similarity measure.");
        }
        distances.push_back({distance, labels[i]});
    }

    sort(distances.begin(), distances.end());

    map<int, int> class_counts;
    for (int i = 0; i < k; ++i) {
        class_counts[distances[i].second]++;
    }

    int predicted_class = -1;
    int max_count = -1;
    for (const auto& pair : class_counts) {
        if (pair.second > max_count) {
            predicted_class = pair.first;
            max_count = pair.second;
        }
    }

    return predicted_class;
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth) {
    int correct_predictions = 0;

    for (size_t i = 0; i < testData.getData().size(); ++i) {
        int predicted_label = predict(trainData.getData(), trainData.getLabels(), testData.getData()[i]);
        if (predicted_label == ground_truth[i]) {
            correct_predictions++;
        }
    }

    return static_cast<double>(correct_predictions) / testData.getData().size();
}
