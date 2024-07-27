class Solution {
public:
    vector<int>nums;
    vector<char>exp;
    int n1;
    vector<vector<vector<int>>>v;
    vector<int>ans;
    int calcexp(int x, char c, int y){
        if(c=='+'){
            return x+y;
        }
        else if(c=='-'){
            return x-y;
        }
        else{
            return x*y;
        }
    }
    vector<int>solve(int x,int y){
        if(v[x][y].size()!=0){
            return v[x][y];
        }
        if(x==y){
            v[x][y].push_back(nums[x]);
            return v[x][y];
        }
        if(y==x+1){
            v[x][y].push_back(calcexp(nums[x],exp[x],nums[y]));
            return v[x][y];
        }
        for(int i=x;i<y;i++){
            
                vector<int>v1=solve(x,i);
                vector<int>v2=solve(i+1,y);
                for(auto &p:v1){
                    for(auto &q:v2){
                        v[x][y].push_back(calcexp(p,exp[i],q));
                    }
                }
            
        }
        return v[x][y];
    }
    vector<int> diffWaysToCompute(string s) {
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                exp.push_back(s[i]);
                i++;
            }
            else{
                string s1="";
                s1+=s[i];
                i++;
                if(i<n && s[i]>='0' && s[i]<='9'){
                    s1+=s[i];
                    i++;
                }
                cout<<(int)s1[1]<<endl;
                nums.push_back(stoi(s1));
            }
        }
        cout<<nums[0]<<endl;
        if(exp.size()==0){
            return {nums[0]};
        }
        n1=nums.size();
        v.resize(n1+1,vector<vector<int>>(n1+1,vector<int>()));
        for(int i=0;i<n1-1;i++){
            
                vector<int>v1=solve(0,i);
                vector<int>v2=solve(i+1,n1-1);
                for(auto &x:v1){
                    for(auto &y:v2){
                        ans.push_back(calcexp(x,exp[i],y));
                    }
                }
         }
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n1;j++){
        //         cout<<i<<" "<<j<<endl;
        //         vector<int>v3=v[i][j];
        //         for(auto &x:v3){
        //             cout<<x<<" ";
        //         }
        //         cout<<endl;
        //     }
        // }
        return ans;
    }
};