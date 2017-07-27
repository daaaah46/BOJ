import java.util.ArrayList;
import java.util.Scanner;

public class boj1707 {
	static int check[]; // 0이면 방문 안한 것, 1,2로 분류
	static int color = 1; // 1이면 red, 2이면 blue
	static ArrayList<Integer> graph[];

	private static void dfs(int n, int color) {
		check[n] = color;
		for (int i = 0; i < graph[n].size(); i++) {
			int m = graph[n].get(i);
			if (check[m] == 0) {
				dfs(m, 3 - color);
			}
		}
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int k = s.nextInt();

		for (int u = 0; u < k; u++) {

			int v = s.nextInt();
			int e = s.nextInt();
			check = new int[v + 1];
			graph = new ArrayList[v + 1];

			for (int i = 0; i <= v; i++)
				graph[i] = new ArrayList<Integer>();

			for (int i = 0; i < e; i++) {
				int vertex1 = s.nextInt();
				int vertex2 = s.nextInt();
				graph[vertex1].add(vertex2);
				graph[vertex2].add(vertex1);
			}

			for (int i = 1; i <= v; i++) {
				if (check[i] == 0) {
					dfs(i, 1);
				}
			}

			boolean yes = true;
			for (int i = 1; i <= v; i++) {
				for (int j = 0; j<graph[i].size(); j++) {
					if (check[i] == check[graph[i].get(j)])
						yes = false;
				}
			}

			if (yes)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}
