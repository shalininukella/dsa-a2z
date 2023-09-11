//brute force 

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

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
int removeDuplicates(vector<int>& a){
   int i=0, j=1;
    while(j<a.size()){
         if(a[i]==a[j]){
             j++;
         }
         else{
         i++;
         a[i]=a[j];
         }
    }
    return i+1;
}
};
