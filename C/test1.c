#include <stdio.h>

unsigned int reverseHex(unsigned int num) {
    unsigned int rev = 0;
    while(num>0){
        unsigned int digit = num & 0xF;
        rev = (rev<<4) | digit;
        num = num>>4;
    }
    return rev;
}

int main() {
    unsigned int n = 0xABCDE;
    unsigned int result = reverseHex(n);
    printf("Original: 0x%X\n", n);
    printf("Reversed: 0x%X\n", result);
    return 0;
}
