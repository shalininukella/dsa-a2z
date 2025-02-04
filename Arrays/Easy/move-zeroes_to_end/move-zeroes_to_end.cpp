/* my solution( beats 100s%)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0; j<n;j++){
            if(nums[i]!= 0){
                i++;
            }

            else if(nums[i]==0 && nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};
*/

/* my solution( beats 80%)
class Solution {
public:
    void moveZeroes(vector<int>& a) {
      int n = a.size();
      int i = 0;
      int j = 1;
      while ( i <= j && j<n){
        if( a[i]==a[j] && a[i]!=0){
            i++;
            j++;
        }
        else if (a[i]==a[j] && a[i]==0){
            j++;
          }
        else if (a[i]!=a[j] && a[i]==0 && a[j]!=0){
          swap(a[i], a[j]);
        }
        else {
          i++;
          j++;
        }
      }
        
    }
}; */

//other solution striver beats ( 90%)
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i = -1;
        int j; // Declare j outside of the loop

        int n = a.size();

        // Find the first zero in the array
        for (j = 0; j < n; j++) {
            if (a[j] == 0) {
                i = j;
                break;
            }
        }

        // If we can't find a zero in the array, return
        if (i == -1) {
            return;
        }

        // Move non-zero elements to the front
        for (j = i + 1; j < n; j++) {
            if (a[j] != 0) {
                swap(a[i], a[j]);
                i++;
            }
        }
    }
};


//chatgpt beats 80%
/*class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int i = 0; // Initialize i at the beginning of the array

        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                swap(a[i], a[j]);
                i++;
            }
        }
    }
};*/


// for both time is o(n) and space is o(1)
