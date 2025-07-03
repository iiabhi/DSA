#include <iostream>
using namespace std;

//Brute Force to find all pairs
void printPairs(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        for(int j=i+1; j<vec.size(); j++){
            cout<<vec[i]<<","<<vec[j]<<" ";
        }
        cout<<endl;
    }
}

//to find target with the same approach
vector<int> findPairs(vector<int> vec, int target){
    vector<int> res;
    for(int i=0; i<vec.size(); i++){
        for(int j=i+1; j<vec.size(); j++){
            if(vec[i]+vec[j] == target){
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

//Optimized approach
vector<int> findPairsum(vector<int> vec, int target){
    vector<int> result;
    int i=0;
    int j= (vec.size())-1;
    while(i<j){
        if(vec[i]+vec[j] == target){
            result.push_back(i); //you can also pushback values (push_back(vec[i]))
            result.push_back(j);
            // return reuslt; //you can return res here if you want only one pair in ans. 
            i++; //if you return you dont need to write these lines but if you don't you need to write these lines!!. to stop from entering infinite loop. 
            j--;  
        } else if(vec[i]+vec[j] > target){
            j--;
            cout<<j<<" ";
        }else {
            cout<<i<<" ";
            i++;
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {1,2,3,4,5};
    printPairs(vec);
    int target = 6;

    cout<<"Result pair indices:"<<endl;
    for(int val:findPairs(vec,6)){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int value:findPairsum(vec,6)){
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;
}