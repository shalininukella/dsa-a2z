class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        int ans = 0; 
        while(i < v1.length() && j < v2.length()) {
            int start_v1 = i, start_v2 = j;
            while(i < v1.length() && v1[i] != '.') i++;
            while(j < v2.length() && v2[j] != '.') j++;
            if(stoi(v1.substr(start_v1, i-start_v1)) != stoi(v2.substr(start_v2, j-start_v2))) {
                if(stoi(v1.substr(start_v1, i-start_v1)) < stoi(v2.substr(start_v2, j-start_v2)))
                    ans = -1;
                else
                    ans = 1;
                break;
            }
            i++; j++;
        }
        if((i < v1.length() || j < v2.length()) && !ans) {
            while(j < v2.length()) {
                if(v2[j] != '.' && v2[j] - '0' > 0) return -1;
                j++;
            }
            while(i < v1.length()) {
                if(v1[i] != '.' && v1[i] - '0' > 0) return 1;
                i++;
            }
        }
        return ans;
    }
};