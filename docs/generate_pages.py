from utils.parser import get_parsed_folder
from datetime import datetime
from pathlib2 import Path
from string import Template
import subprocess
import pprint

pp = pprint.PrettyPrinter(indent=4)

TO_PARSE = ['../codeforces', '../atcoder', '../cses', '../uva']
# TO_PARSE = ['../codeforces/102694E-filthy-rich-trees.cpp']

TEMPLATE = Template("""---
layout: post
mathjax: true
title: $title
url: $url
tags: $tags
time_complexity: $time_complexity
memory_complexity: $memory_complexity
---

{% raw %}
$idea
{% endraw %}

```cpp
{% raw %}
$source_code
{% endraw %}
```
""")

ATTR_FIELDS = [
    'title', 'url', 'tags', 'time_complexity', 'memory_complexity', 'idea'
]


def main():
    files_dict = get_parsed_folder(TO_PARSE)
    for file_dict in files_dict:
        attributes = file_dict['attributes']
        source_file = Path(file_dict['source_file'])
        creation_date = datetime.fromtimestamp(source_file.stat().st_ctime)

        new_filename = f'{creation_date.strftime("%Y-%m-%d")}-{source_file.stem}.md'
        with open(f'_posts/{new_filename}', 'w') as f:
            text = TEMPLATE
            payload = {
                attr: attributes.get(attr, None)
                for attr in ATTR_FIELDS
            }
            if payload['title'] is None:
                alt_title = (' '.join(source_file.stem.split('-'))).title()
                payload['title'] = alt_title

            print(source_file)
            output = subprocess.run(
                ['g++', '-E', '-P', '-nostdinc', source_file],
                capture_output=True)

            payload['source_code'] = output.stdout.decode('utf-8')

            s = text.substitute(**payload)
            f.write(s)


if __name__ == '__main__':
    main()
