def last_digit(A, N):
    # Bảng chu kỳ chữ số tận cùng
    cycles = {
        0: [0],          # 0^N
        1: [1],          # 1^N
        2: [2, 4, 8, 6], # 2^N
        3: [3, 9, 7, 1], # 3^N
        4: [4, 6],      # 4^N
        5: [5],          # 5^N
        6: [6],          # 6^N
        7: [7, 9, 3, 1], # 7^N
        8: [8, 4, 2, 6], # 8^N
        9: [9, 1]       # 9^N
    }
    
    if A == 0:
        return 0  # Nếu A = 0 thì chữ số tận cùng là 0
    A = A % 10  # Lấy chữ số tận cùng của A

    # Tính chỉ số trong chu kỳ
    if N == 0:
        return 1  # A^0 = 1
    cycle_length = len(cycles[A])
    index = (N - 1) % cycle_length  # -1 để chuyển từ 1-indexed sang 0-indexed
    return cycles[A][index]

def main():
    # Đọc dữ liệu từ file
    with open("TANCUNG.INP", "r") as infile:
        A, N = map(int, infile.readline().strip().split())

    # Tính chữ số tận cùng của A^N
    last_digit_value = last_digit(A, N)

    # Ghi kết quả vào file
    with open("TANCUNG.OUT", "w") as outfile:
        outfile.write(str(last_digit_value) + "\n")

if __name__ == "__main__":
    main()
