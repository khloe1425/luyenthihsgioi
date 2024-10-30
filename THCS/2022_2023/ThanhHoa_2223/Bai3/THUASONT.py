import math

def prime_factorization(N):
    factors = []
    # Xử lý số 2
    count = 0
    while N % 2 == 0:
        count += 1
        N //= 2
    if count > 0:
        factors.append((2, count))

    # Xử lý các số lẻ từ 3 đến sqrt(N)
    for i in range(3, int(math.sqrt(N)) + 1, 2):
        count = 0
        while N % i == 0:
            count += 1
            N //= i
        if count > 0:
            factors.append((i, count))

    # Nếu N là một số nguyên tố lớn hơn 2
    if N > 2:
        factors.append((N, 1))

    return factors

def main():
    # Đọc dữ liệu từ file
    with open("THUASONT.INP", "r") as infile:
        N = int(infile.readline().strip())

    # Phân tích N thành các thừa số nguyên tố
    factors = prime_factorization(N)

    # Ghi kết quả vào file
    with open("THUASONT.OUT", "w") as outfile:
        outfile.write(f"{len(factors)}\n")  # Số lượng thừa số nguyên tố
        for factor in factors:
            outfile.write(f"{factor[0]} {factor[1]}\n")  # p_i và a_i

if __name__ == "__main__":
    main()
