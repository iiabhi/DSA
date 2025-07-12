#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
    
    int st = 0;
    int end = str.length() - 1 ;
    while(st<end){
        if(str[st] != str[end]) return false;

        st++; end--;
    }
    return true;
}

bool isValidPalindrome(string s) {
        int st =0;
        int end = s.length() - 1;
        while(st<end){
            if(!(isalnum(s[st]))){
                st++; 
                continue;
            } 
            if(!(isalnum(s[end]))){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

int main()
{
    string s = "0P";
    cout<<isValidPalindrome(s)<<endl;
    return 0;
}