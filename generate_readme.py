#!/usr/bin/env python3
import os

README_TEMPLATE = '.readme_template.md'
README = 'README.md'

var_folder = {
    'codeforces_count': 'codeforces',
    'atcoder_count': 'atcoder',
    'cses_count': 'cses',
    'spoj_count': 'spoj',
    'uva_count': 'uva'
}


def get_count(folder: str):
    return len([
        name for name in os.listdir(folder)
        if os.path.isfile(f'{folder}/{name}')
    ])


def main():
    md = ''
    with open(README_TEMPLATE) as f:
        md = f.read()
        for var, folder in var_folder.items():
            cnt = get_count(folder)
            print(var, cnt)
            md = md.replace(var, str(cnt))

        print(md)

    with open(README, 'wt') as f:
        f.write(md)


if __name__ == '__main__':
    main()
