class Solution {
public:
    int findComplement(int num) {
        int n = log2(num);
        for(int i = 0 ; i <=n ; i++){
            num  = num^ (1 << i);
        }
        return num;
    }
};