public class Solution {
    public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashSet<Integer> hm = new HashSet<Integer>();
        for (int i = 0; i < num.length; ++i) {
            hm.add(num[i]);
        }
        int res = 0;
        for (int i = 0; i < num.length; ++i) {
            int now = 0;
            for (int j = num[i];;--j) {
                if (hm.contains(j)) {
                    ++now;
                    hm.remove(j);
                } else {
                    break;
                }
            }
            for (int j = num[i] + 1;; ++j) {
                if (hm.contains(j)) {
                    ++now;
                    hm.remove(j);
                } else {
                    break;
                }   
            }
            if (res < now) {
                res = now;
            }
            
        }
        return res;
    }
}