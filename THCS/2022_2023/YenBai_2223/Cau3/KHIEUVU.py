def count_dancing_pairs(heights, k):
    """Đếm số cặp đôi có độ chênh lệch chiều cao bằng k."""
    heights.sort()  # Sắp xếp danh sách chiều cao
    count = 0
    n = len(heights)
    
    left = 0
    right = 0
    
    while right < n:
        # Tìm kiếm các cặp có độ chênh lệch chiều cao bằng k
        while right < n and heights[right] - heights[left] < k:
            right += 1
        # Nếu chênh lệch chiều cao bằng k, đếm các cặp
        if right < n and heights[right] - heights[left] == k:
            # Đếm số chiều cao giống nhau ở bên trái
            count_left = 1
            while left + 1 < n and heights[left] == heights[left + 1]:
                count_left += 1
                left += 1
            
            # Đếm số chiều cao giống nhau ở bên phải
            count_right = 1
            while right + 1 < n and heights[right] == heights[right + 1]:
                count_right += 1
                right += 1
            
            # Cộng vào tổng số cặp
            count += count_left * count_right
        
        left += 1

    return count

# Đọc dữ liệu từ tệp
with open("KHIEUVU.INP", "r") as infile:
    n, k = map(int, infile.readline().strip().split())
    heights = list(map(int, infile.readline().strip().split()))

# Tính số cặp đôi và ghi vào tệp
result = count_dancing_pairs(heights, k)

# Ghi kết quả vào tệp
with open("KHIEUVU.OUT", "w") as outfile:
    outfile.write(f"{result}\n")
