//https://www.infoarena.ro/problema/lgput
#include <iostream>
#include <fstream>


using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");
constexpr int h=1999999973;
int ridicare(int n,int p)
{
    
    int r=1;
    while(p!=0){
        if(p%3==1)r=(1LL*r*n)%h;
        else{
            if(p%3==2)r=(1LL*((1LL*r*n)%h)*n)%h;
        }
        n=(1LL*((1LL*n*n)%h)*n)%h;
        p=p/3;
    }
    return r;

}
// n ^ 0 = 1
// n ^ 8 = n^4 * n ^4 
// n ^ 9 = n ^ 4 * n^4 * n
int ridicare_la_putere2(int n, int exp){
    if(exp == 0)
        return 1;
    int rez = ridicare_la_putere2(n,exp/2);
    if(exp % 2 == 0){
        return rez * rez;
    }
    return rez*rez *n;
}
// n ^ 0 = 1
// n ^ 8 = (n*n)^4
// n ^ 9 = (n*n)^4*n
int ridicare_la_putere3(int n, int exp){
    if(exp == 0)
        return 1;
    if(exp % 2 == 0){
        return ridicare_la_putere3(n*n,exp/2);
    }
    return n*ridicare_la_putere3(n*n,exp/2);
}


int main()
{
    int p,n;
    in>>n>>p;
    out<<ridicare(n,p);
    return 0;
}