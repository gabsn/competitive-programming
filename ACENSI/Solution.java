import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	

	static boolean isAccessible(String[] grid, int x, int y) {
		if (x < 0 || x >= grid.length || y < 0 || y >= grid.length) {
			return false;
		} else {
			char c = grid[x].toCharArray()[y];
			if (c == 'X') {
				return false;
			} else {
				return true;
			}
		}
	}

	static void blockCell(String[] grid, int x, int y) {
		if (x >= grid.length || y >= grid.length) {
			return;
		} else {
			char[] line = grid[x].toCharArray();
			line[y] = 'X';
			grid[x] = new String(line);
		}
	}

	static String hash(int x, int y) {
		return x + "|" + y;
	}

	static class Cell {
		int x;
		int y;
		int moves;
		boolean vertical;

		Cell(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static void updateCell(String[] grid, Map<String, Integer> minMoves, ArrayList<Cell> path, int x, int y, int d) {
		if (d > 4) {
			return;
		} else {
			d++;
		}
		Cell c = new Cell(x, y);

		if (!isAccessible(grid, x, y) || path.contains(c)) {
			return;
		} else if (path.isEmpty()) {
			c.moves = 0;
			c.vertical = false;
			updateCell(grid, minMoves, new ArrayList<Cell>(Arrays.asList(c)), x + 1, y, d);
			updateCell(grid, minMoves, new ArrayList<Cell>(Arrays.asList(c)), x - 1, y, d);

			c.vertical = true;
			updateCell(grid, minMoves, new ArrayList<Cell>(Arrays.asList(c)), x, y + 1, d);
			updateCell(grid, minMoves, new ArrayList<Cell>(Arrays.asList(c)), x, y - 1, d);
			return;
		}

		Cell prev = path.get(path.size() - 1);
		if (prev.y == c.y && prev.vertical || prev.x == c.x && !prev.vertical) {
			c.moves = prev.moves;
		} else {
			c.moves = prev.moves + 1;
		}
		c.vertical = (prev.y == c.y);
		path.add(c);

		String key = hash(x, y);
		if (minMoves.containsKey(key)) {
			minMoves.put(key, Math.min(minMoves.get(key), c.moves));
		} else {
			minMoves.put(key, c.moves);
		}
		System.out.printf("Updating cell (%d, %d): %d\n", c.x, c.y, c.moves); 

		updateCell(grid, minMoves, new ArrayList<Cell>(path), x + 1, y, d);
		updateCell(grid, minMoves, new ArrayList<Cell>(path), x - 1, y, d);
		updateCell(grid, minMoves, new ArrayList<Cell>(path), x, y + 1, d);
		updateCell(grid, minMoves, new ArrayList<Cell>(path), x, y - 1, d);
	}

	static int minimumMoves(String[] grid, int startX, int startY, int goalX, int goalY) {
		Map<String, Integer> minMoves = new HashMap<String, Integer>();
		//System.out.println("Before:");
		//for (String line : grid) {
		//	System.out.println(line);
		//}
		updateCell(grid, minMoves, new ArrayList<Cell>(), goalX, goalY, 0);
		//System.out.println("After:");
		//for (String line : grid) {
		//	System.out.println(line);
		//}
		//System.out.println(minMoves);

		String startKey = hash(startX, startY);
		return minMoves.get(startKey);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String[] grid = new String[n];
		for(int grid_i = 0; grid_i < n; grid_i++){
			grid[grid_i] = in.next();
		}
		int startX = in.nextInt();
		int startY = in.nextInt();
		int goalX = in.nextInt();
		int goalY = in.nextInt();
		int result = minimumMoves(grid, startX, startY, goalX, goalY);
		in.close();
		System.out.println(result);
	}
}
