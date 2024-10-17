#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <iostream>

using namespace std;

class SearchingAlgorithm {
public:
    int numberComparisons;
    
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    SearchingAlgorithm();

    virtual int search(const vector<int>& arr, int target) = 0;
    void displaySearchResults(ostream& os, int results, int target) const;
};

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();
    int search(const vector<int>& arr, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch();
    int search(const vector<int>& arr, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch();
    int search(const vector<int>& arr, int target) override;
};

#endif
