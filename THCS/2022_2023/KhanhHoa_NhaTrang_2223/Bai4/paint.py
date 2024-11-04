# Đọc dữ liệu từ PAINT.INP
def read_paint_inp(file_path):
    with open(file_path, "r") as file:
        # Đọc dòng đầu tiên là kích thước m, n
        m, n = map(int, file.readline().split())
        
        # Đọc lưới chiều cao các cột
        grid = [list(map(int, file.readline().split())) for _ in range(m)]
        
    return m, n, grid

# Ghi kết quả vào PAINT.OUT
def write_paint_out(file_path, result):
    with open(file_path, "w") as file:
        file.write(str(result) + "\n")

# Hàm tính diện tích cần sơn
def calculate_painted_area(m, n, grid):
    total_area = 0

    # Cộng diện tích mặt trên
    total_area += m * n

    # Duyệt qua từng ô trong lưới
    for i in range(m):
        for j in range(n):
            # Lấy chiều cao cột tại vị trí (i, j)
            height = grid[i][j]
            
            # Mặt trước: So sánh với cột phía trước (i-1)
            if i == 0:  # Ở rìa trên, luôn sơn mặt trước
                total_area += height
            else:
                total_area += max(0, height - grid[i-1][j])
            
            # Mặt sau: So sánh với cột phía sau (i+1)
            if i == m-1:  # Ở rìa dưới, luôn sơn mặt sau
                total_area += height
            else:
                total_area += max(0, height - grid[i+1][j])
            
            # Mặt trái: So sánh với cột bên trái (j-1)
            if j == 0:  # Ở rìa trái, luôn sơn mặt trái
                total_area += height
            else:
                total_area += max(0, height - grid[i][j-1])
            
            # Mặt phải: So sánh với cột bên phải (j+1)
            if j == n-1:  # Ở rìa phải, luôn sơn mặt phải
                total_area += height
            else:
                total_area += max(0, height - grid[i][j+1])

    return total_area

# Đường dẫn tới file
file_path_inp = "./paint.inp"
file_path_out = "./paint.out"

# Đọc dữ liệu từ file PAINT.INP
m, n, grid = read_paint_inp(file_path_inp)

# Tính diện tích cần sơn
total_area = calculate_painted_area(m, n, grid)

# Ghi kết quả vào PAINT.OUT
write_paint_out(file_path_out, total_area)

# Kết quả
total_area
