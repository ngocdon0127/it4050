// 492.47

import java.math.BigInteger; 
import java.util.Arrays; 

public class AppleTrees { 
	private static final long MOD = 1000000007; 

	public int theCount(int D, int[] r) { 
		int n = r.length; 
		long[][] q = new long[n + 1][80 * n + 1]; 
		q[1][0] = 1; 
		long[][] qq = new long[n + 1][80 * n + 1]; 
		Arrays.sort(r); 
		for (int i = n - 1; i >= 0; i--) { 
			for (int j = 1; j <= n; j++) { 
				for (int k = 0; k <= 80 * n; k++) { 
					if (q[j][k] == 0) 
						continue; 
					qq[j - 1][k] += q[j][k] * j; 
					qq[j][k + r[i] - 1] += q[j][k] * 2 * j; 
					if (j < n) 
						qq[j + 1][k + 2 * r[i] - 2] += q[j][k] * j; 
				} 
			} 
			for (int j = 0; j <= n; j++) { 
				for (int k = 0; k <= 80 * n; k++) { 
					q[j][k] = qq[j][k] % MOD; 
					qq[j][k] = 0; 
				} 
			} 
		} 
		long[] f = new long[D + n + 1]; 
		long[] of = new long[D + n + 1]; 
		f[0] = of[0] = 1; 
		BigInteger mod = BigInteger.valueOf(MOD); 
		for (int i = 1; i <= D + n; i++) { 
			f[i] = (f[i - 1] * i) % MOD; 
			of[i] = (of[i - 1] * BigInteger.valueOf(i).modInverse(mod).longValue()) % MOD; 
		} 
		long ans = 0; 
		for (int i = n; i <= 81 * n && i <= D; i++) { 
			long cur = (q[0][i - n] * f[D - i + n]) % MOD; 
			cur = (cur * of[n]) % MOD; 
			cur = (cur * of[D - i]) % MOD; 
			ans += cur; 
		} 
		return (int) (ans % MOD); 
	} 

} 