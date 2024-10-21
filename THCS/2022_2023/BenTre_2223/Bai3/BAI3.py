def convert_to_numbers(s):
    # Định nghĩa ánh xạ giữa chữ cái và số
    mapping = {
        '2': "ABCabc",
        '3': "DEFdef",
        '4': "GHIghi",
        '5': "JKLjkl",
        '6': "MNOmno",
        '7': "PQRSpqrs",
        '8': "TUVtuv",
        '9': "WXYZwxyz"
    }
    
    # Chuyển đổi ký tự thành số
    result = ""
    for char in s:
        for key, value in mapping.items():
            if char in value:
                result += key
                break
    return result

def is_palindrome(s):
    return s == s[::-1]

def main():
    # Đọc dữ liệu từ file TNGH.INP
    with open("TNGH.INP", "r") as infile:
        input_string = infile.readline().strip()

    # Chuyển đổi ký tự thành dãy số
    number_string = convert_to_numbers(input_string)

    # Kiểm tra xem dãy số có phải là thuận nghịch hay không
    if is_palindrome(number_string):
        result = 1
    else:
        result = 0

    # Ghi kết quả vào file TNGH.OUT
    with open("TNGH.OUT", "w") as outfile:
        outfile.write(str(result) + "\n")

if __name__ == "__main__":
    main()
