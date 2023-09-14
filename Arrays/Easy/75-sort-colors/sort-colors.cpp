// my solution 
//time complexity is o(n) and space complexity O(1)

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


// using two pointers 