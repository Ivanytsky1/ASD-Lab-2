#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<vector<int>> B = {
        {4, 3, 2, 1, 5, 6},
        {9, 8, 7, 6, 5, 4},
        {2, 4, 6, 8, 10, 12},
        {1, 3, 5, 7, 9, 11}
    };

    int maxRowIndex = -1;
    int maxElement = INT_MIN;

    // Find the row with the maximum element
    for (int i = 0; i < B.size(); ++i) {
        auto it = std::max_element(B[i].begin(), B[i].end());
        if (*it > maxElement) {
            maxElement = *it;
            maxRowIndex = i;
        }
    }

    // Sort the row with the maximum element
    heapSort(B[maxRowIndex]);

    // Print the sorted row
    for (int i = 0; i < B[maxRowIndex].size(); ++i) {
        cout << B[maxRowIndex][i] << " ";
    }
    cout << endl;

    return 0;
}