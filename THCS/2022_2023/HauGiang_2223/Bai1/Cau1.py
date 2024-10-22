def main():
    # Đọc dữ liệu từ tệp xau.inp
    with open("xau.inp", "r") as input_file:
        s = input_file.readline().strip()

    # Tạo một tập hợp chứa tất cả các ký tự từ A đến Z
    all_characters = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

    # Tạo một tập hợp từ xâu S
    present_characters = set(s)

    # Tìm các ký tự còn thiếu
    missing_characters = sorted(all_characters - present_characters)

    # Ghi ra tệp xau.out các ký tự còn thiếu
    with open("xau.out", "w") as output_file:
        output_file.write("".join(missing_characters))

if __name__ == "__main__":
    main()
