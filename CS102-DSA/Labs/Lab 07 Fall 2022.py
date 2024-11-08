#Q1 Count Letters in a word/string etc
def count_letter(s):
    s = s.lower()
    dict_s = {}
    for i in s:
        if i in dict_s:
            dict_s[i] += 1
        else:
            dict_s[i] = 1
    return dict_s

stri = 'brontosaurus'

print(sorted(count_letter(stri).items()))

#--------------------------------------------------------------------------------------------------------------------------------
#Q2 Partition Modulo n, Gives a dictionary containing keys as modulo n values and value as list containing all the numbers in the list [passed as argument] that
# correspond to that value

def partition_modulo_n(n, t):
  dict = {}
  if n > 0:
    for i in range(n):
    dict[i] = []
  else:
    for i in range(n+1, 1):
      dict[i] = []
  for j in t:
    x = j % n; dict[x].append(j)
  return dict

#---------------------------------------------------------------------------------------------------------------------------------
#Q3 Sum of digits in an integer recursively
def sum_of_digits(n):
    if n == 0:
        return 0
    return n%10 + sum_of_digits(int(n / 10))
