#include <iostream>
#include <chrono>
#include <vector>
#include <array>

using namespace std;
#define NSIZE 100000

void static1(){
    int v[NSIZE];
    for(int i = 0; i < NSIZE; i ++){
        v[i] = 1;
    }
}

void static2(){
    int v[NSIZE];
    fill(v, v + NSIZE,1);
}
void vector1(){
    vector<int> v(NSIZE);
    for(int i = 0; i < NSIZE; i ++){
        v[i] = 1;
    }
}
void vector12(){
    vector<int> v(NSIZE);
    for(int i = 0; i < v.size(); i ++){
        v[i] = 1;
    }
}
void vector2(){
    vector<int> v(NSIZE);
    fill(v.begin(), v.end(), 1);
}
void vector3(){
    vector<int> v(NSIZE,1);
}
void vector4(){
    vector<int> v;
    for(int i = 0; i < NSIZE; i ++){
        v.push_back(1);
    }
}
void array1(){
    array <int, NSIZE> v;
    v.fill(1);
    for(int i = 0; i < v.size(); i ++){
        v[i] = 1;
    }
}
void array12(){
    array <int, NSIZE> v;
    for(int i = 0; i < NSIZE; i ++){
        v[i] = 1;
    }
}
void array2(){
    array <int, NSIZE> v;
    v.fill(1);
}


auto measure_time(void (*f)(void)){
    int repeat = 10000;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < repeat; i++){
        f();
    };
    auto end = chrono::high_resolution_clock::now();
    return ((end - start).count() / repeat) /1000;
}

int main() {
    cout << "static1 = "<< measure_time(static1)<<"\n";
    cout << "static2 = "<< measure_time(static2)<<"\n";
    cout << "vector1 = "<< measure_time(vector1)<<"\n";
    cout << "vector12= "<< measure_time(vector12)<<"\n";
    cout << "vector2 = "<< measure_time(vector2)<<"\n";
    cout << "vector3 = "<< measure_time(vector3)<<"\n";
    cout << "vector4 = "<< measure_time(vector4)<<"\n";
    cout << "array1 =  "<< measure_time(array1)<<"\n";
    cout << "array12=  "<< measure_time(array12)<<"\n";
    cout << "array2 =  "<< measure_time(array2)<<"\n";
    return 0;
}