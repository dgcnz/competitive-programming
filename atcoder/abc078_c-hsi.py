def solve(n: int, m: int) -> int:
    return (1900 * m + (n - m) * 100) * 2 ** m


def main():
    n, m = (int(x) for x in input().split(" "))
    print(solve(n, m))

if __name__ == "__main__":
    main()