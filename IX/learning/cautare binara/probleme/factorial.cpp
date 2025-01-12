//https://www.infoarena.ro/problema/fact
#include <bits/stdc++.h>
using namespace std;

int zeros(int x){
    int ctr = 0;
    while(x != 0){
        x = x/5;
        ctr += x;
    }
    return ctr;
}
int search1(int p){
    if(p == 0)
        return 1;
    for(int i = 5; i <= INT_MAX; i+=5){
        int zrs = zeros(i);
        if(zrs== p){
            return i;
        }else if(zrs > p)
            return -1;
    }
    return -1;
}

int search(int p)
{
    int cnt;
    if(p==0)
    {
        return 1;
    }
    int st=5, dr=INT_MAX;
    while(st<dr)
    {
        int mj=(st+dr)/2;
        cnt= zeros(mj);
        if(cnt<p)
        {
            st=mj+1;
        }
        else if(cnt>p)
        {
            dr=mj-1;
        }
        else
        {
            dr=mj;
        }
    }
    return st;
}
int main()
{
    ifstream in("fact.in");
    ofstream out("fact.out");
    int p;
    in >> p;
    int res = search(p);
    if(zeros(res) == p){
       out << res; 
    }else{
        out << -1;
    }
    

    return 0;
}