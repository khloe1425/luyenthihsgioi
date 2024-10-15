def main():
    # Đọc dữ liệu từ file TICKET.INP
    with open("TICKET.INP", "r") as input_file:
        a, b, u, v, x, y = map(int, input_file.readline().strip().split())

    # Tính số người lớn
    adults = x - y

    # Tính tổng chi phí
    total_cost = (a * adults) + (b * y) + (u * adults) + (v * y)

    # Ghi kết quả vào file TICKET.OUT
    with open("TICKET.OUT", "w") as output_file:
        output_file.write(str(total_cost))

if __name__ == "__main__":
    main()