#include <iostream>
using namespace std;
int main()
{
    //Bitwise AND
    cout<<(10 & 2)<<endl; //1010 & 0010 == 0010 (2)
    cout<<(8 & 12)<<endl; //1000 & 1100 == 1000 (8)

    //Bitwise OR
    cout<<(10 | 2)<<endl; //1010 | 0010 == 1010 (10)
    cout<<(9 | 12)<<endl; //1001 | 1100 == 1101 (13)

    //Bitwise XOR
    cout<<(11 ^ 2)<<endl; //1011 & 0010 == 1001 (9)
    cout<<(8 ^ 5)<<endl; //1000 & 0101 == 1101 (13)

    //Bitwise Left
    cout<<(50<<2)<<endl; //left shift by two places (multiply by 4(2^2))
    for(int i=1; i<5; i++){
        cout<<(64<<i)<<" "; //you will see the output , each term will get multiply by 2^i
    }
    cout<<endl;

    //Bitwise Right
    cout<<(40>>2)<<endl; //left shift by two places (divide by 4(2^2))
    for(int i=1; i<5; i++){
        cout<<(64>>i)<<" "; //you will see the output , each term will get divide by 2^i
    }
    cout<<endl;

    //But when << and >> , these operator are used in context of IO streams,
    //  overloaded in the i/ostream class to give/take a value and insert in the stream
    cout<<"IO stream"<<endl;
    int x= 0;
    // cin>>x;

    //operator precedence
    // () []
    // ++ --
    // ! + - (unary)
    // * / %
    // + - 
    // << >>
    // < <= > >=
    // == != (equals)
    // & (bitwise AND)
    // ^ (bitwise XOR)
    // | (bitwise OR)
    // && (AND)
    // || (OR)
    // ?: (ternanry)
    // = (assignment)
    // , (comma)
    
    //example
    cout<<(5*5%2)<<endl; //sol: 1 (not 5)


    return 0;
}