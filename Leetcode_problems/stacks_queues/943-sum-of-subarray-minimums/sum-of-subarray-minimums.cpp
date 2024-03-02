class Solution {
public:
    const int MOD = 1000000007;

    // Function to calculate the sum of subarray minimums
    int sumSubarrayMins(const std::vector<int>& arr) {
        int n = arr.size();
        stack<int> leftstack ;
        stack<int> rightstack ; 
        vector<long long > leftcount(n)  , rightcount(n) ; 

        for(int i = 0 ; i <  n ; i++){
            while(!leftstack.empty() && arr[leftstack.top()] >= arr[i]){
                leftstack.pop();
            }
            if(!leftstack.empty()){
                leftcount[i] = i - leftstack.top();
            }
            else{
                leftcount[i] = i +1;
            }
            leftstack.push(i);
        }

        for(int i = n-1 ; i >=0 ; i--){
            while(!rightstack.empty() && arr[rightstack.top()] > arr[i]) {
                rightstack.pop();
            }
            if(rightstack.empty()){
                rightcount[i] = n-i;
            }
            else{
                rightcount[i] = rightstack.top() - i ;
            }
            rightstack.push(i) ; 
        }

        int sum  = 0 ;

        for(int i = 0 ; i <n ; i++){
            int temp  = (arr[i]*leftcount[i]*rightcount[i])%MOD;
            sum += temp;
            sum = sum%MOD;
        }
        return sum;
    }
};