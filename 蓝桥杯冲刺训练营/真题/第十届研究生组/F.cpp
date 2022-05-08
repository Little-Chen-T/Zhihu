#include <iostream>

using namespace std;

// 100-200

// double ans[100] = {112..32.3.23.}

int main(){

    double a,b, c;

    a = 1; b = 1;

    long long  n;
    cin >> n;

    // if (n==1) printf("%.8f\n",1.0/1.0);

    if (n > 1000000000) printf("0.61803399\n");
    else{
        for (long long  i = 0; i < n-1;++i){
            c = a+b;
            a = b;
            b = c;
        }
            printf("%.8f\n", a/b);
    }


    return 0;
}