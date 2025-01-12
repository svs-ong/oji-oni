/*
    https://infoarena.ro/problema/abx
    - ridicare la putere
    - cautare binara
*/

#include <bits/stdc++.h>
using namespace std;

ifstream in("abx.in");
ofstream out("abx.out");
using ll = long long;
ll m, sqrtm;

// ll power(ll x, int exp){
//      if(exp == 1)
//         return x;
//     ll res = power(x, exp / 2);
//     if(res > sqrtm)
//         return LLONG_MAX;
//     res = res*res;
//     if(exp % 2 == 1){
//         if(res > m/x)
//             return LLONG_MAX;
//         return x * res;
//     }
//     return res;
// }
ll power(ll x, int exp){
    if(x == 0)
        return 0;
    ll put = 1;
    for(int i = 1; i<= exp; i++){
        if(put > m / x)
            return LLONG_MAX;
        put *= x;
    }
    return put;
}

inline ll selectBest(ll x, ll sol1, ll sol2){
    ll var1 = abs(sol1 - x);
    ll var2 = abs(sol2 - x);
    if(var1 < var2)
        return sol1;
    if(var2 < var1)
        return sol2;
    return min(sol1, sol2);
}

ll solve(ll x, ll exp){
    ll sol = 1;
    ll left = 1, right = sqrtm + 1;
    ll mid, p;
    while(left < right){
        mid = (left + right) / 2;
        p = power(mid, exp);
        cout << left<<" "<<mid << " "<<right <<" -> " <<p<<"\n";
        if(x <= p){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    p = power(left, exp);
    sol = selectBest(x, sol, p);
    p = power(left - 1,exp);
    //return best from 1 , left^exp , (left-1) ^ exp
    return  selectBest(x, sol, p);
}

ll solve(ll x){
    ll sol = 1;
    for(int exp = 2; exp <= 62; exp++){
        ll sol2 = solve(x, exp);
        sol = selectBest(x,sol,sol2);
        if(sol == x)
            break;
    }
    return sol;
    
}

int main(){  
    // int n;
    // ll x;
    // in >> n>> m;
    // sqrtm = sqrt(m);
    // for(int i = 0 ; i < n ; i ++){
    //     in >> x;
    //     out << solve(x) << "\n";
    // }
    m = 10000000;
    sqrtm = sqrt(m);
    cout <<"\n" << solve(976321,2);
    return 0;
}