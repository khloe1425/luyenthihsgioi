def is_palindrome(s):
    return s == s[::-1]

def longest_palindromic_substring(s):
    n = len(s)
    max_length = 1  # Chiều dài tối thiểu của xâu con đối xứng là 1

    # Tìm xâu con đối xứng
    for i in range(n):
        for j in range(i, n):
            substring = s[i:j + 1]
            if is_palindrome(substring):
                max_length = max(max_length, j - i + 1)

    return max_length

def main():
    with open("CAU04.INP", "r") as infile:
        N = int(infile.readline().strip())  # Đọc chiều dài xâu S
        S = infile.readline().strip()  # Đọc xâu S

    # Tìm chiều dài xâu con đối xứng dài nhất
    longest_length = longest_palindromic_substring(S)

    # Ghi kết quả ra tệp
    with open("CAU04.OUT", "w") as outfile:
        outfile.write(f"{longest_length}\n")

if __name__ == "__main__":
    main()
