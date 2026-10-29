from itertools import chain, combinations

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def is_valid(m: int, s: list[str], selection: list[int]):
    # O(n * m) = 100
    all_selected = [False] * m
    for i in selection:
        for j, mark in enumerate(s[i]):
            if mark == 'o':
                all_selected[j] = True
    return all(all_selected)


def solve(n: int, m: int, s: list[str]):
    if m == 1:
        return 1
    # assume m > 1
    # O(2^n * n * m) = 2^10 * 10 * 10 = 10000
    for selection in powerset(list(range(n))):
        # O(2^n) = 2^10 = 1000
        if len(selection) == 0:
            continue
        if is_valid(m, s, selection):
            return len(selection)
    raise ValueError("No valid selection found") 




def main():
    n, m = map(int, input().split())
    s: list[str] = [input() for _ in range(n)]
    ans = solve(n, m, s)
    print(ans)

if __name__ == "__main__": 
    main()