#include <iostream>
using namespace std;

//find each container volume and take out the max.
//brute force TC: )(n^2)
int container(vector<int> vec){
    int maxx = 0;
    for(int i=0; i<vec.size(); i++){
        for(int j=i+1; j<vec.size(); j++){
            int height = min(vec[i],vec[j]);
            int width = j-i;
            int volume = height*width;
            maxx = max(maxx, volume);
        }
    }
    return maxx;
}

//optimized(twopointer approach)
int containerOpt(vector<int> vec){
    int maxx=0;
    int i=0;
    int j= vec.size()-1;
    while(i<j){
        int height = min(vec[i],vec[j]);
        int width = j-i;
        int volume = height*width;
        maxx = max(maxx, volume);
        if(vec[i]<vec[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxx;
}

int main()
{
    vector<int> vec={1,8,6,2,5,4,8,3,7};
    cout<<"Max volume: "<<container(vec)<<endl;
    cout<<"Max volume: "<<containerOpt(vec)<<endl;
    return 0;
}