def is_prime(num):
    """Kiểm tra một số có phải là số nguyên tố không."""
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def find_last_special_number(arr):
    """Tìm vị trí số đặc biệt cuối cùng trong dãy số."""
    last_special_index = 0
    for i in range(1, len(arr) - 1):
        if is_prime(arr[i - 1]) and is_prime(arr[i + 1]):
            last_special_index = i + 1  # Chuyển sang chỉ số 1-based
    return last_special_index

def main():
    # Đọc dữ liệu từ file Sodb.INP
    with open("Sodb.INP", "r") as infile:
        arr = list(map(int, infile.readline().split()))

    # Tìm vị trí số đặc biệt cuối cùng
    result = find_last_special_number(arr)

    # Ghi kết quả ra file Sodb.OUT
    with open("Sodb.OUT", "w") as outfile:
        outfile.write(f"{result}\n")

if __name__ == "__main__":
    main()
