class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break;
            long long first = stoll(num.substr(0, i));

            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                if (num[i] == '0' && j > 1) break;
                long long second = stoll(num.substr(i, j));

                if (isValid(num.substr(i + j), first, second))
                    return true;
            }
        }
        return false;
    }

    bool isValid(string remaining, long long first, long long second) {
        while (!remaining.empty()) {
            long long sum = first + second;
            string sumStr = to_string(sum);
            if (remaining.substr(0, sumStr.size()) != sumStr)
                return false;
            remaining = remaining.substr(sumStr.size());
            first = second;
            second = sum;
        }
        return true;
    }
};