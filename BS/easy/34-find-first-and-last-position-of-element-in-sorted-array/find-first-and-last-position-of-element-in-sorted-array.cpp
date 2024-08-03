// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int first = -1, last = -1;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 first = mid;
//                 last = mid;
//                 while (first > 0 && nums[first - 1] == target) {
//                     first--;
//                 }
//                 while (last < nums.size() - 1 && nums[last + 1] == target) {
//                     last++;
//                 }
//                 break;
//             }
//             else if (nums[mid] < target) {
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
        
//         return {first, last};
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        vector<int> ans;
        int l=0,h=a.size()-1;
        int first =-1, last =-1;

        while(l<=h){
            int m = l + (h - l) / 2;
            if(a[m]==target){
                first =m; last = m;
                while(first>0 && target==a[first-1]){
                    first --;
                }

                while(last<a.size()-1 && a[last+1]==target){
                    last++;
                }
                break;
            }

            else if (a[m]>target){
                h=m-1;
            }
            else l=m+1;
        }
        return {first,last};
        }
};