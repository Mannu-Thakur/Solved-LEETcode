class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            if (find(u, parent) == find(v, parent)) return edge;
            union(u, v, parent);
        }
        return new int[0];
    }

    private int find(int x, int[] parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    }

    private void union(int a, int b, int[] parent) {
        int pa = find(a, parent), pb = find(b, parent);
        parent[pb] = pa;
    }
}
