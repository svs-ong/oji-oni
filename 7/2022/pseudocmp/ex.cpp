#include <bits/stdc++.h>

using namespace std;
ifstream in("wind.in");
ofstream out("wind.out");
const int NMAX = 100000;
int eoliene[NMAX],eoliene_no,cer;
int groups[NMAX],group_no;

void citire(){
    in >> cer >> eoliene_no;
    for(int i = 0; i < eoliene_no; i++){
        in >> eoliene[i];
    }
}
void calcDivizor(int v[], int &n, int x){
    n = 0;
    if(x <= 1)
        return;
    v[n++] = 1;
    double sq = sqrt(x);
    for(int i = 2; i < sq; i ++){
        if(x % i == 0){
            v[n++] = i;
            v[n++] = x / i;
        }
    }
    if(sq*sq == x){
        v[n++] = sq;
    }
    sort(v,v + n);
}
int getEnergy(int oras, int centPerOras){
    int start = oras * centPerOras;
    int energy = 0;
    for(int i = start; i < start + centPerOras;i++){
        energy += eoliene[i];
    }
    return energy;
}
int getFactorDezechilibru(int centPerOras){
    int nr_orase = eoliene_no / centPerOras;
    int minEnergy = INT_MAX, maxEnergy = INT_MIN;
    for(int i = 0; i <nr_orase; i ++){
        int energy = getEnergy(i, centPerOras);
        if(minEnergy > energy){
            minEnergy = energy;
        }
        if(maxEnergy < energy){
            maxEnergy = energy;
        }
    }
    return maxEnergy - minEnergy;
}

int main(){
    citire();
    calcDivizor(groups, group_no, eoliene_no);
    if(cer == 1){
        out << group_no;
    }else{
        int minFactor = INT_MAX,group;
        for(int i = 0; i < group_no; i ++){
            int factor =  getFactorDezechilibru(groups[i]);
            if(factor < minFactor){
                minFactor = factor;
            }
        }
        cout << minFactor;
    }
}