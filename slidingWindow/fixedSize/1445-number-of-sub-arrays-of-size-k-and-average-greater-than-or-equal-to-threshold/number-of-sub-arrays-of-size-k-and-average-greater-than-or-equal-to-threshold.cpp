class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int t) {
        int i=0,j=0;
        int cnt = 0;
        int sum=0;
        int n = a.size();
        while(j<n){
            //calculations
            sum+=a[j];

            if(j-i+1<k){
                j++;
            }

            else if(j-i+1 == k){
                if(sum/k >= t){
                    cnt++;
                }
                sum -= a[i];
                i++;
                j++;
            }
        }
        return cnt;
    }
};