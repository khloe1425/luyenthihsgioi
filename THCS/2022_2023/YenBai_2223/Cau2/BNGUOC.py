def reverse_number(num_str):
    """Đảo ngược chuỗi số."""
    return num_str[::-1]

def compare_reversed_numbers(A, B):
    """So sánh số đảo ngược của A và B."""
    reversed_A = reverse_number(A)
    reversed_B = reverse_number(B)
    
    # So sánh số đảo ngược
    if reversed_A > reversed_B:
        return A  # Trả về A nếu số đảo ngược của A lớn hơn
    else:
        return B  # Trả về B nếu số đảo ngược của B lớn hơn

# Đọc dữ liệu từ tệp
with open("BNGUOC.INP", "r") as infile:
    A, B = infile.read().strip().split()

# So sánh và lấy kết quả
result = compare_reversed_numbers(A, B)

# Ghi kết quả vào tệp
with open("BNGUOC.OUT", "w") as outfile:
    outfile.write(result + "\n")
