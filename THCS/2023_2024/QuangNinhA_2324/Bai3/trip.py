def main():
    with open("trip.inp", "r") as input_file:
        # Đọc n và q
        n, q = map(int, input_file.readline().split())
        # Đọc mảng a
        a = list(map(int, input_file.readline().split()))

    mins = []

    # Tạo tất cả các bộ ba và tính min
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                mins.append(min(a[i], a[j], a[k]))

    # Sắp xếp các giá trị min
    mins.sort()

    # Xử lý truy vấn
    results = []
    with open("trip.out", "w") as output_file:
        # Mở lại tệp đầu vào để đọc truy vấn
        with open("trip.inp", "r") as input_file:
            input_file.readline()  # Bỏ qua dòng đầu tiên
            input_file.readline()  # Bỏ qua dòng chứa mảng a
            for _ in range(q):
                k = int(input_file.readline())
                results.append(mins[k - 1])  # k - 1 vì chỉ số bắt đầu từ 0
        
        # Ghi kết quả vào tệp
        output_file.write('\n'.join(map(str, results)) + '\n')

if __name__ == "__main__":
    main()
