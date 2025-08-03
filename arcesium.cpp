#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

/* 1 2 4 6 10
1 : 1 + 3 + 5 + 9 = 18
2: 1 + 2 + 4 + 8 = 15
4: 3 + 2 + 2 + 6 = 13
6: 5 + 4 + 2 + 4 = 15
10: 9 + 8 + 6 + 4 = 27
*/
int abs(int num){
    if(num>=0){
        return num;
    }else{
        return -num;
    }

}
int calcDist(vector<int> positions, int median){
    int n = positions.size();
    int dist = 0;
    for(int i=0;i<n; i++){
        dist += (abs(positions[i] - positions[median]));
    }
    return dist%MOD;
}


int solve(vector<int> positions, int n){
    
    if(n==1) return 0;
    sort(positions.begin(), positions.end());
    int medianVal1 = -1;
    int medianVal2 = -1;
    if(n%2 != 0){
        medianVal1 = positions[n/2];
        return calcDist(positions, medianVal1);
    }else{
        medianVal1 = positions[n/2];
        medianVal2 = positions[(n/2) -1];

        int dist1 =  calcDist(positions, medianVal1);
        int dist2 =  calcDist(positions, medianVal2);

        int minn = min(dist1, dist2);
        return minn;
    }

    
}


int main()
{
    vector<int> vec = {1,2,3,27,4,5,100};
    int n = 6;
    cout<<solve(vec, n)<<endl;

    return 0;
}