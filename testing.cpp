#include <iostream>
#include<stdio.h>
using namespace std;
struct car{
    int num;
    const char* name;
    double price;


}c1, c2;
int main()
{
    c1.num = 0;
    c2.num = 1;

    c1.name = "car0";
    c2.name = "car2";

    printf("%d", c1.num);
    printf("%s", c1.name);


    
    printf("%lu", sizeof(c1));
    return 0;
}