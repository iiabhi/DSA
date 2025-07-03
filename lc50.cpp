#include <iostream>
using namespace std;

//start
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long binform = n;
        if(n<0){
            binform = -binform; //we cant right -n (as for edge case -2^31 can be computer with n, as largest =ve value can be (2^31 - 1))
            x = 1/x;
        }

        while( binform>0){
            if(binform%2 == 1 || binform%2 == -1){
                res *= x;
            }
            x *= x;
            binform /= 2;
        }
        return res;
    }
};
//end

int main()
{
    return 0;
}