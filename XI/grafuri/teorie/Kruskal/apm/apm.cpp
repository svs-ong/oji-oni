#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//https://www.infoarena.ro/problema/apm

using namespace std;
//numbers of nodes and edges
int n, m;
struct Edge{
    int nodA;  //first node
    int nodB;  //second node
    int c;  //cost 
};
//retain the componnent name of each node
vector<int> dad;
//retain edges
vector<Edge> edges;
//retain added edges
vector<Edge> newEdges;

bool compareEdges(Edge a, Edge b){
    return a.c < b.c;
}
//Read data, initialize dad vector and sort edges
void read(){
    ifstream in("apm.in");
    in >> n >> m;
    for(int i = 0; i < m; i++){
        Edge m;
        in >> m.nodA >> m.nodB >> m.c;
        edges.push_back(m);
    }
    for(int i = 0 ; i <= n; i++){
        dad.push_back(i);
    }
    sort(edges.begin(), edges.end(),compareEdges);
}

//Return the component of each node
int findDad(int x){
    if(x != dad.at(x))
        dad.at(x) = findDad(dad.at(x));
    return dad.at(x);
}

void Kruskal(){
    for(auto m : edges){
        int dadX = findDad(m.nodA);
        int dadY = findDad(m.nodB);
        //if m.x and m.y are not from the same component
        if(dadX != dadY){
            // merge components
            dad.at(dadY) = dadX;
            newEdges.push_back(m);
        }
    }
}
void display(){
    ofstream out("apm.out");
    int suma = 0;
    for(auto m : newEdges){
        suma += m.c;
    }
    out << suma <<'\n';
    out << newEdges.size()<<'\n';
    for(auto m : newEdges){
        out << m.nodA << " " << m.nodB<<'\n';
    }
}



int main(){
    read();
    Kruskal();
    display();
    return 0;
}