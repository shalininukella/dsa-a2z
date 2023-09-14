// my solution 
//time complexity is o(n) and space complexity O(1) because only 3 elements in the map hence constant space o(1)
/*
class Solution {
public:
    void sortColors(vector<int>& a) {
          map<int , int> mp;
          int n= a.size();
          for(int i = 0;i<n ; i++){
              mp[a[i]]++;
          }
          a.clear();
          for(auto& i : mp){
              for (int j= 0; j< i.second;j++){
                  a.push_back(i.first);
              }
          }
        
    }
};
*/



// using duscth flag algorithm
// time complexity= o(n)
// space = o(1)
class Solution {
public:
    void sortColors(vector<int>& a) {
        int n= a.size();
        int low=0, mid=0, high=n-1;
        while(mid<=high){
        if(a[mid]==0){
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if ( a[mid]==1){
            mid++;
        }
        else {
            swap(a[mid], a[high]);
            high--;
        }
    }
    }

};


// using count variable 
// time complexity= o(n)
// space = o(1)
/*class Solution{
public:
    void sortColors(vector<int>& a) {
        int n= a.size();
        int c0=0, c1=0, c2=0;
        for(int i =0; i<n; i++){
            if(a[i]==0){
            c0++;
        }
            else if( a[i]==1){
                c1++;
            }
            else{
                c2++;
            }
        }
        for(int i =0; i<c0; i++){
            a[i]=0;
        }
        for(int i=c0 ; i< c0+c1; i++){
            a[i]=1;
        }
        for(int i=c0+c1 ; i< n; i++){
            a[i]=2;
        }
    } 
};
*/