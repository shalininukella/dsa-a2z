class Solution {
  public:
  
    /*
    --------------------------------------------
    ✅ Sliding Window Approach (Only Non-Negative Integers)
    --------------------------------------------
    This method uses the two-pointer (sliding window) technique to find the longest subarray 
    with sum exactly equal to `k`. It works **only when all array elements are non-negative**.

    - We maintain a window from index `i` to `j`.
    - Expand the window by adding `a[j]` to the sum.
    - If the sum exceeds `k`, shrink the window from the left (increase `i`).
    - If the sum becomes exactly `k`, update the maximum length.
    - Time Complexity: O(n)
    - Space Complexity: O(1)
    */

    /*
    int longestSubarray(vector<int> &a, int k){
        int maxL = 0;
        int sum = 0, i = 0, j = 0;
        int n = a.size();

        while (j < n) {
            sum += a[j];  // Expand the window by adding a[j]

            // Shrink the window if sum exceeds k
            while (sum > k && i <= j) {
                sum -= a[i];
                i++;
            }

            // Check for exact match
            if (sum == k) {
                maxL = max(maxL, j - i + 1);
            }

            j++; // Move the right end of the window
        }

        return maxL;
    }
    */

    /*
    --------------------------------------------
    ✅ Prefix Sum + Hash Map Approach (Works for Negative Numbers)
    --------------------------------------------
    This method uses a prefix sum and a hash map to track the first occurrence of each prefix sum.
    It works even when the array contains negative numbers.

    - At each index, we calculate the running sum (`sum`).
    - If `sum == k`, the subarray from index 0 to `i` is valid.
    - If `sum - k` has been seen before, the subarray between that previous index + 1 and `i` sums to `k`.
    - Store the first occurrence of every prefix sum in a map to get the longest possible subarray.
    - Time Complexity: O(n)
    - Space Complexity: O(n)
    */
    
     int longestSubarray(vector<int> &a, int k){
        int sum = 0, n = a.size(), maxL = 0;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            sum += a[i];
            
            if(sum == k){
                maxL = max(maxL, i+1);
            }
            
            int rem = sum - k;
            
            if(mp.find(rem) != mp.end()){
                maxL = max(maxL, i-mp[rem]);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxL;
     }
};
