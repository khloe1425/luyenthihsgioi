def main():
    import sys
    from bisect import bisect_left

    # Đọc số lượng phần tử và số truy vấn
    N, Q = map(int, input().split())
    
    # Đọc dãy số đã được sắp xếp
    a = list(map(int, input().split()))

    results = []

    # Xử lý mỗi truy vấn
    for _ in range(Q):
        L, R, S = map(int, input().split())
        # Chuyển đổi L, R từ 1-based sang 0-based
        L -= 1
        R -= 1

        # Tìm số nhỏ nhất >= S trong đoạn a[L] đến a[R]
        pos = bisect_left(a, S, L, R + 1)

        if pos <= R:  # Kiểm tra nếu pos nằm trong đoạn [L, R]
            results.append(a[pos])
        else:
            results.append(-1)

    # Xuất kết quả
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
