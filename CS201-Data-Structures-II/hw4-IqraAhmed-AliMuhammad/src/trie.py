from collections import defaultdict
from typing import Dict, List, Tuple
from pathlib import Path
from document import Document

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)  # A dictionary-like object that initializes any new key to a new TrieNode object.
        self.locations = []  # List of document locations where the current node's term is found.

class Trie:
    def __init__(self):
        self.root = TrieNode()  # Initialize the root node of the trie.

    def add_document(self, doc: Document):
        for term, locations in doc.terms.items():  # For each term in the document and its corresponding locations.
            node = self.root  # Start at the root node.
            for char in term:  # For each character in the term.
                node = node.children[char]  # Traverse to the next child node.
            node.locations.extend([(doc.doc_id, start, end) for start, end in locations])  # Add the document's locations to the current node.

    def prefix_complete(self, prefix: str) -> Dict[str, List[Tuple[str, int, int]]]:
        completions = defaultdict(list)  # Create a dictionary where each key is a string prefix and the value is a list of document locations.
        node = self.root  # Start at the root node.
        for char in prefix:  # For each character in the prefix.
            if char not in node.children:  # If the current character is not a child of the current node, there are no completions.
                return {}
            node = node.children[char]  # Traverse to the next child node.
        self._dfs(node, prefix, completions)  # Traverse the trie starting at the node for the last character in the prefix.
        return completions  # Return the dictionary of prefix completions.

    def _dfs(self, node: TrieNode, prefix: str, completions: Dict[str, List[Tuple[str, int, int]]]):
        if node.locations:  # If the current node has locations.
            completions[prefix] += node.locations  # Add the locations to the dictionary for the current prefix.
        for char in node.children:  # For each child of the current node.
            self._dfs(node.children[char], prefix+char, completions)  # Traverse the subtree of the child node and update the current prefix. 