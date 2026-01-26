 
class Solution {

    static class Node {
        long val;
        Node prev, next;
        boolean alive = true;

        Node(long v) {
            val = v;
        }
    }

    static class Pair {
        long sum;
        Node left, right;

        Pair(long s, Node l, Node r) {
            sum = s;
            left = l;
            right = r;
        }
    }

    public int minimumPairRemoval(int[] arr) {
        int n = arr.length;
        if (n <= 1) return 0;

        // Build doubly linked list
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) nodes[i] = new Node(arr[i]);
        for (int i = 0; i < n - 1; i++) {
            nodes[i].next = nodes[i + 1];
            nodes[i + 1].prev = nodes[i];
        }

        // Count initial disorder: a[i] > a[i+1]
        int bad = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nodes[i].val > nodes[i + 1].val) bad++;
        }
        if (bad == 0) return 0;

        // Min heap of adjacent pairs
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> Long.compare(a.sum, b.sum)
        );

        for (int i = 0; i < n - 1; i++) {
            pq.add(new Pair(nodes[i].val + nodes[i + 1].val, nodes[i], nodes[i + 1]));
        }

        int ops = 0;

        while (bad > 0) {

            Pair p = pq.poll();
            Node L = p.left;
            Node R = p.right;

            // Lazy skip invalid
            if (!L.alive || !R.alive || L.next != R) continue;

            Node A = L.prev;
            Node B = R.next;

            // Remove old disorder contributions
            if (A != null && A.val > L.val) bad--;
            if (L.val > R.val) bad--;
            if (B != null && R.val > B.val) bad--;

            // Merge
            L.val = L.val + R.val;
            R.alive = false;
            L.next = B;
            if (B != null) B.prev = L;

            // Add new disorder contributions
            if (A != null && A.val > L.val) bad++;
            if (B != null && L.val > B.val) bad++;

            // Push new adjacent sums
            if (A != null) pq.add(new Pair(A.val + L.val, A, L));
            if (B != null) pq.add(new Pair(L.val + B.val, L, B));

            ops++;
        }

        return ops;
    }
}
