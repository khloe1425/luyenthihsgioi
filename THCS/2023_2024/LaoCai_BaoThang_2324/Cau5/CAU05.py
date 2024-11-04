def max_subarray_sum(arr):
    max_sum = arr[0]
    current_sum = arr[0]
    
    for num in arr[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    
    return max_sum

# Đọc dữ liệu từ file CAU05.INP
with open("CAU05.INP", "r") as f:
    N = int(f.readline().strip())
    arr = list(map(int, f.readline().strip().split()))

# Tính tổng lớn nhất
result = max_subarray_sum(arr)

# Ghi kết quả ra file CAU05.OUT
with open("CAU05.OUT", "w") as f:
    f.write(str(result))
