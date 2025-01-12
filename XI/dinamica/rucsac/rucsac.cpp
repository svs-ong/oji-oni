//https://www.infoarena.ro/problema/rucsac
#include <bits/stdc++.h>

using namespace std;
ifstream in("rucsac.in");
ofstream out("rucsac.out");
const int GMAX = 10000;
int n,G;
int preturi[GMAX + 1];//profitul maxim cu greutatea g

void display(){
    for(int i = 0 ; i < G; i ++){
        cout << preturi[i] << " ";
    }cout << endl;
}
void addObiect(int greutate, int pret){
    for(int j = G; j >= 0; j--){
        if(preturi[j] != -1){
            int g = min(j + greutate,G);
            int p = pret + preturi[j];
            if(p > preturi[g])
                preturi[g] = p;            
        }
    }
    // display();
}
int main()
{
    
    in >> n >> G;
    for(int i  = 1; i <= G ; i ++)
        preturi[i] = -1;
    
    for(int i = 1 ; i <= n ; i ++){
        int g, p;
        in >> g >>p;
        addObiect(g,p);
    }
    out << *max_element(preturi,preturi + G);
}