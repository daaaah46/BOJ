import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class boj11656 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String a = s.nextLine();
		ArrayList<String> b = new ArrayList<String>();
		for(int i=0;i<a.length();i++){
			b.add(a.substring(i, a.length()));
		}
		Collections.sort(b);
		for(int i=0;i<b.size();i++)
			System.out.println(b.get(i));
	}
}
