n, k = [int(x) for x in input().split()]
x = str(input())


def repeat_to_length(s, wanted):
    return (s * (wanted // len(s) + 1))[:wanted]


upper = x[:k]
y = upper + repeat_to_length(str(upper), n - k)

if y >= x:
    print(len(y), y, sep='\n')
else:
    upper = str(int(upper) + 1)
    y = upper + (repeat_to_length(str(upper), n - k))
    print(len(y), y, sep='\n')
