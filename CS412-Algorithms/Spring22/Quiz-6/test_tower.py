from urllib.request import urlopen

import pytest

from tower import solve

casefile = 'https://waqarsaleem.github.io/cs412/quiz06/cases.txt'


class Case:
    def __init__(self, X: int, num_blocks: int, max_volume: int):
        self.X, self.num_blocks, self.max_volume = X, num_blocks, max_volume

    def __repr__(self):
        return str((self.X, self.num_blocks, self.max_volume))

    def __str__(self):
        return self.__repr__()

def fetch_testcases(path: str) -> [Case]:
    # Read content from path.
    if path.startswith("http"):
        lines = [line.decode('utf-8').strip()
                 for line in urlopen(path).readlines()]
    else:
        lines = [line.strip() for line in open(path).readlines()]
    # Parse for test cases and store.
    cases = []
    itr = iter(lines)
    n = int(next(itr).strip())
    for _ in range(n):
        X = int(next(itr).strip())
        num_blocks, max_volume = map(int, next(itr).strip().split())
        cases.append(Case(X, num_blocks, max_volume))
    return cases

@pytest.mark.parametrize('case', fetch_testcases(casefile))
def test_index(case):
    answer = solve(case.X)
    assert list(answer) == [case.num_blocks, case.max_volume], \
        f'For {case.X=}, wrong {answer=}'
