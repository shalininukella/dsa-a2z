class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        vector<int> ans;
        //int maxi = INT_MIN;
        map<int, int> m;
        while(j < n){
            m[nums[j]]++;

            if(j-i+1 < k){
                j++;
            }

            else {
                ans.push_back(m.rbegin()->first);
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};