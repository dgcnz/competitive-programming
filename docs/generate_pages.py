from utils.parser import get_parsed_folder
from datetime import datetime
from pathlib2 import Path
from string import Template
import subprocess
import pprint

pp = pprint.PrettyPrinter(indent=4)

TO_PARSE = ['../codeforces', '../atcoder', '../cses', '../uva', '../spoj']
# TO_PARSE = ['../codeforces/102694E-filthy-rich-trees.cpp']

TEMPLATE = Template("""---
layout: post
mathjax: true
title: $title
problem_url: $problem_url
tags: $tags
memory_complexity: $memory_complexity
time_complexity: $time_complexity
---

$idea

{% if page.time_complexity != "None" %}
Time complexity: $${{ page.time_complexity }}$$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: $${{ page.memory_complexity }}$$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
$source_code
{% endraw %}
```
</details>

""")

ATTR_FIELDS = [
    'title', 'url', 'tags', 'time_complexity', 'memory_complexity', 'idea'
]


def main():
    files_dict = get_parsed_folder(TO_PARSE)
    for file_dict in files_dict:
        attributes = file_dict['attributes']
        source_file = Path(file_dict['source_file'])

        creation_date = attributes[
            'date'] if 'date' in attributes else datetime.fromtimestamp(
                source_file.stat().st_ctime).strftime("%Y-%m-%d")

        new_filename = f'{creation_date}-{source_file.stem}.md'
        with open(f'_posts/{new_filename}', 'w') as f:
            text = TEMPLATE
            payload = {
                attr: attributes.get(attr, None)
                for attr in ATTR_FIELDS
            }

            if payload['title'] is None:
                temp = source_file.stem.split('-')
                code = temp[0]
                alt_title = temp[1:]
                payload['title'] = code + ' - ' + (' '.join(alt_title)).title()

            if 'url' in payload:
                payload['problem_url'] = payload['url']
                del payload['url']

            if payload['idea'] is None:
                payload['idea'] = ''

            print(source_file)
            output = subprocess.run(
                ['g++', '-E', '-P', '-nostdinc', source_file],
                capture_output=True)

            payload['source_code'] = output.stdout.decode('utf-8')

            s = text.substitute(**payload)
            f.write(s)


if __name__ == '__main__':
    main()
