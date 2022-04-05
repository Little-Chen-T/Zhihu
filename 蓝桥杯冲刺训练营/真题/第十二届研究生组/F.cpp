#include <iostream>

using namespace std;
#define ll long long int

int main(){

    ll sec;

    cin >> sec;

    sec = int(sec/1000); //转化成s

    // cout << sec << endl;

    int hour = sec / 3600;
    sec -= 3600*hour;

    int min = (sec)/60;
    sec -= 60*min;

    printf("%02d:%02d:%02d\n", hour%24, min%60, sec%60);

    return 0;
}