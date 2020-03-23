/**
 * leetcode no.13
 * 
 */
int getcharValue(char a)
    {
        switch(a)
        {
            case'I':return 1;
            case'V':return 5;
            case'X':return 10;
            case'L':return 50;
            case'C':return 100;
            case'D':return 500;
            case'M':return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int res = 0;
        int temp = 0;
        for(char c : s)
        {
            res += getcharValue(c);
            if(temp < getcharValue(c))
            res -= temp * 2;
            temp = getcharValue(c);
        }
        return res;
    }