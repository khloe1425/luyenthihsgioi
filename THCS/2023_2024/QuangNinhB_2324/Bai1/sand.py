def main():
    # Đọc dữ liệu từ file sand.inp
    with open("sand.inp", "r") as infile:
        a, b, c = map(int, infile.readline().strip().split())
        x, y = map(int, infile.readline().strip().split())

    # Tính số bánh sandwich có thể làm
    max_profit = 0

    # Thử bán sandwich thịt bò trước
    max_bo = min(b, a // 2)  # số bánh sandwich thịt bò tối đa có thể làm
    remaining_bread = a - (max_bo * 2)
    max_ga = min(c, remaining_bread // 2)  # số bánh sandwich thịt gà tối đa có thể làm
    profit1 = (max_bo * x) + (max_ga * y)

    # Thử bán sandwich thịt gà trước
    max_ga_first = min(c, a // 2)  # số bánh sandwich thịt gà tối đa có thể làm
    remaining_bread_first = a - (max_ga_first * 2)
    max_bo_first = min(b, remaining_bread_first // 2)  # số bánh sandwich thịt bò tối đa có thể làm
    profit2 = (max_ga_first * y) + (max_bo_first * x)

    # Lợi nhuận tối đa
    max_profit = max(profit1, profit2)

    # Ghi kết quả ra file sand.out
    with open("sand.out", "w") as outfile:
        outfile.write(f"{max_profit}\n")

if __name__ == "__main__":
    main()
