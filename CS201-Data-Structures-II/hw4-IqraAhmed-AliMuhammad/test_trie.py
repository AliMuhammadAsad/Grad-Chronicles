import pytest
import sys
import zipfile
sys.path.append("./src")
import csv

from corpus import *
from urllib.request import urlopen

path = 'https://munawwar-anwar.github.io/CS201/HW4/'
corpus_path = 'corpus.zip'
testcase_path = path+'trie-cases.csv'

class Case:
    def __init__(self, prefix: str, terms: int, instances: int):
        self.prefix, self.terms, self.instances = prefix, terms, instances
    def __str__(self):
        return str(self.prefix)+" "+self.terms+" "+str(self.instances)
    

def get_corpus(zipfilename):
    open(zipfilename, 'wb').write(urlopen(path + zipfilename).read())
    zipfile.ZipFile(zipfilename, 'r').extractall('corpus')
    return Corpus('corpus/')

def fetch_testcases(path: str) -> [Case]:
    testcases = []
    input_lines = [line.decode('utf-8').strip() for line in urlopen(path).readlines()]
    f = csv.reader(input_lines)
    for i,row in enumerate(f):
        if i == 0:
            continue
        else:
            testcases.append(Case(row[0], int(row[1]), int(row[2])))
    return testcases

corpus = get_corpus(corpus_path)
@pytest.mark.parametrize('case', fetch_testcases(testcase_path))
def test_trie(case):
    completions = corpus.prefix_complete(case.prefix)
    print(len(completions))
    assert len(completions) == case.terms, \
        f'bad number of completions for {case.prefix=}'
    instances = sum(map(len, completions.values()))
    assert instances == case.instances, \
        f'bad number of completion {instances=} for {case.prefix=}'
    corpuspath = Path('./corpus/')
    for completion, locations in completions.items():
        for location in locations:
            doc_id, start, end = location
            content = open(corpuspath / doc_id, encoding='ascii', errors='ignore').read()
            assert content[start:end] == completion, \
                f'bad {location=} for {completion=} of {case.prefix=}'
