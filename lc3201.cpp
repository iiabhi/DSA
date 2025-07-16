#include <iostream>
using namespace std;
int maximumLength(vector<int>& nums) {
        // f[x][y] = length of longest subsequence ending with parities x and y
        int f[2][2] = {}; // initialize all to 0
        int ans = 0;

        for (int num : nums) {
            int cur = num % 2;

            // Copy previous state before updates
            int old[2][2];
            memcpy(old, f, sizeof(f));

            for (int j = 0; j < 2; ++j) {
                int y = (j - cur + 2) % 2;
                f[cur][y] = old[y][cur] + 1;
                ans = max(ans, f[cur][y]);
            }
        }

        return ans;
    }

//or


    int maximumLength(vector<int>& nums) {
        int res = 0, n = nums.size();

        int odd = 0, even = 0, alternate = 1, prev = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1) odd++;
            else even++;

            if(i >= 1 && nums[i] % 2 != prev % 2){
                alternate++;
                prev = nums[i];
            }
        }
        return max({odd, even, alternate});
    }


int main()
{
    vector<int> vec = {1,2,1,1,2,1,2};
    cout<<maximumLength(vec)<<endl;
    return 0;
}