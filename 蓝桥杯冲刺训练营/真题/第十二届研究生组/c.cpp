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