from typing import List, Optional
from src.skiplist import SkipList
import csv


class Table(object):
    '''A table that stores records and allows creation of an index on the
    records according to the values of a specified attribute. The index is used
    to efficiently retrieve records using key values. The index can be
    re-initialized in run-time using a different attribute.
    '''
    
    def __init__(self) -> None:
        '''Initialize this table with an empty index.

        The index is initialized with an empty skiplist.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        None
        '''
        self.index = SkipList()

    def read(self, csvfile: str) -> None:
        '''Read and store records from the given CSV file.

        Parameters:
        - self: mandatory reference to this object
        - csvfile: path to a csv file that contains the records

        Returns:
        None
        '''
        self.records = []
        with open(csvfile, 'r', encoding="utf8") as f:
            csvreader = csv.reader(f)
            for record in csvreader:
                self.records.append(record)
        self.attributes = self.records[0] #The first index contains the attributes, corresponding values contain records
        self.records = self.records[1:] # list of records excluding the attributes


    def create_index(self, attribute: str) -> None:
        '''Construct an index using values of the specified attribute.

        attribute must be one of the column headers from the CSV file from which
        the records were read. all values for attribute must be unique.

        Any existing index is lost and a new one is constructed. The constructed
        index is empty if no records are currently stored.

        The index stores (key, value) pairs where the keys are the values of
        attribute. The value is the location, e.g. index, of the corresponding
        record. Note that the value is not the record itself.

        Parameters:
        - self: mandatory reference to this object
        - attribute: the attribute whose values are to be the keys in the index

        Returns:
        None
        '''
        self.index = SkipList()
        for i in range(len(self.records)):
            key = self.records[i][self.attributes.index(attribute)]
            self.index.insert((key, i)) #Inserts the key, value pair in the skiplist

    def select(self, key: str) -> Optional[List[str]]:
        '''Return the record corresponding to the given key, None in case of
        error.

        The index is used to find the record. An error occurs if the index is
        not yet created or the key in invalid. This is indicated by a return of
        None.

        Parameters:
        - self: mandatory reference to this object
        - key: the key whose corresponding value is sought

        Returns:
        The record corresponding to key, None in case of error.
        '''
        #Returns none if the key does not exist, else finds the key and returns the corresponding record
        return None if self.index.find(key) == None else self.records[self.index.find(key)]

    def select_range(self, start: str, end: str) -> Optional[List[List[str]]]:
        '''Returns the records corresponding to the keys in the range
        [start,end] inclusive, None in case of error.

        An error occurs if no index has been created, start or end is not a valid
        key in the index, or start is not less than end.

        Parameters:
        - self: mandatory reference to this object
        - start: the starting key value in the range of keys
        - end: the ending key value in the range of keys

        Returns:
        The records in the order of the keys in the range [start,end], None in
        case of error.
        '''
        vals = self.index.find_range(start, end)
        for i in range(len(vals)):
            vals[i] = self.records[vals[i]]
        return vals

    def delete(self, key: str) -> Optional[List[str]]:
        '''Deletes the record corresponding to key from the table and the index.
        Returns the deleted record, None in case of error.

        An error occurs if no index has been created, or key does not exist in
        it.

        Parameters:
        - self: mandatory reference to this object
        - from: the starting key value in the range of keys
        - to: the ending key value in the range of keys

        Returns:
        The deleted record,  None in case of error.
        '''
        #Returns none if the key does not exist, else removes the key from records [skiplist over here as we are performing operations on a skiplist]
        return None if self.index.find(key) == None else self.index.remove(key)

        
        
