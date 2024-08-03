// Mine
// TC : O(logn)
// SC: O(1)

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int ans = nums[0];
//         int low = 0 , high = nums.size()-1;
//         if(nums[low] < nums[high]){
//             return nums[low];
//         }
//         while(low <= high){
//             if(nums[low] < nums[high]){
//                 ans = min(ans , nums[low]);
//                 break;
//             }

//             int mid = (low + high)/2;
//             ans = min(ans , nums[mid]);

//             if(nums[mid] >= nums[low]){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid -1 ;
//             }
            
//         }

//         return ans;
        
//     }
// };


// Mine
// TC : O(logn)
// SC: O(1)

// class Solution {
// public:
//     int findMin(vector<int>& a) {
//         int l = 0, h = a.size() - 1;

//         // Handle the case where the array is not rotated
//         if (a[l] <= a[h]) {
//             return a[l];
//         }

//         while (l <= h) {
//             int m = (l + h) / 2;

//             // Check if mid element is the minimum
//             if (m > 0 && a[m] < a[m - 1]) {
//                 return a[m];
//             }
//             // Check if mid+1 element is the minimum
//             if (m < a.size() - 1 && a[m] > a[m + 1]) {
//                 return a[m + 1];
//             }

//             // Adjust search range
//             if (a[m] >= a[l]) {
//                 l = m + 1;
//             } else {
//                 h = m - 1;
//             }
//         }

//         // This line should never be reached
//         return -1;
//     }
// };


// Stirver
// TC : O(logn)
// SC: O(1)

class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, h = a.size() - 1;
        int mini = INT_MAX;
        
        // Handle the case where the array is not rotated
        if (a[l] <= a[h]) {
            return a[l];
        }

        while (l <= h) {
            int m = (l + h) / 2;

            if(a[l]<=a[m]){
                //left half is sorted
                mini = min(mini, a[l]);
                l=m+1;
            }

            else{
                //right half is sorted 
                mini = min(mini, a[m]);
                h=m-1;
            }
        }
        return mini;
    }
};

