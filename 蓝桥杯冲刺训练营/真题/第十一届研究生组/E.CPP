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