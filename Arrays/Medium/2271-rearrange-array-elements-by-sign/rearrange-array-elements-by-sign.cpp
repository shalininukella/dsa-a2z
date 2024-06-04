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


#include <vector>
using namespace std;

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

//when pos and neg are not equal, then follow the first one, since the leftover 
// pos or neg will be added alternatively leaving blanks

/*
  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
}
*/