def total_harvest(K, a):
    total = 0
    for ai in a:
        if ai > K:
            total += (ai - K) 
    return total

def find_optimal_K(S, a):
    low, high = 0, max(a) 
    best_K = low 
    min_excess = float('inf')  

    for i in range(low, high+1):
        current_total = total_harvest(i, a)
        if current_total >= S:
            excess = current_total - S
            if excess < min_excess:
                min_excess = excess 
                best_K = i 
    return best_K

N, S = map(int, input().split())
a = list(map(int, input().split()))

result = find_optimal_K(S, a)
print(f"Optimal K: {result}")
