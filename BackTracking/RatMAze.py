def mazeHelper(maze, x, y, n, solution):

	if x == n -1 and y == n - 1:
		solution[x][y] = 1
		print(solution)
		return

	if (x==n or x<0 or y==n or y<0 or maze[x][y] == 0 or solution[x][y] == 1):
		return

	solution[x][y] = 1

	mazeHelper(maze, x-1, y, n, solution)
	mazeHelper(maze, x+1, y, n, solution)
	mazeHelper(maze, x, y-1, n, solution)
	mazeHelper(maze, x, y+1, n, solution)
	solution[x][y] = 0

def RatMaze(maze, n):
	solution = [[0 for i in range(len(maze))] for j in range(len(maze[0]))]
	mazeHelper(maze, 0, 0, n, solution)

if __name__ == "__main__": 
	RatMaze	([[1, 0, 1],[1, 0, 1],[1, 1, 1]], 3)