class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money = 0 ;
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        for(int bill : bills){
            switch(bill){
                case 5:
                    fives++;
                    break;
                case 10: 
                    if(!fives) return false;
                    fives--;
                    tens++;
                    break;
                case 20: 
                    if(tens and fives){
                        tens--;
                        fives--;
                    }
                    else if(fives >=3) fives-=3;
                    else return false;
                    break;
            }
        }
        return true;
    }
};