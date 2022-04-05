// 13:16
/*
4
1 1
1 0
2 2 1
7 992438 1006399 781139 985280 4729 872779 563580
*/

#include <iostream>
#include <cstring>
using namespace std;

int a[20];

inline void cal(int tmp)
{
    int cnt = 0;
    while (tmp)
    {
        if (tmp & 1 == 1)
            a[cnt]++;
        cnt++;
        tmp = tmp >> 1;
    }
}

int main()
{

    int t, n;
    int tmp;
    cin >> t;

    // for (int i = 0; i < t; ++i)
    while(t--)
    {
        cin >> n;

        // 清零a
        memset(a, 0, sizeof(a));
        int res = 0;

        for (int j = 0; j < n; ++j)
        {
            // cin >> tmp;
            scanf("%d", &tmp);
            cal(tmp); // 计算tmp每位信息
            res ^= tmp;
        }

        // //print a
        // for(int a1 = 19; a1>=0;--a1){
        //     cout << a[a1] << " ";
        // }
        // cout << endl;

        // //print a
        // for(int a1 = 19; a1>=0;--a1){
        //     cout << a[1][a1] << " ";
        // }
        // cout << endl;

        if (res == 0)
        {
            printf("0\n");
        }
        else
        {
            //从最高位开始判断
            for (int k = 19; k >= 0; --k)
            {

                // if (k == 0 && a[k] % 2 == 0)
                //     // cout << 0 << endl; // 当直到最后一位1个数为偶数时，一定是平局
                //     printf("0\n");

                if (a[k] == 1)
                { // 1个数是1
                    // cout << 1 << endl;
                    printf("1\n");
                    break;
                }
                else if (a[k] % 2 == 0)
                    continue; // 1个数为偶数
                else
                {

                    if ((n - a[k]) % 2 == 0)
                    { // 1个数为奇数，0个数为偶数，先手赢
                        // cout << 1 << endl;
                        printf("1\n");
                        break;
                    }
                    else // 1和0个数都为奇数，后手赢
                    {
                        // cout << -1 << endl;
                        printf("-1\n");
                        break;
                    }
                }
            }
        }
    }

    return 0;
}