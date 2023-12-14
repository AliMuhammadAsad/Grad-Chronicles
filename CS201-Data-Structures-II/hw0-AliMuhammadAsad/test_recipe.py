from src.recipe import Ingredient, Recipe


def test_recipe():
    my_recipe = Recipe('Stairway to Heaven')
    assert (size := len(my_recipe)) == 0, \
        f'bad {size=}'
    my_recipe.add_ingredient(Ingredient('Sugar'), 10)
    assert (size := len(my_recipe)) == 1, \
        f'bad {size=}'
    my_recipe.add_ingredient(Ingredient('Spice'), 10)
    assert (size := len(my_recipe)) == 2, \
        f'bad {size=}'
    my_recipe.add_ingredient(Ingredient('Everything Nice'), 20)
    assert (size := len(my_recipe)) == 3, \
        f'bad {size=}'
    my_recipe.add_ingredient(Ingredient('Chemical X'), 100)
    assert (size := len(my_recipe)) == 4, \
        f'bad {size=}'
    itr = iter(my_recipe)
    ingredient, amount = next(itr)
    assert str(ingredient) == 'Sugar', \
        f'bad {ingredient=}'
    assert amount == 10, \
        f'bad {ingredient=}'
    ingredient, amount = next(itr)
    assert str(ingredient) == 'Spice', \
        f'bad {ingredient=}'
    assert amount == 10, \
        f'bad {ingredient=}'
    ingredient, amount = next(itr)
    assert str(ingredient) == 'Everything Nice', \
        f'bad {ingredient=}'
    assert amount == 20, \
        f'bad {ingredient=}'
    ingredient, amount = next(itr)
    assert str(ingredient) == 'Chemical X', \
        f'bad {ingredient=}'
    assert amount == 100, \
        f'bad {ingredient=}'
