#include <iostream>

using namespace std;

int main(){

    int data = 78120;
    int cnt = 0;

    for (int i = 1; i <= data; ++i){
        if (data%i==0){
            cnt++;
            cout << i << endl;
        }
    }

    cout << "ans is :" << cnt << endl;
    return 0;
}