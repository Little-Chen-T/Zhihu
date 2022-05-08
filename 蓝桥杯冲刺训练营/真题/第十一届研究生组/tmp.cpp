#include <iostream>
using namespace std;

int main()
{
	int cnt = 1;			
	for (int x = 1; x <= 127; x ++)
	{
		cout << "====" << cnt ++ << "====" << endl;
		for (int i = 0; i < 7; i ++)
		{
			if(i == 0)
			{
				if(x >> i & 1) cout << " --";
				cout << endl;
			}
			if(i == 1)
			{
				if(x >> i & 1) cout << '|';
				else cout << " ";
			}
			if(i == 2)
			{
				if(x >> i & 1) cout << "  |";
				cout << endl;
			}
			if(i == 3)
			{
				if(x >> i & 1) cout << " --";
				cout << endl;
			}
			if(i == 4)
			{
				if(x >> i & 1) cout << '|';
				else cout << " ";
			}
			if(i == 5)
			{
				if(x >> i & 1) cout << "  |";
				cout << endl;
			}
			if(i == 6)
			{
				if(x >> i & 1) cout << " --";
				cout << endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}
