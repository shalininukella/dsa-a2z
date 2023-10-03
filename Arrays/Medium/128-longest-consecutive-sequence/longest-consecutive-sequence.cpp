//optimal (striver)
//tc=o(2n)+o(n)=o(n)
//sc=o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(a.size()==0){
            return 0;
        }
        int longest = 1; 
        int cnt = 1;
        unordered_set<int> st;
        //to add elements into the set (unique will be added)
        for(int i =0;i < a.size();i++){
            st.insert(a[i]);
        }       

        //to iterate thtrough every element, 
        for(auto it: st){

            //continue the loop if the current element(it)-1 is found i.e the starting element of the sequence is not found.
            if(st.find(it-1)!=st.end()){
                continue;
            }

            //if currentelement-1 is no more there, the "it" is the starting of the sequence 
            else if(st.find(it-1)==st.end()){
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                longest= max(longest, cnt);
                cnt=1;
            }
        } 
    return longest;
    }
};

// //better approach using sorting(mine)
// //tc=o(nlogn)+o(n)
// //sc=o(1)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& a) {
//         if(a.size()==0){
//             return 0;
//         }
//         int longest=1;
//         int cnt=1;
//         sort(a.begin(), a.end());
//         for(int i =0;i<a.size()-1;i++){
//             if(a[i+1]-a[i]==1){
//                 cnt++;
//             }
//             else if (a[i+1]-a[i]==0){
//                 continue;
//             }
//             else if(a[i+1]-a[i]!=1){
//                 cnt=1;
//             }
//             longest=max(longest, cnt);
//         }
//         return longest;
//     }
// };


// // Brute force (striver)
// //tc = o(n^2) TLE
// //sc= o(1)
// class Solution {
// public:

//     bool linearSearch(vector<int>& a, int num){
//         int n = a.size();
//         for(int i=0;i<n;i++){
//             if(a[i]==num){
//                 return true;
//             }
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& a) {

//         int n = a.size();
//         if(n==0) return 0;

//         int longest=1;
//         int cnt=1;

//         for(int i =0; i<n;i++){
//             int x = a[i];
//             while(linearSearch(a, x+1)){
//                 cnt++;
//                 x++;
//             }
//             longest=max(longest, cnt);
//             cnt=1;
//         }
//         return longest;
//     }
// };




