from math import gcd
from functools import reduce

def main():
    # Đọc dữ liệu từ tệp
    with open("gift.inp", "r") as input_file:
        n = int(input_file.readline().strip())
        a = list(map(int, input_file.readline().strip().split()))

    # Tích của phần đầu
    product_prefix = 1
    total_product = reduce(lambda x, y: x * y, a, 1)  # Tính tích toàn bộ dãy số

    for l in range(n - 1):  # Không tính đến phần tử cuối cùng
        product_prefix *= a[l]
        
        # Tính tích phần sau
        product_suffix = total_product // product_prefix  # Tính tích phần sau

        # Kiểm tra nếu GCD của hai tích bằng 1
        if gcd(product_prefix, product_suffix) == 1:
            # Ghi kết quả vào tệp gift.out
            with open("gift.out", "w") as output_file:
                output_file.write(f"{l + 1}\n")  # Lưu vị trí cắt
            return

if __name__ == "__main__":
    main()
