






//2)
//OMG!!!! my solution - leetcode hard - sliding window - fixed size - might not be optimal

//Time Complexity: 
//𝑂(𝑛log 𝑘)

//Space Complexity: 
//O(k)
//k = size of map

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        vector<int> ans;
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
