def check(x, a, n, k):
    t = a[0] + x
    d = 1  # Số trạm phát sóng đã sử dụng

    for i in range(1, n):
        if a[i] > t + x:  # Nếu trạm thu sóng thứ i không được bao phủ
            d += 1
            t = a[i] + x  # Đặt trạm phát sóng tại vị trí a[i]

    t = a[1] + x  # Khởi tạo lại t cho lần kiểm tra thứ hai
    d1 = 1  # Số trạm phát sóng thứ hai

    for i in range(2, n + 1):
        if a[i] > t + x:  # Tương tự như trên
            d1 += 1
            t = a[i] + x  # Đặt trạm phát sóng tại vị trí a[i]

    return min(d, d1) <= k  # Trả về true nếu số trạm phát sóng không vượt quá K

def binary_search(l, r, a, n, k):
    res = 0  # Biến để lưu kết quả
    while l <= r:
        mid = (l + r) // 2
        if check(mid, a, n, k):
            res = mid  # Cập nhật kết quả
            r = mid - 1  # Tìm kiếm phạm vi nhỏ hơn
        else:
            l = mid + 1  # Tìm kiếm phạm vi lớn hơn
    return res  # Trả về phạm vi phát sóng ngắn nhất

def main():
    # Đọc dữ liệu từ tệp
    with open("TPS.INP", "r") as inp:
        n = int(inp.readline().strip())  # Số trạm thu sóng
        a = [int(inp.readline().strip()) for _ in range(n)]  # Đọc vị trí trạm thu sóng
        k = int(inp.readline().strip())  # Số trạm phát sóng

    a.sort()  # Sắp xếp vị trí các trạm thu sóng
    a.append(1000000 + a[0])  # Thêm trạm thu sóng đầu tiên vào cuối để xử lý vòng tròn

    # Tìm và in ra phạm vi phát sóng ngắn nhất
    result = binary_search(1, 1000000, a, n, k)
    with open("TPS.OUT", "w") as out:
        out.write(str(result) + "\n")

if __name__ == "__main__":
    main()
