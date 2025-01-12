#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <fstream> 
using namespace std;
ifstream in("primprim.in");
ofstream out("primprim.out");
#define cin in
#define cout out

const int NMAX = 1000000;
bool ciur[NMAX + 1];
int v[NMAX + 1];
int mod[NMAX + 1];

void setare_ciur()
{
    ciur[0]=ciur[1]=1;
    for(int i=2; i*i <= NMAX; i++)
    {
        if(ciur[i]==0)
        {
            for(int j=i*i; j<=NMAX; j=j+i)
            {
                ciur[j]=1;
            }
        }
    }
}

int calc_cost(int a)
{
    int cost=1000000;
    int cost_nou=0;
    for(int i=2; i<1000000; i++)
    {
        if(ciur[i]==0)
        { 
            cost_nou=abs(a-i);
            if(cost_nou<cost)
            {
                cost=cost_nou;
            }
            else
            {
                break;
            }
        }
    }

    return cost;
}

void sorteazaV(int n){
    for(int i = 0 ; i < n - 1;i++ ){
        for(int j = i; v[j] > v[j+1]; j-- ){
            swap(v[j],v[j+1]);
        }
    }
}
int main()
{
    setare_ciur();
    int n, c, sum=0, o, q;
    cin >> c >> n;
    for(int t=0; t<n; t++)
    {
       cin >> v[t];
    }
    if(c==1)
    {
        for(int t=0; t<n; t++)
        {
            sum=sum+calc_cost(v[t]);
        }
        cout << sum;
    }
    else
    {
        // cin >> q;
        // int p, x, i;
        // for(int j=0; j<q; j++)
        // {
        //     cin >> i >> x >> p;
        //     cout << i << " "<<x<<" "<<p<<"\n";
        //     v[i-1]=x;
        //     // sorteazaV();
        //     for(int r=0; r<n; r++)
        //     {
        //         cout << v[r] << " ";
        //     }
        //     cout << endl;
        //     for(int y=0; y<n; y++)
        //     {
        //         mod[y]=calc_cost(v[y]);
        //         cout  << mod[y] << " ";
        //     }
            
        //     cout << "\n\n";
        // }
    }
    return 0;
}