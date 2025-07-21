#include <iostream>
using namespace std;

//brute force O(n^2)
int subSum(vector<int> vec, int target){
    int count =0;
    int n = vec.size();
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += vec[j];
            if(sum==target){
                count++;
                break;
            }
        }
    }
    return count;
}

//optimal o(n)
int optimalsubSum(vector<int> vec, int target){
    int count =0;
    int n= vec.size();
    int sum =0;
    int startIdx = 0;
    for(int i=0; i<n; i++){
        sum += vec[i];
        
        if(sum==target){
            count++;
            sum = sum-vec[startIdx];
            startIdx++;
        }else if(sum>target){
            while(sum>=target && startIdx<n &&startIdx!=i){
                sum = sum - vec[startIdx];
                startIdx++;
                if(sum==target){
                    count++;
                }
            }    
        }
    }
    return count;
}

int main()
{

    vector<int> arr={1,2,3};
    cout<<subSum(arr,3)<<endl;
    cout<<optimalsubSum(arr,3)<<endl;
    return 0;
}