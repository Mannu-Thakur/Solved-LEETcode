import java.util.*;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n = arr.length;

        // Count frequencies of each number
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        if (k == 0) {
            return freq.size();
        }

        // Sort frequencies in ascending order
        List<Integer> counts = new ArrayList<>(freq.values());
        Collections.sort(counts);

        // Remove elements greedily starting from smallest frequency
        int i = 0;
        while (k > 0 && i < counts.size()) {
            if (counts.get(i) <= k) {
                k -= counts.get(i);
                counts.set(i, 0); // this element is completely removed
            } else {
                counts.set(i, counts.get(i) - k);
                k = 0;
            }
            i++;
        }

        // Count remaining numbers with frequency > 0
        int remaining = 0;
        for (int c : counts) {
            if (c > 0) remaining++;
        }

        return remaining;
    }
}
