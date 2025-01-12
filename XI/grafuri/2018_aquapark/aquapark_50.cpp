#include <bits/stdc++.h>
// https://www.infoarena.ro/problema/aquapark
using namespace std;
ifstream in ("aquapark.in");
ofstream out ("aquapark.out");

const int N_MAX = 70000;
const int M_MAX = 100000;
const int modulo = 666013;

struct Edge{
    int nodA;
    int nodB;
    int tip;
    inline int getReversedType(){
        return 3 - tip;
    }
    inline bool isTipSet(){
        return tip != 0;
    }
};
Edge v[M_MAX];
int n,m,p;
long long s = 1;

void read()
{
  in >> p >>n >>m;
  for(int i =0 ; i < m; i++)
  {
      int x,y;
      in>>x >>y;
      if(y < x)swap(x, y);
      v[i] = {x, y, 0};
  }
}

///Daca tipul muchiei a si b nu poate fi acelasi (ambele 1 sau ambele 2)
inline bool intersects(Edge &a, Edge &b)
{
    // ax < bx < ay < by
    if(a.nodA < b.nodA && b.nodA < a.nodB && a.nodB < b.nodB) 
        return true;

    // bx < ax < by < ay
    if(b.nodA < a.nodA && a.nodA < b.nodB && b.nodB < a.nodB ) 
        return true;
    return false;
}
inline bool compareXY(const Edge &a,const  Edge &b){
    if(a.nodA != b.nodA)
      return a.nodA < b.nodA;  
    return a.nodB < b.nodB;
}
inline bool compareX(const Edge &a,const Edge &b){
    return a.nodA < b.nodA;  
}

inline void construct()
{
    sort(v, v + m, compareXY);
    // for(int i = 0 ; i < m; i ++){
    //     cout << i << " " << v[i].x << " "<<v[i].y<<"\n";
    // }
    for(int i = 0; i < m; i++)
    {
        Edge *a = v + i;
        bool newConexComponnent;
        if(a->isTipSet()){
            newConexComponnent = false;

        }else{
            a->tip = 1;
            newConexComponnent = true;
        }

        Edge *b = upper_bound(a, v + m, *a, compareX);
        for (;b < v + m && b->nodA < a->nodB ; b++)
        {
            if(intersects(*a, *b)){
                if(b->isTipSet()){
                    newConexComponnent = false;
                }else{
                    b->tip = a->getReversedType();
                }
            }
        }
        if(newConexComponnent){
            s = (s * 2) % modulo;
        }
    }
}

inline void afiseaza()
{
    if(p == 1)
    {
        for(int i= 0; i < m;i++)
            out <<v[i].nodA <<" " <<v[i].nodB <<" " <<v[i].tip <<'\n';
    }
    else
    {
        out << s;
    }
}

int main()
{
  read();
  construct();
  afiseaza();

}