from pathlib import Path
from document import Document
from trie import Trie
from index import InvertedIndex
class Corpus:
    def __init__(self, path: str):
        docs = []
        trie = Trie()
        pathname_length = len(path)
        for p in Path(path).rglob('*'):
            if p.is_file():
                doc_id = str(p)[pathname_length:]
                doc = Document(p, doc_id)
                docs.append(doc)
                trie.add_document(doc)
        index = InvertedIndex(docs)
        self.docs = docs
        self.trie = trie
        self.index = index

    def __iter__(self):
        yield from self.docs

    def query(self, terms: str, k: int):
        return self.index.query(terms, k)
    
    
    def and_query(self, query1: str, query2:str, k: int):
        return self.index.and_query(query1, query2, k)
    
    def or_query(self, query1: str, query2:str, k: int):
        return self.index.or_query(query1, query2, k)


    def prefix_complete(self, prefix: str):
        return self.trie.prefix_complete(prefix)


    
