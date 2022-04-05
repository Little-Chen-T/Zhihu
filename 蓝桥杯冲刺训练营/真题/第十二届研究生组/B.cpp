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

    set<string> ans_set; // 对于tan = 2/5，直接放入set 2/5, 对于tan = -2/5，同理放入-2/5

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
                        //特殊情况，0和无穷大，他们分别对应0和90°
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

                        // cout << dx << " " << dy << endl;
                        GCM_value = GCM(abs(dx), abs(dy));
                        ss << (tan_neg_or_pos==0?"-":"+") << abs(dx/GCM_value) << "/" << abs(dy/GCM_value) << " ";// 传入tan
                        // cout << GCM_value << endl;

                        
                        if (b1 == 0){
                            ss << "0";
                        }
                        else{
                            // cout << b1 << " " << b2 << endl;
                            GCM_value = GCM(abs(b1),abs(b2));
                            ss << (b_neg_or_pos==0?"-":"+") << abs(b1/GCM_value) << "/" << abs(b2/GCM_value); //传入b值
                        }

                        // cout << ss.str() << endl;

                        ans_set.insert(ss.str());
                    }
                    
                }
            }
        }
    }

    // set<string>::iterator it = ans_set.begin();

    // while (it != ans_set.end())
    // {
    //     cout << *it << endl;
    //     it++;
    // }
    
    cout << "The ans is :" << ans_set.size() << endl;

    return 0;
}