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

class Solution {
    public :
    int singleNumber(vector<int>& a){
        int n = a.size(), x=0;
        if (n==1){
            return a[0];
        }
        for (int i=0; i<n ; i++){
           x^=a[i];
        }
        return x;
    }
};