import pytest
import random

def select(A: [int], k: int) -> int:
    '''
    Returns the k-th largest element in A using divide and conquer.

    Parameters:
    - A: the sequence of numbers, with possible duplicates.
    - k: return the k-th largest element

    Constraints:
    - 1 <= k <= len(A)

    Return:
    the k-th largest element in A.
    '''
    pass


def select_sort(A: [int], k: int) -> int:
    '''
    Returns the k-th largest element in A using sorting.

    Parameters:
    - A: the sequence of numbers, with possible duplicates.
    - k: return the k-th largest element

    Constraints:
    - 1 <= k <= len(A)

    Return:
    the k-th largest element in A.
    '''
    pass

@pytest.mark.parametrize("_", range(100))
def test_select(_):
    A = [random.randrange(10**3) for _ in range(random.randint(100, 10**5))]
    random.shuffle(A)
    k = random.randrange(1, len(A) + 1)
    assert sorted(A, reverse=True)[k-1] == select(A, k)
