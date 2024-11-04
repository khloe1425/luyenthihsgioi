def is_repeated_substring(s):
    n = len(s)
    for i in range(1, n // 2 + 1):
        if n % i == 0:  # Nếu độ dài của xâu chia hết cho i
            if s[:i] * (n // i) == s:  # Kiểm tra xem xâu có phải là lặp lại không
                return s[:i]  # Trả về đoạn đầu ngắn nhất
    return None  # Nếu không tìm thấy đoạn đầu ngắn nhất

def main():
    try:
        # Đọc file SUBSTR.INP
        with open("SUBSTR.INP", "r") as infile:
            n = int(infile.readline().strip())  # Đọc số lượng xâu
            substrings = [infile.readline().strip() for _ in range(n)]  # Đọc các xâu
            
    except FileNotFoundError:
        print("Không thể mở file SUBSTR.INP")
        return

    result = ""

    for s in substrings:
        substring = is_repeated_substring(s)  # Kiểm tra xâu lặp và lấy đoạn đầu
        if substring:
            result += substring  # Ghép đoạn đầu vào kết quả

    # Ghi kết quả vào file SUBSTR.OUT
    try:
        with open("SUBSTR.OUT", "w") as outfile:
            outfile.write(result)  # Ghi kết quả vào file
    except:
        print("Không thể mở file SUBSTR.OUT")

if __name__ == "__main__":
    main()
