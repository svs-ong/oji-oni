#include <bits/stdc++.h>
using namespace std;


void exempleImplementate(){
    // LOWER_BOUND: 
    int v[] = {1,3,3,3,5};
    int n = sizeof(v)/ sizeof(v[0]);
    int p1 = lower_bound(v, v + n, 3) - v;
    int p2 = lower_bound(v, v+n, 2) - v;
    int p3 = lower_bound(v, v+n, 4) - v;
    int p4 = lower_bound(v, v+n, 10) - v;
    int p5 = lower_bound(v, v+n, 0) - v;
    cout << p1<<" "<<p2 << " " <<p3 << " "<<p4<< " "<<p5;
    
    cout << "\n-------------------\n";
    p1 = upper_bound(v, v + n, 3) - v;
    p2 = upper_bound(v, v+n, 2) - v;
    p3 = upper_bound(v, v+n, 4) - v;
    p4 = upper_bound(v, v+n, 10) - v;
    p5 = upper_bound(v, v+n, 0) - v;
    cout << p1<<" "<<p2 << " " <<p3 << " "<<p4<< " "<<p5;
}

//Cautare binara dupa primul element >= x
int lowerBound(int v[], int n, int x){

}

//Cautare binara dupa primul element > x
int upperBound(int v[], int n, int x){

}

long long division3(long long x){
    return x/3;
}
long long division4(long long x){
    return x/4;
}
using Function = long long (*)(long long);

//Cautare binara cel mai mare i pentru care f(i) <= x
long long lowerBound(Function f, long long x)
{
    for(long long i = 0 ; i < x; i ++){
        cout << f(i)<<" ";
    }
}
//Cautare binara cel mai mic i pentru care f(i) >= x
int upperBound(Function f, long long x){

}

int main(){
    exempleImplementate();
}