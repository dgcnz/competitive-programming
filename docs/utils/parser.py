from pathlib2 import Path
from typing import List
import xml.etree.ElementTree as ET
import pprint
import subprocess
import os
from tqdm import tqdm

pp = pprint.PrettyPrinter(indent=4)

XML_FOLDER = Path('./xml/')
"""
<simplesect kind="par">
<title>Idea</title>

<para>
[Maybe this is flawed, but it got AC. Nevertheless, here&apos;s my reasoning.]
<itemizedlist>
    <listitem>
        <para>Let&apos;s define:
            <orderedlist>
                <listitem><para>Even state: 2 piles have an even amount of rocks.</para></listitem>
                <listitem><para>Odd state: not even state.</para></listitem>
            </orderedlist>
        </para>
    </listitem>
    <listitem><para>If a player is on an even state, the second player can always force him to be on even states.</para></listitem>
    <listitem><para>So, since the end state has trivially an even state, then whoever starts on an uneven state can force the second player to lose by keeping him on even states. </para></listitem>
</itemizedlist>
</para>

</simplesect>
"""


def walk(node, indent=0):
    '''
    - ``para``
    - ``orderedlist``
    - ``itemizedlist``
    - ``verbatim`` (specifically: ``embed:rst:leading-asterisk``)
    - ``formula``
    - ``ref``
    - ``emphasis`` (e.g., using `em`_)
    - ``computeroutput`` (e.g., using `c`_)
    - ``bold`` (e.g., using `b`_)
    '''
    ans = ''
    for child in node:
        if child.tag == 'itemizedList':
            itemizedList = child
            for listitem in itemizedList.findall('listitem'):
                ans += ' - '
                ans += walk(listitem, level + 1)
                ans += '\n'
        if child.tag == 'para':
            para = child
            ans += walk(para, level + 1)


def run_doxygen(input, verbose=False):
    with tqdm(total=100, desc='Doxygen') as pbar:
        s = subprocess.run(['doxygen', 'Doxyfile'],
                           env=dict(os.environ, INPUT_PATHS=input),
                           stdout=subprocess.PIPE)
        if verbose:
            pbar.write(s.stdout.decode('utf-8'))
        pbar.update(100)


def get_files():
    index_files = XML_FOLDER.glob('dir*xml')

    payload = []
    for index in index_files:
        tree = ET.parse(index)
        root = tree.getroot()

        compounddef = root.find('compounddef')
        compoundname = compounddef.find('compoundname')

        dir = Path(compoundname.text)
        for innerfile in compounddef.findall('innerfile'):
            source_file = innerfile.text
            parsed_file = innerfile.attrib['refid'] + '.xml'
            payload.append({
                'dir': dir,
                'source_file': dir / source_file,
                'parsed_file': XML_FOLDER.absolute() / parsed_file
            })
    return payload


def get_attributes(parsed_file):
    payload = {}

    root = ET.parse(parsed_file)
    compounddef = root.find('compounddef')
    detaileddescription = compounddef.find('detaileddescription')
    para = detaileddescription.find('para')
    if para is not None:
        for simplesect in para.iter('simplesect'):
            title = simplesect.find('title').text.strip()
            title = '_'.join(title.lower().split())
            content = simplesect.find('para')
            if title == 'idea':
                md = walk(content, 0)
                parameter = md
            else:
                parameter = content.text
            #  parameter = ET.tostring(content, encoding='utf-8',
            #                        method='text').strip().decode('utf-8')
            payload[title] = parameter
    return payload


def get_parsed_folder(input_paths: List[Path]):
    run_doxygen(input=' '.join([str(path) for path in input_paths]),
                verbose=False)
    files = get_files()
    pbar = tqdm(files)
    for file in pbar:
        pbar.set_description(f'Parsing {Path(file["source_file"]).name}.')
        file['attributes'] = get_attributes(file['parsed_file'])
    return files


if __name__ == '__main__':
    name = '1327E-count-the-blocks.cpp'
    p = Path(f'../codeforces/{name}')
    files = get_parsed_folder([p.absolute()])
    print(files)
