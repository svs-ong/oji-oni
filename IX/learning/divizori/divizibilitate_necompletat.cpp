#include <bits/stdc++.h>

using namespace std;

//check if a number is prim
bool isPrime(int num) {
    if(num < 2)
        return false;
    for(int i = 2; i <= sqrt(num); i ++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
//get all dividers of a number
void getAllDividers(int v[], int &n, int x){
    n = 0;
    int i;
    for(i = 1; i < sqrt(x); i ++){
        if(x % i == 0){
            v[n++] = i;
            v[n++] = x / i;
        }
    }
    if(i * i == x)
        v[n++] = i;
    sort(v, v + n);
}

//divide x prin divider cat de mult poate
//! divider-ul trebuie sa fie diferit de 0 si de 1
int divide(int &x, int divider){
    int exp = 0;
    while(x % divider == 0){
        x = x / divider;
        exp++;
    }
    return exp;
}
//stocheaza toate numerele prime prin care se divide x in v
//! nu ii da numere mai mici ca 1
void getprimiDivisors(int v[], int &n, int x) {
    n = 0;
    if(divide(x,2) > 0)
        v[n++] = 2;
    for(int i = 3; i <= sqrt(x); i+=2){
        if(divide(x,i) > 0){
            v[n++] = i;
        }
    }
    if(x != 1)
        v[n++] = x;
}

int cmmdc(int a, int b){
    
}
void Eratostene(bool v[], int xMAx){
    
}

int main()
{
    int n = 37, v[30];
    getprimiDivisors(v,n,2048);
    for(int i = 0 ; i < n ; i ++){
        cout << v[i] << " ";
    }
    return 0;
}