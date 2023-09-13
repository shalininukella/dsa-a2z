// time comolexity = o(n)
//space complexity = o(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size();
        int max_zeroes=0, size=0;
        for ( int i =0; i<n; i++){
            if ( a[i]==1){
                size++;
                max_zeroes= max(max_zeroes, size);
            }
            else{
                size=0;
            }
        }
        return max_zeroes;
    }
};
