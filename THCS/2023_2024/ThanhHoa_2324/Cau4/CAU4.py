from math import gcd
from collections import defaultdict

def main():
    # Mở file để đọc dữ liệu
    try:
        with open("CAU4.INP", "r") as infile:
            n = int(infile.readline().strip())  # Đọc số lượng cặp
            
            ans = 0
            mp = defaultdict(int)  # Map để lưu số lượng các giá trị a
            mp2 = defaultdict(int) # Map để lưu số lượng cặp (ff, ss)

            for _ in range(n):
                a, b = map(int, infile.readline().strip().split())  # Đọc các cặp số a và b

                gcd_value = gcd(a, b)
                ff = a // gcd_value
                ss = b // gcd_value

                ans += mp[a] - mp2[(ff, ss)]
                mp[a] += 1
                mp2[(ff, ss)] += 1

    except FileNotFoundError:
        print("Không thể mở file CAU4.INP")
        return

    # In kết quả ra file output
    try:
        with open("CAU4.OUT", "w") as outfile:
            outfile.write(str(ans))  # Ghi kết quả vào file
    except:
        print("Không thể mở file CAU4.OUT")

if __name__ == "__main__":
    main()
