import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a1 = sc.nextInt(), a2 = sc.nextInt(), b1 = sc.nextInt(), b2 = sc.nextInt(), c = sc.nextInt();
		TreeSet<Integer> ans = new TreeSet<>();
		if (c==a1 || c==a2) {
			ans.add(b1);
			ans.add(b2);
		}
		if (c==b1 || c==b2) {
			ans.add(a1);
			ans.add(a2);
		}
		System.out.println(ans.size());
		for (int i:ans) System.out.println(i);
	}
}
