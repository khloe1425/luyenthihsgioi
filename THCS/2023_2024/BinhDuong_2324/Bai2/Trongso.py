def max_weight_after_move(N, A):
    C = sum((i + 1) * A[i] for i in range(N)) 
    max_C = C  

    for k in range(N):
        # Lưu giá trị hiện tại của A trước khi thay đổi
        current_A = A.copy()
        
        # Di chuyển ak đến đầu
        element = A.pop(k)
        A.insert(0, element)
        new_C_head = sum((i + 1) * A[i] for i in range(N))
        max_C = max(max_C, new_C_head)

        # Quay lại danh sách A
        A = current_A.copy()
        
        # Di chuyển ak đến cuối
        element = A.pop(k)
        A.append(element)
        new_C_tail = sum((i + 1) * A[i] for i in range(N))
        max_C = max(max_C, new_C_tail)

    return max_C

N = int(input("Nhập số nguyên N: "))
A = list(map(int, input("Nhập dãy số A: ").split()))

result = max_weight_after_move(N, A)

print(f"\nTrọng số lớn nhất có thể: {result}")
1