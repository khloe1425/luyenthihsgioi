import math

# Hàm tính số ngày leo để đạt đến đỉnh
def calculate_days(V, A, B):
    if A >= V:
        return 1  # Nếu A >= V thì chỉ cần 1 ngày để leo đến đỉnh
    return math.ceil((V - A) / (A - B)) + 1

# Đọc dữ liệu từ tệp ATHORUA.INP
with open("ATHORUA.INP", "r") as inputFile:
    V = int(inputFile.readline().strip())
    A1, B1 = map(int, inputFile.readline().strip().split())
    A2, B2 = map(int, inputFile.readline().strip().split())

# Tính số ngày cho Thỏ và Rùa
days_tho = calculate_days(V, A1, B1)
days_rua = calculate_days(V, A2, B2)

# Xác định kết quả
with open("ATHORUA.OUT", "w") as outputFile:
    if days_tho < days_rua:
        outputFile.write("THO")
    elif days_tho > days_rua:
        outputFile.write("RUA")
    else:
        outputFile.write("HOA")
