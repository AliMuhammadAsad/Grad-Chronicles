class Ingredient(object):
    def __init__(self, name: str)->None:
        self.name = name
    
    def __str__(self) -> str:
        return self.name


class Recipe(object):
    def __init__(self, name: str) -> None:
        self.name = name
        self.ingredients = []
        self.iterate = 0
    
    def add_ingredient(self, ingredient: Ingredient, amt: int)->None:
        ing = (ingredient.name, amt)
        self.ingredients.append(ing)
    
    def __len__(self)->int:
        return len(self.ingredients)
    
    def __iter__(self):
        return self
        
    def __next__(self):
        # if self.iterate >= len(self.ingredients):
        #     raise StopIteration
        ingred = self.ingredients[self.iterate]
        self.iterate += 1
        return ingred
