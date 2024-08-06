class Solution {
public:
    int minimumPushes(string word) {
        vector<int> dis(26);
        for(auto c : word){
            dis[c-'a']++;
        }
        sort(dis.begin() , dis.end());
        int no = 0;
        int res =0 ;

        //debugging :
        // cout<< " dis size : "<< dis.size()<< endl;
        // int ind = 0;
        // for(auto f : dis){
        //     cout<< " "<< f ;
        // }
        for(int i = dis.size()-1 ; i>=0 ; i--){
            if(no <8){
                res+= dis[i];
            }
            else if(no <16){
                res+= (dis[i]*2);
            }
            else if(no < 24){
                res += (dis[i]*3);
            }
            else{
                res+= (dis[i] *4);
            }
            no++;
        }

        return res;
    } 
};