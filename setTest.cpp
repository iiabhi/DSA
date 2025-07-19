#include <iostream>
#include<unordered_set>
#include<set>
using namespace std;
int main()
{

    set<string> s;
    s.emplace("1");
    s.emplace("2");
    s.emplace("1");
    for(auto x: s){
        cout<<x<<" ";
    }

    unordered_set<string> u_s;
    u_s.emplace("1");
    u_s.emplace("2");
    u_s.emplace("1");
    for(auto x: s){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0; i<5; i++){
        cout<<i<<" ::  ";
        cout<<" i loop ends here"<<endl;
        for(int j=6; j<10; j++){
            cout<<j<<" ::  ";
            cout<<" j loop starts here"<<endl;
            if(j==7){
                cout<<" checkpoint"<<endl;
                continue;
            }

            cout<<"j loop ends here"<<endl;
        }
    }

    

    return 0;
}