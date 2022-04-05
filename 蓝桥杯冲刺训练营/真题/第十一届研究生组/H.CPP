/*
6 2 4 6
5 3 4 6 4 9
1 2
1 2 3
2 3 5
1 3 4
4 5 6
----
7 2 5 7
50 30 40 60 40 90 100
1 2
1 2 3
1 3 4
2 3 5
4 5 6
5 6 7
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include<list>

#define INF 999999

using namespace std;

struct Cross
{
    int a,b;
};

vector<int> time_v(2002,0);
vector<int> dp_v(2002,INF);
vector<Cross> tmp_cross_v;
Cross tmp_cross;
vector<vector<Cross> > function(1000002, tmp_cross_v);//存储杂交方案

inline int dfs(int c){
    if (dp_v[c] != INF) return dp_v[c];

    else
    {
        //遍历每个种子的杂交方案
        for (int i = 0; i < function[c].size(); ++i){

            int a = function[c][i].a;
            int b = function[c][i].b;
            dp_v[a] = dfs(a);
            dp_v[b] = dfs(b);

            dp_v[c] = min(dp_v[c], max(dp_v[a], dp_v[b])+max(time_v[a], time_v[b]));
        }
        
        return dp_v[c];
    }
}


int main(){
    
    int n,m,k,t;
    int tmp;
    int a,b,c;

    cin >> n >> m >> k >> t;

    for (int i = 1; i <= n; ++i){
        scanf("%d", &time_v[i]);
    }

    for (int i = 0; i < m; ++i){
        scanf("%d", &tmp);
        dp_v[tmp] = 0; // 已有种子培养时间为0
    }
    

    while(k--){ // A B C
        scanf("%d %d %d", &tmp_cross.a, &tmp_cross.b, &c);
        function[c].push_back(tmp_cross);    // c号种子的杂交方案, 每种种子杂交方案不止一种
    }

    cout << dfs(t);

    return 0;
}