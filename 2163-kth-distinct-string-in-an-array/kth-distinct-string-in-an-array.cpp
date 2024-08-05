class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> distinct;
        vector<string> all;
        for(auto s : arr){
            auto it = find(distinct.begin() , distinct.end() , s)  ; 
            auto it2 = find(all.begin() , all.end()  ,s);
            if(it== distinct.end()  and it2 == all.end()){
                distinct.push_back(s);
                all.push_back(s);
            }
            else if(it != distinct.end()){
                distinct.erase(it);
            }
        }
        if(k-1 < distinct.size()) return distinct[k-1];
       // cout<< distinct.size() << "k : "<< k <<  endl;
        return "";
    }
};