#include <bits/stdc++.h>

using namespace std;
ifstream in("energii.in");
ofstream out("energii.out");
const int WMAX = 5001;
int n,w;
int cost[WMAX + 1]; // cost(energy)


void addGenerator(int e, int c){
    for(int j = w; j >= 0; j--){
        if(cost[j] != INT_MAX){
            int energy = min(e + j, w);
            int co = cost[j] + c;
            if(co < cost[energy]){
                cost[energy] = co;
            }
        }
    }
}

int main(){
    in >> n >> w;
    cost[0] = 0;
    for(int i = 1 ; i <= w; i++)
        cost[i] = INT_MAX;
    
    for(int i = 0 ; i < n ; i ++){
        int e, c;
        in >> e >> c;
        addGenerator(e,c);
    }
    if(cost[w] == INT_MAX)
        out << -1;
    else 
        out << cost[w];
}