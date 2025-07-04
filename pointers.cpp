#include <iostream>
using namespace std;

//Adress of - operator : &
//Address in hexadecimal form

void changenum(int* ptr){
    *ptr = 20;
}

void change(int &x){
    x= 20;
}

int main()
{
    int a = 5;
    cout<<&a<<endl;

    //Pointers
    int b = 5;
    int* ptr = &b; //we passed the address of a.
    cout<<&b<<"  "<<ptr<<endl; //both will have same address, ptr will have adress of b as a value
    cout<<*ptr<<endl; //* refers to the value of variable at address stored in ptr(de-refrencing)

    int** ptr2 = &ptr;
    cout<<ptr2<<"  "<<&ptr<<endl;
    cout<<*ptr2<<"  "<<**ptr2<<endl;
    cout<<*(&a)<<"  "<<*(&b)<<endl;

    //NULL pointer
    int* pointerA;
    int* nullPtr = NULL;
    cout<<pointerA<<"  "<<nullPtr<<endl;
    

    //Pass by reference (using pointer)
    int num = 10;
    cout<<num<<" ";
    changenum(&num);
    cout<<num<<endl;

    //pass by refrence(using alias)
    int number = 10;
    cout<<number<<" ";
    change(number);
    cout<<number<<endl;

    //Array Pointers
    int arr[]= {1,2,3,4,5};
    int an = 2;
    // arr = &a; //this is not possible as arr is a CONSTanT pointer ans its value cant be changed
    cout<<arr<<" "<<arr+1<<" "<<arr+2<<" "<<arr+3<<endl; //increase by 4B (1 int )
    cout<<*arr<<" "<<*(arr+1)<<" "<<*(arr+2)<<" "<<*(arr+3)<<endl;

    int* ptrx = &num;
    ptrx++;
    cout<<(ptrx)<<endl;
    ptrx--;
    cout<<(ptrx)<<endl;

    int* ptrxx = &b;

    cout<<ptrxx<<"  "<<ptrx<<endl;
    cout<<ptrxx - ptrx<<endl; //no of int ( no of bytes diff / 4)



    return 0;

}