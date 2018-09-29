import java.util.*;
import java.math.*;
import java.io.*;

public class java{
    static class Comp implements Comparator<Integer>{
        public int compare(Integer lhs, Integer rhs){
            return lhs - rhs;
        }
    }
    static class Yee implements Comparable<Yee>{
        public int compareTo(Yee y){
            return 0;
        }
    }
    static class Reader{
        private BufferedReader br;
        private StringTokenizer st;
        public Reader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        boolean hasNext() throws IOException{
            String s;
            while (st == null || !st.hasMoreElements()){
                if ((s = br.readLine())==null) return false;
                st = new StringTokenizer(s);
            }
            return true;
        }
        String next() throws IOException{
            while (st == null || !st.hasMoreElements())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        int nextInt() throws IOException{
            return Integer.parseInt(next());
        }// Long.parseLong, Double.parseDouble, br.readLine
    }
    public static void main(String args[])throws IOException{
        Reader cin = new Reader();
        //Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);
        //Scanner cin = new Scanner(new File("t.in"));
        //PrintWriter cout = new PrintWriter(new File("t.out"));
        // ***** cout.close() or cout.flush() is needed *****

        // 2D array: int[][] a = new int[10][10];
        // input, EOF, Graph
        int n = cin.nextInt();
        // nextFloat, nextLine, next
        ArrayList<ArrayList<Integer>> G = new ArrayList<>();
        for (int i=0; i<n; i++) G.add(new ArrayList<>());
        while (cin.hasNext()){ // EOF
            int u = cin.nextInt(), v = cin.nextInt();
            G.get(u).add(v);
        }
        // Math: E, PI, min, max, random(double 0~1), sin...
        // Collections(List a): swap(a,i,j), sort(a[,comp]), min(a), binarySearch(a,val[,comp])

        // set
        Set<Integer> set = new TreeSet<>();
        set.add(87); set.remove(87);
        if (!set.contains(87)) cout.println("no 87");

        // map
        Map<String, Integer> map = new HashMap<>();
        map.put("0", 1); map.put("2", 3);
        for ( Map.Entry<String,Integer> i : map.entrySet() )
            cout.println(i.getKey() + " " + i.getValue() + " wry");
        cout.println( map.get("1") );

        // Big Number: TEN ONE ZERO, modInverse isProbablePrime modInverse modPow
        // add subtract multiply divide remainder, and or xor not shiftLeft shiftRight

        // queue: add, peek(==null), poll
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        Queue<Integer> q = new ArrayDeque<Integer>();

        // stack: push, empty, pop
        Stack<Integer> s = new Stack<Integer>();

        cout.close();
    }
}
