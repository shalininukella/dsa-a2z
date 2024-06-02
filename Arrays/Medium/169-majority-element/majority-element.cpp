//Moore's Voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        int c=0;
        int ele=0;
        for (int i=0; i< n;i++){
            if(c ==0){
                c = 1;
                ele=a[i]; // element = current element
            }
            
            //if  element = current element
            else if (ele == a[i]){
                c++;
            } 
            
            //if  element != current element
            else c--;
        }
        return ele;
    }
        
    /*  when the question doesn't guarantee thaht the majority 
    element always exists in the array.
    
    // check if the max element we found occurs more than n/2 times or not 
        int count1=0;
        for (int i=0; i<n; i++){
            if( ele == a[i]){
                count1++;
            }
        }
        if(count1 > n/2){
            return ele;
        }
    } */ 
};
