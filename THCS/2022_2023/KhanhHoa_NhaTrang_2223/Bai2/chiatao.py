def get_divisors(n):
    """Hàm tìm các ước số của n."""
    divisors = set()
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    return divisors

def main():
    # Đọc dữ liệu từ file
    with open("chiatao.inp", "r") as f:
        r, g = map(int, f.readline().strip().split())

    # Tìm các ước số của r và g
    divisors_r = get_divisors(r)
    divisors_g = get_divisors(g)

    # Mở file để ghi kết quả
    with open("chiatao.out", "w") as f:
        # Kiểm tra ước số chung và ghi kết quả
        for n in divisors_r:
            if n in divisors_g:
                x = r // n
                y = g // n
                f.write(f"{n} {x} {y}\n")

if __name__ == "__main__":
    main()
