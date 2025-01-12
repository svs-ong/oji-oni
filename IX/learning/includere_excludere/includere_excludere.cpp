//https://www.infoarena.ro/problema/pinex
#include <bits/stdc++.h>

using namespace std;

ifstream in("pinex.in");
ofstream out("pinex.out");
const int MAX_DIVIDERS = 20;

bool divide(long long &x, long long divide){
    if(x % divide != 0)
        return false;
    do{
        x /= divide;
    }while(x % divide == 0);
    return true;
}

void descompunere(long long v[], int &n, long long x){
    n = 0;
    for(long long d = 2; d <= sqrt(x); d++){
        if(divide(x,d))
            v[n++] = d;
    }
    if(x != 1)
        v[n++] = x;
}
void display(long long v[], int n){
    for(int i = 0 ; i <n; i++)
        cout << v[i] << ' ';
    cout << '\n';
}
long long getSol(long long A, long long v[], int n){
    long long ans = 0;
    int full = (1<<n) - 1;
    for(int sets = 1 ; sets <= full ; sets++)
    {
        // cout << (bitset<5>)sets<<endl;
        short int nrOfSets = 0;
        long long sum = A;
        for(int j = 0 ; j < n ; j++)
        {
            int mask = (1<<j);
            if(sets & mask)
            {
                nrOfSets++;
                sum /= v[j];
            }
        }

        if(nrOfSets % 2 == 1) ans += sum;
        else ans -= sum;
    }
    return ans;
}
int main()
{  
    char cuvinte[10][11];
    int n;
    cin >> n;
    for(int i = 0; i < n ; i ++){
        cin >> cuvinte[i];
    }
    char prop[10][11];
    int nr = 0;
    char s[100];
    cin.getline(s, 100);

    char *p = strtok(s, " ");
    while(p){
        strcpy(prop[nr], p);
        nr++;
        p = strtok(NULL, " ");
    }

    for(int i = 0 ; i < nr; i ++){
        if(strchr(prop[i], '*')){
            for(int j = 0 ; j < n ; j ++){
                if(strlen(prop[i]) == strlen(cuvinte[j])){
                    strcpy(prop[i], cuvinte[j]);
                    break;
                }
            }
        }
    }
    strcpy(s, "");
    for(int i = 0 ; i < nr ; i ++){
        strcat(s, prop[i]);
        strcat(s, " ");
    }

    return 0;
}