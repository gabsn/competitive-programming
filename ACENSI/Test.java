import java.util.*;

class Test {
	
	public static void main(String[] args) {
		List<Integer> l1 = new ArrayList<>(Arrays.asList(1, 3, 2));
		List<Integer> l2 = new ArrayList<>(l1);
		l2.add(4);
		l1.add(5);
		l2.add(0, 8);
		System.out.println(l1);
		System.out.println(l2);
	}
}
