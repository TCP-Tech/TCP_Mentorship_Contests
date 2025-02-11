import java.io.*;
import java.util.*;

public class Java_Solution {

    public static void main(String[] args) {
        int t = in.nextInt();
        while (t-- > 0) {
            long a = in.nextLong();
            long b = in.nextLong();
            int k = in.nextInt();
            int [] pows = new int [k];
            long pow = 1;
            int exp = 0;
            int cnt = 0;
            while (exp < k){
                long ca = a&pow;
                long cb = b&pow;
                if(ca == 0 && cb == 0){
                    pows[exp] = 1;
                } else if(ca == 0 || cb == 0){
                    pows[exp] = 2;
                    cnt++;
                }
                pow *= 2;
                exp++;
            }
            long sum = 0;
            long p1 = pow(2, cnt);
            long p2 = 0;
            if(cnt > 0) p2 = pow(2, cnt-1);
            for (int i = 0; i < k; i++) {
                long cur = (1L << i)%mod;
                if(pows[i] == 1){
                    sum = sum + (cur * p1)%mod;
                } else if(pows[i] == 2){
                    sum = sum + (cur * p2)%mod;
                }
                sum %= mod;
            }
            System.out.println(sum);
        }
    }

    static long pow(long a, long b){
        long res = 1;
        while(b > 0){
            if(b%2 == 1){
                res = (res * a%mod)%mod;
            }
            a = (a%mod*a%mod)%mod;
            b >>= 1;
        }
        return res%mod;
    }

    static long [] al(int n){
        long [] arr = new long [n];
        for(int i = 0; i<n; i++) arr[i] = in.nextLong();
        return arr;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static class Pair<T, U>  {
        T f;
        U s;

        public Pair(T first, U sec) {
            this.f = first;
            this.s = sec;
        }

        @Override
        public String toString() {
            return f + " " + s;
        }

        @Override
        public boolean equals(Object obj) {
            if(!(obj instanceof Pair<?,?>)) return false;
            Pair<T, U> pair = (Pair<T, U>) obj;
            return f.equals(pair.f) && s.equals(pair.s);
        }
    }

    static int mod = (int)1e9 + 7;

    static int [] ai(int n){
        int [] arr = new int [n];
        for(int i = 0; i<n; i++) arr[i] = in.nextInt();
        return arr;
    }

    static FastReader in = new FastReader();

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return java.lang.Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
