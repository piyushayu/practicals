#include <iostream>

using namespace std;

int main() {
    int value;
    cout << "Enter an integer value: ";
    cin >> value;

    int* ptr = &value;    // Single pointer holding address of value
    int** dptr = &ptr;    // Double pointer holding address of ptr

    cout << "\n--- Values ---\n";
    cout << "value          = " << value << "\n";
    cout << "*ptr           = " << *ptr << "\n";
    cout << "**dptr         = " << **dptr << "\n";

    cout << "\n--- Addresses ---\n";
    cout << "&value         = " << &value << "\n";
    cout << "ptr            = " << ptr << "\n";
    cout << "*dptr          = " << *dptr << "\n";
    cout << "&ptr           = " << &ptr << "\n";
    cout << "dptr           = " << dptr << "\n";
    cout << "&dptr          = " << &dptr << "\n";

    // Modifying value using double pointer
    **dptr += 10;
    cout << "\nAfter **dptr += 10, value = " << value << "\n";

    return 0;
}
