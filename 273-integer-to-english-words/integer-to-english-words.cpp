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
           // cout<< " words[i] : "<< words[i] << " res : "<< res << "i : "<< i << endl;
            if (i == 0) {
                res += ones[words[i] - '0'];
                break;
            }
            if(words[i] =='0' )continue;

            if (i % 3 == 0 and words[i]!='0') {
                // if i%3 == 0
                // index is either thousandth, millionth, billionth position
                //CAUTION : shouldn't execute when i = 3, 6 , 9 and words[i] ==0

                switch (i) {
                    case 3:
                        res += ones[words[i] - '0'] + " Thousand";
                        break;
                    case 6:
                        res += ones[words[i] - '0'] + " Million";
                        break;
                    case 9:
                        res += ones[words[i] - '0'] + " Billion";
                        break;
                }

                continue;
            } else if (i != 1 && i != 4 && i != 7 and words[i]!='0') {
                // if index is just before i%3==0 index
                // i.e. 2, 5, 8
                // then hundred + x is the position
                switch (i) {
                    case 2:
                        res += ones[words[i] - '0'] + " Hundred";
                        if (words[i - 1] != '1') {
                            res += tens[words[i - 1] - '0'] + ones[words[i - 2] - '0'];
                        } else {
                            res += ten[words[i - 2] - '0'];
                        }
                        i -= 2;
                        break;
                    case 5:
                        res += ones[words[i] - '0'] + " Hundred";
                        if (words[i - 1] != '1') {
                            res += tens[words[i - 1] - '0'] + ones[words[i - 2] - '0'];
                        } else {
                            res += ten[words[i - 2] - '0'];
                        }
                        res += " Thousand";
                        i -= 2;
                        break;
                    case 8:
                        res += ones[words[i] - '0'] + " Hundred";
                        if (words[i - 1] != '1') {
                            res += tens[words[i - 1] - '0'] + ones[words[i - 2] - '0'];
                        } else {
                            res += ten[words[i - 2] - '0'];
                        }
                        res += " Million";
                        i -= 2;
                        break;
                    default :
                        res+="";
                }
            } else {
                // if neither
                // then tenth's position
                // 11, 12, 43, 56 etc.
                // make special case for tens starting with "1"

                if (words[i] == '1') {
                    res += ten[words[i - 1] - '0'];
                    i -= 1;

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
                            // for words[i] == 0 
                    }
                    continue;
                }
                // for tens like: "forty-seven"
                res += tens[words[i] - '0'];
                res+= ones[words[i-1] - '0'];
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
                            // for words[i] == 0 
                    }
                    continue;
            }
        }
        // to truncate first space
        return res.substr(1, res.size() - 1);
    }
};
