def find_consecutive_sum(n):
    results = []
    
    # Duyệt từ 1 đến n/2 để tìm các dãy số liên tiếp
    for start in range(1, n // 2 + 1):
        sum_consecutive = 0
        current = start
        
        while sum_consecutive < n:
            sum_consecutive += current
            current += 1
            
            if sum_consecutive == n:
                # Thêm dãy số vào kết quả
                results.append(list(range(start, current)))
    
    return results

def main():
    n = int(input("Nhap vao so tu nhien n (0 < n <= 32000): "))
    
    if n <= 0 or n > 32000:
        print("Nhap khong hop le. Vui long nhap lai.")
        return
    
    results = find_consecutive_sum(n)

    if results:
        for seq in results:
            print(" ".join(map(str, seq)))
        print(f"Co {len(results)} cach chia so {n}")
    else:
        print("Khong co cach chia nao.")

if __name__ == "__main__":
    main()
