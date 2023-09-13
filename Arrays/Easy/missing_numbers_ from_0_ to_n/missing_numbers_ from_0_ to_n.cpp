/ my solution 
// time= o(n)
// space = o(1)

class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int sum= (n*(n+1))/2;
        int new_sum= accumulate( a. begin(), a. end(), 0);
        if (new_sum == sum ){
            return 0;
        }
        else return ( sum - new_sum );
        
    }
};



// using xor( striver )
// time= o(n)
// space = o(1)
/*class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int xor1 = 0, xor2 = 0;
        for ( int i=1; i<=n;i++){
            xor1 = xor1 ^ i;
        }
        for ( int i=0; i<n;i++){
            xor2 = xor2 ^ a[i];
        }
        return (xor1 ^ xor2);
    }
};
*/

/*brute force 

// time= o(n^2)
// space = o(1)

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
*/

/* using hashing 
  // time= o(n)+ o(n)
// space = o(n)

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
*/

