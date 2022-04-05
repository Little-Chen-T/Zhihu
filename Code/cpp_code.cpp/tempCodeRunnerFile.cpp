int binary_insert(int *num, int len, int target){
//     if (num == NULL || len == 0) return -1;

//     int left = 0;
//     int right = len;
//     int mid = -1;

//     while(left <= right){
//         mid = left + (right-left);

//         if (num[mid] == target) return mid;

//         if (target < num[left]) return left;
//         else if (target > num[right]){
//             return right+1;
//         }else{

//             if (target < num[mid]){
//                 right = mid-1;
//             }
//             else{
//                 left = mid+1;
//             }
//         }
//     }
// }
