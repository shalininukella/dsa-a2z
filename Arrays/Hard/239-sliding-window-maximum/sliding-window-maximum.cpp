//1)

//Time Complexity: 
//\U0001d442(\U0001d45b)

//Space Complexity: 
//O(n)

// class Solution {
//   public:
//     vector<int> maxSlidingWindow(vector<int>& arr, int k) {
//         // your code here
//         int n = arr.size();
//         deque<int>q;
//         int i=0,j=0;
//         vector<int>res;
//         while(j<n){
//             while(!q.empty() && q.back()<arr[j]) q.pop_back();
//             q.push_back(arr[j]);
//             if(j-i+1<k) j++;
//             else if(j-i+1==k){
//                 res.push_back(q.front());
//                 if(q.front()==arr[i]) q.pop_front();
//                 i++;
//                 j++;
//             }
//         }
//         return res;
//     }
// };


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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        // next greater index
        vector<int>NGI(n);
        stack<int>st;
        NGI[n-1]=n;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) NGI[i]=n;
            else NGI[i]=st.top();
            st.push(i);
        }
        // window maximum
        vector<int>ans;
        for(int i=0; i<n-k+1; i++){
            int Wmax=arr[i];
            int j=i;
            while(j < i+k){
                Wmax=arr[j];
                j=NGI[j];
                //j++;
            }
            ans.push_back(Wmax);
        }
        return ans;
    }
};
