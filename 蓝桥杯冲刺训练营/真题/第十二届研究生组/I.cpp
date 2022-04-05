/*
3 3
0 3
1 2
0 2
----
3 1 2

5 3
0 3
1 2
0 2


*/
#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(int a, int b){
    return a>b;
}

using namespace std;

int main(){

    int m,n,p,q;

    cin >> n >> m;
    vector<int> v(n,0);
    for (int i = 0; i < n; ++i){
        v[i] = i+1;
    }

    while(m--){
        cin >> p >> q;
        if (p == 0){//cmp
            sort(v.begin(),v.begin()+q, cmp);
        }else{//default
            sort(v.begin()+q-1, v.end());
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    
    return 0;
}