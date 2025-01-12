/**
 * @brief 
 * Simple KRUSKAL
 * 
 */

#include<iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;
const int MAXN = 101;
vector< pair <int, int> >edges;
vector< pair <int, int> >addedEdges;
vector<int> dad;
vector<int> extra;
int n, m;

void read(){
    ifstream in("conexidad.in");
    in>> n>> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        in >> x >> y;
        edges.push_back(make_pair(x,y));
    }
    for(int i = 0 ; i <=n; i++){
        dad.push_back(i);
        extra.push_back(0);
    }
}
int findDad(int i){
    if(dad.at(i) != i)
        dad.at(i) = findDad(dad.at(i));
    return dad.at(i);
}
void unifyNodes(int x, int y){
    int dadx = findDad(x);
    int dady = findDad(y);
    if(dadx != dady){
        dad.at(dadx) = dady;
    }
}
int findNodeWithMinimumExtrainGraph(int graph){
    int minExtra = numeric_limits<int>::max();
    int node = -1;
    for(int i = 1; i <= n ; i ++){
        if(findDad(i) == graph && extra.at(i) < minExtra){
            minExtra = extra.at(i);
            node = i;
        }
    }
    return node;
}
void connectComponents(int x, int y){
    int nodeOfX = findNodeWithMinimumExtrainGraph(x);
    int nodeOfY = findNodeWithMinimumExtrainGraph(y);
    unifyNodes(nodeOfX,nodeOfY);
    extra.at(nodeOfX)++;
    extra.at(nodeOfY)++;
    addedEdges.push_back(make_pair(nodeOfX,nodeOfY));
    
}

void display(){
    int max = 0;
    for(int i = 0 ; i<= n ; i ++){
        if(extra.at(i) > max){
            max = extra.at(i);
        }
    }
    ofstream out("conexidad.out");
    out << max<< "\n"<< addedEdges.size() <<"\n";
    for(auto m : addedEdges){
        out << m.first << " "<< m.second<<"\n";
    }
}

int main(){
    read();
    for(auto m : edges){
        unifyNodes(m.first, m.second);
    }
    for (int i = 2; i <= n ; i ++){
        int dad1 = findDad(1);
        int dadI = findDad(i);
        if(dad1 != dadI){
            connectComponents(dad1, dadI);
        }
    }
    display();
}