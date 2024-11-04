import bisect

# Hàm tìm kiếm nhị phân để tìm đơn cuối cùng không chồng chéo với đơn hiện tại
def find_last_non_overlapping(orders, current_start):
    left, right = 0, len(orders) - 1
    while left <= right:
        mid = (left + right) // 2
        if orders[mid][1] < current_start:
            if mid + 1 < len(orders) and orders[mid + 1][1] < current_start:
                left = mid + 1
            else:
                return mid
        else:
            right = mid - 1
    return -1

# Hàm tính lợi nhuận lớn nhất
def max_profit(n, bookings):
    # Sắp xếp các đơn theo ngày trả phòng
    bookings.sort(key=lambda x: x[1])

    # Mảng dp lưu lợi nhuận tối đa đạt được tại mỗi đơn
    dp = [0] * n
    dp[0] = bookings[0][2]  # Lợi nhuận của đơn đầu tiên

    for i in range(1, n):
        current_profit = bookings[i][2]

        # Tìm đơn không chồng chéo gần nhất với đơn i
        last_index = find_last_non_overlapping(bookings, bookings[i][0])

        # Nếu tìm được, cộng lợi nhuận của đơn không chồng chéo vào
        if last_index != -1:
            current_profit += dp[last_index]

        # Lợi nhuận tối đa tại đơn i là chọn hoặc không chọn đơn i
        dp[i] = max(dp[i - 1], current_profit)

    # Kết quả là lợi nhuận tối đa tại đơn cuối cùng
    return dp[-1]

# Nhập dữ liệu
n = int(input("Nhập số lượng đơn đặt phòng: "))
bookings = []
for _ in range(n):
    a, b, c = map(int, input("Nhập a, b, c: ").split())
    bookings.append((a, b, c))

# Tính toán và in ra kết quả
print(max_profit(n, bookings))
