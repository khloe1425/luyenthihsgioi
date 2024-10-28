def process_queries(N, Q, A, queries):
    results = []
    for query in queries:
        if query[0] == 1:
            # Loại 1: Tăng giá trị phần tử
            p, m, x = query[1], query[2], query[3]
            for j in range(p - 1, m):  # Chuyển đổi sang chỉ số bắt đầu từ 0
                A[j] += x
        elif query[0] == 2:
            # Loại 2: Tính tổng
            u, v = query[1], query[2]
            total_sum = sum(A[u - 1:v])  # Tính tổng từ chỉ số u-1 đến v-1
            results.append(total_sum)
    return results

def main():
    with open("CAU3.INP", "r") as input_file:
        N, Q = map(int, input_file.readline().split())
        A = list(map(int, input_file.readline().split()))
        
        queries = []
        for _ in range(Q):
            data = list(map(int, input_file.readline().split()))
            queries.append(data)
    
    results = process_queries(N, Q, A, queries)

    with open("CAU3.OUT", "w") as output_file:
        for result in results:
            output_file.write(f"{result}\n")

if __name__ == "__main__":
    main()
