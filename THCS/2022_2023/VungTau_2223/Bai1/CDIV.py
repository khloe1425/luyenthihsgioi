def find_max_gcd():
    # Đọc dữ liệu từ file
    with open("CDIV.INP", "r") as infile:
        N = int(infile.readline().strip())  # Số phần tử trong mảng
        A = list(map(int, infile.readline().strip().split()))  # Đọc mảng A

    # Mảng đếm số lần xuất hiện của từng số từ 1 đến 10^6
    count = [0] * 1000001

    # Đếm số lần xuất hiện của từng số trong mảng
    for number in A:
        count[number] += 1

    # Tìm GCD lớn nhất
    for g in range(1000000, 0, -1):
        sum_boi = 0  # Biến đếm số bội của g
        # Kiểm tra các bội của g
        for j in range(g, 1000001, g):
            sum_boi += count[j]
            if sum_boi >= 2:  # Nếu có ít nhất 2 số là bội của g
                with open("CDIV.OUT", "w") as outfile:
                    outfile.write(f"{g}\n")  # Ghi GCD lớn nhất ra file
                return

if __name__ == "__main__":
    find_max_gcd()
