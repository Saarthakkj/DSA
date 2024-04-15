class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gS) {
        if(hand.size() % gS != 0){
            //cout<< "false no 1" ;
            return false ; 
        }

        priority_queue<int, vector<int> , greater<int> > min_heap  ; 
        map<int , int> mpp ; 

        for(int i = 0 ; i < hand.size() ; i++){
            mpp[hand[i]] ++ ; 
            if(mpp[hand[i]] == 1){
                min_heap.push(hand[i]) ; 
            }
        }

        //created the min heap for the array
      
        //for, the groups with the min heap and maps
        while(!min_heap.empty()){
            int ele = min_heap.top()  ;

            //now check if the group can be formed with this
            // min_heap.pop()  ;
            for(int i =  0 ; i < gS ; i++ ){
                int curr = ele + i ; 
                if(mpp.find(curr) == mpp.end() or mpp[curr] == 0){
                    //cout<< "false no 2"; 
                    return false; 
                }
                //if it is present , decrease its frequency 
                mpp[curr] -- ;
                if (mpp[curr] == 0) {
                    mpp.erase(curr); // Remove the card from the map if its count becomes zero

                    // Check if the next smallest card in the heap matches 'current'
                    if (curr == min_heap.top()) {
                        min_heap.pop(); // Remove the next smallest card from the min heap
                    } else {
                        //cout << "false no 3" << endl;
                        return false;
                    }
                }
            }
        }

        return true ; 
    }
};