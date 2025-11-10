#include <iostream>
#include <string>
using namespace std;

//Analytical Minds Group
//Osasumwen Osazuwa: 
//Daniel Igwe: 
//Emmanuella:
//Joseph Inaku:
//Emmanuel:

/* ================================
   1. FACTORIAL CALCULATION
   ================================ */

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1)
        return 1;
    // Recursive case: n * factorial of (n - 1)
    return n * factorial(n - 1);
}

/* ================================
   2. FIBONACCI SEQUENCE
   ================================ */

// Recursive function to generate nth Fibonacci number
int fibonacci(int n) {
    // Base cases: first two Fibonacci numbers are 0 and 1
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    // Recursive case: sum of the two previous numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* ================================
   3. STRING REVERSAL
   ================================ */

// Recursive function to reverse a string
string reverseString(string str) {
    // Base case: empty or single-character string
    if (str.length() <= 1)
        return str;
    // Recursive case: reverse substring and append first character
    return reverseString(str.substr(1)) + str[0];
}

/* ================================
   4. BINARY SEARCH
   ================================ */

// Recursive function for binary search
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if range is invalid, element not found
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // If element found at mid
    if (arr[mid] == target)
        return mid;

    // Recursive cases:
    if (target < arr[mid])
        return binarySearch(arr, left, mid - 1, target);  // search left half
    else
        return binarySearch(arr, mid + 1, right, target);  // search right half
}

/* ================================
   MAIN FUNCTION FOR TESTING
   ================================ */

int main() {
    cout << "=== Factorial Tests ===" << endl;
    cout << "Factorial of 0: " << factorial(0) << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Factorial of 7: " << factorial(7) << endl;

    cout << "\n=== Fibonacci Tests ===" << endl;
    for (int i = 0; i < 7; i++)
        cout << "Fib(" << i << ") = " << fibonacci(i) << endl;

    cout << "\n=== String Reversal Tests ===" << endl;
    cout << "Reverse of 'hello': " << reverseString("hello") << endl;
    cout << "Reverse of 'a': " << reverseString("a") << endl;
    cout << "Reverse of 'recursion': " << reverseString("recursion") << endl;

    cout << "\n=== Binary Search Tests ===" << endl;
    int arr1[] = {}; // empty array
    int arr2[] = {1, 3, 5, 7, 9, 11};
    int size1 = 0, size2 = 6;

    cout << "Search 7 in arr2: Index " << binarySearch(arr2, 0, size2 - 1, 7) << endl;
    cout << "Search 4 in arr2: Index " << binarySearch(arr2, 0, size2 - 1, 4) << endl;
    cout << "Search 1 in arr1 (empty array): Index " << binarySearch(arr1, 0, size1 - 1, 1) << endl;

    return 0;
}

