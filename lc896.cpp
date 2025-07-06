#include <iostream>
using namespace std;


    bool isMonotonic(vector<int>& nums) {
        bool isMono = true;
        for(int i = 0; i<=(nums.size()-1); i++){
            cout<<nums[i]<<" "<<nums[i+1]<<endl;
            if(nums[i]<=nums[i+1]){
                isMono = true;
            }else{
                isMono = false;
                break;
            }
        }
        cout<<isMono<<endl;
        if(isMono == true) return true;
        for(int i = 1; i<(nums.size()); i++){
            if(nums[i]<=nums[i-1]){
                isMono = true;
            }else{
                isMono = false;
                break;
            }
        }
        return isMono;
    }

int main()
{
    // int n=10;
    // bool x= true;
    // for(int i =0; i<n; i++){
    //     if(i==5){
    //         break;
    //     }
    //     cout<<i<<" ";
    // }
    vector<int> nums = {1,3,2};
    cout<<isMonotonic(nums)<<endl;
    return 0;
}