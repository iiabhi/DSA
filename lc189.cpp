#include <iostream>
using namespace std;
//sol
class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};//end
int main()
{
    return 0;
}