//using temp array 

/*Time Complexity: O(n)

Space Complexity: O(k) since k array element needs to be stored in temp array


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 0 || k>n) {
            return; // No need to rotate if k is 0
        }
        k = k % n; // Ensure k is within bounds

        vector<int> temp(nums.begin() + n - k, nums.end()); // Store the last k elements in temp
        nums.erase(nums.begin() + n - k, nums.end()); // Remove the last k elements from nums
        nums.insert(nums.begin(), temp.begin(), temp.end()); // Insert the elements from temp at the beginning of nums
    }
}; */


//using reversal algorithm as well as user defined reverse 

// time complexity O(n)
// space complexity O(1)


/*class Solution {
    public :
    void reverse_f(vector<int>& a , int start, int end){
        while(start<=end){
            int temp = a[start];
            a[start]= a[end];
            a[end]=temp;
            end--;
            start++;
        }
    }
     void rotate(vector<int>& a, int k ){
         int n = a.size();
         if(k==0){
             return;
         }
         k=k%n;
         reverse_f(a, 0, n-k-1);
         reverse_f(a, n-k, n-1);
         reverse_f(a, 0, n-1);
     }
};
*/


//using reversal algorithm inbuilt reverse 
// time complexity O(n)
// space complexity O(1)
class Solution {
    public :
     void rotate(vector<int>& a, int k ){
         int n = a.size();
         if(k==0){
             return;
         }
         k=k%n;
         reverse(a.begin(), a.begin()+n-k);
         reverse(a.begin()+n-k, a.end());
         reverse(a.begin(), a.end());
     }
};


