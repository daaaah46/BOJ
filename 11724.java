package boj;

import java.util.Scanner;

public class boj11724 {
	static int sum;
	static boolean list[][];
	static boolean check_dfs[];
	private static void dfs(int n) {
		check_dfs[n] = true;
		for(int i=0;i<list[n].length;i++){
			if(list[n][i] == true 
					&& check_dfs[i] == false){
				dfs(i);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		sum = 0;
		
		check_dfs = new boolean[n+1];
		list = new boolean[n+1][n+1];
		
		for(int i=0;i<m;i++){
			int u = s.nextInt();
			int v = s.nextInt();
			list[u][v] = list[v][u] = true;
		}
		
		for(int i=1;i<=n;i++){
			if(check_dfs[i]==false){
				dfs(i);
				sum++;
			}
		}
		System.out.println(sum);
	}
}
