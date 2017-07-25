package boj;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj1260 {
	static boolean check_dfs[];
	static boolean check_bfs[];
	static boolean list[][];
	static Queue<Integer> q;
	private static void dfs(int n) {
		check_dfs[n] = true;
		System.out.print(n + " ");
		for(int i = 0;i<list[n].length;i++){
			if(list[n][i] == true && check_dfs[i] == false){
				dfs(i);
			}
		}
	}
	
	private static void bfs(int n){
		if(q.isEmpty()){
			q.add(n);
		}
		check_bfs[n] = true;
		
		while(!q.isEmpty()){
			int v = q.peek();
			System.out.print(v+ " ");
			for(int i=0;i<list[v].length;i++){
				if(list[v][i]==true && check_bfs[i]==false){
					q.add(i);
					check_bfs[i] = true;
				}
			}
			q.remove();
		}
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		int start = s.nextInt();
		
		check_dfs = new boolean[n+1];
		check_bfs = new boolean[n+1];
		list = new boolean[n+1][n+1];
		q = new LinkedList();
		
		for(int i=0;i<m;i++){
			int u = s.nextInt();
			int v = s.nextInt();
			list[u][v] = list[v][u] = true;
		}
		dfs(start);
		System.out.println();
		bfs(start);
	}
}
