import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int[] arr = new int[b];
		for(int i=0; i<b; i++) {
			arr[i] = sc.nextInt();
		}
		
		double percent = a;
		for(int i=0; i<b; i++) {
			percent += percent*arr[i]/100;
		}
		
		double result = percent-a;
		System.out.format("%.0f%n", result);
		if(result==0)
			System.out.println("same");
		else if(result>0)
			System.out.println("good");
		else
			System.out.println("bad");
	}
}