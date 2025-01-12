#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
//https://www.infoarena.ro/problema/dijkstra
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");


const int NMAX = 100001;

//nod, cost to nod
vector<pair <int, int> >v[NMAX];
int cost[NMAX];
bool isInQueue[NMAX];

struct compara
{
    bool operator()(int x, int y)
    {
        return cost[x] > cost[y];
    }
};
priority_queue<int, vector<int>, compara> q;
int n, m;

void reading(){
    in>> n>> m;
    for (int i = 0; i < m; i++){
        int x, y, c;
        in>> x >> y >> c;
        v[x].push_back(make_pair(y,c));
    }
    
}

// void Dijkstra(int startNode){
//     q.push(startNode);
//     while(!q.empty()){
//         int nod = q.top();
//         q.pop();
//         masca[nod] = false;
//         for (auto neigh_pair : v[nod]){
//             int neigh = neigh_pair.first;
//             int c = neigh_pair.second;

//             if(cost[neigh] == 0){
//                 cost[neigh] = cost[nod] + c;
//                 if(!masca[neigh]){
//                     masca[neigh] = true;
//                     q.push(neigh);
//                 }
//             }
//         }
//     }
// }

void Dijkstra(int start){
    for(int i = 1; i <= n ; i ++)
        cost[i] = -1;

    q.push(start);
    cost[start] = 0;
    while(!q.empty()){
        int nod = q.top();
        q.pop();
        for(pair<int , int> neigh_pair : v[nod]){
            int neigh = neigh_pair.first;
            int c = neigh_pair.second;
            if(cost[neigh] == -1){
                cost[neigh] = cost[nod] + c;
                q.push(neigh);
            }
        }
    }
}


void output(){
    for (int i = 2; i <= n; i++){
        out << cost[i] << " ";
    }
}

int main(){
    reading();
    Dijkstra(1);
    for(int i = 1; i <= n ; i ++){
        cout << cost[i] << " ";
    }
    output();
}