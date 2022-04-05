# 1. 题目描述
题目来源：http://poj.org/problem?id=3984
## Description
定义一个二维数组：

```c++
int maze[5][5] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};
```
它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
## Input
一个$5 × 5$的二维数组，表示一个迷宫。数据保证有唯一解。
## Output
左上角到右下角的最短路径，格式如样例所示。
## Sample Input
```cpp
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
```
## Sample Output
```cpp
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
```
# 2. 解题思路
这题要求解从左上角$(0, 0)$走到右下角$(4, 4)$的最短路径走法。即，有明确的起点和终点，且要求最短路径，故本题可采用广度优先搜索算法(BFS)。

将迷宫视为图，值为0的节点表示可访问，值为1的节点不可访问。由于题目要求输出路径，所以每个节点应该有其全部**上级节点**信息，这里用一个带有坐标和上级节点信息的结构体$point$来表示每个节点。
```cpp
struct point{
	
	int x;
	int y;
	vector<string> p_point;// 所有上级节点 
};
```
每次遍历节点4个方向的时候，将当前节点压入其上级节点中，以走到终点的时候能直接通过上级节点获取从起点走到终点的路径。
# 3. 代码
## 3.1 C++代码
```cpp
#include <iostream> 
#include <vector>
#include <queue>
#include <stdio.h>
#include <sstream> 
using namespace std;

struct point{
	
	int x;
	int y;
	vector<string> p_point;// 所有上级节点 
};

int visit[5][5]; // 访问过的数组
int maze[5][5]; // 迷宫 

int nx[] = {0,0,1,-1};
int ny[] = {1,-1,0,0};

stringstream ss;

int main(){
	
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j)
			scanf("%d", &maze[i][j]);
	} 
	
	queue<point> Q;
	point tmp2 = {0,0};
	Q.push(tmp2);
	
	while(!Q.empty()){
		
		point current = Q.front();
		Q.pop();
		visit[current.x][current.y] = 1;
		
		// 判断当前点是否是终点
		if (current.x==4&&current.y==4){
			int len_v = current.p_point.size();
			
			for (int j = 0; j < len_v; ++j){
				cout << current.p_point[j] << endl;
			}
			cout << "(4, 4)";
			break;
		} 
		
		for (int i = 0; i < 4; ++i){ // 遍历4个方向 
			int c_x = current.x+nx[i];
			int c_y = current.y+ny[i];
			
			// 判断行走方向是否是已经走过的，或者出界或者是墙 
			if (c_x<0 || c_x>4 || c_y<0 || c_y>4 || visit[c_x][c_y]==1||maze[c_x][c_y]==1)
				continue;
			
			ss << "(";
			ss << current.x;
			ss << ", ";
			ss << current.y;
			ss << ")";
			
			string tmp_str = ss.str();
			vector<string> tmp_v = current.p_point;
			tmp_v.push_back(tmp_str);
			
			ss.str("");
			point tmp_p = {c_x,c_y,tmp_v};
			Q.push(tmp_p);
		}
		
	}
	
	return 0; 
}
```
## 3.2 Python代码
```python
from distutils.command.config import LANG_EXT
from sys import maxsize
import numpy as np

# 存储是否访问的数组
visit = np.zeros([5,5], dtype=np.int)
maze = np.zeros([5,5], dtype=np.int)

# 四个方向x,y增量
nx = [0,0,1,-1]
ny = [1,-1,0,0]

def BFS():

    list_q = []
    
    list_q.append({'x':0,'y':0,'parent':[]})
    
    while(len(list_q) != 0):
        
        current_p = list_q[0].copy()
        list_q.pop(0)
        
        # 当前遍历点x,y坐标
        c_x = current_p['x']
        c_y = current_p['y']
        
        visit[c_x][c_y] = 1
        
        # 到达终点
        if (c_x==4 and c_y==4):
            # print("pass")
            for i in range(len(current_p['parent'])):
                print(current_p['parent'][i])
            print("(4, 4)")
            break
            
        # 遍历4个方向
        for i in range(4):
            # 下一个节点坐标
            n_x = c_x+nx[i]
            n_y = c_y+ny[i]

            # 判断下一个节点坐标是否合法，是否访问过，以及是否是墙
            if (n_x<0 or n_x>4 or n_y<0 or n_y>4 or visit[n_x][n_y]==1 or maze[n_x][n_y]==1):
                continue
            
            # 将当前节点信息压入下一个节点上级节点
            
            tmp_parent = current_p['parent'].copy()
            if (tmp_parent!=None):
                tmp_parent.append("("+str(c_x)+", "+str(c_y) + ")")
            else:
                tmp_parent = "("+str(c_x)+", "+str(c_y) + ")"
            
            list_q.append({'x':n_x,'y':n_y,'parent':tmp_parent})
            
            
if __name__ == '__main__':
    
    # 输入数据
    for i in range(5):
        tmp_input = input().split()
        
        for j in range(5):
            maze[i][j] = int(tmp_input[j])
    
    # print(maze)
    
    BFS()
```

# 4. 代码细节

## 4.1 四个方向的遍历
```cpp
    int nx[] = {0,0,1,-1};
    int ny[] = {1,-1,0,0};
```
这里采用当前节点坐标$x,y\text{分别与}nx[i],ny[i]$相加的方式实现4个方向的遍历。

## 4.2 上级节点信息
由于题目是需要输出完整移动路径，所以这里直接通过$vector<string>$去存储输出格式的坐标点。

通过$stringstream$实现字符串的拼接。
```cpp
    ss << "(";
    ss << current.x;
    ss << ", ";
    ss << current.y;
    ss << ")";
```

## 4.3 copy()
在Python代码中，注意使用深拷贝copy()。