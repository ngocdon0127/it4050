// 436.19
import java.util.*;
 
public class AppleTrees {
  private static final long MOD = 1000000007;
 
  public int theCount(int D, int[] r) {
    List<Map<Integer, Long>> q = new  ArrayList<Map<Integer, Long>>();
    q.add(null);
    q.add(new HashMap<Integer, Long>());
    q.get(1).put(0, 1L);
    Arrays.sort(r);
    for (int i = r.length - 1; i >= 0; i--) {
      int l = r[i];
      List<Map<Integer, Long>> qq = new ArrayList<Map<Integer, Long>>();
      for (int j = 0; j < q.size(); j++) {
        Map<Integer, Long> m = q.get(j);
        if (m != null) {
          if (j > 0) {
            for (Integer len : m.keySet()) {
              add(qq, j - 1, len, m.get(len) * j);
            }
          }
          if (j >= 1) {
            for (Integer len : m.keySet()) {
              add(qq, j, len + l, m.get(len) * j * 2);
            }
            for (Integer len : m.keySet()) {
              add(qq, j + 1, len + 2 * l, m.get(len) * j);
            }
          }
        }
      }
      q = qq;
    }
 
    long[][] c = new long[D + r.length + 1][r.length + 2];
    c[0][0] = 1;
    for (int i = 0; i < c.length; i++) {
      c[i][0] = 1;
      for (int j = 1; j < Math.min(i + 1, c[i].length); j++) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        c[i][j] %= MOD;
      }
    }
 
    int res = 0;
    Map<Integer, Long> z = q.get(0);
    for (Integer len : z.keySet()) {
      long num = z.get(len);
      int n = D - len - 1;
      if (n >= 0) {
        int k = r.length;
        res += (c[n + k][k] * num) % MOD;
        res %= MOD;
        //System.out.println(len + " " + num + " " + n + " " + k + " " + res);
      }
 
    }
 
        return res;
    }
 
  private void add(List<Map<Integer, Long>> qq, Integer i, Integer l, Long n) {
    while (qq.size() < i + 1) qq.add(null);
    if (qq.get(i) == null) {
      qq.set(i, new HashMap<Integer, Long>());
    }
    Long m = qq.get(i).get(l);
    if (m == null) m = 0L;
    qq.get(i).put(l, (m + n) % MOD);
  }
 
}