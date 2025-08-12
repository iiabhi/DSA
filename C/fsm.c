#include<stdio.h>
#include<unistd.h>

typedef enum{
    RED, //0
    GREEN, //1
    YELLOW //2
}State;


int main(){

    State current = RED;

    int cycle = 25;

    while(cycle>0){
        switch(current){
        case RED:
            printf("RED");
           
            sleep(1);
            break;

        case GREEN:
            printf("GREEN");
    
            sleep(1);
            break;
        case YELLOW:
            printf("YELLOW");
           
            sleep(1);
            break;  
        }
        
        cycle--;
    }
    
    return 0;
}