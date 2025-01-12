// https://www.infoarena.ro/problema/aquapark
#include<bits/stdc++.h>

using namespace std;
ifstream fin ("aquapark.in");
ofstream fout("aquapark.out");
const int MMAX = 100005, mod=666013;

struct Edge
{
    int tip, nodA, nodB, ind;
};
vector<pair<int,int>> edges;
vector<Edge> events;
vector<int> w[MMAX];
int T, N, M, cul[MMAX], nrcomp;

bool comp(Edge &A, Edge &B){
    if(A.nodA != B.nodA)
        return A.nodA < B.nodA;
    if(A.tip != B.tip)
        return A.tip>B.tip;
    return A.nodB>B.nodB;
}

void dfs(int nod, int c){
    cul[nod]=c;
    for(auto urm: w[nod]){
        if(cul[urm]==0)
            dfs(urm,3-c);
    }
}

int main()
{
    fin>>T>>N>>M;

    int x, y;
    for(int i=0;i<M;i++){
        fin>>x>>y;
        if(x>y) swap(x,y);
        events.push_back({0,x,y,i});
        events.push_back({1,y,x,i});
        edges.push_back({x,y});
    }
    sort(events.begin(),events.end(),comp);

    stack<Edge> st;
    for(int i=0;i<2*M;i++){
        if(events[i].tip==0)
            st.push(events[i]);
        else{
            Edge last={0,0,0,0};
            while(!st.empty() and st.top().nodA>events[i].nodB){
                last=st.top();
                w[events[i].ind].push_back(st.top().ind);
                w[st.top().ind].push_back(events[i].ind);
                st.pop();
            }
            if(!st.empty() and st.top().ind==events[i].ind)
                st.pop();
            if(last.nodA!=0)
                st.push(last);
        }
    }

    for(int i=0;i<M;i++){
        if(cul[i]==0){
            nrcomp++;
            dfs(i,1);
        }
    }

    if(T==1){
        for(int i=0;i<M;i++)
            fout<<edges[i].first<<' '<<edges[i].second<<' '<<cul[i]<<'\n';
        return 0;
    }
    int sol=1;
    for(int i=1;i<=nrcomp;i++)
        sol=(sol*2)%mod;
    fout<<sol;

    fin.close();
    fout.close();
    return 0;
}