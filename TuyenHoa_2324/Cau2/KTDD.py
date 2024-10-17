def main():
    # Đọc dữ liệu từ file KTDD.INP
    with open("KTDD.INP", "r") as infile:
        st = infile.read().strip()

    # Tạo tập hợp ký tự đại diện
    # Sử dụng set để tự động loại bỏ các ký tự trùng lặp
    representative_set = set(st)

    # Chuyển tập hợp về danh sách và sắp xếp nếu cần
    representative_list = sorted(representative_set)

    # Ghi kết quả vào file KTDD.OUT
    with open("KTDD.OUT", "w") as outfile:
        # Nối các ký tự trong danh sách bằng khoảng trắng
        outfile.write(" ".join(representative_list) + "\n")

if __name__ == "__main__":
    main()
