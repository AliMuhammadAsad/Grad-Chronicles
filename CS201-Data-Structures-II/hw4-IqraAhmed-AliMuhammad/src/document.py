from pathlib import Path
class Document:
    def __init__(self, path: Path, doc_id: str):
        self.doc_id = doc_id.replace('\\','/')
        content = open(path, encoding='ascii', errors='ignore').read()
        terms = dict()
        in_term = False
        term = ''
        start = end = 0
        for i, c in enumerate(content):
            if c.isalnum():
                if not in_term:
                    start = i
                term += c
                end = i+1
                in_term = True
            elif in_term:
                in_term = False
                terms[term] = terms.get(term, []) + [(start, end)]
                term = ''
        if in_term:
            terms[term] = terms.get(term, []) + [(start, end)]
        self.terms = terms

    def __contains__(self, key):
        return key in self.terms

    def __getitem__(self, key):
        return self.terms.get(key, [])

    def __iter__(self):
        yield from self.terms