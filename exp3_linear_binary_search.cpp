#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& sortedArr, int target) {
    int low = 0;
    int high = static_cast<int>(sortedArr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sortedArr[mid] == target) {
            return mid;
        } else if (sortedArr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    // Linear Search on original array
    int linIdx = linearSearch(arr, target);
    if (linIdx != -1) {
        cout << "Linear Search: Found at index " << linIdx << " (0-based).\n";
    } else {
        cout << "Linear Search: Element not found.\n";
    }

    // Binary Search requires a sorted array
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    cout << "Sorted array for Binary Search: ";
    for (int x : sortedArr) {
        cout << x << " ";
    }
    cout << "\n";

    int binIdx = binarySearch(sortedArr, target);
    if (binIdx != -1) {
        cout << "Binary Search: Found at index " << binIdx << " (0-based in sorted array).\n";
    } else {
        cout << "Binary Search: Element not found.\n";
    }

    return 0;
}
