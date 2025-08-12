#include <iostream>
using namespace std;
int main()
{
    int i=0;
    for(i=0; i<10; i++){
        while(i<5){
            i++;
            cout<<"here"
            if(i==3) break;
        }
    }
    cout<<i<<endl;
    return 0;
}