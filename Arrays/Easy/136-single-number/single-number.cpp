//using xor - most optimized 
// time = o(n)
// space = o(1)
class Solution {
    public :
    int singleNumber(vector<int>& a){
        int x=0;
        for (int i=0; i<a.size() ; i++){
           x^=a[i];
        }
        return x;
    }
};



//using hasing array
// not working for [-1] or any negative inputs since hash array doesnt have negative indices hence use unordered map.
/*class Solution {
     public :
   int singleNumber(vector<int>& arr){
//size of the array:
    int n = arr.size();
    if (n == 1) {
        return arr[0];
    }
    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
};*/


/*//using unordered_map
// Time Complexity: O(N*logM) + O(M)
//space complexity: O(M), M= (N/2) + 1
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        if ( n==1){
            return a[0];
        }
        unordered_map<int, int> mp;

        //time = O(nlogm), size of map= m=()n/2)+1 i.e every element is twice + 1 element which occurs once 
        for( int i=0;i<n;i++){
            mp[a[i]]++;
        }

        //time = o(m)
        for(auto i : mp){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
};*/


/* 
//brute force 
//Time Complexity: O(N2
//Space : O(1)
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
};
*/

/* TLE not at all optimised but works 
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        if ( n==1){
            return a[0];
        }
        sort( a.begin(), a.end());
        int i=0;
        while ( i < n){
            if ( a[i]== a[i+1]){
                i+2;
            }
            else {
                break;
            }
        }
        return a[i];
    }
};
*/


