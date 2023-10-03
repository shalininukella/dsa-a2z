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


