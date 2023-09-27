/*//optimised using two pointers(greedy way) when yes/no is supposed to be returned.
// time = O(N) + O(N*logN), where N = size of the array
// space = o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
       int n = a.size();
       int i=0, j=n-1;
       sort(a.begin(), a.end()); //o(nlogn)
       while (i<=j)//o(n)
       {
           int sum=a[i]+a[j];
           if(sum<target)// need a greater no.
           {
               i++;
           }
           else if(sum> target)// need a smaller no.
           {
                j--;
           }
           else{
               break; //given has atleast one solution, so once the loop is broken obviously we'll return the indices of the sum only.
           }
       }
        return "YES";
    }   
};*/


//using hashmap i.e unordered map in one loop. optimised here

/*Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).

Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.

Space Complexity: O(N) as we use the map data structure.

Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map data structure, then we should move on to the following approach i.e. two pointer approach. This approach will have the same time complexity as the better approach.
*/


/*define a hashmap with the elements of arrays as the key values of map and elemetns of map as the indices so that it becomes easier to access the index of a required element, i.e target-x, where x is is the current element*/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
       int n = a.size();
       unordered_map<int, int> mp;
       
       for(int i=0; i<n; i++){
           int num = a[i];
           int remain = target-a[i];
           //mp.find(key), if key not found find will return mp.end();
           if(mp.find(remain)!=mp.end()) 
           //or if(mp.count(remain)), count(key) returns 0 if key is not there,else 1
           {
               return {mp[remain], i};
           }       
           /*inserting num now cus we dont want to compare the num with num, hence compare num with other nos. in map and then insert num in the map. */
             mp[num]=i;
           }
           //it won't get executed at all since in this que each input has an ans
           return {}; //no solution found
    }
};


//two pass hash table 

/* the time complexity of the twoSum function is O(n) due to the two linear passes through the input array.
space complexity= o(n)
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};*/


/*// brute force 
//time = o(n^2), space = o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
}; */