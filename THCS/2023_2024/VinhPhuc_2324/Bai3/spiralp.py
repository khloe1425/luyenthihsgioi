from collections import deque

def is_valid(x, y, N, M, grid):
    return 0 <= x < N and 0 <= y < M and grid[x][y] == 0

def bfs_min_steps(N, M, K, grid):
    queue = deque([(0, 0)])  # Bắt đầu từ ô (0, 0)
    visited = [[False] * M for _ in range(N)]
    visited[0][0] = True
    steps = 0

    while queue:
        size = len(queue)
        for _ in range(size):
            x, y = queue.popleft()

            # Kiểm tra nếu đã đến ô (N-1, M-1)
            if (x, y) == (N - 1, M - 1):
                return steps

            current_index = x * M + y + 1  # Đánh số ô bắt đầu từ 1
            for move in range(1, K + 1):
                for j in range(move + 1):
                    new_x = x + (move - j)  # Di chuyển xuống
                    new_y = y + j            # Di chuyển sang phải

                    if is_valid(new_x, new_y, N, M, grid) and not visited[new_x][new_y]:
                        visited[new_x][new_y] = True
                        queue.append((new_x, new_y))
        steps += 1

    return -1  # Nếu không đến được ô (N-1, M-1)

def calculate_ways(N, M, K, grid):
    ways = [0] * (N * M + 1)
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 0:  # Nếu ô là trắng
                index = i * M + j + 1
                for move in range(1, K + 1):
                    for jMove in range(move + 1):
                        new_x = i + (move - jMove)
                        new_y = j + jMove

                        if is_valid(new_x, new_y, N, M, grid):
                            ways[index] += 1
    return ways

def main():
    # Đọc dữ liệu từ file 'spiralp.inp'
    with open('spiralp.inp', 'r') as f:
        N, M, K = map(int, f.readline().split())
        grid = [list(map(int, f.readline().split())) for _ in range(N)]

    # Tính số bước tối thiểu
    min_steps = bfs_min_steps(N, M, K, grid)

    # Tính số cách di chuyển hợp lệ
    ways = calculate_ways(N, M, K, grid)

    # Tìm giá trị max(F(1), F(2), ..., F(N*M))
    max_ways = max(ways[1:])  # Bỏ qua cách số 0

    # Ghi kết quả vào file 'spiralp.out'
    with open('spiralp.out', 'w') as out_file:
        out_file.write(f"{min_steps} {max_ways}\n")

if __name__ == "__main__":
    main()
