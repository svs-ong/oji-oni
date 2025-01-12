//https://www.infoarena.ro/problema/triang
#include <bits/stdc++.h>
using namespace std;


ifstream in("triang.in");
ofstream out("triang.out");
struct  Point
{
    double  x,y;
    double length(){
        double dx = this->x * this->x;
        double dy = this->y * this->y;
        return sqrt(dx*dx + dy *dy);
    }
    void add(const Point& p){
        this->x += p.x;
        this->y += p.y;
    }
    void rotate(const double radianAngle){
        double xCopy = this->x;
        this->x = this->x *cos(radianAngle) - this->y * sin(radianAngle);
        this->y = xCopy *sin(radianAngle) + this->y * cos(radianAngle);
    }
    void multiply(double value){
        this->x *= value;
        this->y *= value;
    }
    void normalize(){
        double length = this->length();
        this->multiply(1/length);
    }
    void resize(double length){
        this->normalize();
        this->multiply(length);
    }
    void display(){
        cout << "( "<<this->x <<" "<<this->y << " )";
    }
};
const int NMAX = 1500;
const double epsilon = 0.0001;

int n;
Point v[NMAX];

bool isImportant(const Point &a,const Point &b){
    if(fabs(a.x - b.x) >= epsilon)//they are not equal
        return a.x < b.x;
    if(fabs(a.y - b.y) >= epsilon)
        return a.y < b.y;
    return false;
}

void getThird(Point &a, Point &b){
    Point mid = {(a.x + b.x) / 2, (a.y + b.y) /2};

    a.add((Point){-mid.x, -mid.y});
    b.add((Point){-mid.x, -mid.y});

    a.rotate(M_PI_2);
    b.rotate(M_PI_2);

    a.multiply(sqrt(3));
    b.multiply(sqrt(3));
    
    a.add(mid);
    b.add(mid);
}

int main(){
    
    in >> n;
    for(int i = 0 ; i < n ; i ++){
        in >> v[i].x >> v[i].y;
    }
    sort(v, v + n, isImportant);

    int nr = 0;
    for(int i = 0 ; i < n-2 ; i ++){
        for(int j = i+1; j < n - 1; j ++){
            Point a = v[i];
            Point b = v[j];
            getThird(a,b);
            if(binary_search(v + j + 1, v + n, a, isImportant)){
                nr++;
            }
            if(binary_search(v + j + 1, v + n,b ,isImportant)){
                nr++;
            }
        }
    }
    out << nr;
}