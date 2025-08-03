#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {

        int minn = INT_MAX;
        int n = nums.size();


        vector<int> prefix(n);
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            prefix[i] = prefixSum + nums[i];
            prefixSum +=nums[i];
        }
       
        if(prefix[n-1]<target) return 0;
        unordered_map<int , int> map;
        for(int i=0; i<n; i++){
            if(target == prefix[i]){
                int len = i+1;
                cout<<"len: "<<len<<endl;
                minn = min(len, minn);
                cout<<"minn: "<<minn<<endl;
            }
            int resSum =  prefix[i] - target;
            cout<<"res: "<<resSum<<endl;
            
            if(map.find(resSum)!=map.end()){
                int len = i-map[resSum];
                minn = min(len, minn);
            }else{
                map[prefix[i]] = i;
            }
        }
        return minn;
    }

int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout<<minSubArrayLen(11,arr)<<endl;
    return 0;
}