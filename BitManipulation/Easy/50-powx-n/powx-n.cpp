class Solution {
public:
    double myPow(double a, int b) {
        double ans = 1;
        long sign;
        if(b<0){
           sign = long(b);
    }
        sign = abs(sign);
        while(sign!=0){
            if(sign&1){
                ans = (ans * a);
            }
            a = (a * a);
            sign = sign >> 1;
        }
        return b<0?1/ans:ans;
    }
};
        
        
