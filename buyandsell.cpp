#include <iostream>
using namespace std;
int buysell(vector<int> vec){
    int maxx= 0;
    int bestBuy = vec[0];
    for(int i=1; i<vec.size(); i++){
        if(vec[i]>bestBuy){
            maxx = max(maxx, vec[i] - bestBuy);
        }
        bestBuy = min(bestBuy, vec[i]);
    }
    return maxx;
}
int main()
{
    vector<int> vec = {7,1,3,6,4,5};
    cout<<buysell(vec);
    cout<<endl;
    return 0;
}