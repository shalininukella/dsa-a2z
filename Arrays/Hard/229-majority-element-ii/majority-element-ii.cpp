class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size(); //size of the array

        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1=0, cnt2=0;

        for(int i=0;i<n;i++){
            if(cnt1==0 && a[i]!=ele2){
                cnt1=1;
                ele1=a[i];
            }
            else if(cnt2==0 && a[i]!=ele1){
                cnt2=1;
                ele2=a[i];
            }
            else if(a[i]==ele1) cnt1++;
            else if(a[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        //manually check if the ele1, ele2 are the majority elements, cuz 
        //it's not given that they must contain for sure in the array.
        // So, ele1 and ele2 are the 2 most occuring element in the array 
        //so to make sure that the count of those majority elements is >n/3

        cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==a[i])
                cnt1++;
            if(ele2==a[i]) 
                cnt2++;
        }     
    
        vector<int> res;
        //check if cnt1, cnt2>n/3
        if(cnt1>int(n/3))
            res.push_back(ele1);
        if(cnt2>int(n/3))
            res.push_back(ele2);

        // Uncomment the following line
        // if it is told to sort the answer array:     
        // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

        return res;
    }
};


