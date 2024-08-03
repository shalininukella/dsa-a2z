// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;

//         while (left <= right) {
//             int mid = (left + right) / 2;

//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] >= nums[left]) {
//                 if (nums[left] <= target && target <= nums[mid]) {
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             } else {
//                 if (nums[mid] <= target && target <= nums[right]) {
//                     left = mid + 1;
//                 } else {
//                     right = mid - 1;
//                 }
//             }
//         }

//         return -1;        
//     }
// };


class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0,h=a.size()-1;
        while(l<=h){
            int m=(l+h)/2;

            if(a[m]==target){
                return m;
            }

            else if(a[l]<=a[m]){
                //left half is sorted 
                if(target >= a[l] && target <= a[m]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }

            else {
                //right is sorted
                if(target>=a[m] && target<=a[h]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            } 
        } 
        return -1;  // if not found 
    }
};