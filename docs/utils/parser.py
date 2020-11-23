from pathlib2 import Path
from typing import List
import xml.etree.ElementTree as ET
import pprint
import subprocess
import os
from tqdm import tqdm

pp = pprint.PrettyPrinter(indent=4)

XML_FOLDER = Path('./xml/')


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
                raw = content.find('verbatim').text
                clean = '\n'.join([line[2:] for line in raw.splitlines()])
                parameter = clean
            else:
                parameter = ET.tostring(content, encoding='utf-8', method='text').strip().decode('utf-8')
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
    # name = '1327E-count-the-blocks.cpp'
    # print(ET.tostring(ET.fromstring(example), pretty_print=True).decode())
    p = Path('utils/test.cpp')
    files = get_parsed_folder([p.absolute()])
    print(files)
