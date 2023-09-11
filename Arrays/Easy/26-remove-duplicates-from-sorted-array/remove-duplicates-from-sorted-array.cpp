//brute force using hashset 


//time= O(nlogn) + O(n)= logn for one insertion iinto the set insertion 
//space= O(n)

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> a;
//         for( int i=0; i < nums.size(); i++){
//             a.insert(nums[i]);
//         }
//         auto it=a.begin();
//         for (int i =0; i < a.size(); i++, it++){
//             nums[i]= *it;
//         }
//         return a.size();
//     }
// };

//optimal using two pointers 
 class Solution {
 public:
int removeDuplicates(vector<int>& arr)
{
  int i = 0;
  for (int j = 1; j < arr.size(); j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
 };
