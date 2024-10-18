
def find_ways_to_stack_books(N):
    ways = []  # Danh sách các cách chia sách hợp lệ

    # Tìm tất cả các dãy liên tiếp có tổng bằng N
    k = 2  # Số chồng sách bắt đầu từ 2 trở lên
    while k * (k + 1) // 2 <= N:  # Điều kiện tổng tối thiểu của dãy liên tiếp phải <= N
        # Tính giá trị x từ công thức S = k(2x + k - 1) / 2 = N
        if (N - k * (k - 1) // 2) % k == 0:
            x = (N - k * (k - 1) // 2) // k  # Tính x
            if x > 0:  # x phải là số tự nhiên dương
                # Tạo dãy liên tiếp bắt đầu từ x và có k phần tử
                way = [x + i for i in range(k)]
                ways.append(way)
        k += 1
    
    return ways

N = int(input("Nhập số sách N: "))

ways = find_ways_to_stack_books(N)

if ways:
    print(len(ways))  # 
    for way in ways:
        print(" + ".join(map(str, way))) 
else:
    print(0) 
