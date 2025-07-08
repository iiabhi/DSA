#include <iostream>
using namespace std;
void swap(int &x, int&y){
    int temp =x;
    x=y;
    y=temp;
}

//brute force
void brute(vector<int> &vec){
    sort(vec.begin(),vec.end());
}

//optimized //two pass
void op(vector<int> &vec){
    int cnt1 =0, cnt2 = 0, cnt0 = 0;
    for(int val:vec){
        if(val == 0) cnt0++;
        else if(val == 1) cnt1++;
        else if(val == 2) cnt2++;
    }
    cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
    for(int i=0;i<cnt0; i++){
        vec[i] = 0;
    }
    for(int i=cnt0;i<(cnt1+cnt0); i++){
        vec[i] = 1;
    }
    for(int i=(cnt0+cnt1);i<(cnt0+cnt1+cnt2); i++){
        vec[i] = 2;
    }
}

//Dutch flag algo(3 pointer approach) //TC: O(n) //most optimal SC: O(1) //single pass
void array012(vector<int> &vec){
    int low =0, mid = 0, high = vec.size()-1;
    while(mid<=high){
        if(vec[mid]==0){
            swap(vec[low],vec[mid]);
            mid++;
            low++;
        }else if(vec[mid]==1){
            mid++;
        }else if(vec[mid]==2){

            swap(vec[high],vec[mid]);
           
            high--; //mid won't increment as el can be 0 or 1 (any)
        }else{
            cout<<vec[mid]<<endl;
            cout<<"Invalid Array Enetered"<<endl;
            return;
        }
    }
}

void printArray(vector<int> vec){
    for(int val:vec) cout<<val<<" ";
    cout<<endl;
}

int main()
{
    vector<int> arr = {1,0,2,2,0,0,1,0,2,1,0};
    printArray(arr);
    brute(arr);
    printArray(arr);

    vector<int> arr1 = {1,0,2,2,0,0,1,0,2,1,0};
    printArray(arr1);
    op(arr1);
    printArray(arr1);

    vector<int> arr2 = {1,0,2,2,0,0,1,0,2,1,0};
    printArray(arr2);
    array012(arr2);
    printArray(arr2);


    return 0;   
}