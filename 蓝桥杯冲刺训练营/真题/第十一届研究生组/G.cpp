/*
20200202
10000101
89991231
*/
#include <iostream>
#include <sstream>
using namespace std;

int month_1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年
int month_2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年

stringstream ss;

inline bool years(int n){//是否是闰年

    if (n%400==0) return true;
    else if (n%100==0) return false;
    else if (n%4==0) return true;

}

inline bool legal_date(int n){
    int tmp = n;
    int day = tmp%100;
    
    tmp/=100;

    int month = tmp%100;
    tmp/=100;

    int year = tmp;

    if (years(year)){
        if (month<=12 && month>0 && day <= month_1[month-1]) return true;
    }
    else
    {
        if (month<=12 && month>0 && day <= month_2[month-1]) return true;
    }

    return false;
}

inline bool check_palindrome(string n){
    
    for (int i = 0; i < 8;++i){
        if (n[i]!=n[7-i]) return false;
    }
    return true;
}

inline bool chech_AB(string n){
    if (n[0] != n[1] && n[0]==n[2] && n[2]==n[5] && n[5]==n[7] && n[1]==n[3] && n[3]==n[4] && n[4]==n[6]) return true;

    return false;
}

int main(){

    int n;
    cin >> n;
    n++;

    while (true)
    {

        ss.str("");
        ss << n;
        
        if (check_palindrome(ss.str()) && legal_date(n)){
            cout << n << endl;        
            break;
        }
        n++;
    }
    

    while(true){
        
        ss.str("");
        ss << n;
                
        if (chech_AB(ss.str()) && legal_date(n)){
            cout << n << endl;
            break;
        }
        n++;
    }

    return 0;
}