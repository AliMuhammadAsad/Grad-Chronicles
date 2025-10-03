import pytest
import random
import sys
sys.path.append("./src")

from db import Table
from data import Data


datafile = "https://waqarsaleem.github.io/cs201/hw2/books.csv"

data = Data(datafile)
table = Table()
table.read('data/books.csv')

@pytest.mark.parametrize('i', range(20))
def test_blank_index(i):
    record = data.get_random_record()
    idx = data.get_random_header_index()
    key = record[idx]
    assert table.select(key) == None, \
        f'FAIL: Select {key=} is non-None without index'

@pytest.mark.parametrize('i', range(100))
def test_select_range(i):
    idx = data.get_random_header_index()
    attribute = data.get_header(idx)
    table.create_index(attribute)
    data.sort(idx)
    start_idx = random.randint(0, data.size())
    end_idx = random.randint(0, data.size())
    if start_idx > end_idx:
        start_idx, end_idx = end_idx, start_idx
    start_key = data[start_idx][idx]
    end_key = data[end_idx][idx]
    result = table.select_range(start_key, end_key)
    result.sort(key=lambda x: x[idx])
    assert result == data[start_idx:end_idx+1], \
        f'{i+1}. FAIL: Mismatch {attribute=}, {start_key=}, {end_key=}'

@pytest.mark.parametrize('i', range(100))
def test_select(i):
    record = data.get_random_record()
    idx = data.get_random_header_index()
    attribute = data.get_header(idx)
    table.create_index(attribute)
    key = record[idx]
    result = table.select(key)
    assert result == record, \
        f'{i+1}. FAIL: {attribute=}, {key=}.\nQuery {result=}\n{record=}'
