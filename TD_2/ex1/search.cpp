#include "search.h"
#include <cmath>
#include <algorithm>

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(ostream& os, int results, int target) const {
    totalSearch++;
    if (results == -1) {
        os << "\nSearching for the element " << target << " was not successful.\n";
    } else {
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
        os << "\nFound the element " << target << " at index " << results << ".\n";
        os << "It took a total of " << numberComparisons << " comparisons to find it.\n";
        os << "Total comparisons: " << totalComparisons << ", Average comparisons: " << averageComparisons << ".\n";
    }
}

LinearSearch::LinearSearch() : SearchingAlgorithm() {}

int LinearSearch::search(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;  
}

JumpSearch::JumpSearch() : SearchingAlgorithm() {}

int JumpSearch::search(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;  
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;  
        }
    }

    return -1;  
}

BinarySearch::BinarySearch() : SearchingAlgorithm() {}

int BinarySearch::search(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  
        }

        if (arr[mid] < target) {
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return -1;  
}