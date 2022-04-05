#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int my_lower_bound(int *nums, int len, int target){

	// nums 升序排列

	int left = 0;
	int right = len-1;

	while(left <= right){

		int mid = left + ((right-left)>>1);

		// lower_bound是找第一个大于等于的数，所以对于小于target的数划分为一边
		// 然后将大于等于target的数划分到一边
		if (nums[mid] < target){
			right = mid+1;
		}
		else{
			left = mid; // 这里不是mid-1,而是mid,原因就是要保留大于等于target的数
		}
	}

	return (nums[left] >= target)? left : len;
}

int my_upper_bound(int *nums, int len, int target){

}

int main(){
	
	int nums[] = {1,2,4,6,7,10,11,23,333};

	int len = sizeof(nums)/ sizeof(nums[0]);

	cout << my_lower_bound(nums, len, 20) << endl;

	cout << my_lower_bound(nums, len, 11) << endl;

	cout << my_lower_bound(nums, len, 500) << endl;
	

    return 0;
}
