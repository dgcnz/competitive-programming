from random import randint
from itertools import permutations
from tqdm import tqdm
import subprocess

TESTS = 100

NMIN = 2
NMAX = 3

diego_exe = "./appointment.out"
chahua_exe = "./awa.out"

for _ in tqdm(range(TESTS)):
    _input = "1\n"

    n: int = randint(NMIN, NMAX)
    _input += str(n) + "\n"

    rang = []
    for i in range(n):
        l: int = randint(1, n)
        r: int = randint(l, n)
        rang.append((l, r))
        _input += str(l) + " " + str(r) + "\n"

    msg = _input.encode()
    diego_ans = subprocess.run([diego_exe], input=msg,
                               capture_output=True).stdout.decode()
    chahua_ans = subprocess.run([chahua_exe], input=msg,
                                capture_output=True).stdout.decode()

    answers = []
    # print(rang)
    for p in permutations(range(n)):
        flag = True
        # print(p)
        for ix, pi in enumerate(list(p)):
            l, r = rang[pi]
            ix += 1
            if not (l <= ix and ix <= r):
                flag = False
                break

        if flag:
            ans = " ".join(list([str(pi + 1) for pi in p])) + " \n"
            answers.append(ans)

    if len(answers) == 0:
        answers.append("impossible\n")

    if diego_ans not in answers:
        print("BAD")
        print(_input)
        print(repr(diego_ans))
        print(answers)
        break

    # if diego_ans != chahua_ans and (diego_ans == "impossible\n"
    #                                 or chahua_ans == "impossible\n"):
    #     print("BAD")
    #     print(_input)
    #     print(diego_ans)
    #     print(chahua_ans)
    #     break
