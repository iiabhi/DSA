#include <iostream>
#include <vector>
using namespace std;

// I will explain the whole Process including every approach and thinking process.

//Ques: To find max subarray sum.

//First we need to print every subarray of a array.
//if No. of element = N, then no. of subarray = (N(N+1))/2
//TC: O(n^3)
//Brute Force
void subArr(int arr[], int size){
    for(int st=0; st<size; st++){
        for(int end = st; end<size; end++){
            for(int i=st; i<=end; i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

//Now, finding Max subarray sum(BRUTE FORCE) TC: O(n^2)

int subArrSum(int arr[], int size){
    int maxSum = INT_MIN;
    for(int st=0; st<size; st++){
        int currSum = 0;
        for(int end = st; end<size; end++){
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

//Now, we will used kadane algo. Leetcode : 53
//TC : O(n)
//INTUITION: How sum of two digits work.
// +ve + +ve = +ve
// -ve + +ve(big no.) = +ve
// +ve + -ve(big no.) = -ve
// Thus, when adding a no. makes the whole negative, make currsum = 0(reset the sum)

int kadane(vector<int> arr){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int val: arr){
        currSum += val;
        maxSum = max(maxSum, currSum);
        if(currSum<0){
            currSum = 0;
        }
    }
    return maxSum;
}




int main()
{
    int arr[5] = {1,2,3,4,5};
    subArr(arr,5);

    cout<<subArrSum(arr, 5)<<endl;;
    cout<<endl;

    vector<int> vec = {-1,2,-4,7,1,-10,1};
    vector<int> vec1 = {1,2,3,4,5};
    int res = kadane(vec);
    
    cout<<res<<endl;
    cout<<kadane(vec1)<<endl;;
    return 0;
}