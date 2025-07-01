#include <iostream>
using namespace std;
int main()
{
    cout<<sizeof(int)<<endl; //4 bytes
    cout<<sizeof(long int)<<endl; //8bytes
    cout<<sizeof(long long int)<<endl; //8bytes (in mac)( can be more in windows and depends on system design)
    cout<<sizeof(long long)<<endl; //8 bytes
    cout<<sizeof(short int)<<endl; //2bytes

    cout<<sizeof(unsigned int)<<endl; //no msb is used for sign, all 32 bits are treated as magnitude //4 bytes

    unsigned int x = -10; // here 32th bit will become 1
    cout<<x<<endl; //but this will print the corr. magnitude (as no concept of. negative num, compiler wont reverse compute(2's complement))

    return 0;
}