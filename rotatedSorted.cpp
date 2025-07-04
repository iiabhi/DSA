#include <iostream>
#include <vector>
using namespace std;

int searchRotated(const vector<int>& arr, int st, int end, int target) {
    if (st > end)
        return -1;

    int mid = st + (end - st) / 2;

    if (arr[mid] == target)
        return mid;

    // Check if left half is sorted
    if (arr[st] <= arr[mid]) {
        // Target in left half?
        if (arr[st] <= target && target < arr[mid])
            return searchRotated(arr, st, mid - 1, target);
        else
            return searchRotated(arr, mid + 1, end, target);
    }
    // Right half is sorted
    else {
        // Target in right half?
        if (arr[mid] < target && target <= arr[end])
            return searchRotated(arr, mid + 1, end, target);
        else
            return searchRotated(arr, st, mid - 1, target);
    }
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 6;

    int index = searchRotated(arr, 0, arr.size() - 1, target);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
