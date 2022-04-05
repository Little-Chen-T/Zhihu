#include <iostream>
#include <map>
using namespace std;

int main()
{

    map<int, int> num_table;
    int find = 0; // find == 1时表明找到了

    for (int i = 0; i < 10; ++i)
    {
        num_table[i] = 2021; // 初始化每张卡片张数
    }

    int ans = 1;

    while (find == 0)
    {
        cout << ans << endl;
        
        int tmp = ans;

        while (tmp)
        {
            int digit = tmp % 10; //每次取个位

            if (num_table[digit] == 0){
                find = 1;
                break;// 如果某个整数剩余为0，则表明找到了结果
            }
            else
            {
                num_table[digit] -= 1; // 对应整数减一
                tmp /= 10; // 扔掉个位数字
            }
        }

        for (int i = 0; i < 10; ++i){
            cout << "table " << i <<  ":" << num_table[i] << endl;
        }

        if (find == 0) ans++;

    }

    cout << "the ans is :" << ans - 1;

    return 0;
}