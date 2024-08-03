//1)

//Time Complexity: 
//\U0001d442(\U0001d45b)

//Space Complexity: 
//O(n)

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        // your code here
        int i=0,j=0;
        int n = a.size();
        deque<int> dq;
        vector<int> ans;

        while(j<n){
            //calculation
            while(!dq.empty() && a[j]>dq.back()){
                dq.pop_back();
            }

            dq.push_back(a[j]);

            if(j-i+1 < k){
                j++;
            }

            else if (j-i+1 == k){
                //ans
                ans.push_back(dq.front());
                if(a[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};


//2)
//OMG!!!! my solution - leetcode hard - sliding window - fixed size - might not be optimal

//Time Complexity: 
//\U0001d442(\U0001d45blog \U0001d458)

//Space Complexity: 
//O(k)
//k = size of map

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int i=0,j=0;
//         int n = nums.size();
//         vector<int> ans;
//         //int maxi = INT_MIN;
//         map<int, int> m;
//         while(j < n){
//             m[nums[j]]++;

//             if(j-i+1 < k){
//                 j++;
//             }

//             else {
//                 ans.push_back(m.rbegin()->first);
//                 m[nums[i]]--;
//                 if(m[nums[i]]==0){
//                     m.erase(nums[i]);
//                 }
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };

