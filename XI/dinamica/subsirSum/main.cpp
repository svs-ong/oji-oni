//https://www.infoarena.ro/problema/scmax
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("scmax.in");
ofstream out("scmax.out");

constexpr int NMAX = 100000;
int x[100000];
int nr[10000];

int main(){

    int n;
    in >> n;
    for(int i = 0 ; i < n ; i ++){
        in >> x[i];
        nr[i] = 1;
        for(int j = i - 1; j >= 0; j ++){
            if(x[j] < x[i]){
                nr[i] = max(nr[i], nr[j] + 1);
            }
        }
    }
    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
    
}