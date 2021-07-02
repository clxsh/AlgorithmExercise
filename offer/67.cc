class Solution {
public:
    int strToInt(string str) {
        int len = str.length();
        int sign = 1;
        int i;
        
        // 跳过前置空格
        for (i = 0; i < len; ++i) {
            if (str[i] != ' ')
                break;
        }
        if (i == len)
            return 0;
        
        // 判断正负
        if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        else if (str[i] == '+'){
            sign = 1;
            ++i;
        }

        int res = 0;
        int boundry = INT_MAX / 10;
        int remainder = INT_MAX % 10;
        for (; i < len; ++i) {
            if (!(str[i] >= '0' && str[i] <= '9'))
                break;
            
            if (res > boundry || (res == boundry && str[i] > '7')) {
                if (sign == 1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }

            res = res * 10 + (str[i] - '0');    // 括起来保证优先性
        }

        return res * sign;
    }
};