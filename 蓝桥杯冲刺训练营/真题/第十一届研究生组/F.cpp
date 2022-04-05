// 11:00
/*
7
80
92
56
74
88
99
10
*/

#include <iostream>

using namespace std;

int main(){

    int n, max_score = -1, min_score = 101;
    double sum = 0;
    int tmp;

    cin >> n;

    for (int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        sum+=tmp;
        max_score = max(max_score, tmp);
        min_score = min(min_score, tmp);
    }

    cout << max_score << endl;
    cout << min_score << endl;
    printf("%.2f", sum/n);

    return 0;
}