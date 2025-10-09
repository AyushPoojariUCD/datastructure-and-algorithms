#include <bits/stdc++.h>
using namespace std;

// Function to find the largest element in a vector using linear search
int findLargestElement(const vector<int> &nums)
{
    int maxElement = INT_MIN;
    for (int num : nums)
    {
        maxElement = max(maxElement, num);
    }
    return maxElement;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
Where n = size of the input vector.
*/

void runTestCases()
{
    vector<vector<int>> testCases = {
        {1, 2, 4, 3, 6, 7, 8}, // Normal case
        {-1, -5, -3, -10},     // All negative
        {42},                  // Single element
        {INT_MIN, 0, INT_MAX}, // Extremes
        {7, 7, 7, 7},          // All same
    };

    for (int i = 0; i < testCases.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << "Largest Element = " << findLargestElement(testCases[i]) << endl;
    }
}

int main()
{
    runTestCases();
    return 0;
}
