/*
3
1 4 6

动态规划，每次放入一个砝码，和前面的砝码进行加减操作，得到新的重量状态，知道最后一个砝码放置，即可获得答案
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;

int pre_dp[100002]; //上一个状态dp数组 数组值为1表示可以组合成对应的下标
int now_dp[100002]; // 当前状态dp数组

int main()
{

    int n;
    cin >> n;

    vector<int> w(n, 0); //初始化n个砝码重量为0

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &w[i]);
    }

    int pre_max = w[0]; // 上一个状态中最大值，用来作为遍历上一个dp状态数组
    int now_max = w[0];
    pre_dp[w[0]] = 1;

    for (int i = 1; i < n; ++i)
    { //依次放入n-1个砝码

        now_max = pre_max;
        
        copy(begin(pre_dp), end(pre_dp), begin(now_dp)); // 复制数组的值

        now_dp[w[i]] = 1;
        for (int j = 1; j <= pre_max; ++j)
        {
            if (pre_dp[j] == 1)
            {
                now_dp[j + w[i]] = 1;
                now_dp[abs(j - w[i])] = 1;
                now_max = max(now_max, j + w[i]);
            }
        }

        pre_max = now_max;
        
        copy(begin(now_dp), end(now_dp), begin(pre_dp));
    }

    int ans = 0;

    for (int i = 1; i <= pre_max; ++i)
    {
        
        if (pre_dp[i] == 1)
            ans++;
    }

    cout << ans;

    return 0;
}
