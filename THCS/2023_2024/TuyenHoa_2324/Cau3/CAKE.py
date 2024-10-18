def main():
    # Đọc dữ liệu từ file CAKE.INP
    with open("CAKE.INP", "r") as infile:
        N = int(infile.readline().strip())
        cake = infile.readline().strip()

    # Biến lưu tổng số quả dâu và sim
    totalD = cake.count('D')
    totalS = cake.count('S')

    # Nếu tổng số quả dâu hoặc sim là lẻ thì không thể chia đều
    if totalD % 2 != 0 or totalS % 2 != 0:
        with open("CAKE.OUT", "w") as outfile:
            outfile.write("-1\n")
        return

    # Duyệt qua từng vị trí để tìm cách chia
    for start in range(N):
        countD = 0
        countS = 0

        # Tính số lượng quả trong đoạn từ start đến start + N/2
        for length in range(N):
            if cake[(start + length) % N] == 'D':
                countD += 1
            else:
                countS += 1

            # Kiểm tra nếu số lượng quả đến hiện tại đã đủ chia đều
            if length + 1 >= N // 2:
                # Kiểm tra điều kiện cắt bánh
                if countD == totalD // 2 and countS == totalS // 2:
                    end = (start + length) % N

                    # Định dạng kết quả a, b (a < b)
                    a = start + 1
                    b = end + 1

                    # Điều chỉnh b nếu b <= a
                    if b <= a:
                        b += N

                    with open("CAKE.OUT", "w") as outfile:
                        outfile.write(f"{a} {b}\n")  # Ghi kết quả
                    return  # Kết thúc chương trình

    # Nếu không tìm thấy cách chia, ghi -1 vào file
    with open("CAKE.OUT", "w") as outfile:
        outfile.write("-1\n")

if __name__ == "__main__":
    main()
