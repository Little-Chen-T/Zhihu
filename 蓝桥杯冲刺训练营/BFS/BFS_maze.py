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
        
        current_p = list_q[0]
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