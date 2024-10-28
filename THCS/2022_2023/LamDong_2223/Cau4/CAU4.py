def min_cost_artists(n, m, performances):
    # Khởi tạo mảng DP với giá trị vô cùng
    dp = [float('inf')] * (n + 1)
    dp[0] = 0  # Không thuê nghệ sĩ nào tại thời điểm 0 có chi phí 0

    # Duyệt qua từng thời điểm từ 1 đến n
    for i in range(m):
        s, t, c = performances[i]
        for j in range(t, s, -1):  # Từ t về s
            if dp[j - (t - s)] != float('inf'):
                dp[j] = min(dp[j], dp[j - (t - s)] + c)

    # Tính toán chi phí tối thiểu cho từng thời điểm từ 1 đến n
    for i in range(1, n + 1):
        for j in range(m):
            s, t, c = performances[j]
            if t >= i >= s:
                dp[i] = min(dp[i], dp[s] + c)

    return dp[n]

def main():
    with open("CAU4.INP", "r") as input_file:
        n, m = map(int, input_file.readline().split())
        performances = []
        
        for _ in range(m):
            s, t, c = map(int, input_file.readline().split())
            performances.append((s, t, c))
    
    result = min_cost_artists(n, m, performances)

    with open("CAU4.OUT", "w") as output_file:
        output_file.write(f"{result}\n")

if __name__ == "__main__":
    main()
