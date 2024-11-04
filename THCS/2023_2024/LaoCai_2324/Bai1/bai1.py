# Đọc dữ liệu từ file
with open('bai1.inp', 'r') as infile:
    a, b, K = map(int, infile.readline().split())

# Mở file output để ghi kết quả
with open('bai1.out', 'w') as outfile:
    # Kiểm tra nếu K là số lẻ
    if K % 2 != 0:
        outfile.write("NO\n")
    else:
        # Tìm số chia hết cho K đầu tiên và cuối cùng trong đoạn [a, b]
        first = a if a % K == 0 else a + (K - a % K)
        last = b if b % K == 0 else b - (b % K)
        
        # Kiểm tra xem có tồn tại số nào chia hết cho K trong đoạn [a, b]
        if first > b or last < a:
            outfile.write("NO\n")
        else:
            # Tính số lượng các số chia hết cho K trong đoạn [a, b]
            count = ((last - first) // K) + 1
            # Kiểm tra nếu số lượng chẵn
            if count % 2 == 0:
                outfile.write("YES\n")
            else:
                outfile.write("NO\n")
