def isPossible(n, row, col, board):
	for i in reversed(range(row)):
		if board[i][col] == 1:
			return False
	for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
		if board[i][j] == 1:
			return False

	for i, j in zip(range(row, -1, -1), range(col, len(board[0]) - 1)):
		if board[i][j] == 1:
			return False

	return True

def NQueenHelper(n, row, board):
	if row == n:
		for i in range(n):
			for j in range(n):
				print(board[i][j], end = " ")
		print()

	for j in range(n):
		if isPossible(n, row, j, board):
			board[row][j] = 1
			NQueenHelper(n, row + 1, board)
			board[row][j] = 0

	return


def NQueen(n):
	board = [[0 for i in range(n + 1)] for j in range(n + 1)]

	NQueenHelper(n, 0, board)


if __name__ == "__main__": 
	NQueen(4)