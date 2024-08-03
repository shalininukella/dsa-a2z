//optimal 
// tc : O(logn)
//space : 0(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        vector<int> ans;
        int l=0,h=a.size()-1;
        int first =-1, last =-1;

//to ge the first occurence
        while(l<=h){
            int m = l + (h - l) / 2;
            if(target<=a[m]){
                if (a[m] == target) 
                    first = m;
                h=m-1;
            }
            else {
                l=m+1;
            }
        }
//to get the last occurence 
        l=0,h=a.size()-1;
        while(l<=h){
            int m = l + (h - l) / 2;
            if(a[m]<=target){
                if (a[m] == target) 
                    last = m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
                
    return {first,last};
    }
};

// // tc : O(logn)+O(k) = 0(n)
// //space : 0(1)

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& a, int target) {
//         vector<int> ans;
//         int l=0,h=a.size()-1;
//         int first =-1, last =-1;

//         while(l<=h){
//             int m = l + (h - l) / 2;
//             if(a[m]==target){
//                 first =m; last = m;
//                 while(first>0 && target==a[first-1]){
//                     first --;
//                 }

//                 while(last<a.size()-1 && a[last+1]==target){
//                     last++;
//                 }
//                 break;
//             }

//             else if (a[m]>target){
//                 h=m-1;
//             }
//             else l=m+1;
//         }
//         return {first,last};
//         }
// };