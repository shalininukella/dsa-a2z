// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         if(nums.size() < 3) return ans;
//         sort(nums.begin(), nums.end());
        
// for(int i = 0; i < nums.size()-2; ++i)
//         {
//             if(i != 0 && nums[i] == nums[i-1])
//                 continue;
            
//             int a = i + 1, b = nums.size() -1, t;
//     while(a < b)
//             { 
//                 t = nums[i] + nums[a] + nums[b];
//                 if(t > 0)
//                     b--;
//                 else if(t < 0)
//                     a++;
//                 else
//                 {
//                     ans.push_back({nums[i] , nums[a] , nums[b]});
//                     a++; b--;
//                     while(nums[a] == nums[a-1] && a < b)
//                         a++;
//                     while(nums[b] == nums[b+1] && a < b)
//                         b--;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


// //1) brute force - TLE - 3 loops 
// //tc = O(N3 * log(no. of unique triplets)), where N = size of the array.
// //inserting triplets into the set takes O(log(no. of unique triplets))
// //But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// //Space Complexity: O(2 * no. of the unique triplets) as we are using a set 
// //data structure and a list to store the triplets.

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& a) {
//         set<vector<int>> st;
//         int n=a.size();

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     int sum = a[i]+a[j]+a[k];
//                     if(sum==0){
//                         vector<int> temp={a[i],a[j],a[k]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp); // to have unique elements 
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };


// //2) Better - using hashset to remove the third loop - TLE 
// //TC: O(n^2 * log(no. of unique triplets)), sorting only 3 elements, so ignore
// //SC: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a 
// //list to store the triplets and extra O(N) for storing the array elements in another set.
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& a) {
//         set<vector<int>> st;
//         int n = a.size();

//         for(int i=0;i<n;i++){
//             set<int> hashset;
//             for(int j=i+1;j<n;j++){
//                 int third = -(a[i]+a[j]);

//                 if(hashset.find(third)!=hashset.end()){
//                     vector<int> temp = {a[i],a[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(a[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;

//     }
// };


//Optimal

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(), a.end());

        for(int i=0;i<n;i++){
            //skipping the duplicates
            if(i!=0 && a[i-1]==a[i])
                continue;

            int j=i+1, k=n-1;
            while(j<k){
                int sum = a[i]+a[j]+a[k];

                if(sum>0)
                    k--;

                else if(sum<0)
                    j++;

                else{
                    //when sum==0
                    vector<int> temp={a[i],a[j],a[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    //skip the suplicated of a[j] and a[k]
                    while(j<k && a[j-1]==a[j])
                        j++;
                    while(j<k && a[k+1]==a[k])
                        k--;
                }
            }   
        }
        return ans;
    }
};
