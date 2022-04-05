> 真题链接:[https://www.lanqiao.cn/courses/2786/learning/?id=88890](https://www.lanqiao.cn/courses/2786/learning/?id=88890)

## 结果填空题

### A. 约数个数

直接for循环遍历，每次判断对78120求余是否为0 ，为0就是78120的约数。答案：96

```cpp
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
```

### D. 蛇形填数

按照蛇形方式为数组赋值，然后取第20行20列结果。实现思路如下：
- 首先判断应该累加多少个数
- 然后判断是上行赋值还是下行赋值
- 对于上行赋值，第一次让x加1，y不变，此后每次x-1，y+1
- 对于下行赋值，第一次让x不变，y加1，此后每次x+1，y-1

最终答案：761

```cpp
#include <iostream>

using namespace std;

int nums[40][40];

int main()
{

    int up_down = 0; // 1-up, 0-down
    int cul = 2;
    int current = 1;

    int x = 0, y = 0;

    int nx = 1;
    int ny = -1;

    nums[0][0] = 1;

    while (nums[19][19] == 0)
    {
        cout << "pass" << endl;
        for (int i = 1; i <= cul; ++i)
        {
            if (up_down == 0)
            {
                nx = 1;
                ny = -1;

                if (i == 1)
                {
                    y += 1;
                }
                else
                {
                    x += nx;
                    y += ny;
                }
            }
            else
            {
                nx = -1;
                ny = 1;

                if (i == 1)
                {
                    x += 1;
                }
                else
                {
                    x += nx;
                    y += ny;
                }
            }

            current += 1;
            // cout << x << " " << y << endl;
            nums[x][y] = current;
        }

        cul++;
        up_down ^=1;
    }

    for (int i = 0; i < 40; ++i)
    {
        for (int j = 0; j < 40; ++j)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << nums[19][19] << endl;

    return 0;
}
```

### E. 七段码

这题通过DP遍历7段数码管的每种组合状态作为发光段，然后判断每种状态是否满足相连。判断相连思路如下：
- 首先通过vector保存每段数码管临近数码管
- 将待判断状态的每个数码管的邻居都压入map中
- 循环判断待判断状态每个数码管，只要有一个不在上一步的map中，则表示不能形成连通的发光符号

答案：80

```cpp
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

map<char, bool> neigh;// 邻居数码管
vector<string> last, current; // 上一次遍历状态，这一次遍历状态
set<string> ans;// 

map<char, vector<char> > structure; // 每段数码管的邻居

bool cmp(string s1, string s2){
    return s1.size() < s2.size();
}

bool check(string s){

    if (s.size()==1 || s.size()==7) return true;
    neigh.clear();// 清空邻居


    // 将状态s中每个数码管的邻居压入map neigh中
    for (int i = 0; i < s.size(); ++i){

        vector<char> tmp_v;

        tmp_v = structure[s[i]];

        for (int j = 0; j < tmp_v.size();++j){
            neigh[tmp_v[j]] = true;
        }
        
    }

    // 再次遍历s，如果有一个数码管不在map neigh中，则表示不能相连
    for (int i = 0; i < s.size(); ++i){
        if(neigh[s[i]]==false) return false;
    }

    return true;
}

void init(){
       // 跟据7段数码管的结构，为每个数码管赋值邻居
    structure['a'].push_back('f');
    structure['a'].push_back('b');

    structure['b'].push_back('a');
    structure['b'].push_back('g');
    structure['b'].push_back('c');

    structure['c'].push_back('b');
    structure['c'].push_back('g');
    structure['c'].push_back('d');
    
    structure['d'].push_back('e');
    structure['d'].push_back('c');

    structure['e'].push_back('f');
    structure['e'].push_back('g');
    structure['e'].push_back('d');

    structure['f'].push_back('a');
    structure['f'].push_back('g');
    structure['f'].push_back('e');
    
    structure['g'].push_back('f');
    structure['g'].push_back('e');
    structure['g'].push_back('b');
    structure['g'].push_back('c');
}

int main(){

    init();

    int cnt = 0;

    last.push_back("a");

    for(int i = 0; i < 6; ++i){// 每次添加一种数码管，和上一次状态遍历形成新的状态

        current = last;

        string tmp_str(1, char(i+'b'));
        current.push_back(tmp_str);

        for (int j = 0; j < last.size(); ++j){
            cnt++;
            tmp_str = last[j]+char(i+'b');

            cout << tmp_str << endl;

            current.push_back(tmp_str); 
        }

        last = current;

    }

    cout << "total nums = " << current.size() << endl;

    sort(current.begin(), current.end(), cmp);

    for (int i = 0; i < current.size(); ++i){

        if(check(current[i])){
            cout << current[i] << "\n";
            ans.insert(current[i]);
        }
    }

    cout << "ans = " << ans.size()-3 << endl; //-3是排除这种check算法会误判的3种状态，abde, bcef, acdf
    return 0;
}
```

## 程序设计题

### F. 成绩分析

> OJ提交网站：[https://www.dotcpp.com/oj/problem2570.html](https://www.dotcpp.com/oj/problem2570.html)

```cpp
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
```

### G. 回文日期

> OJ提交网站：[https://www.dotcpp.com/oj/problem2571.html](https://www.dotcpp.com/oj/problem2571.html)

直接for循环判断每次n值，需要注意的是对于n需要是合法的日期，需要判断闰年平年。

```cpp
/*
20200202
10000101
89991231
*/
#include <iostream>
#include <sstream>
using namespace std;

int month_1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年
int month_2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年

stringstream ss;

inline bool years(int n){//是否是闰年

    if (n%400==0) return true;
    else if (n%100==0) return false;
    else if (n%4==0) return true;

}

inline bool legal_date(int n){
    int tmp = n;
    int day = tmp%100;
    
    tmp/=100;

    int month = tmp%100;
    tmp/=100;

    int year = tmp;

    if (years(year)){
        if (month<=12 && month>0 && day <= month_1[month-1]) return true;
    }
    else
    {
        if (month<=12 && month>0 && day <= month_2[month-1]) return true;
    }

    return false;
}

inline bool check_palindrome(string n){
    
    for (int i = 0; i < 8;++i){
        if (n[i]!=n[7-i]) return false;
    }
    return true;
}

inline bool chech_AB(string n){
    if (n[0] != n[1] && n[0]==n[2] && n[2]==n[5] && n[5]==n[7] && n[1]==n[3] && n[3]==n[4] && n[4]==n[6]) return true;

    return false;
}

int main(){

    int n;
    cin >> n;
    n++;

    while (true)
    {

        ss.str("");
        ss << n;
        
        if (check_palindrome(ss.str()) && legal_date(n)){
            cout << n << endl;        
            break;
        }
        n++;
    }

    while(true){
        
        ss.str("");
        ss << n;
                
        if (chech_AB(ss.str()) && legal_date(n)){
            cout << n << endl;
            break;
        }
        n++;
    }

    return 0;
}
```

### H. 作物杂交

> OJ提交网站：[https://www.dotcpp.com/oj/problem2590.html](https://www.dotcpp.com/oj/problem2590.html)

这题用DP+DFS求解，用DP存储每个种子的最小培养时间，已有的种子培养时间为0。注意每种种子培养方案不止一种，所以在DFS中遍历每种种子的杂交方案，更新每种种子的最小培养时间。在本代码中，最关键的DP更新策略就是$dp_v[c] = min(dp_v[c], max(dp_v[a], dp_v[b])+max(time_v[a], time_v[b]));$

```cpp
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
```

### I. 子串分值和

> OJ提交网站：[https://www.dotcpp.com/oj/problem2585.html](https://www.dotcpp.com/oj/problem2585.html)

非AC答案。通过递归+剪枝暴力通过了45分。思路如下：
- 跟据题目中解析可以发现子串有两种形式变化
    - 字符串逐渐删去最后一个字符，记这个操作为pos_traverse
    - 字符串逐渐删去第一个字符，记这个操作为pre_traverse
    - 获得答案的过程如下：对输入字符s进行pre_traverse得到新字符s_pre, 然后对s_pre另存为s_pre2，对s_pre2进行pos_traverse操作直到s_pre2长度为1。然后对s_pre继续进行pre_traverse操作，循环此操作，直到s_pre长度为1。

- 通过counts函数，每次计算字符串中不同字符个数，并保留结果避免重复计算

```cpp
/*
ababc

*/
#include <iostream>
#include <map>

using namespace std;

map<string ,int > map_table ; // 记录已经计算好的字符串中字母个数
map<string ,int > map_pos; // 记录已经计算好的后遍历结果
map<string ,int > map_pre; // 记录已经计算好的前遍历结果

map<char, bool> alpha;// 记录每个字母是否出现

int counts(string s){ // 计算字符串中不同字母个数

    // cout << s << endl;

    if (map_table[s] != 0){
        // cout << s << endl;
        return map_table[s];//如果需要计算的字符串已经计算过，直接返回结果
    }

    alpha.clear();
    int len_s = s.size();

    for (int i = 0; i < len_s; ++i){
        alpha[s[i]] = true;
    }

    map_table[s] = alpha.size();//记录已经计算过的结果
    return alpha.size();
}

int pos_traverse(string s){ // 后遍历，每次把最后一个字符舍去，直到只有一个字符
    if (s.size()==1) return 1;

    if (map_pos[s] != 0) return map_pos[s];

    string ori_str = s;

    int cnt = counts(s);
    s.erase(s.size()-1);

    int cnt_pos = pos_traverse(s);
    map_pos[ori_str] = cnt+cnt_pos;
    return cnt + cnt_pos;
}

int pre_traverse(string s) { // 前遍历，每次把第一个字符舍去，直到只有一个字符
    if (s.size()==1) return 1;

    if (map_pre[s] != 0) return map_pre[s];

    int pos_cnt = pos_traverse(s);
    // cout << s << ":" << pos_cnt << endl;

    // 去掉字符串第一个字符
    string s2(s.begin()+1, s.end());
    int pre_cnt = pre_traverse(s2);

    map_pre[s] = pos_cnt + pre_cnt;
    return pos_cnt + pre_cnt;
}

int main(){

    string s;

    cin >> s;

    // cout << counts(s) << endl;
    cout << pre_traverse(s);

    return 0;
}
```