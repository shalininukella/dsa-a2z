// my solution 
//time complexity is o(n) and space complexity O(1)
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