#include <iostream>
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {
        int maxx = INT_MIN;
        int n = arr.size();
        
        

        for(int i=n-1; i>=0; i--){
            int j = i-1;
            int prevGreater = INT_MAX;
            int idx = -1;
            while(j>=0){
                if(arr[j] > arr[i] && arr[j]< prevGreater){
                    prevGreater = arr[j];
                    idx = j;
                }
                j--;
            }
            if(idx == -1){
                return arr;
            }else{
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }

int main()
{
    vector<int> vec = {3,1,1,3};
    vector<int> res = prevPermOpt1(vec);
    for(auto x: res){
        cout<<x<<endl;
    }

    return 0;
}