#include <iostream>
using namespace std;

string remove(string s, string part){
    int sz = part.length();
    while(s.length()>0 && s.find(part) < s.length()){
        int idx = s.find(part);
        s.erase(idx, sz);
    }
    return s;
}

int main()
{
    string s= "daabcbaabcbc";
    string part = "abc";
    string final = remove(s, part);

    cout<<final<<endl;
    


    return 0;
}