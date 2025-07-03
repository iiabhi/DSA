#include <iostream>
using namespace std;

//Full explanation with all approach (LC: 169)
//Assume each array has a majority element(freq greater than n/2. n->size of array)

//Brute force: count frq for each element and return the maximun freq element
int bruteMJ(vector<int> vec){
    int n = vec.size();
    for(int val:vec){
        int freq = 0;
        for(int el: vec){
            if(el == val){
                freq++;
            }
        }
        if(freq> (n/2)){
            return val;
        }
    }
    return -1; // this would never execute as mj always exist but for the sake of simplicity
}

//Optimized approach, using sorting.(O(nlogn))
int optMJ(vector<int> vec){
    int n = vec.size();
    sort(vec.begin(),vec.end()); //to sort a vector //nlogn
    int freq = 1;
    int res = vec[0];
    for(int i = 1; i<n; i++){
        if(vec[i] == vec[i-1]){
            freq++;
        }else{
            freq = 1;
            res = vec[i];
        }
        if(freq>(n/2)){
            return res;
        }
    }
    return -1;
}

//Moore's Algo
//Intution (if we add frq for the same no. and minus for diff no. and everytime we hit zero freq we make that no. the MJ, it will work)
//WHY? the MJ will always make the freq positive, and if we assumed mj to be some other no, then mj will surely make freq 0 and becomes the mj.
int mooreAlgo(vector<int> vec){
    int freq = 0;
    int res;
    for(int i=0; i<vec.size(); i++){
        if(freq==0){
                res = vec[i];
            }
        if(vec[i]==res){
            freq++;
        }else{
            freq--;
        }
    }
    return res;

}


int main()
{
    vector<int> vec = {1,2,1,1,1,3,1,3,4,1};
    cout<<"Majority Element: "<<bruteMJ(vec)<<endl;

    cout<<"Majority Element: "<<optMJ(vec)<<endl;

    cout<<"Majority Element: "<<mooreAlgo(vec)<<endl;
    return 0;
}