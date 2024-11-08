import pytest
import sys
from urllib.request import urlopen
import requests
sys.path.append("./src")
from listadt import load
INPUT_FILE  = "tmp-input.txt"
OUTPUT_FILE = "tmp-output.txt"
TEST_FILE  = "tmp-test.txt"
casefile = "https://munawwar-anwar.github.io/CS201/HW2/tests.csv"

class Case:
    def __init__(self):
        self.linkedlist = []
        self.array = []

    def __repr__(self):
        return f'linked: {self.linkedlist}, array: {self.array} \n'


def fetch_testcases(path):
    testcases = []
    csv_lines = [line.decode('utf-8').strip()
                 for line in urlopen(path).readlines()[1:]]
    for row in csv_lines:
        if not row:
            continue
        print(row)
        row = row.split(',')
        case = Case()
        case.source = row[0]

        if case.source == 'linkedlist':
            case.linkedlist.append((row[1],row[2]))
        elif case.source == 'array':
            case.array.append((row[1],row[2]))

        testcases.append(case)
    return testcases

cases = fetch_testcases(casefile)



def test_dynamic_array():
    for case in cases:
        if not case.linkedlist:
            continue
        for input, output in case.linkedlist:
            url_res = requests.get(url= input)
            with open(INPUT_FILE, "wb") as file:
                    file.write(url_res.content)
            url_res = requests.get(url= output)
            with open(TEST_FILE, "wb") as file:
                    file.write(url_res.content)
            load(INPUT_FILE,OUTPUT_FILE)
            original = open(TEST_FILE)
            test = open(OUTPUT_FILE)
            assert original.read().strip() == test.read().strip()


def test_linkedlist():
    for case in cases:
        if not case.array:
            continue
        for input, output in case.array:
            url_res = requests.get(url= input)
            with open(INPUT_FILE, "wb") as file:
                    file.write(url_res.content)
            url_res = requests.get(url= output)
            with open(TEST_FILE, "wb") as file:
                    file.write(url_res.content)
            load(INPUT_FILE,OUTPUT_FILE)
            original = open(TEST_FILE)
            test = open(OUTPUT_FILE)
            assert original.read().strip() == test.read().strip()