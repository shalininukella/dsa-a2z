// class Solution {
// public:
//     void nextPermutation(vector<int>& a) {
//         int n = a.size();

//         vector<int> b(a);
//         sort(b.begin(), b.end(), greater<int>());
    
//         if(a==b){
//             sort(a.begin(), a.end());
//         }
//          else{
//              swap(a[n-1], a[n-2]);
//          }
//     }
// };



//using next_permutation funtion 
//time complexity = O(N)
//space complexity = O(1)
// class Solution {
// public:
//     void nextPermutation(vector<int>& a) {
//         next_permutation(a.begin(), a.end());
//     }
// };



class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i, brkpnt, greater;
        for (i = n - 1; i > 0; i--) {
            if (a[i] > a[i - 1]) {
                brkpnt = i - 1;
                break;
            }
        }

        if (i <= 0) {
            // If no breakpoint is found, the array is in descending order.
            // Reverse the entire array to get the smallest permutation.
            reverse(a.begin(), a.end());
        } else {
            for (int j = n - 1; j >= i; j--) {
                if (a[i - 1] < a[j]) {
                    greater = j;
                    break;
                }
            }
            swap(a[brkpnt], a[greater]);
            reverse(a.begin() + brkpnt + 1, a.end());
        }
    }
};

