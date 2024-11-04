def main():
    # Đọc dữ liệu từ file
    with open("TANGQUA.INP", "r") as infile:
        N = int(infile.readline().strip())  # Số lượng món quà
        gifts = list(map(int, infile.readline().strip().split()))  # Danh sách giá trị quà

    # Tìm giá trị lớn nhất trong danh sách quà
    max_value = max(gifts)
    
    # Đếm số lượng quà có giá trị lớn nhất
    count_max_gifts = gifts.count(max_value)

    # Ghi kết quả vào file
    with open("TANGQUA.OUT", "w") as outfile:
        outfile.write(str(count_max_gifts) + "\n")

if __name__ == "__main__":
    main()
