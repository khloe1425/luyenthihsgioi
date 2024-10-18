input_path = "./CHUMDEN.INP"
output_path = "./CHUMDEN.OUT"

def count_subarrays_with_k_odds(arr, n, k):
    # Tạo mảng binary: 1 nếu số lẻ, 0 nếu số chẵn
    binary = [1 if x % 2 != 0 else 0 for x in arr]

    # Hash map để đếm số lần xuất hiện của từng prefix sum
    prefix_sum_count = {}
    prefix_sum_count[0] = 1  # Giá trị khởi đầu của prefix sum (trước khi bắt đầu mảng)
    
    prefix_sum = 0
    result = 0

    # Duyệt qua từng phần tử của mảng binary
    for i in range(n):
        # Cập nhật prefix sum
        prefix_sum += binary[i]
        
        # Tìm xem có bao nhiêu prefix_sum trước đó có tổng là (prefix_sum - k)
        if prefix_sum - k in prefix_sum_count:
            result += prefix_sum_count[prefix_sum - k]
        
        # Cập nhật số lần xuất hiện của prefix_sum hiện tại
        if prefix_sum in prefix_sum_count:
            prefix_sum_count[prefix_sum] += 1
        else:
            prefix_sum_count[prefix_sum] = 1

    return result
def solve():
    with open(input_path, 'r') as file_in:
        n, k = map(int, file_in.readline().split())
        arr = list(map(int, file_in.readline().split()))
    
    result = count_subarrays_with_k_odds(arr, n, k)
    
    with open(output_path, 'w') as file_out:
        file_out.write(str(result))

solve()
