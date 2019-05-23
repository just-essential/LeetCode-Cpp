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

enum State {
    Nil, Sign, Integer, Dot, Decimal, Euler, ExpSign, Exponent
};

class Solution {
public:
    bool isNumber(string s) {
        int l = s.length(), i = 0;
        while (i < l && s[i] == ' ') i++;
        while (l > 0 && s[l - 1] == ' ') l--;
        State state = Nil;
        bool leadingNumber = false;
        while (i < l) {
            if (s[i] >= '0' && s[i] <= '9') {
                leadingNumber = true;
                if (state <= Integer) {
                    state = Integer;
                } else if (state <= Decimal) {
                    state = Decimal;
                } else {
                    state = Exponent;
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (state == Nil) {
                    state = Sign;
                } else if (state == Euler) {
                    state = ExpSign;
                } else {
                    return false;
                }
            } else if (s[i] == '.') {
                if (state < Dot) {
                    state = Dot;
                } else {
                    return false;
                }
            } else if (s[i] == 'e') {
                if (leadingNumber && (state <= Decimal)) {
                    state = Euler;
                } else {
                    return false;
                }
            } else {
                return false;
            }
            i++;
        }
        return state == Integer || (leadingNumber && state == Dot) || state == Decimal || state == Exponent;
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