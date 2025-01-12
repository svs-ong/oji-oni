
#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100000;

enum Color{
    WHITE = 0,GRAY,BLACK
};
int n,m,k;
vector <int> v[NMAX + 1];
Color visited[NMAX + 1];
int dad[NMAX + 1];

void read(){
    cin >> n >>m >>k;
    for(int i = 0 ; i < m ; i ++){
        int x,y;
        cin >> x>> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void dfs(int start){
    visited[start] = GRAY;
    for(auto neigh : v[start]){
        if(visited[neigh] == WHITE){
            dad[neigh] = start;
            dfs(neigh);
        }else if(visited[neigh] == GRAY){
            cout << 
        }
    }
    visited[start] = BLACK;
}

int main(){
    read();
    dfs(1);


}

