// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& a) {
//         vector<int> pos;
//         vector<int> neg;
//         for(int i=0;i<a.size();i++){
//             if(a[i]>0)
//                 pos.push_back(a[i]);
//             else 
//                 neg.push_back(a[i]);
//         }
//         for(int i=0;i<a.size()/2;i++){
//             a[2*i] = pos[i];
//             a[(2*i)+1] = neg[i];
//          }
//          return a;
//     }
// };



class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& a) {
            int n = a.size(); // Initialize n with the size of the input vector
            int posInd = 0, negInd = 1;
            vector<int> ans(n, 0); // Use n to initialize the size of ans

            for (int i = 0; i < a.size(); i++) {
                if (a[i] > 0) {
                    ans[posInd] = a[i];
                    posInd += 2;
                } else {
                    ans[negInd] = a[i];
                    negInd += 2;
                }
            }
            return ans;
        }
};
