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
//find the brkpnt
//         for (i = n - 1; i > 0; i--) {
//             if (a[i] > a[i - 1]) {
//                 brkpnt = i - 1;
//                 break;
//             }
//         }

//if the brk pt is not found i.e the array is sorted in decreasing order, i.e the last permutation , reverse it.
//         if (i <= 0) {
//             // If no breakpoint is found, the array is in descending order.
//             // Reverse the entire array to get the smallest permutation.
//             reverse(a.begin(), a.end());
//         } 

 /* if brk pt is just smaller than the elemnet which we are searchig from the end(greater) swap it. 
 Since the array is sorted in the decresing order till that brk point and we are finding the element
which is just greater than the brkpnt, so when we swap it, the subarray which was sorted in the 
decreasing order will still be in the decreasion order. hence after reversing that subarray we'll
 get an increasning order of that subarry just after the position where brkpt used to present. 
 Now again this continues from the ending, the searching for the brk pnt, swapping and reversing, 
 since the permutations are starting from the ending means 1,2,3,4,5 -> 1,2,3,5,4 so here last 
 two have changed, then next will be 1,2,4,3,5 now here brkpoint is 3 and last 3 have changed 
 including 3. now since we've swapped 3 with 4, now we'll again start the permutaion from the 
 ending for every 2 elements , then 3 elements then 4 elements..... */
//            
//          else {
//             for (int j = n - 1; j >= i; j--) {
//                 if (a[brkpnt] < a[j]) {
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
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         //find the breakpoint
//         int breakpoint=-1;
//         int n=nums.size();
//         for(int i=n-2;i>=0;i--){
//           if(nums[i]<nums[i+1]){
//             breakpoint=i;
//             break;
//           }  
//         } 
//         if(breakpoint==-1){reverse(nums.begin(),nums.end());return;}
        
//         //find least greater of element at the breakpoint
//         int leastgreater=-1; 
//         int leastGvalue=101;
//         for(int i=n-1;i>breakpoint;i--){
//             if(nums[i]>nums[breakpoint]){
//                 if(nums[i]<leastGvalue){
//                     leastgreater=i;
//                     leastGvalue=nums[i];
//                 }
//             }
//         }

//         //now swap breakpoint with leastgreater
//         swap(nums[breakpoint],nums[leastgreater]);
        
//         //reverse everything after the breakpoint
//         reverse(nums.begin()+breakpoint+1,nums.end());
// return;
// }
// };

//4) striver , same tc = o(n), sc=o(1)

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int brkpnt = -1;
        int n = a.size();
        
        // Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                brkpnt = i;
                break;
            }
        }
        
        // If no breakpoint, it's already the last permutation, hence reverse the whole array
        if (brkpnt == -1) {
            reverse(a.begin(), a.end());
            return;  // Return immediately after reversing the entire array
        }
        
        // Find a number from brkpnt+1 index to n-1 which is just greater than the brkpnt element
        for (int i = n - 1; i > brkpnt; i--) {
            if (a[i] > a[brkpnt]) {
                swap(a[i], a[brkpnt]);
                break;
            }
        }
        
        // Reverse the array from brkpnt+1 to n-1
        reverse(a.begin() + brkpnt + 1, a.end());
    }
};

