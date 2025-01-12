#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define cin in
// #define cout out
#define float double
ifstream in("desen.in");
ofstream out("desen.out");
struct Edge
{
    int nodA,nodB;
    float c;
};
struct Nod{
    int x, y;
};
int i,n,m,dad[1001];
Nod N[1001];
Edge M[499500];

queue<float>qu;


float getDistance(Nod &a,Nod&b){
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy *dy);
}

void daddupalapte(int x,int dad[])
{
    for (int h=0;h<x;h++)
        dad[h]=h;
}

bool compi(Edge &a,Edge &b)
{
    return a.c<b.c;
}

int getdad(int x)
{
    if (x==dad[x])
        return x;
    dad[x]=getdad(dad[x]);
    return dad[x];
}

void addEdges(int i){
    for(int j = 0; j <i; j ++){
        M[m++] = {j,i,getDistance(N[i],N[j])};
    }
}
void displayEdges(){
    for(int i = 0 ; i < m ;i ++){
        cout << M[i].nodA << " "<<M[i].nodB << " "<<M[i].c<<endl;
    }cout << endl;
}
float krusc(int n){
    cout << "----------------------------\n";
    displayEdges(); 
   float maxi = 0;
   for(int i = 0;i <n; i++){
        dad[i] = i;
   }
   for(int i = 0; i < m; i ++){
     int dadx=getdad(M[i].nodA);
     int dady=getdad(M[i].nodB);
     if (dadx!=dady)
     {
        maxi+=M[i].c;
        dad[dadx]=dady;
        cout << M[i].nodA << " " << M[i].nodB<< " "<<M[i].c << " " << maxi<<"\n";
    }
   }
   return maxi;
}


void cit()
{
    int x,y;
    cin>>n;
    displayEdges();
    for (i=0;i<n;i++)
    {
        dad[i]=i;
        cin>>x>>y;
        N[i]= {x,y};

        addEdges(i);
        sort(M,m+M,compi);
        // displayEdges();
        float maxi = krusc(i);
        out << maxi<<'\n';
    }
}

int main()
{
    cit();
    // while (!qu.empty())
    // {
    //     cout<<qu.front()<<'\n';
    //     qu.pop();
    // }
    return 0;
}