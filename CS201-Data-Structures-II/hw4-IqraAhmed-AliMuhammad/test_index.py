import pytest
import sys
import csv
import zipfile
sys.path.append("./src")

from corpus import *
from urllib.request import urlopen

path = 'https://munawwar-anwar.github.io/CS201/HW4/'
corpus_path = 'corpus.zip'
testcase_path = path+'index-cases.csv'
testcase1_path = path+'index-cases-1.csv'
testcase2_path = path+'index-cases-2.csv'

class Case:
    def __init__(self, *args):
        if len(args) == 3:
            self.query, self.k, self.result = args
        else:
            self.query1, self.query2, self.k,self.result = args

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
            if 'index-cases-1.csv' in path or 'index-cases-2.csv' in path:
                testcases.append(Case(row[0], row[1], int(row[2]),row[3]))
            else:
                testcases.append(Case(row[0],int(row[1]), row[2]))
    return testcases
    
corpus = get_corpus(corpus_path)

@pytest.mark.parametrize('case', fetch_testcases(testcase_path))
def test_index(case):
    result = corpus.query(case.query, case.k)
    result = [doc for _,doc in result]
    print(case.result)
    assert result == case.result.split(), \
        f'bad {result=} for {case.query=}, {case.k=}'
    
@pytest.mark.parametrize('case', fetch_testcases(testcase1_path))
def test_and_index(case):
    result = corpus.and_query(case.query1,case.query2,case.k)
    result = [doc for _,doc in result]
    print(case.result)
    assert result == case.result.split(), \
        f'bad {result=} for {case.query1=}, for {case.query2=}, {case.k=}'
@pytest.mark.parametrize('case', fetch_testcases(testcase2_path))
def test_or_index(case):
    result = corpus.or_query(case.query1,case.query2,case.k)
    result = [doc for _,doc in result]
    print(case.result)
    assert result == case.result.split(), \
        f'bad {result=} for {case.query1=}, for {case.query2=}, {case.k=}'