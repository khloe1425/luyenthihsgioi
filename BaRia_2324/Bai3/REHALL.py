input_path = './THCS/2024/BaRia/Bai3/REHALL.INP'
output_path = './THCS/2024/BaRia/Bai3/REHALL.OUT'
def main():
    with open(input_path, 'r') as file:
        n = int(file.readline().strip())
        events = []
        for _ in range(n):
            start, end, cost = map(int, file.readline().strip().split())
            events.append((start, end, cost))

    # Sắp xếp các sự kiện theo thời gian kết thúc
    events.sort(key=lambda x: x[1])

    # dp lưu lợi nhuận tối ưu tại thời điểm kết thúc
    dp = [0] * n  # dp[i] là lợi nhuận tối ưu tại sự kiện thứ i
    prev = [-1] * n  # prev[i] là sự kiện không trùng thời gian với sự kiện i

    # Tìm sự kiện trước đó không trùng với sự kiện hiện tại
    for i in range(n):
        for j in range(i - 1, -1, -1):
            if events[j][1] < events[i][0]:  # sự kiện j kết thúc trước khi sự kiện i bắt đầu
                prev[i] = j
                break

    # Tính toán lợi nhuận tối ưu
    for i in range(n):
        if prev[i] == -1:
            dp[i] = events[i][2]  # Nếu không có sự kiện nào trước đó, lợi nhuận chỉ là chính sự kiện đó
        else:
            dp[i] = max(dp[i - 1], dp[prev[i]] + events[i][2])  # Chọn giữa việc lấy hoặc không lấy sự kiện i

    max_profit = max(dp)

    with open(output_path, 'w') as file:
        file.write(f"{max_profit}\n")

if __name__ == "__main__":
    main()
