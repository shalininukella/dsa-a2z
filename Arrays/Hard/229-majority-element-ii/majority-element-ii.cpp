//1)striver optimal 
//TC = O(n) + O(n) = O(n), sc=o(1)

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


//2) better - using maps
//tc = O(N), sc = o(n)

// vector<int> majorityElement(vector<int> v) {
//     int n = v.size(); //size of the array
//     vector<int> ls; // list of answers

//     //declaring a map:
//     map<int, int> mpp;

//     // least occurrence of the majority element:
//     int mini = int(n / 3) + 1;

//     //storing the elements with its occurnce:
//     for (int i = 0; i < n; i++) {
//         mpp[v[i]]++;

//         //checking if v[i] is
//         // the majority element:
//         if (mpp[v[i]] == mini) {
//             ls.push_back(v[i]);
//         }
//         if (ls.size() == 2) break;
//     }

//     return ls;
// }



//3) brute force 
//tc = O(N^2), sc = o(1)

// vector<int> majorityElement(vector<int> v) {
//     int n = v.size(); //size of the array
//     vector<int> ls; // list of answers

//     for (int i = 0; i < n; i++) {
//         //selected element is v[i]:
//         // Checking if v[i] is not already
//         // a part of the answer:
//         if (ls.size() == 0 || ls[0] != v[i]) {
//             int cnt = 0;
//             for (int j = 0; j < n; j++) {
//                 // counting the frequency of v[i]
//                 if (v[j] == v[i]) {
//                     cnt++;
//                 }
//             }

//             // check if frquency is greater than n/3:
//             if (cnt > (n / 3))
//                 ls.push_back(v[i]);
//         }

//         if (ls.size() == 2) break;
//     }

//     return ls;
// }




