#include <iostream>
using namespace std;

bool interleave(string s, string t, string final){
    if(s.length()+t.length() != final.length()) return false;

    
    


}

int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout<<interleave(s1,s2,s3)<<endl;
    
    
    return 0;
}