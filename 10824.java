import java.util.Scanner;
public class boj10824 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String A = s.next();
		String B = s.next();
		String C = s.next();
		String D = s.next();
		System.out.println(Long.parseLong(A+B)+Long.parseLong(C+D));
	}
}
