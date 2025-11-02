class Solution {
    boolean check(int n){
        Map<Integer,Integer> mp = new HashMap<>();

        while(n > 0){
            int d = n % 10;
            mp.put(d, mp.getOrDefault(d, 0) + 1);
            n /= 10;
        }

        for(Map.Entry<Integer,Integer> e : mp.entrySet()){
            if(e.getKey() != e.getValue()) return false;
        }
        return true;
    }

    public int nextBeautifulNumber(int n) {
        int i = n + 1;
        while(true){
            if(check(i)) return i;
            i++;
        }
    }
}
