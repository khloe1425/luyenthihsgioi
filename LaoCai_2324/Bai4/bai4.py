def main():
    with open("bai4.inp", "r") as infile:
        k = int(infile.readline().strip())  # Đọc số lượng truy vấn
        results = []

        for _ in range(k):
            s = infile.readline().strip()  # Đọc chuỗi ký tự S
            count = {}  # Từ điển để đếm số lần xuất hiện của từng ký tự

            # Đếm số lần xuất hiện của từng ký tự
            for c in s:
                if c in count:
                    count[c] += 1
                else:
                    count[c] = 1

            position = -1  # Biến để lưu vị trí của ký tự xuất hiện duy nhất
            # Tìm vị trí đầu tiên của ký tự xuất hiện duy nhất
            for j in range(len(s)):
                if count[s[j]] == 1:  # Nếu ký tự xuất hiện duy nhất
                    position = j + 1  # Lưu vị trí (thay đổi từ 0-index sang 1-index)
                    break  # Thoát khỏi vòng lặp

            results.append(position)  # Lưu kết quả vào danh sách

    # Ghi kết quả vào tệp đầu ra
    with open("bai4.out", "w") as outfile:
        for result in results:
            outfile.write(str(result) + "\n")

if __name__ == "__main__":
    main()
