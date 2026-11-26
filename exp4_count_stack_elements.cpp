#include <iostream>
#include <stack>

using namespace std;

// Counts elements without permanently modifying the stack
int countStackElements(stack<int>& s) {
    stack<int> temp;
    int count = 0;

    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
        ++count;
    }

    // Restore original stack
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    return count;
}

int main() {
    stack<int> s;
    int n, val;

    cout << "Enter number of elements to push into the stack: ";
    cin >> n;

    if (n < 0) {
        cout << "Number of elements cannot be negative.\n";
        return 1;
    }

    if (n > 0) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; ++i) {
            cin >> val;
            s.push(val);
        }
    }

    cout << "Number of elements in the stack: " << countStackElements(s) << "\n";

    return 0;
}
