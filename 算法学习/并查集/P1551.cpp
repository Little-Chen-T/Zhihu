/*

6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

*/
#include <iostream>

using namespace std;

int pre[5001];
int rank_value[5001];

int find(int x){
    if (pre[x]==x) return x;
    return pre[x] = find(pre[x]);
}


void join(int x, int y){
    int pre_x = find(x);
    int pre_y = find(y);

    if (rank_value[pre_x] <= rank_value[pre_y]){
        pre[pre_x] = pre_y;
        if (rank_value[pre_x] == rank_value[pre_y] && pre_x != pre_y) rank_value[pre_y]++;
    }
    else{
        pre[pre_y] = pre_x;
    }

    

}

void init(){
    
    for (int i = 1; i <= 5001; ++i){
        pre[i] = i;
        rank_value[i] = 1;    
    } 
}

int main(){
    
    int n,m,p;
    int a,b;
    cin >> n >> m >> p;
    // cout << n << m << p << endl;

    init();

    while(m--){
        cin >> a >> b;
        // cout << a << " " << b << endl;
        join(a,b);
        // cout << " " << m << endl;
    }

    while(p--){
        cin >> a >> b;

        if (find(a)==find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    // //init
    
    // for(int i = 1; i <= n; ++i){
    //     cout << i << ":" << find(i) << endl;
    // }

    return 0;
}