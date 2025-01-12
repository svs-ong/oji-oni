//https://www.infoarena.ro/problema/cautbin
#include <fstream>

using namespace std;
ifstream in ("cautbin.in");
ofstream out ("cautbin.out");

int v[100001], n, i, intrebari, x, tip;
int cautbinar1(int x)
{
    int st=1;
    int dr=n;
    int nr=-1, mij;
    while(st<=dr)
    {
        mij=(dr+st)/2;
        if(v[mij]==x)
        {
            nr=mij;
            st=mij+1;
        }
        else if(v[mij]>x)
            dr=mij-1;
        else if(v[mij]<x)
            st=mij+1;
    }
    return nr;
}
int cautbinar2(int x)
{
    int st=1;
    int dr=n;
    int nr, mij;
    while(st<=dr)
    {
        mij=(dr+st)/2;
        if(v[mij]<=x)
        {
            st=mij+1;
            nr=mij;
        }
        else dr=mij-1;
    }
    return nr;
}
int cautbinar3(int x)
{
    int st=1;
    int dr=n;
    int nr, mij;
    while(st<=dr)
    {
        mij=(dr+st)/2;
        if(v[mij]>=x)
        {
            dr=mij-1;
            nr=mij;
        }
        else st=mij+1;
    }
    return nr;
}

int main()
{
    in >> n;
    for(i=1;i<=n;i++)
        in >> v[i];
    in >> intrebari;
    for(i=1;i<=intrebari;i++)
    {
        in >> tip >> x;
        if(tip==0)
            out << cautbinar1(x) << '\n';
        else if(tip==1)
            out << cautbinar2(x) << '\n';
        else if(tip==2)
            out << cautbinar3(x) << '\n';
    }
    return 0;
}