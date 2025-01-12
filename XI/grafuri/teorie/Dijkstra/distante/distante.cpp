//https://www.infoarena.ro/problema/distante

#include <bits/stdc++.h>
using namespace std;
///distante
/**
t- nr grafu
n noduri
m muchii
s nod sursa
dn++ cost calc de future coleg de camera la nebuni
dm++ nod nod cost
d[] dement calc
*/
#define pb push_back
#define cin in
#define cout out
int cost[50001],n,m,s,t;
bool masca[50001];

struct compara
{
    bool operator()(int x, int y)
    {
        return cost[x] > cost[y];
    }
};
priority_queue<int, vector<int>, compara> q;

ifstream in("distante.in");
ofstream out("distante.out");

int krusadi(int x, vector < pair<int,int> >v[])
{
    cost[x] = 0;
    q.push(x);
    int nod;
    while (!q.empty())
    {
        nod=q.top();
        q.pop();
        masca[nod]=false;

        for (auto coleg:v[nod])
        {
            int colegu=coleg.first;
            int chirie=coleg.second;
            
            if (cost[colegu] > cost[nod]+chirie)
            {
                cost[colegu] = cost[nod] + chirie;
                if (masca[colegu]==false)
                {
                    q.push(colegu);
                    masca[colegu]=true;
                }

            }
        }
    }
}

bool cit()
{
    int a,b,ca,d[50001];
    cin >> n>> m >> s;
    vector < pair<int,int> >v[n + 1];

    for (int i=1;i<=n;i++){
        cin>>d[i];
        cost[i] = INT_MAX;
    }
        
    for (int i=0;i<m;i++)
    {
        cin>> a >> b >> ca;
        v[a].pb(make_pair(b,ca));
        v[b].pb(make_pair(a,ca));
    }
    krusadi(s,v);

    bool aw=true;
    for (int i=1;i<=n;i++)
        if (d[i]!=cost[i])
            aw=false;
    return aw;
}

int main()
{
    cin>>t;
    for (int e=0; e<t; t--)
    {
        if(cit()){
            cout << "DA" <<'\n';
        }else{
            cout << "NU" <<'\n';
        }
    }
    return 0;
}