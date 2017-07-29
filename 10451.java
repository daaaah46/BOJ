import java.util.Scanner;

public class boj10451 {

	private static boolean check[];
	private static int arr[];

	public static void dfs(int n) {
		check[n] = true;
		int m = arr[n];
		if (check[m] == false)
			dfs(m);
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int k = s.nextInt();
		for (int v = 0; v < k; v++) {
			int n = s.nextInt();
			int sum = 0;

			check = new boolean[n + 1];
			arr = new int[n + 1];
			for (int i = 1; i < n + 1; i++)
				arr[i] = s.nextInt();

			for (int i = 1; i < n + 1; i++) {
				if (check[i] == false) {
					dfs(i);
					sum++;
				}
			}
			System.out.println(sum);
		}
	}
}
