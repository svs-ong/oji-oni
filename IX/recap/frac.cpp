//https://www.infoarena.ro/problema/frac

#include <bits/stdc++.h>

using namespace std;
ifstream in("frac.in");
ofstream out("frac.out");

static constexpr int MAX = 109544;

bool ciur[MAX + 5];
int n, p;
vector<int> primes, v;

void decomp(int n)
{
    for(int i = 0;i < primes.size() && primes[i] * primes[i] <= n; ++i)
    {
        bool ok = 0;
        while(!(n % primes[i]))
        {
            ok = 1;
            n /= primes[i];
        }
        if(ok)
            v.push_back(primes[i]);
    }
    if(n != 1)
        v.push_back(n);
}


int compute(int a)
{
    int size = v.size(), total = 0;
    for(int i = 1;i < (1 << size); ++i)
    {
        int cnt = 0, number = 1, bits = 0;
        for(int j = 1;j <= i; j *= 2)
        {
            if(i & j)
                number *= v[cnt], bits++;
            cnt++;
        }
        if(bits % 2)
            total += a / number;
        else
            total -= a / number;
            cout << i << " " <<total<<endl;
    }
    return total;
}

int main()
{
    n = 12,p = 5;

    primes.push_back(2);
    for(int i = 3;i <= MAX; i += 2)
    {
        if(!ciur[i])
        {
            primes.push_back(i);
            for(int j = i + i + i;j <= MAX; j += i << 1)
                ciur[j] = 1;
        }
    }
    decomp(n);
    cout << compute(6);
}