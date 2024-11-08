from urllib.request import urlopen
from PIL import Image
from src.myimage import MyImage
from src.image_operations import *

import sys
sys.path.append("./src")


casefile = "https://munawwar-anwar.github.io/CS201/tests.csv"
OUTPUT_IMAGE = 'tmp-output.png'
OUTPUT_MASK = 'tmp-mask.txt'


class Case:
    def __init__(self):
        self.source = ''
        self.suppressed = ''
        self.rotated = ''
        self.masked = ''
        self.resize = ''
        self.suppress = []
        self.maskfiles = []
        self.maskaverages = []

    def __repr__(self):
        return f'src: {self.source}, rot: {self.rotated}\n'\
            f'sup: {self.suppress}, sup: {self.suppressed}\n'\
            f'masks: {self.maskfiles}, avg: {self.maskaverages}, masked: {self.masked}\n'\
            f'resize: {self.resize}\n'


def fetch_testcases(path):
    testcases = []
    csv_lines = [line.decode('utf-8').strip()
                 for line in urlopen(path).readlines()[1:]]
    for row in csv_lines:
        if not row:
            continue
        row = row.split(',')
        case = Case()
        case.source = row[0]
        print(len(row))
        if len(row) > 1:
            case.rotated = row[1]
        if len(row) > 5:
            case.suppressed = row[5]
            case.suppress = [f == '1' for f in row[2:5]]
        if len(row) > 8:
            case.masked = row[8]
            case.maskfiles = row[6].split('::')
            case.maskaverages = [a == '1' for a in row[7].split(':')]
        if len(row) > 9:
            case.resize = row[9]

        testcases.append(case)
    return testcases

cases = fetch_testcases(casefile)

def test_array_resize():
    for case in cases:
        if not case.resize:
            continue
        source = urlopen(case.source)
        resize(MyImage.open(source)).save(OUTPUT_IMAGE)
        resized = urlopen(case.resize)
        assert Image.open(OUTPUT_IMAGE) == Image.open(resized),\
            f'rotation of {case.source} does not match reference'\
            f'{case.resize}'

def test_array_suppression():
    for case in cases:
        if not case.suppressed:
            continue
        sp = case.suppress
        source = urlopen(case.source)
        remove_channel(MyImage.open(source),
                       red=sp[0], green=sp[1], blue=sp[2]).save(OUTPUT_IMAGE)
        suppressed = urlopen(case.suppressed)
        assert Image.open(OUTPUT_IMAGE) == Image.open(suppressed),\
            f'suppression of {case.source} does not match reference'\
            f'{case.suppressed} under channels {case.suppress}'


def test_array_rotation():
    for case in cases:
        if not case.rotated:
            continue
        source = urlopen(case.source)
        rotations(MyImage.open(source)).save(OUTPUT_IMAGE)
        rotated = urlopen(case.rotated)
        assert Image.open(OUTPUT_IMAGE) == Image.open(rotated),\
            f'rotation of {case.source} does not match reference'\
            f'{case.rotated}'


def test_array_mask():
    for case in cases:
        if not case.masked:
            continue
        avgs = case.maskaverages
        # masks = [urlopen(path) for path in case.maskfiles]
        open(OUTPUT_MASK, 'w').write(
            urlopen(case.maskfiles[0]).read().decode('utf-8'))
        source = urlopen(case.source)
        dst = apply_mask(MyImage.open(source),
                         OUTPUT_MASK, average=case.maskaverages[0])
        for mask, avg in zip(case.maskfiles[1:], case.maskaverages[1:]):
            open(OUTPUT_MASK, 'w').write(urlopen(mask).read().decode('utf-8'))
            dst = apply_mask(dst, OUTPUT_MASK, average=avg)
        dst.save(OUTPUT_IMAGE)
        masked = urlopen(case.masked)
        assert Image.open(OUTPUT_IMAGE) == Image.open(masked),\
            f'masking of {case.source} does not match reference '\
            f'{case.masked}\nunder masks {case.maskfiles} '\
            f'and averages {case.maskaverages}'


### DUMP ###
        # im = Image.open(OUTPUT_IMAGE)
        # pixellist = list(im.getdata())
        # im2 = Image.open(resized)
        # pixellist2 = list(im2.getdata())
        # im.show()
        # im2.show()
        # compare(pixellist, pixellist2)
# def compare(pixellist, pixellist2):
#     for i in range(len(pixellist2)):
#         if pixellist[i] != pixellist2[i]:
#             print(f"pixel1 : {pixellist[i]} and pixel2 : {pixellist2[i]} at iteration: {i}")