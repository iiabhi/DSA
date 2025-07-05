#include <iostream>
using namespace std;

int peak(vector<int> vec){
    int st = 1; //st not 0 and end not n-1 cause, idx 0 and n-1 can never be answer if array is mountain
    int end = vec.size()-2;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(vec[mid-1]<vec[mid] && vec[mid+1]<vec[mid]) return mid;
        if(vec[mid-1]<vec[mid]){ // peak on right, mid on left
            st = mid+1;
        }else{
            end = mid-1; // peak on left, mid on right
        }
    }
    return -1;
}
int main()
{
    vector <int> vec = {1,2,3,4,3,2,1,0};
    int idx = peak(vec);
    if(idx>=0){
        cout<<"Index: "<<idx<<endl;
    }else{
        cout<<"NO element found"<<endl;
    }
    return 0;
}