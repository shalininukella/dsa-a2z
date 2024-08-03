//tc : O(logn)
//sc:O(1)

class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0,h=a.size()-1;
        while(l<=h){
            int m=(l+h)/2;

            if(a[m]==target){
                return m;
            }

            else if(a[l]<=a[m]){
                //left half is sorted 
                if(target >= a[l] && target <= a[m]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }

            else {
                //right is sorted
                if(target>=a[m] && target<=a[h]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            } 
        } 
        return -1;  // if not found 
    }
};
