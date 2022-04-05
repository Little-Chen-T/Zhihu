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