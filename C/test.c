#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>


//set of bit manipulation functions.

#define SET_BIT(x, b) (x = x|(1U<<b));
#define CLEAR_BIT(x, b) (x= x&(~(1U<<b)));
#define TOOGLE_BIT(x, b) (x = x^(1U<<b));
#define CHECK_BIT(x, b) ((x>>b)&1U);



bool power2(int x){
    if(x<=0) return false;
    return x && !(x&(x-1));
}
 
void swap(int* a, int* b){
    *a = *a^*b;
    *b = *b^*a;
    *a = *a^*b;
    
}

int reverse(int num){
    int rev = 0;
    while(num>0){
        rev = rev<<1;
        rev = rev|(num&1);
        num= num>>1;
    }
    return rev;
}
unsigned int revHex(unsigned int hexVal){
    unsigned int rev = 0x0;
    while(hexVal>0){
        unsigned int digit = hexVal &0xF;
        rev = (rev<<4) | digit;
        hexVal = hexVal >>4;
    }
    return rev;


}


int main(){
    //to count no. of ones:

    int x = 0b101011;
    int count = 0;

    while(x){
        x= x&(x-1);
        count++;
    }
    printf("%d", count);
    printf("\n");


    int y = 8;
    bool val = power2(y);
    if(val){
        printf("power of 2");
    }else{
        printf("not a power of 2");
    }

    printf("\n");
    int a = 2;
    int b = 3;
    printf("%d and %d", a, b);
    printf("\n");
    swap(&a, &b);
    printf("%d and %d", a, b);
    printf("\n");

    int num = 12;
    int isolate = num&(-num);
    printf("%d",  isolate );
    printf("\n");
    int number = 0b10110;
    unsigned int hexaNumber = 0x12AB;
    printf("%x", hexaNumber);
    printf("\n");

    int sol = reverse(number);
    printf("%d",  sol );
    printf("\n");

    unsigned int reverse = revHex(hexaNumber);
    printf("%x",  reverse);
    printf("\n");

    return 0;
    

}

