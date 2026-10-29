def solve(n: int, a: int, t: list[int]):
    finish = [-1] * n
    finish[0] = t[0] + a
    for i in range(1, n):
        finish[i] = max(finish[i - 1], t[i]) + a
    return finish


def main():
    n, a = map(int, input().split())
    t = list(map(int, input().split()))
    ans = solve(n, a, t)
    print(*ans, sep='\n')


if __name__ == '__main__':
    main()