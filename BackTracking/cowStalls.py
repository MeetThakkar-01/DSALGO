# (BINARY SEARCH PROBLEM) (O(N Log(d)))

# Cow Stalls problem :
# We are given N stalls and C cows place c cows in n stalls such that largest distance between cows
# is minimum

def check(c, positions, n, distance):
	count = 1
	last_position = positions[0]

	for i in range(1, n):
		if positions[i] - last_position >= distance:
			last_position = positions[i]
			count += 1
		if count == c:
			return True
	return False


if __name__ == "__main__": 
	for _ in range(int(input())):
		n, c = map(int, input().split())
		positions = []
		for i in range(n):
			positions.append(int(input()))
		positions.sort()
		# print(positions)

		start = 0
		end = positions[n-1] - positions[0]

		ans = -1

		while start<=end:
			mid = start + (end - start)//2
			# print("**" + str(mid))

			if check(c, positions, n, mid):
				ans = mid
				start = mid + 1
			else:
				end = mid - 1

		print(ans)

