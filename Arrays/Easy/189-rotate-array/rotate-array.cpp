class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within bounds

        if (k == 0) {
            return; // No need to rotate if k is 0
        }

        vector<int> temp(nums.begin() + n - k, nums.end()); // Store the last k elements in temp
        nums.erase(nums.begin() + n - k, nums.end()); // Remove the last k elements from nums
        nums.insert(nums.begin(), temp.begin(), temp.end()); // Insert the elements from temp at the beginning of nums
    }
};
