#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool isPalindrome(const string& input) {
    stack<char> charStack;
    queue<char> charQueue;

    for (char c : input) {
            charStack.push(tolower(c));
            charQueue.push(tolower(c));   
    }

    while (!charStack.empty() && !charQueue.empty()) {
        if (charStack.top() != charQueue.front()) {
            return false;
        }
        charStack.pop();
        charQueue.pop();
    }
    return true;
}

int main() {
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;

    return 0;
}

