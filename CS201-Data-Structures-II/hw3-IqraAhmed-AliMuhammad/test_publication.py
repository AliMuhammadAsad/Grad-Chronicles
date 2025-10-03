import pytest
import random
from publication import Publication

P = Publication()
P.read('data/publications.csv')
P.create_tree()
@pytest.mark.parametrize('i', range(1000))
def test_keyword(i):
    key = random.choice(list(P.keywords))
    result = P.search(key)
    record = P.keywords[key]
    assert result == record, \
        f'{i+1}. FAIL:  {key=}.\nQuery {result=}\n{record=}'

