def count_virus(n, k):
    MOD = 10**9 + 7
    # Danh sách để lưu số lượng cá thể mỗi ngày
    virus = [0] * (k + 1)
    virus[0] = n  # Ngày 0 có n cá thể ở mức 1

    # Lặp qua từng ngày
    for day in range(1, k + 1):
        new_viruses = 0
        # Tính số cá thể mới sinh ra trong ngày
        for level in range(day):
            new_viruses += virus[level] * (level + 1)
            new_viruses %= MOD

        # Cập nhật số lượng cá thể cho ngày tiếp theo
        for level in range(day, 0, -1):
            virus[level] = virus[level - 1]
        virus[0] = new_viruses  # Cập nhật số lượng cá thể ở mức 1

    # Tính tổng số cá thể
    total_virus = sum(virus) % MOD

    return total_virus


if __name__ == "__main__":
    # Đọc dữ liệu từ file FLASHBACK.INP
    with open("FLASHBACK.INP", "r") as input_file:
        n, k = map(int, input_file.readline().strip().split())

    # Tính số lượng cá thể virus sau k ngày
    result = count_virus(n, k)

    # Ghi kết quả ra file FLASHBACK.OUT
    with open("FLASHBACK.OUT", "w") as output_file:
        output_file.write(str(result) + "\n")
