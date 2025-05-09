// Name: Luke Pritchard
// Date: 05/08/2025
// File: FileStats_Final.cpp
// Description: Reads numbers from a file and outputs the min, max, total, and average.
// See ReadMe.md for more information

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Function declarations
bool ReadFileIntoVector(const string& filename, vector<int>& numbers);
int GetMin(const vector<int>& numbers);
int GetMax(const vector<int>& numbers);
int GetTotal(const vector<int>& numbers);
double GetAverage(const vector<int>& numbers);

int main() {
    string filename;
    vector<int> numbers;

    while (true) {
        cout << "Enter the filename (e.g., numbers.txt): ";
        getline(cin, filename);

        if (ReadFileIntoVector(filename, numbers) && !numbers.empty()) {
            break;  // Success
        }

        cout << "Error: Could not open or read from file. Try again.\n";
        numbers.clear();
    }

    cout << fixed << setprecision(2);
    cout << "\nLowest number: " << GetMin(numbers) << endl;
    cout << "Highest number: " << GetMax(numbers) << endl;
    cout << "Total: " << GetTotal(numbers) << endl;
    cout << "Average: " << GetAverage(numbers) << endl;

    return 0;
}

// Reads numbers from a file into a vector
bool ReadFileIntoVector(const string& filename, vector<int>& numbers) {
    ifstream inputFile(filename);
    int value;

    if (!inputFile)
        return false;

    while (inputFile >> value) {
        numbers.push_back(value);
    }

    return !numbers.empty();  // Must contain at least one valid number
}

int GetMin(const vector<int>& numbers) {
    int minVal = numeric_limits<int>::max();
    for (int num : numbers)
        if (num < minVal) minVal = num;
    return minVal;
}

int GetMax(const vector<int>& numbers) {
    int maxVal = numeric_limits<int>::min();
    for (int num : numbers)
        if (num > maxVal) maxVal = num;
    return maxVal;
}

int GetTotal(const vector<int>& numbers) {
    int total = 0;
    for (int num : numbers)
        total += num;
    return total;
}

double GetAverage(const vector<int>& numbers) {
    if (numbers.empty()) return 0.0;
    return static_cast<double>(GetTotal(numbers)) / numbers.size();
}