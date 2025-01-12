#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//https://www.pbinfo.ro/probleme/4400/primprim
using namespace std;
ifstream in("primprim.in");
ofstream out("primprim.out");

constexpr int XMAX =  1000000;
constexpr int NMAX = XMAX;

int n;
int cost[XMAX + 1];
int v[NMAX + 1];
int index[NMAX + 1];

void Eratostene(){
    cost[0] = 2;
    cost[1] = 1;
        
    for(int i = 2; i <= XMAX; i++){
        if(cost[i] == 0){
            for(int j = i + i; j <= XMAX; j += i){
                cost[j] = -1;
            }
        }
    }
}

int getClosestPrim(int x, int direction){
    for(int i = x ; i >= 0 && i <= XMAX; i+= direction){
        if(cost[i] == 0){
            return i;
        }
    }
    return -1;
}

int getCost(int x){
    if(cost[x] != -1){
        return cost[x];
    }
    int primL = getClosestPrim(x, -1);
    int primR = getClosestPrim(x, 1);
    if(primL != -1 && primR != -1){
        cost[x] = min(abs(primL - x), abs(primR - x));
        for(int i = primL + 1 ; i < (primL + primR)/2 ; i++){
            cost[i] = i - primL;
        }
        for(int i = (primL + primR) / 2;i < primR ;i++){
            cost[i] = primR - i;
        }
    }else if(primL != -1){
        for(int i = x; i < primR ;i++){
            cost[i] = primR - i;
        }
    }else{
        for(int i = primL + 1; i <= x ;i++){
            cost[i] = i - primL;
        }
    }
    return cost[x];
}

bool descrescator(int index1, int index2){
    return getCost(v[index1]) < getCost(v[index2]);
}
int findIndex(int i){
    for(int j = 0 ; j <n; j++){
        if(index[j] == i ){
            return j;
        }
    }
}

void display(){
    for(int i = 0; i < n ; i ++){
        cout <<v[i]<< " ";
    }cout << "\n";
    for(int i = 0; i < n ; i ++){
        cout <<getCost(v[i])<< " ";
    }cout << "\n";
    for(int i = 0; i < n ; i ++){
        cout <<index[i]<< " ";
    }cout << "\n";
    for(int i = 0; i < n ; i ++){
        cout <<getCost(v[index[i]])<< " ";
    }cout << "\n\n";
}

int solutie(int i, int x, int p){
    i--;
    int idx = findIndex(i);
    int j = idx;
    while( j > 0 &&  getCost(x) < getCost(v[index[j - 1]])){
            index[j] = index[--j];
    }
    while( j < n-1 &&  getCost(x) > getCost(v[index[j + 1]])){
            index[j] = index[++j];
    }
    v[i] = x;
    // display();
    int sum = 0;
    for(int i = 0; i < p; i ++){
        sum += getCost(v[index[i]]);
    }
    return sum;
}


int main(){
    int p;
    Eratostene();
    in >> p >>n;
    for(int i = 0 ; i < n; i ++){
        in >> v[i];
    }
    if(p == 1){
        unsigned long long sum = 0;
        for(int i = 0 ; i < n; i ++){
            sum += getCost(v[i]);
        }
        out << sum;
    }else{
        for(int i = 0; i < n; i++){
            index[i] = i;
        }
        std::sort(index, index + n, descrescator);

        // display();

        int q,i,x,p;
        in >>q;
        for(int j = 0 ; j < q; j++){
            in >> i>> x >> p;
            out << solutie(i,x,p) <<"\n";
        }
    }
    return 0;
        
}