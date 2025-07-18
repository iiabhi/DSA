#include <iostream>
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

    return 0;
}