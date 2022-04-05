> 真题链接：[第十二届C&C++研究生组](https://www.lanqiao.cn/courses/2786/learning/?id=280828)

## 结果填空题

### A. 卡片

这题可以采用while循环判断，当某个数字需要的某个整数没有的时候就表示上一个数是最大能拼凑的结果了。最终结果：3181

```cpp
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
```

### B. 直线

这题可以采用数学知识求解，不过我不太会，在这里采用编程暴力求解的方式解决。思路如下：

- 跟据两点坐标以及直线的斜截式方程$:y=kx+b$可知，直线可由斜率$k = tan(\theta)=(y_2-y_1)/(x_2-x_1)$以及偏移中心距离$b = (x_2*y_1-y_2*x_1)/(x_2-x_1)$**唯一**确定。

- 采用斜截式方程，需要判断特殊情况，并特殊处理。即$x_2=x_1$的情况。

- 基于上面的分析，暴力四重$for$循环（第1，2重循环确定第一个点，第3，4重循环确定第二个点），每次先判断是否是同一个点，对于不同的点$(x_1,y_1),(x_2,y_2)$，保留其约分后的$k$以及$b$的分数形式到$set$中，最后，取$set$的大小就是答案

注：为验证程序是否正确，可以先测试题目给出的样例以及自建小样例。本题最终答案：40257

```cpp
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int GCM(int a, int b) {//最大公倍数

    if(a == b) return a;

    if (a < b){
        return GCM(max(b-a,a), min(b-a,a));
    }
    else
    {
        return GCM(max(a-b,b), min(a-b,b));   
    }
    
}

int main(){

    int len_x = 20;
    int len_y = 21;
    stringstream ss;
    int GCM_value;
    int tan_neg_or_pos;//标志tan正负
    int b_neg_or_pos; // 标志b正负

    set<string> ans_set; 

    for (int x_1 = 0; x_1 < len_x; ++x_1){

        for (int y_1 = 0; y_1 < len_y; ++y_1){
            // 前两层for循环取第一个点

            for (int x_2 = 0; x_2 < len_x; ++x_2){

                for (int y_2 = 0; y_2 < len_y; ++y_2){
                    // cout << "pass" << endl;
                    // 后两层for 循环取第二个点
                    if (!(x_1 == x_2 && y_1 == y_2)){
                        // cout << "pass" << endl; 
                        ss.str("");
                        int dx = x_2-x_1;
                        int dy = y_2-y_1;
                        //特殊情况，0和无穷大
                        if (dy == 0){
                            ss << "0 " << y_1;
                            ans_set.insert(ss.str());
                            continue;
                        }
                        else if (dx == 0){
                            ss << "INF " << x_1;
                            ans_set.insert(ss.str());
                            continue;
                        }

                        if (dx*dy<0) tan_neg_or_pos = 0;
                        else tan_neg_or_pos = 1;

                        // b = (x_2*y_1-y_2*x_1)/(x_2-x_1)
                        int b1 = x_2*y_1-y_2*x_1;
                        int b2 = x_2-x_1;
                        if (b1*b2<0) b_neg_or_pos = 0;
                        else b_neg_or_pos = 1;

                        GCM_value = GCM(abs(dx), abs(dy));
                        ss << (tan_neg_or_pos==0?"-":"+") << abs(dx/GCM_value) << "/" << abs(dy/GCM_value) << " ";// 传入tan

                        if (b1 == 0){
                            ss << "0";
                        }
                        else{
                            GCM_value = GCM(abs(b1),abs(b2));
                            ss << (b_neg_or_pos==0?"-":"+") << abs(b1/GCM_value) << "/" << abs(b2/GCM_value); //传入b值
                        }
                        ans_set.insert(ss.str());
                    }
                }
            }
        }
    }

    set<string>::iterator it = ans_set.begin();

    while (it != ans_set.end())
    {
        cout << *it << endl;
        it++;
    }
    
    cout << "The ans is :" << ans_set.size() << endl;

    return 0;
}
```

### C. 货物摆放

这题如果直接用两重for循环跑肯定跑不出来，跟据提意，我们可以找到2021041820210418的因子，然后三重for循环组合这些与因子，只要他们相乘等于2021041820210418就是一种结果。最终答案：2430

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
#define ULL unsigned long long int

int main(){
    ULL ans = 2021041820210418;
    set<ULL> s;
    // ULL ans = 8;
    ULL result = 0;
    ULL i,j,k;

    for(i = 1; i <= sqrt(ans);i++){
        if (ans%i==0){
            cout << i << endl;
            // s.push_back(i);
            s.insert(i);
            if (i*i!=ans) s.insert(ans/i);
        }
    }

    int len = s.size();
    cout << "len=" << len << endl;
   
    set<ULL>::iterator it1, it2, it3;

    for (it1=s.begin();it1!=s.end();++it1)
    for (it2=s.begin();it2!=s.end();++it2)
    for (it3=s.begin();it3!=s.end();++it3)
        if ((*it1)*(*it2)*(*it3)==ans){
            cout << *it1 << " " << *it2 << " " << *it3 << endl;
            result++;
        }

    cout << result << endl;

    return 0;
}
```

## 程序设计题

### F. 时间显示

> OJ提交网站：[https://www.dotcpp.com/oj/problem2609.html](https://www.dotcpp.com/oj/problem2609.html)

```cpp
#include <iostream>

using namespace std;
#define ll long long int

int main(){

    ll sec;

    cin >> sec;

    sec = int(sec/1000); //转化成s

    // cout << sec << endl;

    int hour = sec / 3600;
    sec -= 3600*hour;

    int min = (sec)/60;
    sec -= 60*min;

    printf("%02d:%02d:%02d\n", hour%24, min%60, sec%60);

    return 0;
}
```

### G. 砝码称重

动态规划，每次放入一个砝码，和前面的砝码进行加减操作，得到新的重量状态，知道最后一个砝码放置，即可获得答案。

> OJ提交网站：[https://www.dotcpp.com/oj/problem2604.html](https://www.dotcpp.com/oj/problem2604.html)

```cpp
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
```

### H. 异或数列
> OJ提交网站：https://www.dotcpp.com/oj/problem2605.html

```cpp

```