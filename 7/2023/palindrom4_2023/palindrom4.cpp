#include <vector>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
ifstream in("palindrom.in");
ofstream out("palindrom.out");

bool isPalindrom(string &num, int i){
    int size = num.size();
    int steps = (size - i) / 2;
    for(int j = 0 ; j < steps; j++){
        if(num.at(j + i) != num.at(num.size() - j - 1)){
            return false;
        }
    }
    return true;
}
int getCif(string &num){
    int maxCif = num.size() - 1;
    for(int i = 0 ; i <= maxCif; i++){
        if(isPalindrom(num, i)){
            return i;
        }
    }
}

int main(){
    string s = "121";
    cout << s;
    int c,n;
    in >> c >> n;
    if(c == 1){
        int sum = 0;
        string num;
        for(int i = 0; i < n ; i++){
            in >> num;
            sum += getCif(num);
        }
        out << sum;
    }else{
        vector<int> v;
        for(int i = 0; i < n ; i++){
            string num;
            in >> num;
            v.push_back(getCif(num));
        }

        int maxCif;
        in >> maxCif;
        int curentCif = 0;
        int maxConsecutive = 0;
        int i = 0;
        for(int j = 0; j < v.size(); j++){
            curentCif += v.at(j);
            while(curentCif > maxCif && i<= j){
                curentCif -= v.at(i);
                i++;
            }
            if(maxConsecutive < j - i)
                maxConsecutive = j - i;
        }
        out << maxConsecutive + 1;
    }
}
