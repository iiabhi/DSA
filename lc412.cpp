#include <iostream>
#include <vector>
using namespace std;

//Solution
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for(int i=1; i<=n; i++){
            string s="";
            if(i%3==0){
                s = s+"Fizz";
            }if(i%5==0){
                s = s+"Buzz";
            }if(s == ""){
                s = to_string(i);
            }
            result[i-1] = s;
        }
        return result;
    }
};
//END

int main()
{
    return 0;
}