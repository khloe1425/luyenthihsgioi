def read_input(file_path):
    with open(file_path, 'r') as f:
        m, n = map(int, f.readline().strip().split())
        matrix = [list(map(int, f.readline().strip().split())) for _ in range(m)]
    return m, n, matrix

def get_neighbors(i, j, m, n):
    neighbors = []
    # Các chỉ số hàng xóm có thể
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right
    for di, dj in directions:
        ni, nj = i + di, j + dj
        if 0 <= ni < m and 0 <= nj < n:
            neighbors.append((ni, nj))
    return neighbors

def count_lucky_guests(m, n, matrix):
    lucky_count = 0
    for i in range(m):
        for j in range(n):
            neighbors = get_neighbors(i, j, m, n)
            neighbor_values = [matrix[ni][nj] for ni, nj in neighbors]
            if neighbor_values:  # Đảm bảo có hàng xóm
                avg_neighbors = sum(neighbor_values) / len(neighbor_values)
                if matrix[i][j] > avg_neighbors:
                    lucky_count += 1
    return lucky_count

def write_output(file_path, result):
    with open(file_path, 'w') as f:
        f.write(str(result) + '\n')

# Thực thi các bước
input_file = 'LUCKY.INP'
output_file = 'LUCKY.OUT'

m, n, matrix = read_input(input_file)
lucky_count = count_lucky_guests(m, n, matrix)
write_output(output_file, lucky_count)
