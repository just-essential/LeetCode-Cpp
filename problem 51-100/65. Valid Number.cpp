/*
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
*/
class Solution {
public:
    bool isNumber(string s) {
        int l = s.length(), i = 0;
        while (i < l && s[i] == ' ') i++;
        if (s[i] == '-' || s[i] == '+') i++;
        if (i < l && s[i] >= '0' && s[i] <= '9') {
            i++;
            while (i < l && s[i] >= '0' && s[i] <= '9') i++;
        } else if (s[i] != '.') return false;
        if (i < l && s[i] == '.') {
            i++;
            while (i < l && s[i] >= '0' && s[i] <= '9') i++;
        }
        if (i < l && s[i] == 'e') {
            i++;
            if (s[i] == '-' || s[i] == '+') i++;
            if (i < l && s[i] >= '0' && s[i] <= '9') {
                i++;
                while (i < l && s[i] >= '0' && s[i] <= '9') i++;
            } else return false;
        }
        while (i < l && s[i] == ' ') i++;
        return i == l;
    }

    void test() {
        assert(isNumber("0"));
        assert(isNumber(" 0.1 "));
        assert(!isNumber("abc"));
        assert(!isNumber("1 a"));
        assert(isNumber("2e10"));
        assert(isNumber(" -90e3   "));
        assert(!isNumber(" 1e"));
        assert(!isNumber("e3"));
        assert(isNumber(" 6e-1"));
        assert(!isNumber(" 99e2.5"));
        assert(isNumber("53.5e93"));
        assert(!isNumber(" --6"));
        assert(!isNumber("-+3"));
        assert(!isNumber("95a54e53"));
    }
};