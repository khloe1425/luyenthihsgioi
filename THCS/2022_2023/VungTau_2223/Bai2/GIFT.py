def main():
    # Đọc dữ liệu từ file GIFT.INP
    with open("GIFT.INP", "r") as infile:
        N, K = map(int, infile.readline().strip().split())
        gifts = [int(infile.readline().strip()) for _ in range(N)]

    # Sắp xếp danh sách phần quà theo giá trị tăng dần
    gifts.sort()

    count = 0  # Số lượng phần quà đã chọn
    lastGift = -1  # Giá trị của phần quà cuối cùng đã chọn

    for gift in gifts:
        # Kiểm tra xem phần quà có thể được chọn hay không
        if lastGift == -1 or gift >= lastGift + K:
            count += 1
            lastGift = gift  # Cập nhật giá trị của phần quà đã chọn

    # Ghi kết quả vào file GIFT.OUT
    with open("GIFT.OUT", "w") as outfile:
        outfile.write(f"{count}\n")  # Ghi số lượng phần quà đã chọn

if __name__ == "__main__":
    main()
