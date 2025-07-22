#include <iostream>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map;
        int n= nums.size();
        int sum=0;
        int maxx = INT_MIN;
        int ptr =0;
        int ptrdel =0;
        for(int i=0; i<n; i++){
            if(map.find(nums[i]) != map.end()){
                int idx = map[nums[i]];
                cout<<"idx: "<<idx<<endl;
                for(int j=ptr; j<=idx; j++){
                    sum = sum - nums[j];
                }
                cout<<"sum: "<<sum<<endl;
                sum += nums[i];
                cout<<"sum: "<<sum<<endl;
                ptr = idx+1;
                cout<<"ptr: "<<ptr<<endl;

                while(ptrdel!=ptr){
                    map.erase(nums[ptrdel]);
                    ptrdel++;
                }
                map[nums[i]] = i;
                
                
            }
            else{
                map[nums[i]] = i;
                sum += nums[i];
                maxx = max(maxx, sum);
                cout<<"sum: "<<sum<<"maxx: "<<maxx<<endl;
            }
        }
        return maxx;
    }
int main()
{
    vector<int> num = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
    cout<<maximumUniqueSubarray(num)<<endl;
    return 0;
}