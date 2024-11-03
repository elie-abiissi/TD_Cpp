#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        int count = 1;
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[j] == numbers[i]) {
                count++;
            }
        }
        if (i == 0 || numbers[i] != numbers[i - 1]) {
            cout << numbers[i] << " : " << count << " times" << endl;
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    for (const int& number : numbers) {
        frequencyMap[number]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    
    cout << "Frequency (Brute Force): " << endl;
    countFrequencyBruteForce(numbers);
    
    cout << "\nFrequency (Optimal): " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }
    return 0;
}