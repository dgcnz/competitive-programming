def solve(n: int, m: int, a: list[int], b: list[int]):
    a.sort()
    b.sort()
    i = 0
    total = 0
    for j in range(m):
        while i < n and a[i] < b[j]:
            i += 1
        if i == n:
            return -1
        total += a[i]
        i += 1
    return total

def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = solve(n, m, a, b)
    print(ans)

if __name__ == "__main__":
    main()