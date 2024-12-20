import itertools
import pytest

from maxflow import *

class Case:
    def __init__(self, graph, val, flow):
        self.graph, self.val, self.flow = graph, val, flow

    def __repr__(self) -> str:
        return f'{self.graph=}\n{self.val=}\n{self.flow=}'

def fetch_testcases(path: str):
    testcases = []
    input_lines = open(path).readlines()
    line = iter(input_lines)
    case_count = int(next(line).strip())
    for _ in range(case_count):
        e = int(next(line).strip())
        graph = list(itertools.islice(line, e))
        maxflow, e = list(map(int, next(line).strip().split()))
        flow = dict()
        for _ in range(e):
            u, v, f = list(next(line).strip().split())
            flow[(u,v)] = int(f)
        testcases.append(Case(graph, maxflow, flow))
    return testcases

@pytest.mark.parametrize('case', fetch_testcases('cases.txt'))
def test_maxflow(case):
    maxflow = MaxFlow(case.graph)
    assert case.val == maxflow.get_value(), \
        f'bad max flow value for graph:\n{case.graph}'
    assert case.flow == maxflow.get_flow(), \
        f'bad max flow for graph:\n{case.graph}'