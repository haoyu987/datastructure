// upgraded parameter types
string fractionToDecimal(int64_t n, int64_t d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}

class Solution2 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};
