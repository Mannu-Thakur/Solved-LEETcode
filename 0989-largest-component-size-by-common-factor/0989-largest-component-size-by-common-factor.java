import java.util.*;

class Solution {
    class DSU {
        int[] parent, size;

        DSU(int n) {
            parent = new int[n + 1];
            size = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int v) {
            if (v == parent[v]) return v;
            return parent[v] = find(parent[v]); // path compression
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    public int largestComponentSize(int[] nums) {
        int max = 0;
        for (int num : nums) max = Math.max(max, num);

        DSU dsu = new DSU(max);

        // Step 1: Union numbers with their factors
        for (int num : nums) {
            for (int f = 2; f * f <= num; f++) {
                if (num % f == 0) {
                    dsu.unite(num, f);
                    dsu.unite(num, num / f);
                }
            }
        }

        // Step 2: Count frequency of each component
        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0;
        for (int num : nums) {
            int root = dsu.find(num);
            count.put(root, count.getOrDefault(root, 0) + 1);
            ans = Math.max(ans, count.get(root));
        }

        return ans;
    }
}
