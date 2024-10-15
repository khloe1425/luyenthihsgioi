input_path = './2024/Hue/Bai2/GME.INP'
output_path = './2024/Hue/Bai2/GME.OUT'

with open(input_path, 'r') as file:
    n = int(file.readline().strip())
    menhGia = list(map(int, file.readline().strip().split()))

menhGia.sort()

with open(output_path, 'w') as file:
    file.write(f"- Tien sau khi sap xep: {' '.join(map(str, menhGia))}\n")
    file.write(f"- Menh gia thap nhat: {menhGia[0]} (dong); Menh gia cao nhat: {menhGia[-1]} (dong)\n")
    file.write(f"- Tong so tien thu duoc: {sum(menhGia)} (dong)\n")
