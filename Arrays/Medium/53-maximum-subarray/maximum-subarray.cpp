//Kadane's algorithm
class Solution{
    public:
    int maxSubArray(vector<int>& a){
        int sum=0;
        int maxi=INT_MIN;

        for(int i=0;i<a.size();i++){
            sum += a[i];

            if(sum>maxi){
                maxi=sum;
            }

            /*if , not else if cuz, next iteration me abhi jo negative h vo add ho jaega, bcuz 
            aesa bhi ek case ho skta h [-2,3,4], in this case sum=-2 in the first iteration and else if dekhega toh 
            use sirf consider bhi nhi karega kyunki 1st time m obviously sum was > maxi, so 2nd iteration me
             -2+3 hoga toh sum =1 */
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};



// class Solution {
// public:
//     vector<int> pre, suf;
//     int maxSubArray(vector<int>& nums) {
//         pre = suf = nums;
//         for(int i = 1; i < size(nums); i++)  pre[i] += max(0, pre[i-1]);
//         for(int i = size(nums)-2; ~i; i--)   suf[i] += max(0, suf[i+1]);
//         return maxSubArray(nums, 0, size(nums)-1);
//     }
//     int maxSubArray(vector<int>& A, int L, int R){
//         if(L == R) return A[L];
//         int mid = (L + R) / 2;
//         return max({ maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1] });
//     }	
// };