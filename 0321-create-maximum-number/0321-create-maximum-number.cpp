class Solution {
public:
     vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stack;
        int drop = n - k;  
        for (int num : nums) {
            while (!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
         stack.resize(k);
        return stack;
    }

     bool greaterSeq(vector<int>& a, int i, vector<int>& b, int j) {
        int n = a.size(), m = b.size();
        while (i < n && j < m && a[i] == b[j]) {
            i++;
            j++;
        }
        return j == m || (i < n && a[i] > b[j]);
    }

     vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (greaterSeq(a, i, b, j))
                merged.push_back(a[i++]);
            else
                merged.push_back(b[j++]);
        }
        return merged;
    }

     vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> best;

        for (int i = max(0, k - m); i <= min(k, n); i++) {
            vector<int> subseq1 = maxSubsequence(nums1, i);
            vector<int> subseq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subseq1, subseq2);
            if (best.empty() || greaterSeq(candidate, 0, best, 0))
                best = candidate;
        }
        return best;
    }
};
