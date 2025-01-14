class Solution {
public
     int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        Map<Integer, Integer> freq = new HashMap<>();
        int[] ans = new int[n];
        int common = 0;

        for (int i = 0; i < n; i++) {
            freq.put(A[i], freq.getOrDefault(A[i], 0) + 1);
            if (freq.get(A[i]) == 2) common++;
            freq.put(B[i], freq.getOrDefault(B[i], 0) + 1);
            if (freq.get(B[i]) == 2) common++;
            ans[i] = common;
        }
        return ans;
    }
}
