class Solution {
public:
    string numberToWords(int num) {
        // length
        if (num == 0) {
            return "Zero";
        }

        string words = to_string(num);
        reverse(words.begin(), words.end());

        string res = "";
        vector<string> tens = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        vector<string> ten = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};

        for (int i = words.size() - 1; i >= 0; i--) {
            cout<< " words[i] : "<< words[i] << " res : "<< res << "i : "<< i << endl;
            if (i == 0) {
                res += ones[words[i] - '0'];
                break;
            }
            if(words[i] =='0' )continue;

            if (i % 3 == 0 and words[i]!='0') {
                // if i%3 == 0
                // index is either thousandth, millionth, billionth position
                //CAUTION : shouldn't execute when i = 3, 6 , 9 and words[i] ==0
                res += ones[words[i] - '0'] ;
                switch (i) {
                    case 3:
                        res+= " Thousand";
                        break;
                    case 6:
                        res += " Million";
                        break;
                    case 9:
                        res += " Billion";
                        break;
                }

                continue;
            } else if (i != 1 && i != 4 && i != 7 and words[i]!='0') {
                // if index is just before i%3==0 index
                // i.e. 2, 5, 8
                // then hundred + x is the position
                res += ones[words[i] - '0'] + " Hundred";
                if (words[i - 1] != '1') {
                    res += tens[words[i - 1] - '0'] + ones[words[i - 2] - '0'];
                } else {
                    res += ten[words[i - 2] - '0'];
                }
                switch (i) {
                    case 2:
                        res+="";
                        //no such thing as twelve hundred . it's one thousand two hundred.
                        break;
                    case 5:
                        res += " Thousand";
                        //i -= 2;
                        break;
                    case 8:
                        res += " Million";
                        // -= 2;
                        break;
                }
                i -= 2;
            } else {
                // if neither
                // then tenth's position
                // 11, 12, 43, 56 etc.
                // make special case for tens starting with "1"

                if (words[i] == '1') {
                    res += ten[words[i - 1] - '0'];
                }
                else{
                    res += tens[words[i] - '0'];
                    res+= ones[words[i-1] - '0'];
                }
                // for tens like: "forty-seven"
                
                i-=1;
                 // select position for 11...19
                switch (i) {
                    case 0:
                        break;
                    case 3:
                        res += " Thousand";
                        break;
                    case 6:
                        res += " Million";
                        break;
                    default : 
                        res+="";
                        break;
                }
                continue;
            }
        }
        // to truncate first space
        return res.substr(1, res.size() - 1);
    }
};
