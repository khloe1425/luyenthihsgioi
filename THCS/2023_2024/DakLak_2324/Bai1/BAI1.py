def calculate_sum(n):
    # Tính S(N) theo công thức đã rút gọn
    return (n * (n + 1) * (2 * n + 7)) // 6

def main():
    t = int(input("Nhập số lượng test: "))
    results = []
    for _ in range(t):
        n = int(input())
        results.append(calculate_sum(n))

    # Xuất kết quả
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
