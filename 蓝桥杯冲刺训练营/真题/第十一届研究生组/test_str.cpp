#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){

    map<string , double> table;

    table["1"] = 100;

    cout << table["1"] << endl;

    cout << table["12"] << endl;
    cout << table["13"] << endl;
    cout << table["15"] << endl;

    return 0;
}