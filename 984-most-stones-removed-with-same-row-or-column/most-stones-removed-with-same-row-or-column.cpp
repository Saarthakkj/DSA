class Solution {
public:
    static const int N = 10001;
    static const int M = 10001;  // Size of the 2D grid
    bitset<N * M> vis;
    void dfs(  set<pair<int  , int>>& s, int& row , int& col){
        vis[row*M + col] = true;
        //cout<< "row : "<< row << " col : "<< col << "vis: " << row*M + col << endl;
        //int ans = 1;

        //...O(n)
        //...to see if any connected stones
        //...traverse row and col for this
        for(auto temp : s){
            if(  temp.first ==row and  !vis[row*M + temp.second]){
                dfs( s , row , temp.second);
            }
            //cout<< "val : " << temp.first*M + col-1000000;
            if( temp.second==col and !vis[temp.first*M + col]){
                dfs( s , temp.first ,col);
            }
        }

        
        //return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n  = -1;
        //... finding dimensions
        for(auto temp : stones){
            n = max(temp[0] , max(temp[1] , n));
        }
        set<pair<int , int>> s ; 
        for(auto temp : stones){
            s.insert({temp[0], temp[1]});
        }

       // vector<vector<int>> graph(n+1 , vector<int>(n+1 , 0));

        //... initialsiing the the matrix that contains 1 at stones coordinates.
        // for(auto temp : stones){
        //     graph[temp[0]][temp[1]] ++;
        // }

        int k =0; //... to contain how many connected stones are there

        //vector<vector<int>> vis( n+1,vector<int>(n+1 ,0)); //.. getting MLE here

        //... to fill the set with no. of connected stones.
        for(auto [i,j] : s){
            if(!vis[M*i + j] ){
                //cout<< "i: "<< i << "j: "<< j << endl;
                dfs( s , i , j);
                k++;
            }
        }
        n = stones.size();
        // cout<< "k :"<< s.size();
        // cout<< "n : "<< n ;
        // cout<< " n - k : "<< n - s.size();
        return (n - k);
    }
};