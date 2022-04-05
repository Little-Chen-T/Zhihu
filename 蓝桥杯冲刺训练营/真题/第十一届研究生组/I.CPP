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

inline int counts(string s){ // 计算字符串中不同字母个数

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

inline int pos_traverse(string s){ // 后遍历，每次把最后一个字符舍去，直到只有一个字符
    if (s.size()==1) return 1;

    if (map_pos[s] != 0) {
        // cout << "pos:" << s << endl;
        return map_pos[s];
    }

    string ori_str = s;

    int cnt = counts(s);
    s.erase(s.size()-1);

    int cnt_pos = pos_traverse(s);
    map_pos[ori_str] = cnt+cnt_pos;
    return cnt + cnt_pos;
}

inline int pre_traverse(string s) { // 前遍历，每次把第一个字符舍去，直到只有一个字符
    // if (s.size()==1) return 1;

    // if (map_pre[s] != 0) {
    //     // cout << "pre:" << s << endl;
    //     return map_pre[s];
    // }

    // int pos_cnt = pos_traverse(s);
    // // cout << s << ":" << pos_cnt << endl;

    // // 去掉字符串第一个字符
    // string s2(s.begin()+1, s.end());
    // int pre_cnt = pre_traverse(s2);

    // map_pre[s] = pos_cnt + pre_cnt;
    // return pos_cnt + pre_cnt;
    int len_s = s.size();

    int sum = pos_traverse(s);
    
    while(s.size() != 1){
        string s2(s.begin()+1, s.end());
        s = s2;

        sum += pos_traverse(s2);
    }

    return sum;
}

int main(){

    string s;

    cin >> s;

    // cout << counts(s) << endl;
    cout << pre_traverse(s);

    return 0;
}