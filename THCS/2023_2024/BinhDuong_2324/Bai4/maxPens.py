def max_pens(N, M, pens):
    # Sắp xếp các loại bút theo giá
    pens.sort(key=lambda x: x[0])  # Sắp xếp theo giá

    total_pens = 0  # Tổng số bút đã mua

    for price, quantity in pens:
        if M <= 0:
            break  # Nếu không còn tiền, dừng lại

        # Tính số bút có thể mua từ loại này
        max_can_buy = min(quantity, M // price)

        # Cập nhật tổng số bút và số tiền còn lại
        total_pens += max_can_buy
        M -= max_can_buy * price

    return total_pens

N = int(input("Nhập số loại bút N: "))
M = int(input("Nhập số tiền M: "))

pens = []
for _ in range(N):
    ai, bi = map(int, input("Nhập giá và số lượng của từng loại bút: ").split())
    pens.append((ai, bi))

result = max_pens(N, M, pens)

print("Số lượng bút tối đa mà Nam có thể mua:", result)
