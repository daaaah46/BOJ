package boj;

import java.io.*;
import java.util.StringTokenizer;

/**
 * 문제 : 빠른 A+B (https://www.acmicpc.net/problem/15552)
 * Time : 21/03/2019 8:23 PM
 * Created By @hellododa
 */

public class boj_15552 {
    public static void main(String[] args) throws IOException{
        BufferedReader in =  new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(in.readLine());
        for(int i = 0; i < T; i++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            int plus = n1 + n2;
            bw.write(plus + "\n");
        }
        bw.flush();
        bw.close();
    }
}
