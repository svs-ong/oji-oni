#include <iostream>
#include <fstream>
#include <limits>
#include <climits>

using namespace std;
ifstream in("palindrom1.in");
ofstream out("palindrom.out");

const int NMAX = 500000;


unsigned long long getInv(unsigned long long num){
    unsigned long long inv = 0;
    while(num > 0){
        inv = inv * 10 + num % 10;
        num /= 10;
    }
    return inv;
}
bool isPalindrome(unsigned long long num) {
    return num == getInv(num);
}
int getCif(unsigned long long x){
    int k = 0;
    if(x % 10 == 0 && x != 0){
        while(x % 10 == 0)
            x/=10;
        while(x != 0){
            x /= 10;
            k++;
        }
        return k;
    }
    x = getInv(x);
    
    while(x > 0){
        if(isPalindrome(x)){
            return k;
        }
        x = x / 10;
        k++;
    }
}


int main()
{
    unsigned long long x;
    int C;
    int n,f=0,j=0,maxD=0;
    int S;
    in>>C;
    in>>n;
    in>>S;
    for(int i = 0;i<n;i++){
         cin >> x;
         f+= getCif(x);
    }
    out <<f;
    return 0;
}