import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str = in.readLine();
		String strs[] = str.split("\\s+");
		System.out.println(Integer.parseInt(strs[0]) + Integer.parseInt(strs[1]));
	}
}
