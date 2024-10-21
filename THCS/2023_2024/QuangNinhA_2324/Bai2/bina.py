def solve():
    # Đọc dữ liệu từ file
    with open("bina.inp", "r") as infile:
        n, k = map(int, infile.readline().strip().split())
        s = infile.readline().strip()

    # Biến để đếm số thao tác và lưu chuỗi sửa đổi
    operations = 0
    result = list(s)  # Chuyển đổi chuỗi thành danh sách để có thể sửa đổi

    # Duyệt qua chuỗi để kiểm tra và sửa
    count = 1  # Đếm số lượng bit giống nhau liên tiếp
    for i in range(1, n):
        if result[i] == result[i - 1]:  # Nếu bit giống nhau
            count += 1
        else:
            count = 1  # Đặt lại đếm nếu gặp bit khác

        # Nếu số lượng bit giống nhau vượt quá k
        if count > k:
            # Lật bit hiện tại
            operations += 1
            result[i] = '0' if result[i] == '1' else '1'  # Đảo bit
            count = 1  # Reset đếm về 1 vì vừa lật bit

    # Ghi kết quả ra file
    with open("bina.out", "w") as outfile:
        outfile.write(f"{operations}\n")  # Số thao tác tối thiểu
        outfile.write("".join(result))  # Chuỗi đã sửa đổi

if __name__ == "__main__":
    solve()
