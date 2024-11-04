def main():
    T = int(input())  # Nhập số lượng test
    results = []  # Danh sách lưu kết quả

    for _ in range(T):
        N = int(input())  # Nhập số nguyên dương N
        S_N = N * (N + 1) // 2  # Tính tổng S(N)
        results.append(S_N)  # Thêm kết quả vào danh sách

    # Xuất ra tất cả kết quả
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
