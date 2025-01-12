//https://www.infoarena.ro/problema/deminare

#include <fstream>

using namespace std;

ifstream fin("deminare.in");
ofstream fout("deminare.out");

int t, n, m, k, maxim, nrsol, nr, sol[505], a[505][505], s[505][505];

bool prim(int x)
{
    int i;

    for (i=2;i*i<=x;i++)
        if (!(x%i))
            return 0;
    return 1;
}

int main()
{
    int x, y, i, j, l, c;

    fin >> t;
    fin >> n >> m;
    fin >> k;
    for (i=1;i<=k;i++)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            
    if (t == 1)
    {
        for (i=1;i<=n;i++)
        {
            nr = s[i][m]-s[i-1][m];
            if (nr > maxim)
            {
                maxim = nr;
                nrsol = 1;
                sol[1] = i;
            }
            else if (nr == maxim)
                sol[++nrsol] = i;
        }
        for (i=1;i<=nrsol;i++)
            fout << sol[i] << ' ';
        fout << '\n';
    }
    else
    {
        if (prim(k))
            fout << -1 << '\n';
        else
        {
            maxim = 0;
            for (i=1;i*i<=k;i++)
            {
                if (!(k%i))
                {
                    j = k/i;
                    for (l=1;l<=n;l++)
                        for (c=1;c<=m;c++)
                        {
                            if (l >= i && c >= j)
                            {
                                nr = s[l][c]-s[l-i][c]-s[l][c-j]+s[l-i][c-j];
                                if (nr > maxim)
                                    maxim = nr;
                            }
                            if (l >= j && c >= i)
                            {
                                nr = s[l][c]-s[l-j][c]-s[l][c-i]+s[l-j][c-i];
                                if (nr > maxim)
                                    maxim = nr;
                            }
                        }
                }
            }
            if (maxim == 0)
                fout << -1 << '\n';
            else fout << k-maxim << '\n';
        }
    }
    return 0;
}
