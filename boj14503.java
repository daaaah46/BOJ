package SS_SW;

import java.util.Scanner;

public class boj14503 {
	static int R[] = { -1, 0, 1, 0 };
	static int C[] = { 0, 1, 0, -1 };

	public static void main(String[] args) {
		int n, m, r, c, d, matrix[][];
		boolean visit[][], notExplore = false;
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		m = s.nextInt();
		r = s.nextInt();
		c = s.nextInt();
		d = s.nextInt();

		matrix = new int[n][m];
		visit = new boolean[n][m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] = s.nextInt();

		while (true) {
			visit[r][c] = true;// 현재 위치를 청소한다.
			notExplore = true; // 네 방향 모두 청소가 되어 있나?
			System.out.println("r : " + r + "c :" + c);
			for (int i = 0; i < 4; i++) { // 4방향을 탐색한다.
				int nextd = (d + 1) % 4; // 현재 방향을 기준으로 왼쪽 방향을 받는다.
				int nextr = r + R[nextd], nextc = c + C[nextd];
				//배열의 인덱스가 넘어가는 것을 방지하는 코드 넣기
				if (matrix[nextr][nextc] == 0 // 왼쪽 방향이 만약 청소되지 않았다면
						&& !visit[nextr][nextc]) { // 그리고 방문한 적이 없다면
					d = nextd;
					r = r + nextr;
					c = c + nextc; // 현재 방향을 왼쪽 방향으로 바꾸고 로봇 위치 변경
					notExplore = false;
					break;
				}
			}
			if (notExplore) { // 네 방향 모두 청소가 되어있는 경우
				//로봇의 위치를 한 칸 후진함
			}
			//만약 네 방향 모두 청소가 되어 있고, 뒤가 벽이라면
			//반복문을 빠져 나간다.
		}
	}
}
