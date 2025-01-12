//https://www.pbinfo.ro/probleme/4411/veri
#include <bits/stdc++.h>
using namespace std;
ifstream in("veri3.in");
ofstream out("veri.out");
const int NMAX = 5001;

struct Cycle{
    int size;
    int start;
    int stop;
};
enum Color{WHITE,GRAY,BLACK};
int cerinta,n,S,A,B;
vector<int> v[NMAX];

vector<Cycle> cycles;

Color visited[NMAX];
int dad[NMAX];

void read(){
    int m;
    in >> cerinta;
    in >> n >> m;
    in >> S >> A >> B;
    for(int i = 0 ; i < m ; i ++){
        int x, y;
        in >> x>> y;
        v[x].push_back(y);
    }
}

void addCycle(int start, int end){
    int size = 1;
    while (end != start)
    {
        cout << end << " ";
        size++;
        end = dad[end];
    }
    cout << start << " - "<<size<<"\n\n";
}

void findCycles(int nod){
    visited[nod] = GRAY;
    for(auto neigh :v[nod]){
        if(visited[neigh] == WHITE){
            dad[neigh] = nod;
            findCycles(neigh);
        }else if(visited[neigh] == GRAY){
            addCycle(neigh,nod);
        }
    }
    visited[nod] = WHITE;
}

int main(){
    vector<Cycle> c;
    sort(c.begin(),c.end());
    read();
    findCycles(S);
}