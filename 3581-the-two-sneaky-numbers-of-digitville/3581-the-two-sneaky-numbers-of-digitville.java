import java.util.*;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length;
        Vector<Integer> ans = new Vector<>();
        Set<Integer> stt = new HashSet<>();

        for (int i = 0; i < n; ++i) {
            if (stt.contains(nums[i])) {
                ans.add(nums[i]); 
            } else {
                stt.add(nums[i]);
            }
        }

        ans.sort(null); // sort ascending

        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}
