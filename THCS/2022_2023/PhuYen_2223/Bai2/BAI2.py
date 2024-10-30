def is_harmonic(A, B, start):
    """
    Hàm kiểm tra xem đoạn con B có đồng điệu với dãy A hay không.
    A là dãy mẫu, B là dãy cần kiểm tra, start là vị trí bắt đầu của đoạn con trong B.
    """
    k = B[start] - A[0]
    N = len(A)
    
    for i in range(1, N):
        if B[start + i] != A[i] + k:
            return False
    return True

def count_harmonic_sequences(A, B):
    """
    Hàm đếm số dãy con đồng điệu với dãy A trong dãy B.
    """
    N = len(A)
    M = len(B)
    count = 0
    
    i = 0
    while i <= M - N:
        if is_harmonic(A, B, i):
            count += 1
            i += N  # Bỏ qua các đoạn con rời nhau
        else:
            i += 1
    return count

# Đọc dữ liệu từ file BAI2.INP
with open("BAI2.INP", "r") as inp_file:
    # Đọc dòng đầu tiên chứa N và dãy A
    A = list(map(int, inp_file.readline().split()))[1:]  # Bỏ qua N, chỉ lấy dãy A
    
    # Đọc dòng thứ hai chứa dãy B
    B = list(map(int, inp_file.readline().split()))[1:]  # Bỏ qua M, chỉ lấy dãy B

# Đếm số dãy con đồng điệu
result = count_harmonic_sequences(A, B)

# Ghi kết quả vào file BAI2.OUT
with open("BAI2.OUT", "w") as out_file:
    out_file.write(str(result) + "\n")
