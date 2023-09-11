class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> a;
        for( int i=0; i < nums.size(); i++){
            a.insert(nums[i]);
        }
        auto it=a.begin();
        for (int i =0; i < a.size(); i++, it++){
            nums[i]= *it;
        }
        return a.size();
    }
};