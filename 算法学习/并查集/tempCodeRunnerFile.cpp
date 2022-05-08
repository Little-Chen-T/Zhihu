/*
3 
2 4 1 
0 0 1 
0 0 3 
2 5 1 
0 0 1 
0 0 4 
2 5 2 
0 0 2 
2 0 4
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct my_point{
    double x, y,z;

    bool operator<(my_point const& p) const { 
        return p.z<z; 
    }

    void print_value(){
        cout << "x:" << x << endl;
        cout << "y:" << y << endl;
        cout << "z:" << z << endl;
    }
};

double eps = 0.00001;
int T, n,h,r;
my_point tmp_p;
vector<my_point> v(1001,tmp_p);// 保存输入的孔的点数据
vector<my_point> v_down(1001, tmp_p);// 与底面相交或者相切的孔
// double rank_value[1001]; //孔的优先度，即其高度
// map<my_point, double> high; // 某个孔上级高度
map<my_point, my_point> pre; // 某个孔上级孔

bool same_my_point(my_point p1, my_point p2){
    double x1 = p1.x, x2 = p2.x;
    double y1 = p1.y, y2 = p2.y;
    double z1 = p1.z, z2 = p2.z;

    if (fabs(x1-x2)<=eps && fabs(y1-y2)<=eps && fabs(z1-z2)<=eps) return true;

    return false;
}

//距离计算函数
double dis(my_point p1, my_point p2){
    double x1 = p1.x, x2 = p2.x;
    double y1 = p1.y, y2 = p2.y;
    double z1 = p1.z, z2 = p2.z;

    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}

// 判断是否相交或者相切
bool cross(my_point p1, my_point p2, string up_down="normal"){
    if (up_down == "up"){ // 上表面
        return (h-p1.z-r) <= eps;
    }
    else if (up_down == "down"){ //下表面
        return (p1.z-r) <= eps;
    }
    else if (up_down == "normal"){
        return (dis(p1,p2)-2*r)<=eps;
    }
    else{
        cout << "input error\n";
    }
}

//寻找某个孔根节点孔
my_point find(my_point p){
    if (same_my_point(pre[p], p)) return p;
    return pre[p] = find(pre[p]);
}


// 将后一个点合并到前一个点
void join(my_point p1, my_point p2){
    my_point pre1 = find(p1);
    my_point pre2 = find(p2);
    // cout << "high p2" << p2.z << " high p1" <<p1.z << endl;
    // p2.print_value();

    if (cross(p1,p2,"normal") && p1.z<p2.z){
        // cout << "joined" << endl;
        pre[pre1] = p2;
    }
}

bool cmp(my_point p1, my_point p2){
    return p1.z < p2.z;
}

int main(){
    //输入数据，保存在vector， 合并高度，找到和底面相切的点，寻找其根高度，判断是否大于高度h
    cin >> T;

    while(T--){
        // v.clear();
        // v_down.clear();
        // high.clear();
        pre.clear();

        int down = 0;
        int normal = 0;
        int find_flag = 0;
        
        cin >> n >> h >> r;
        find_flag = 0;
        for (int i = 0; i < n; ++i){
            cin >> tmp_p.x >> tmp_p.y >> tmp_p.z;
            // tmp_p.print_value();
            // v[i] = tmp_p;
            if(cross(tmp_p, tmp_p, "down")) v_down[down++]=tmp_p;
            else v[normal++] = tmp_p;
            // high[tmp_p] = tmp_p.z+r;// 初始化每个点上级高度为自己高度
            pre[tmp_p] = tmp_p;// 某个孔初始上级为自己
        }

        if (v_down.empty()) cout << "No" << endl;
        else{//让每一个
            // 让v里面的元素按照my_point高度由低到高排序

            // cout << "len_v" << normal << " " << "len_down" <<down<< endl;
            sort(v.begin(), v.begin()+normal, cmp);

            for (int i = 0; i < down; ++i){
                for (int j = 0; j < normal; ++j){
                    join(v_down[i], v[j]);
                }

                if (cross(find(v_down[i]), find(v_down[i]), "up")){//当某个与底面相交的孔与上面相交时，输出Yes
                    cout << "Yes" << endl;
                    find_flag = 1;
                    break;
                }

                // find(v_down[i]).print_value();
            }

            if (find_flag==0) cout << "No" << endl;
        }
    }

    return 0;
}