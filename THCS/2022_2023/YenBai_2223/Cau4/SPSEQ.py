def longest_cone_subsequence(arr):
    n = len(arr)
    
    if n < 3:
        return 0  # Không đủ số phần tử để tạo thành dãy hình nón

    # Tạo mảng tăng dần và giảm dần
    inc = [0] * n
    dec = [0] * n

    # Tính độ dài chuỗi con tăng dần
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j] and arr[i] != arr[j]:
                inc[i] = max(inc[i], inc[j] + 1)

    # Tính độ dài chuỗi con giảm dần
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if arr[i] > arr[j] and arr[i] != arr[j]:
                dec[i] = max(dec[i], dec[j] + 1)

    max_length = 0

    # Tính độ dài chuỗi con hình nón
    for i in range(n):
        # x + 1 phần tử tăng, x + 1 phần tử giảm => m = 2x + 1
        if inc[i] + dec[i] >= 1:  # Điều kiện phải có ít nhất 1 phần tử tăng và giảm
            current_length = inc[i] + dec[i] + 1  # +1 cho phần tử giữa
            if current_length % 2 == 1:  # Đảm bảo độ dài là số lẻ
                max_length = max(max_length, current_length)

    return max_length

def main():
    with open("SPSEQ.INP", "r") as infile:
        n = int(infile.readline().strip())
        arr = list(map(int, infile.readline().strip().split()))

    result = longest_cone_subsequence(arr)

    with open("SPSEQ.OUT", "w") as outfile:
        outfile.write(str(result) + '\n')

if __name__ == "__main__":
    main()
