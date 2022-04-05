# 1. 题目描述

**题目来源：**[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：
```cpp
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```

示例 2：
```cpp
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
```

# 2. 解题思路

此题想求解独立岛屿的数量，可以采用DFS思想求解。由于上下左右是岛屿的地方视作一个岛屿，故可以遍历整个grid，发现一个岛屿后就不断的从这个地方出发，去遍历上下左右的岛屿，只要遍历时遇到的岛屿均置为$0$，同时从新的岛屿开始遍历，直到把这**一片岛屿**均置为0为止。

更多的细节可以见C++代码，代码中有详细的注释。

# 3. 代码
## 3.1 C++代码
```cpp
class Solution {
public:

int m,n; // grid的宽和长
int cnt; // 总的岛屿数

    void traveseGrid(vector<vector<char> >& grid, int i, int j){
        int nx[] = {0,0,-1,1};// nx,ny用于上下左右遍历
        int ny[] = {1,-1,0,0};
        
        for (int index = 0; index < 4; ++index){
            int next_x = i+nx[index];
            int next_y = j+ny[index];

            // 当下一个点的坐标不在（m,n）范围时，继续for循环
            if (next_x<0 || next_x>=m || next_y<0 || next_y>=n) continue;

            // 如果遍历中发现新的岛屿，将其置为0，并从这里开始遍历寻找他附近的岛屿。因为与这个岛屿连接的岛屿和最初那块岛屿也是属于同一片岛屿，所以也需要遍历
            if (grid[next_x][next_y]=='1'){
                grid[next_x][next_y] = '0';
                traveseGrid(grid,next_x,next_y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();
        cnt = 0;

        //双重for 循环遍历整个grid,发现一个岛屿后，然后不断的递归去遍历他周围的岛屿，直到将这一片岛屿都置为0
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){

                if (grid[i][j]=='1'){
                  //因为grid是引用，所以在函数中对他的改变会改变全局，当一片岛屿都被置为0后，再去遍历grid的时候，那片岛屿都是0，所以只需要加一个数量就行
                    cnt++;
                    grid[i][j] = '0';

                    traveseGrid(grid,i,j);
                }
            }
        }
        
        return cnt;
    }
};
```

## 3.2 Python代码
```python
class Solution:

    def traverseGrid(self,grid,i,j):
        nx = [1,-1,0,0]
        ny = [0,0,1,-1]

        for index in range(4):
            next_x = nx[index]+i
            next_y = ny[index]+j

            if (next_x<0 or next_x>=m or next_y<0 or next_y>=n): continue

            if (grid[next_x][next_y]=="1"):
                grid[next_x][next_y] = 0
                self.traverseGrid(grid,next_x, next_y)

    def numIslands(self, grid: List[List[str]]) -> int:

        # 声明全局变量
        global m,n
        
        cnt = 0
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if (grid[i][j]=="1"):
                    grid[i][j] = 0
                    cnt = cnt+1

                    self.traverseGrid(grid,i,j)

        return cnt
```

# 4. 代码细节

## 上下左右遍历
这里采用了$nx,ny$作为坐标的累加值去实现上下左右移动，$nx,ny$中的顺序不重要，只要$nx[i], ny[i]$的组合能覆盖$(0,1),(0,-1),(1,0),(-1,0)$就可以了。这种遍历的技巧很实用，关于$nx,ny$的使用可以参考我另一篇关于BFS的文章——[蓝桥杯冲刺训练营之BFS——例1.迷宫问题](https://blog.csdn.net/qq_32614873/article/details/123645355?spm=1001.2014.3001.5501)。