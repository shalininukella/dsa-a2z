class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return true;
        }

        int rotations = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                rotations++;
            }
            if (rotations > 1) {
                return false;
            }
        }

        return true;
    }
};

