//optimal - striver
//tc: O(n)
//sc: o(n) for ans vector

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        //select an interval
        for(int i=0;i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back({intervals[i][0], intervals[i][1]});
            }

            else{
                //intervals[i][0] <= ans.back()[1]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};


// //brute force 
// //tc: 
// //sc: o(n) for ans vector

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& a) {
//         int n = a.size();
//         sort(a.begin(), a.end());
//         vector<vector<int>> ans;
        
//         //select an interval
//         for(int i=0;i<n; i++){
//             int start = a[i][0];
//             int end = a[i][1];
//             if(!ans.empty() && ans.back()[1] >= end){
//                 //skip selecting the intervals which can already be the part of the last interval present in the ans vector
//                 continue;
//             }

//             for(int j=i+1;j<n;j++){
//                 //if the current jth interval can be merged with the selected ith interval
//                 if(end >= a[j][0]){
//                     end = max(end, a[j][1]);
//                 }

//                 else{
//                     //can't be merged i.e end < a[j][0]
//                     break; //out of jth loop
//                 }
//             }
//             ans.push_back({start, end});
//         }
//         return ans;
//     }
// };


//LC solutions

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
//       if(intervals.size()==1)
//          return intervals;
//       vector<pair<int,int>> p;
//       for(int i=0;i<intervals.size();i++)
//       {
//           p.push_back({intervals[i][0],intervals[i][1]});
//       } 
//       sort(p.begin(),p.end());

//       vector<vector<int>> ans;
//       int f=p[0].first,s=p[0].second;
//       for(int i=0;i<p.size()-1;i++)
//       {
//           vector<int> a(2);
//           if(s>=p[i+1].first)
//           {
//               s=max(s,p[i+1].second);
//           }
//           else
//           {
//               a[0]=f;
//               a[1]=s;
//               f=p[i+1].first;
//               s=p[i+1].second;
//               ans.push_back(a);
//           }
//       } 
//       int n=intervals.size();
//       ans.push_back({f,s});
//       return ans;
//     }
// };

