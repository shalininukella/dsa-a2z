/*//optimised using two pointers(greedy way) when yes/no is supposed to be returned.
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


//using hashmap i.e unordered map. optimised here
/*define a hashmap with the elements of arrays as the key values of map and elemetns of map as the indices so that it becomes easier to access the index of a required element, i.e target-x, where x is is the current element*/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
       int n = a.size();
       unordered_map<int, int> mp;
       //mp.find(key), if key not found find will return mp.end();
       for(int i=0; i<n; i++){
           int num = a[i];
           int remain = target-a[i];
           if(mp.find(remain)!=mp.end()){
               return {mp[remain], i};
           }       
           /*inserting num now cus we dont want to compare the num with num, hence compare num with other nos. in map and then insert num in the map. */
             mp[num]=i;
           }
           //it won't get executed at all since in this que each input has an ans
           return {-1, -1};
    }
};
