class Solution {
public:
    int histogram(vector<int>& arr){
        int n = arr.size();
        stack<pair<int , int>> stack ; 
        int max_area = 0 ; 
        for(int i   =0 ; i < arr.size() ; i++){
            int curr_height = arr[i];
            cout<< "curr_height is : "<< curr_height << endl;
            int ind = i ;
            while(!stack.empty() and stack.top().second > curr_height){
                ind  = stack.top().first ;
                int height = stack.top().second ;
                //calc. the area
                int area = height * (i - ind);
                cout<< "area here : "<< area << endl;
                max_area = max(max_area , area);
                stack.pop();
            }
            stack.push({ind, curr_height});
        }
        //calc. for rect that came till last
        while(!stack.empty()){
            int ind = stack.top().first ;
            int height = stack.top().second ; 
            int area = (n- ind)* (height);
            cout<< "area here is : "<< area << endl;
            max_area = max(area , max_area);
            stack.pop();
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_area = 0 ;
        
        //need to solve the histogram problem for every row :
        for(int i = 0 ; i < row ; i++){
            //make histograms
            vector<int> v ; 
            for(int j =  0 ; j< col ; j++){
                int height = 0  ;
                int i1 = i;
                while(i1 >= 0 ){
                    if(matrix[i1][j] == '0'){
                        break;
                    }else{
                        height +=1;
                    }
                    i1--;
                }
                cout<< "height : "<< height << endl;
                v.push_back(height);
            }
            //made histogram for ith row 
            //now evaluate the max rectangle in this histogram
            
            int area = histogram(v);
            cout<< "area : "<< area << endl;
            max_area = max(max_area , area);
        }
        return max_area;
    }
};