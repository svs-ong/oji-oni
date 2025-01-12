//https://infoarena.ro/problema/mostenire3
#include <bits/stdc++.h>

using namespace std;
ifstream in("mostenire3.in");
ofstream out("mostenire3.out");
static constexpr int NMAX = 100000;
int v[NMAX],n,k;
void read(){
    in >> n >> k;
    for(int i = 0 ; i < n ; i ++){
        in >>v[i];
    }
}

int main(){
    read();
}

