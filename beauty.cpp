#include <iostream>
#include <vector>
using namespace std;

vector<int> getBeauty(vector<int>& nums, int k, int x) {
    const int OFFSET = 50;  // To map [-50..50] to [0..100]
    vector<int> freq(101, 0);  // Frequency of elements in window
    vector<int> result;

    // Initialize first window
    for (int i = 0; i < k; ++i) {
        if (nums[i] < 0)
            freq[nums[i] + OFFSET]++;
    }

    // Helper to get x-th smallest negative value
    auto getXthNegative = [&]() -> int {
        int count = 0;
        for (int i = 0; i < 50; ++i) {  // Only negative values: [-50..-1]
            count += freq[i];
            if (count >= x)
                return i - OFFSET;
        }
        return 0;
    };

    // First window
    result.push_back(getXthNegative());

    // Slide window
    for (int i = k; i < nums.size(); ++i) {
        // Remove element going out
        if (nums[i - k] < 0)
            freq[nums[i - k] + OFFSET]--;

        // Add new element
        if (nums[i] < 0)
            freq[nums[i] + OFFSET]++;

        result.push_back(getXthNegative());
    }

    return result;
}

int main() {
    int k, x, n;
    cin >> k >> x >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> result = getBeauty(nums, k, x);
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
