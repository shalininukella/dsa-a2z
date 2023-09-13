//using two pointers
//time = O(m+n)
//space =O(m+n)
public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
     int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}
    
}; 



 //using hashset

/*Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. 
At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. 
So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, 
it would take O((m+n)log(m+n) time.
Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector 
takes O((m+n)log(m+n)) time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
O(1) {If Space of union ArrayList is not considered}*/

   /* class Solution{
    public:
    arr1,arr2 : the arrays
    n, m: size of arrays
    Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int a[], int b[], int n, int m){   
        int i=0, j=0;
        set<int> s;
        while(i<n || j<m){
            if(i<n){
                s.insert(a[i]);
                i++;
            }
            if(j<m){
                s.insert(b[j]);
                j++;
            }
        }
        vector<int> v;
        for(auto i: s){
            v.push_back(i);
        }
        return v;
    }
    };*/


    
//using hashmap
/* Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can 
store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element 
takes log(m+n) time. 
Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.
Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but 
sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
O(1) {If Space of union ArrayList is not considered} */
   
  /*  class Solution{
        public:
        vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        map < int, int > freq;
        vector < int > Union;
        for (int i = 0; i < n; i++)
            freq[arr1[i]]++;
        for (int i = 0; i < m; i++)
            freq[arr2[i]]++;
        for (auto & it: freq)
            Union.push_back(it.first);
        return Union;
        }
    };
    */
