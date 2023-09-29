/*Brute force is to list all the permutations, search for the given permutation in the question 
and then find the immediate next permutation on the searched question in the question

*/

//1) using next_permutation funtion 
//time complexity = O(N)
//space complexity = O(1)
// class Solution {
// public:
//     void nextPermutation(vector<int>& a) {
//         next_permutation(a.begin(), a.end());
//     }
// };


//2) mycode
//tc=O(N)
//sc=o(1)
// class Solution {
// public:
//     void nextPermutation(vector<int>& a) {
//         int n = a.size();
//         int i, brkpnt, greater;
//         for (i = n - 1; i > 0; i--) {
//             if (a[i] > a[i - 1]) {
//                 brkpnt = i - 1;
//                 break;
//             }
//         }

//         if (i <= 0) {
//             // If no breakpoint is found, the array is in descending order.
//             // Reverse the entire array to get the smallest permutation.
//             reverse(a.begin(), a.end());
//         } else {
//             for (int j = n - 1; j >= i; j--) {
//                 if (a[i - 1] < a[j]) {
//                     greater = j;
//                     break;
//                 }
//             }
//             swap(a[brkpnt], a[greater]);
//             reverse(a.begin() + brkpnt + 1, a.end());
//         }
//     }
// };

//3)or use brk pt's loop as i=n-2 to 0 ans compare i and i+1 --- striver 
//tc=O(N)
//sc=o(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the breakpoint
        int breakpoint=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
          if(nums[i]<nums[i+1]){
            breakpoint=i;
            break;
          }  
        } 
        if(breakpoint==-1){reverse(nums.begin(),nums.end());return;}
        
        //find least greater of element at the breakpoint
        int leastgreater=-1; 
        int leastGvalue=101;
        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                if(nums[i]<leastGvalue){
                    leastgreater=i;
                    leastGvalue=nums[i];
                }
            }
        }

        //now swap breakpoint with leastgreater
        swap(nums[breakpoint],nums[leastgreater]);
        
        //reverse everything after the breakpoint
        reverse(nums.begin()+breakpoint+1,nums.end());
return;
}
};
