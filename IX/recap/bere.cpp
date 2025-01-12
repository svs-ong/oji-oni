//https://www.infoarena.ro/problema/br
#include <bits/stdc++.h>

using namespace std;
ifstream in("br.in");
ofstream out("br.out");

const int NMAX = 15000;
int v[NMAX + 1], sum[2 * NMAX + 1], n;

int solve(int k, int x){
    if(x < v[k])
        return 0;
    int base = sum[k-1] + x;
    return upper_bound(sum + k, sum + k + n, base) - sum - k;
}

int main(){
    int T;
    in >> n >> T;
    for(int i = 1; i <= n; i ++){
        in >> v[i];
    }
    for(int i = 1; i <= 2*n ; i ++){
        sum[i] = sum[i -1] + v[(i-1) % n + 1];
    }

    // for(int i = 0 ; i <= 2*n;i++)
    //     cout << sum[i] << " ";

    for(int i = 1; i <= T; i ++){
        int k, x;
        in >> k >> x;
        out << solve(k,x) << '\n';
    }
}