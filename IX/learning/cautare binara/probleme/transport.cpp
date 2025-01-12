//https://www.infoarena.ro/problema/transport
#include <bits/stdc++.h>

using namespace std;
ifstream in("transport.in");
ofstream out("transport.out");
static const int MAX_RIGHT = 16000*16000;
int n, k;
bool testCapacity(int v[],const int maxCapacity){
    int transportsNo = 1;
    int sum = 0;
    for(int i = 0; i < n ; i ++){
        sum += v[i];
        if(maxCapacity < v[i])
            return false;
        if(sum > maxCapacity){
            sum = v[i];
            if(++transportsNo > k)
                return false;
        }
    }
    return true;
}


bool getTransports(int capacity){
    int transportsNo = 1;
    int sum = 0;
    for(int i = 0; i < n ; i ++){
        sum += v[i];
        if(sum > capacity){
            sum = v[i];
            transportsNo++;
        }
    }
    return transportsNo;
}

int main(){
    in >> n >> k;
    int v[n];
    int max = 0;
    for(int i = 0 ; i < n ; i ++){
        in >> v[i];
        if(v[i] > max)
            max = v[i];
    }

    //Binary Search
    int left = max;
    int right = MAX_RIGHT;
    while(left < right){
        int mid = (left + right) /2;
        if(testCapacity(v, mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    out << left;
}