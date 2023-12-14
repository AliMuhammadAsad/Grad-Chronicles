import nltk
nltk.download('punkt')
nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.stem import PorterStemmer
from src.avl_tree import *
import string
import csv


class Publication:
    def __init__(self) -> None:
        self.data = []
        self.tree = None
        self.header  = None
        self.keywords = {}
        self.stop_words = set(stopwords.words('english'))
        self.stemmer = PorterStemmer()
        self.translator = str.maketrans('', '', string.punctuation)
    def read(self,file: str) -> None:
        input_lines = open(file,encoding="utf-8").readlines()
        reader = csv.reader(input_lines)
        for i,row in enumerate(reader):
            if i == 0:
                self.header = row
                continue
            self.data.append(row)
    def _get_all_keywords(self,index):
        keywords = {}
        sentences = sent_tokenize(self.data[index][1])
        for i, sentence in enumerate(sentences):
            words = word_tokenize(sentence)
            filtered_words = [word.lower().translate(self.translator) for word in words if word.lower() not in self.stop_words and word.isalnum()]
            stemmed_words = [self.stemmer.stem(word) for word in filtered_words]
            for word in stemmed_words:
                if word in keywords:
                    keywords[word].append((index,i))
                else:
                    keywords[word] = [(index,i)]
        return keywords

    def create_tree(self) -> None:
        self.tree = AVLTree()
        for i in range(len(self.data)):
            doc_key = self._get_all_keywords(i)
            for key,value in doc_key.items():
                if key in self.keywords:
                    self.keywords[key].extend(value)
                else:
                    self.keywords[key] = value

                self.tree.insert(key,value)
    def search(self,key):
        return self.tree.search(key)
                

    


