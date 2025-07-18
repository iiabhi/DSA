#include <iostream>
#include<string>
using namespace std;


int solve(string str){
   
    
    int totalLen = str.length();
    int len = str.length();
    int count =0;
    while(len>0){
        char digit = str[len-1];
        str = str.substr(0,--len);
        if(digit!='0'){
            while(len>0){
                char dig = str[len-1];
                str = str.substr(0,--len);
                if(dig=='0'){
                    count++;
                }
            }
        }
            
    }
    return totalLen-count-1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        cout<<solve(n)<<endl;
        

        
    }
    return 0;
}