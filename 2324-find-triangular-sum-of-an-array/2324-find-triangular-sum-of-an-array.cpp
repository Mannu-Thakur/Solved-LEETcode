int collapseShortcut(vector<int>& nums) {
    int n = nums.size();
    int result = 0;

    // Compute row n-1 of Pascal's triangle modulo 10
    vector<int> C(n);
    C[0] = 1;
    for(int i = 1; i < n; ++i) {
        C[i] = (C[i-1] * (n-1-i+1) / i);  // standard nCr formula
        C[i] %= 10;
    }

    for(int i = 0; i < n; ++i) {
        result = (result + nums[i] * C[i]) % 10;
    }

    return result;
}
