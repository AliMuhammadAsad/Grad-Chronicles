import math
from document import Document
from typing import List, Tuple

class InvertedIndex:
    ''' Creates an Inverted Index '''

    def __init__(self, docs: List[Document]) -> None:
        ''' Initializes the index
        Args:
        - self: mandatory reference to this object
        - docs: list of docs
        Returns: None 
        '''
        # Initialize the inverted index and the document length dictionaries
        self.index = {}
        self.doc_length = {}

        for doc in docs: # Looping through each document
            doc_id = doc.doc_id # id of each document
            self.doc_length[doc_id] = 0 # setting the length of document to 0 initially
            for term in doc: # Looping through each term in the document
                #Add the term to the index if not already present
                if term not in self.index: 
                    self.index[term] = {}
                # Add the document id to the term's posting list if not already present
                if doc_id not in self.index[term]:
                    self.index[term][doc_id] = 0
                #Update the term frequency and the document length
                self.index[term][doc_id] += len(doc[term])
                self.doc_length[doc_id] += len(doc[term])

    def query(self, terms: str, k: int) -> List[Tuple[int, str]]:
        ''' Accepts a string and an int argument representing the query term and the number of desired results. 
        Args:
        - self: mandatory reference to this object
        - terms: string
        - k: int representing the number of desired results

        Returns: list(tuple(int, str)) sorted list of 2-tuples representing the ranked list of documents, that is each pair contains the rank and corresponding document ID. 
        '''
        # Initialize the scores dictionary and splits the query terms
        scores = {}
        query_terms = terms.split()

        # Calculate the document scores based on the term frequency 'tf' and the inverse document frequencies 'idf'
        for term in query_terms:
            if term in self.index:
                for doc_id, term_freq in self.index[term].items():
                    if doc_id not in scores:
                        scores[doc_id] = 0
                    idf = math.log(len(self.doc_length) / len(self.index[term]))
                    tf = term_freq / self.doc_length[doc_id]
                    scores[doc_id] += tf * idf

        # Sort the document scores and create a ranked list
        sorted_scores = []
        for doc_id, score in scores.items():
            insert_index = len(sorted_scores)
            for i in range(len(sorted_scores)):
                if score > sorted_scores[i][1]:
                    insert_index = i
                    break
            sorted_scores.insert(insert_index, (doc_id, score))
        
        # Create a ranked list of document ids based on their scores
        ranked_results = []
        for rank in range(len(sorted_scores[:k])):
            doc_id = sorted_scores[rank][0]
            ranked_results.append((rank, doc_id))

        return ranked_results

    def and_query(self, query1: str, query2: str, k: int):
        ''' Accepts two strings and an int argument and returns the intersection of the ranked list of documents for query 1 and query 2.
        Args:
        - self: mandatory reference to this object
        - query1: first query
        - query2: second query
        - k: int representing the number of desired results

        Returns: list(tuple(int, str)) intersection of the ranked list of documents for query 1 and query 2
        '''
        # Get the ranked list of results of documents for both the queries
        results_query1 = self.query(query1, k)
        results_query2 = self.query(query2, k)

        # Find the intersection of the ranked list of results
        intersection = []
        for rank1, doc_id1 in results_query1:
            for rank2, doc_id2 in results_query2:
                if doc_id1 == doc_id2:
                    intersection.append((rank1, doc_id1))
                    break
        
        # Sort the intersection based on IDs. Merging over here is done through merge_sort for fancy schmancy plus cos merge_sort has lesser time complexity and is stable than bubble although bubble is simpler to write
        self.merge_sort(intersection)

        return intersection

    def or_query(self, query1: str, query2: str, k: int):
        ''' Accepts two strings and an int argument and returns the union of the ranked list of documents for query1 and query2
        Args:
        - self: mandatory reference to this object
        - query1: first query
        - query2: second query
        - k: int representing the number of desired results

        Returns: list(tuple(int, str)) union of the ranked list of documents for query 1 and query 2
        '''
        # Get the ranked list of result of documents for both the queries
        results_query1 = self.query(query1, k)
        results_query2 = self.query(query2, k)

        # Combine the results and create a dictionary to store the union of their results
        combined_results = results_query1 + results_query2
        union_dict = {}
        for rank, id in combined_results:
            if id not in union_dict:
                union_dict[id] = rank
        
        # Create a list of the union dictionary items
        union = list(union_dict.items())

        # The above dictionary was created with ids as keys as it would be easier to check, so format the list with the required format (rank, id)
        for i in range(len(union)):
            union[i] = (union[i][1], union[i][0])
        
        # Sort the union based on their ids
        self.merge_sort(union)

        return union
    
    def merge_sort(self, lst):
        if len(lst) > 1:
            mid = len(lst) // 2 #mid of the list
            left, right = lst[:mid], lst[mid:] #dividing the list into two halves
            self.merge_sort(right), self.merge_sort(left) #sorting the two halves
            i = j = k = 0
            while i < len(left) and j < len(right):
                if left[i][1] < right[j][1]:
                    lst[k] = left[i]
                    i += 1
                else:
                    lst[k] = right[j]
                    j += 1
                k += 1
            while i < len(left):
                lst[k] = left[i]
                i += 1
                k += 1
            while j < len(right):
                lst[k] = right[j]
                j += 1
                k += 1
        return lst