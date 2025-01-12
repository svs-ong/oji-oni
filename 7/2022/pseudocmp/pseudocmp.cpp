//https://www.pbinfo.ro/probleme/4084/pseudocmp
#include <iostream>
using namespace std;

int v[100000];
int sumCif[100000],n;
int getSumCif(int x){
    int s = 0;
    while(x != 0){
        s += x % 10;
        x /= 10;
    }
    return s;
}

void citire(){
    cin >> n;
    for(int i = 0; i <n; i ++){
        cin >> v[i];
        sumCif[i] = getSumCif(v[i]);
    }
}
void one(){
    int i, j;
    for(int i = 0 ; i < n -1; i ++){
        for(int j = i + 1; j < n ; j ++){
            
        }
    }
}

int main(){
    citire();
    for(int i = 0 ; i < n -1; i ++){
        for(int j = i + 1; j < n ; j ++){

        }    
    }
}

