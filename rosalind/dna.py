from collections import Counter

def main():
    seq: str = input()
    cnt: Counter = Counter()

    for c in seq:
        cnt[c] += 1

    for c in ['A', 'C', 'G', 'T']:
        print(cnt[c])
    
if __name__== "__main__":
    main()
