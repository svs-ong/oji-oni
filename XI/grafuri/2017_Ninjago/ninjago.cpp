/**
 * @brief https://www.infoarena.ro/problema/ninjago
 *  Complex Kruskal with 2 cost eges
 */
#include <bits/stdc++.h>

using namespace std;
ifstream in("ninjago.in");
ofstream out("ninjago.out");

struct Edge{
    int nodA;
    int nodB;
    int cost;
    int numbersOfE;
};
const int NMAX = 31200;
int n,m;
vector <Edge> edges;
int father[NMAX + 1];
int nrOfNodes[NMAX + 1];

bool compara(Edge &a, Edge &b){
    if(a.numbersOfE != b.numbersOfE)
        return a.numbersOfE < b.numbersOfE;
    return a.cost < b.cost;
}

void readEdges(bool readEEdges){
    int costWeight[] = {1,5,25,125};
    for(int i = 0 ; i < m ; i ++){
        int x, y, cost = 0, nrOfE = 0;
        in >> x >>y;
        for(int j = 0 ; j < 4; j ++){
            char obstacle;
            in>> obstacle;
            if(obstacle != 'E'){
                cost += (obstacle - 'A' + 1) * costWeight[j];
            }else{
                nrOfE++;
            }
        }
        if(readEEdges || nrOfE == 0){
            edges.push_back({x, y, cost, nrOfE});
        }
    }
    sort(edges.begin(),edges.end(), compara);
    for(int i = 1; i <= n ; i ++){
        father[i] = i;
        nrOfNodes[i] = 1;
    }
}

void displayEdges(){
    for(auto e : edges){
        cout << e.nodA << " "<<e.nodB <<" cost = "<<e.cost << " E = "<<e.numbersOfE<<"\n";
    }
}
int getDad(int x){
    if(father[x] == x)
        return x;
    father[x] = getDad(father[x]);
    return father[x];
}
struct Answer{
    int TotalCost, Enumbers, helpers;
};
Answer Kruskal(){
    int cost = 0, ENumbers = 0, helpers = 0;
    for(auto e : edges){
        int dadX = getDad(e.nodA);
        int dadY = getDad(e.nodB);
        if(dadX != dadY){
            father[dadY] = dadX;
            nrOfNodes[dadX] += nrOfNodes[dadY];
            cost+= e.cost;
            if(e.numbersOfE){
               ENumbers += e.numbersOfE; 
               helpers++; 
            }
            
        }
    }
    return {cost,ENumbers,helpers};
}


int main(){
    int cerinta;
    in >> cerinta >> n >> m;
    if(cerinta == 1){
        readEdges(false);
        Kruskal();
        out << nrOfNodes[getDad(1)];
        //out << nrOfNodes(1);
    }else{
        readEdges(true);
        Answer ans = Kruskal();
        if(cerinta == 2){
            out << ans.helpers<<"\n"<<ans.Enumbers;
        }else{
            out <<ans.TotalCost;
        }
    }
    // displayEdges();
}   