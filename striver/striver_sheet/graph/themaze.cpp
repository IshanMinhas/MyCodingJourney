import java.util.*;
class Node {
    int start, end;
    Node(int s, int e) {
        start = s;
        end = e;
    }
}

public class Solution {
    public static Boolean reachDestination(int[][] maze, int n, int m, int startX, int startY, int destX, int destY) {
        
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(startX, startY));

        int[][] vis = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }

        vis[startX][startY] = 1;

        while(!q.isEmpty()) {
            int x = q.peek().start;
            int y = q.peek().end;
            q.poll();

            if(x == destX && y == destY) return true;

            int[] dx = {0, 0, -1, 1};
            int[] dy = {1, -1, 0, 0};

            for(int ind = 0; ind < 4; ind++) {
                int newX = x;
                int newY = y;

                while(newX >= 0 && newX < n && newY >= 0 && newY < m && 
                    maze[newX][newY] == 0) {
                    newX += dx[ind];
                    newY += dy[ind];
                }
                // After this step.. you are either out of boundary or stopped at 1

                // Comeback one step;
                newX -= dx[ind];
                newY -= dy[ind];

                if(vis[newX][newY] == 0) {
                    vis[newX][newY] = 1;
                    q.offer(new Node(newX, newY));
                }
            }
        }
        return false;
    }
}