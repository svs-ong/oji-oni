/**
 * https://www.pbinfo.ro/probleme/4116/superhedgy
*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
ifstream in("superhedgy1.in");
ofstream out("superhedgy.out");

#define mp make_pair
#define fi first

constexpr int NMAX = 100000;
constexpr int MAX_NODES = NMAX*2 + 2;

struct Edge{
    int nodA;
    int cost;
};
struct Block
{
    int L, H, E;
};

queue<int> q;
vector<Edge> v[200003];
int nodes, cost[MAX_NODES], l, node;

inline int getCost(const Block &a,const Block &b){
    return abs(a.H -b.H);
}


int cit()
{
    int n, m;
    vector<Block> v1,v2;
    //up
    in >> n;
    Block x;
    in>> x.L >> x.H >> x.E;
    v[0].push_back({1, x.H});//start to node 1
    v1.push_back(x);
    for(int i = 1 ; i < n; i ++){
        in>> x.L >> x.H >> x.E;
        x.L += v1.at(i-1).L;
        v1.push_back(x);
        int c = getCost(v1.at(i-1),v1.at(i));
        v[i].push_back({i +1,c});
    }

    //down
    in >> m;
    in>>x.L>>x.H>>x.E;
    v[0].push_back({n+1, x.H});//start to node n+1
    v2.push_back(x);
    for(int i = 1 ; i < m; i ++){
        in>>x.L>>x.H>>x.E;
        x.L += v2.at(i-1).L;
        v2.push_back(x);
        int c = getCost(v2.at(i-1),v2.at(i));
        v[n+i].push_back({n+i+1,c});
    }

    nodes = n + m + 2;
    v[n].push_back({n+m+1, v1.at(n-1).H});
    v[n+m].push_back({n+m+1, v2.at(m-1).H});


    //between
    int  i = 0 , j = 0;
    while(i < n && j < m){
        int nodUp = i + 1;
        int nodDown = n + j + 1;
        int cost = v1.at(i).E + v2.at(j).E;
        v[nodUp].push_back({nodDown, cost});
        v[nodDown].push_back({nodUp, cost});
        int w1 = v1.at(i).L;
        int w2 = v2.at(j).L;
        if(w1 < w2){
            i++;
        }else if(w1 > w2){
            j++;
        }else{
            i++;
            j++;
        }
    }
    return v1.at(n-1).L;
}

void disk()
{
    q.push(0);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (auto neigh_pair : v[node])
        {
            int neigh = neigh_pair.nodA;
            int c = neigh_pair.cost;
            if (cost[neigh] == 0 || cost[neigh] > cost[node] + c)
            {
                cost[neigh] = c + cost[node];
                q.push(neigh);
            }
        }
    }
}

int main()
{
    l = cit();
    for(int i  = 0; i < nodes; i ++){
        cout << i << " : ";
        for(auto e : v[i]){
           cout <<"(" << e.nodA << " "<<e.cost <<") ";
        }
        cout <<'\n';
    }

    disk();
    cout << cost[nodes-1] + l;
    return 0;
}