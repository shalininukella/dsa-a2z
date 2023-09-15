//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int onmask=(1<<(i-1));
        int offmask= ~(1<<(i-1));
        int a=num & onmask;
        if(a==0)cout<<0<<" ";
        else if(a!=0)cout<<1<<" ";
        
        /*a | 1 = 1 and 0 | 1 = 1 = to change 0 to 1 and 
        rest are obviously 0s in the 32 bit representation of 1. 
        Hence, 0|a=a, shame as it is will be changed. */
        cout<< (num | onmask)<< " "; 
        
        /*Similarly 1 & 0 = 0 = to change 1 to 0, if already 0 is there, 
        returns the same no. without any change. Since rest all are ones in the nagation
        1&a gives 'a', hence rest all witll be printed as they are. */
        cout<<(num & offmask)<<" "; 
        
    }
};




//or my solution using pow function 
 /*class Solution {
       public:
  void bitManipulation(int num, int i) {
  // your code here
        int onmask=(1<<(i-1));
        int x;
        int a=num & onmask;
        if(a==0) {
            x=0;
            cout<<0<<" ";
        }
        else {
            x=1;
            cout<<1<<" ";
        }
        long long one=(num-pow(2, (i-1))), zero=(num+pow(2, (i-1)));
        if(x==1){
            cout<<num << " "<< one;
        }
        else cout<<zero << " "<< num;
    }
};*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
