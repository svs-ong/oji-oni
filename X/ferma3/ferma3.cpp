#include <bits/stdc++.h>

using namespace std;
ifstream in("ferma3.in");
ofstream out("ferma3.out");
int culturi[101][101];
int parcele[101][101];
int aparitii[10000];
int n,m;
struct Point
{
    int x,y;
};
Point dir[] = {{1,0}, {-1,0} ,{0,1},{0,-1}};
int dirLength = 4;


void citire(){
    in >> n >> m;
    for(int i = 1 ; i <= n; i ++){
        for(int j = 1; j <=m ; j ++){
            char c;
            in >> c;
            culturi[i][j] = c;
        }
    }
    // for(int i = 1 ; i <= n; i ++){
    //     for(int j = 1; j <=m ; j ++){
    //         cout << culturi[i][j] <<" ";
    //     }cout <<'\n';
    // }
}

bool ok(Point a, int cultura){
    return a.x >=1 && a.x <= m && a.y >= 1 && a.y <= n 
        && culturi[a.y][a.x] == cultura && parcele[a.y][a.x] == 0; 
}

void fill(Point start, int parcela, int cultura){
    queue<Point> q;
    q.push(start);
    parcele[start.y][start.x] = parcela;

    while(!q.empty()){
        Point nod = q.front();
        q.pop();
        aparitii[parcela]++;
        for(int i = 0 ; i < dirLength; i++){
            Point neigh = {nod.x + dir[i].x, nod.y + dir[i].y};
            if(ok(neigh,cultura)){
                parcele[neigh.y][neigh.x] = parcela;
                q.push(neigh);
            }
        }
    }
}

void displayParcele(){
     for(int i = 1; i <=n ; i ++){
        for(int j = 1; j <= m ; j ++){
            // cout << parcele[i][j] << " ";
            cout << aparitii[parcele[i][j]] << " ";
        }cout << '\n';
    }
    cout << "\n\n";
}



int main(){
    citire();
    int idParcela = 0;
    for(int i = 1; i <=n ; i ++){
        for(int j = 1; j <= m ; j ++){
            if(parcele[i][j] == 0){
                idParcela++;
               fill({j,i},idParcela,culturi[i][j]); 
               displayParcele();
            }
        }
    }
}