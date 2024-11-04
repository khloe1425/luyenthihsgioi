def main():
    # Đọc dữ liệu từ file GAME.INP
    with open("GAME.INP", "r") as infile:
        N, K = map(int, infile.readline().strip().split())
        energies = list(map(int, infile.readline().strip().split()))

    # Khởi tạo mảng chi phí tối thiểu
    min_cost = [float('inf')] * N
    min_cost[0] = 0  # Chi phí để đứng ở ô 1 là 0

    # Tính toán chi phí tối thiểu
    for i in range(N):
        for j in range(1, K + 1):
            if i + j < N:
                min_cost[i + j] = min(min_cost[i + j], min_cost[i] + abs(energies[i + j] - energies[i]))

    # Ghi kết quả vào file GAME.OUT
    with open("GAME.OUT", "w") as outfile:
        outfile.write(f"{min_cost[N - 1]}\n")  # Chi phí tối thiểu để đến ô N

if __name__ == "__main__":
    main()
