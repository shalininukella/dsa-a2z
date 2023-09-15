//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//using & operator
class Solution{   
public:
    string oddEven(int N){
        if(N & 1) // eg: N = 1010 and & with 1, hence, 1010 & 0001, so gives the LSB
        {
            return "odd";
        }else return "even";
    }
};

//or normal %2
// class Solution{   
// public:
//     string oddEven(int N){
//         if(!(N%2==0)){
//             return "odd";
//         }
//         else return "even";
//         // code here 
//     }
// };

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
