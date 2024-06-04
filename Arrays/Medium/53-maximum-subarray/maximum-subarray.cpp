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

// if asked to return the array as well - Kadane's algo 

/*
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}
*/


//brute force 
/*

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
*/




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