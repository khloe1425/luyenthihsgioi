def find_shortest_prefix(s):
    n = len(s)
    # Duyệt qua các độ dài của đoạn đầu
    for length in range(1, n // 2 + 1):
        # Kiểm tra nếu n chia hết cho length
        if n % length == 0:
            prefix = s[:length]
            # Tạo xâu từ đoạn đầu
            repeated = prefix * (n // length)
            # Kiểm tra xem xâu lặp lại có giống với xâu ban đầu không
            if repeated == s:
                return prefix  # Trả về đoạn đầu ngắn nhất
    return ""

def main():
    with open("SUBSTR.INP", "r") as infile:
        n = int(infile.readline().strip())
        result = ""

        for _ in range(n):
            s = infile.readline().strip()  # Đọc từng xâu
            prefix = find_shortest_prefix(s)
            if prefix:  # Nếu xâu lập
                result += prefix  # Ghép các đoạn đầu ngắn nhất

    # Ghi kết quả ra file
    with open("SUBSTR.OUT", "w") as outfile:
        outfile.write(result)

if __name__ == "__main__":
    main()
