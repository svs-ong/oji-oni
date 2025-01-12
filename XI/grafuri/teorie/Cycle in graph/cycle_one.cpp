/**
 * Discover first graph that it meets
 * @brief https://codeforces.com/problemset/problem/263/D
 * support : https://www.geeksforgeeks.org/print-all-the-cycles-in-an-undirected-graph/
 * 
 */
#include <bits/stdc++.h>

using namespace std;

// ifstream in("cycle3.in");
// #define cin in
constexpr int NMAX = 100000;

enum Color{
    WHITE = 0,GRAY,BLACK
};
struct Cycle{
    int startNode,endNode, size;
};

int n,m,k;
vector <int> v[NMAX + 1];
Color visited[NMAX + 1];
int dad[NMAX + 1];
Cycle cycle;
queue<int> q;

void read(){
    cin >> n >>m >>k;
    for(int i = 0 ; i < m ; i ++){
        int x,y;
        cin >> x>> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void tryCycle(int startNode, int lastNode){
    int size = 1;
    int node = lastNode;
    while (node != startNode)
    {
        size++;
        node = dad[node];
    }
    if(size > k)
        cycle = {startNode, lastNode, size};
}


void dfs(int node){
    if(cycle.size >k)
        return;
    visited[node] = GRAY;
    for(auto neigh : v[node]){
        if(visited[neigh] == WHITE){
            dad[neigh] = node;
            dfs(neigh);
        }else if(visited[neigh] == GRAY && dad[node] != neigh){
            tryCycle(neigh, node);
        }
    }
    visited[node] = BLACK;  
    
   
}

void displayCycle(Cycle & cycle){
    int node = cycle.endNode;
    while (node != cycle.startNode)
    {
        cout << node << " ";
        node = dad[node];
    }
    cout << node;
    
}

int main(){
    read();
    for(int i = 1; i <= n; i ++){
        if(visited[i] == WHITE){
            dfs(i);
        }
    }
    int size = cycle.size;
    if(size > k){
        cout << size << "\n";
        displayCycle(cycle);
    }
    
}

