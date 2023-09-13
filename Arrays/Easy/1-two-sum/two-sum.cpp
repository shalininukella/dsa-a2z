class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        //We will store our values and the indices here.
        unordered_map<int,int> map;        
		
        //We iterate through the loop.
        for(int index = 0; index < nums.size(); index++){
			if(map.find(target-nums[index]) != map.end()){
                //If map contains the value target - nums[index] return the indices of these two values.
                return {index, map[target-nums[index]]};
            }			
            map[nums[index]] = index;
            //If nota dd nums[index] to map.
        }
        
        //If there is no solution return an empty vector.        
        return {};
    }   
};