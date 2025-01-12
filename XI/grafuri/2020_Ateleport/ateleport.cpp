#include <bits/stdc++.h>

using namespace std;
ifstream in("ateleport.in");
ofstream out("ateleport.out");
const int NMAX = 10001;
const int KMAX = 11;
int cost[NMAX][KMAX];
bool isInQueue[NMAX][KMAX];

struct Path{
    int y;
    int c;
    bool teleportare;
};
struct  Node{
    int x;
    int teleportari;
};

struct compara{
    bool operator()(const Node &a,const Node &b)
    {
        return cost[a.x][a.teleportari] > cost[b.x][b.teleportari];
    }
};
priority_queue<Node, vector<Node>, compara> q;
vector <Path> v[NMAX];

int n,m,p,l,k;
void read(){
    in >> n >> m;
    in >> p >> l >> k;
    for(int i = 0 ; i < m ; i ++){
        int x, y, c;
        in >> x >> y >> c;
        v[x].push_back({y,c,0});
        v[y].push_back({x,c,0});
    }
}

void initCost(){
    for(int i = 0 ; i < NMAX; i ++){
        for(int j = 0 ; j <KMAX; j ++){
            cost[i][j] = INT_MAX;
        }
    }
}

void DijKstra(){
    q.push({1,0});
    cost[1][0] = 0;
    while(!q.empty()){
        Node nod = q.top();
        q.pop();
        isInQueue[nod.x][nod.teleportari] = false;
        for(auto neigh : v[nod.x]){
            int &oldCost = cost[neigh.y][nod.teleportari];
            int newCost = cost[nod.x][nod.teleportari] + neigh.c;
            if(newCost < oldCost && nod.teleportari + neigh.teleportare <= k){
                oldCost = newCost;
                if(!isInQueue[neigh.y][nod.teleportari] ){
                    isInQueue[neigh.y][nod.teleportari] = true;
                    q.push({neigh.y,nod.teleportari + neigh.teleportare});
                }

            }
        }
    }
}
void addEdges(int nodPrim){
    bool mask[n] = {};
    queue<pair<int, int>> q1;
    q1.push({nodPrim,0});
    while(!q1.empty()){
        auto current = q1.front();
        int nod = current.first;
        int distance = current.second;
        q1.pop();
        if(distance >= l)
            continue;
        
        for(auto neigh : v[nod]){
            if(neigh.teleportare == true)
                continue;
            if(mask[neigh.y] == false){
                q1.push({neigh.y,distance + 1});
                v[nodPrim].push_back({neigh.y,p,true});
            }
        }
    }

}
void addEdges(){
    for(int i = 1; i <= n ; i ++){
        addEdges(i);
    }
}


int main(){
    read();
    addEdges();
    initCost();
    DijKstra();

    int minCost = INT_MAX;
    for(int i = 0 ; i < KMAX; i ++){
        if(cost[n][i] < minCost){
            minCost = cost[n][i];
        }
    }
    out << minCost;
}