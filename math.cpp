#include <iostream>
using namespace std;

//Prime
string isPrime(int n){
    if(n==1) return "Non prime";
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return "Non Prime";
    }
    return "Prime";
}

//Prime ( sieve of eratosthenes)
vector<bool> prime(int n){
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    int count = 0;
    for(int i=2; i<=n; i++){
        if(isprime[i]){
            count++;
            for(int j=i*2; j<=n; j=j+i){
                isprime[j] = false;
            }
        }   
    }
    return isprime;
}

//Diits of a no.
void printDigits(int n){
    int len = to_string(n).length();
    for(int i=0; i<len; i++){
        int digit = n%10;
        n /= 10;
        cout<<digit<<" ";
    }
    cout<<endl;
}

//Armstrong
bool armstrong(int n){
    int temp =n;
    int compNum = 0;
    int len = to_string(n).length();
    for(int i=0; i<len; i++){
        int digit = temp%10;
        
        compNum += digit*digit*digit;
       
        temp /= 10;
    }
    if(compNum == n) return true;
    else return false;
    
}

//reverse a no.
int reverse(int n){
    if(n==0) return 0;
    int rev = 0;
    while(n>0){
        int digit = n%10;
        rev = rev*10 + digit;
        n /=10;
    }
    return rev;
}

//palindrom
//method 1
bool palindrome(int n){
    if(n<0) return false;
    if(n==0) return true;
    int rev = reverse(n);
    if(rev==n) return true;
    else return false;
}

//method 2
bool palindrome2(int n){
    if(n<0) return false;
    if(n==0) return true;
    string str = to_string(n);
    int i=0;
    int j = str.length()-1;
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}

//GCD( VERY IMPORTANTTTT) [using euclid]
int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }else {
            b = b%a;
        }
    }
    if(a==0) return b;
    else return a;
}
//recusrsion(we will use this mostly)
int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

//LCM*GCD = num1*num2
int lcm(int a, int b){
    int gcd = GCD(a,b);
    return (a*b)/gcd;
}

int main()
{
    int num = 1;
    string ans = isPrime(num);
    cout<<ans<<endl;

    int n = 50;
    vector<bool> vec = prime(n);
    for(int i=0; i<vec.size(); i++){
        if(vec[i]) cout<<i<<" ";
    }
    cout<<endl;

    int x = 3489;
    printDigits(x);
    cout<<endl;

    //shortcut for digit count
    cout<<(int)log10(x) + 1<<endl;

    int nm = 371;
    cout<<armstrong(nm)<<endl;

    int nm1 = 1234;
    cout<<reverse(nm1)<<endl;

    int nm2 = 12321;
    cout<<palindrome(nm2)<<endl;
    cout<<palindrome2(nm2)<<endl;

    int a = 24, b=30;
    cout<<"GCD: "<<gcd(a,b)<<" and "<<GCD(a,b)<<endl;
    cout<<"LCM: "<<lcm(a, b)<<endl;
    
    return 0;
}