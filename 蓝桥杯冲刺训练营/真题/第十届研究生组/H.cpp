/*
5
2 1 1 3 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;



int main(){


    time_t start;
    start = time(NULL);

    int n;
    cin >> n;
    vector<int> v(n,0);

    // for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) v[i] = 1;

    cout << v[0] << " ";
    map<int , int > tmp_map;
    for (int i = 1; i < n; ++i){
        // vector<int> tmp_v(v.begin(), v.begin()+i);
        tmp_map.clear();

        for (int j = 0; j < i; ++j){
            tmp_map[v[j]] = 1;
        }

        // if (find(tmp_v.begin(), tmp_v.end(), v[i]) != tmp_v.end()){
        //     v[i] = *upper_bound(v.begin(), v.begin()+i, v[i])+1;
        // }

        // if (tmp_map[v[i]] == 1){
        //     v[i] = upper_bound(tmp_map.begin(), tmp_map.end(), v[i])->first+1;
        // }

        while(tmp_map[v[i]] == 1){
            v[i]++;
        }

        // while(find(tmp_v.begin(), tmp_v.end(), v[i]) != tmp_v.end()){
        //     v[i]++;
        // }
        cout << v[i] << " ";
    }

    time_t end;
    end = time(NULL);
    clock_t

    // cout << end-start << endl;
    cout << difftime(end, start) << endl;
    return 0;
}