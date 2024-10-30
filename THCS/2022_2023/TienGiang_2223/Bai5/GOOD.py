def read_input(file_path):
    with open(file_path, 'r') as infile:
        n, m = map(int, infile.readline().strip().split())
        weights = list(map(int, infile.readline().strip().split()))
    return n, m, weights

def select_goods(n, m, weights):
    # Sắp xếp trọng lượng kiện hàng theo thứ tự giảm dần
    sorted_weights = sorted(weights, reverse=True)
    selected_goods = []
    current_load = 0

    # Chọn các kiện hàng thỏa mãn điều kiện
    for weight in sorted_weights:
        if current_load + weight <= m:
            selected_goods.append(weight)
            current_load += weight

    return selected_goods

def write_output(file_path, selected_goods):
    with open(file_path, 'w') as outfile:
        outfile.write(' '.join(map(str, selected_goods)) + '\n')

def main():
    input_file = "GOOD.INP"
    output_file = "GOOD.OUT"

    n, m, weights = read_input(input_file)
    selected_goods = select_goods(n, m, weights)
    write_output(output_file, selected_goods)

if __name__ == "__main__":
    main()
