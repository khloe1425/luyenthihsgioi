def main():
    # Đọc dữ liệu từ file
    with open('CAKE.INP', 'r') as infile:
        N = int(infile.readline().strip())
        cake = infile.readline().strip()

    # Đếm tổng số quả dâu và quả sim
    total_D = cake.count('D')
    total_S = cake.count('S')

    # Nếu số lượng quả dâu hoặc sim là lẻ, không thể chia đều
    if total_D % 2 != 0 or total_S % 2 != 0:
        with open('CAKE.OUT', 'w') as outfile:
            outfile.write("-1\n")
        return

    # Tổng số quả cần có ở mỗi phần
    half_D = total_D // 2
    half_S = total_S // 2

    # Duyệt qua các vị trí để tìm cách cắt
    for start in range(N):
        count_D = 0
        count_S = 0
        for end in range(start, start + N):  # Duyệt vòng tròn
            if cake[end % N] == 'D':
                count_D += 1
            else:
                count_S += 1

            # Kiểm tra điều kiện
            if count_D == half_D and count_S == half_S:
                a = (start + 1)  # Thêm 1 vì yêu cầu số nguyên dương
                b = (end % N + 1)  # Thêm 1 vì yêu cầu số nguyên dương
                if a > b:
                    a, b = b, a  # Đảm bảo a < b
                with open('CAKE.OUT', 'w') as outfile:
                    outfile.write(f"{a} {b}\n")
                return

    # Nếu không tìm thấy cách chia
    with open('CAKE.OUT', 'w') as outfile:
        outfile.write("-1\n")

if __name__ == '__main__':
    main()
