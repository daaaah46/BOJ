import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		String str = s.next();
		int array[];
		array = new int[26];	
		for(int i=0; i<str.length(); i++){
			char temp = str.charAt(i);
			for(char j='a';j<='z';j++){
				if(j == temp){
					array[j-97]++;
					break;
				}
			}
		}
		for(int i=0;i<array.length;i++){
			System.out.print(array[i]+" ");
		}
	}
}
