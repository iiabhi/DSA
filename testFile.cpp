#include <iostream>
using namespace std;

int colorsAlt(vector<int> colors, int k){
    int ans =0;
    int n = colors.size();
    bool isNotAlt = true;

    for(int i=0; i<n; i++){
        int p1 = i%n;
        int p2 = (i+1)%n;
        int count = 1;
        int j=0;
        for(j=0; j<n-1; j++){
            if(colors[p1] == (!(colors[p2]))){
                count++;
                
                p1 = (p1+1)%n;
                p2 = (p2+1)%n;
                if(isNotAlt && n%2==0){
                    if(count == n) return n;
                }
                cout<<"count: "<<count<<endl;
                if(count>=k){
                    ans++;
                    cout<<"ans: "<<ans<<endl;
                }
            }else{
                isNotAlt = false;
                break;
            }

        }
        
        if(j>i){
            i = j;
        }

        

    }
    return ans;

}

int main()
{
    // string str = "abc";
    // string str1 = "b";
    // auto it = str.find(str1);
   
    // cout<<it<<endl;
    // cout<<(!0)<<endl;

    vector<int> vec = {0,1,0,0,1};
    int k=3;
    cout<<colorsAlt(vec, k)<<endl;

    return 0;
}