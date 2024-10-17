#include "search.h"
using namespace std;

int main() {
    vector<int> arr = {4, 8, 12, 15, 17, 23, 25, 33, 34, 39, 42, 48, 56, 61, 69, 73, 77, 82, 90, 91};
    int target = 42;

    cout << endl << "LINEAR SEARCH" <<endl;
    LinearSearch linear;
    int result = linear.search(arr, target);
    linear.displaySearchResults(cout, result, target);

    cout << endl << "JUMP SEARCH" <<endl;
    JumpSearch jump;
    result = jump.search(arr, target);
    jump.displaySearchResults(cout, result, target);

    cout << endl << "BINARY SEARCH" <<endl;
    BinarySearch binary;
    result = binary.search(arr, target);
    binary.displaySearchResults(cout, result, target);

    return 0;
}
