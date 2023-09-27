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
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        next_permutation(a.begin(), a.end());
    }
};
        

