from urllib.request import urlopen

import csv
import random

class Data:
    def __init__(self, datafile):
        if datafile.startswith('http'):
            input_lines = [line.decode('utf-8').strip()
                           for line in urlopen(datafile).readlines()]
        else:
            input_lines = open(datafile).readlines()
        self.header = None
        self.data = []
        reader = csv.reader(input_lines)
        for i,row in enumerate(reader):
            if i == 0:
                self.header = row
                continue
            self.data.append(row)
        self.indexes = [0, 1, 3, 4]

    def __getitem__(self, idx):
        return self.data[idx]
    
    def get_header(self, idx):
        return self.header[idx]
    
    def get_random_header_index(self):
        return random.choice(self.indexes)
    
    def get_random_record(self):
        return random.choice(self.data)
    
    def size(self):
        return len(self.data)
    
    def sort(self, i):
        self.data.sort(key=lambda x: x[i])

