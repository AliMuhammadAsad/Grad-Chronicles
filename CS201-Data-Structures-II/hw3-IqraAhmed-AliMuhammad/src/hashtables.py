from typing import Any
import random

'''
This file contains: 
1) Different implementations of the HashTables; Chained Hashing and Linear Hashing
    i) Chained Hashing: uses a sort of chain at each index in the set/table to store elements in a form of chain.
                        [Was pretty easy to implement, much fun as well]
    ii) Linear Hashing: uses linear probing for hashing, stores 'deleted' items. There is only a single set/table, whenever there
                        is a collision between elements with the same index, the element is inserted into the next free index.
                        [Was fairly easy to implement, had some struggles but was done. Liked Chained hashing more though]
2) Corresponding Implementations of the Dictionary Classes; Chained Dictionary and Linear Dictionary
    i) Chained Dictionary: A chained hash table is used to implement a dictionary that stores key value pairs as tuples in a set/table.
    ii) Linear Dictionary: A linear hash table is used to implement a dictionary that stores key value pairs as tuples in a set/table

    The Hash Table implementation was heavily influenced by the book "Open Data Structures" by Pat Morin that contains detailed analysis and pseudocodes for various methods. The inspiration taken includes the initialization, hash function, find(x) operation, add(x) operation, remove(x) operation and the resize() function.
    Implementation of __setitems__(x, y) and get(x) function uses the above operations.
'''

class MySet(object):
    '''An abstract class that provides a set interface which is just sufficient
    for the implementation of this assignment.
    '''

    def __init__(self, elements: [Any]) -> None:
        """Initializes this set with elements.

        Each element in elements must be hashable by python.

        Args:
        - self: manadatory reference to this object.
        - elements: this set is populated with these elements.

        Returns:
        None
        """
        pass

    def add(self, element: Any) -> None:
        """Adds element to this set.

        element must be hashable by python.

        Args:
        - self: manadatory reference to this object.
        - element: the element to add to this set

        Returns:
        None
        """
        pass    

    def discard(self, element: Any) -> None:
        """Removes element from this set.

        there is noting to be done if element is not present in this set.

        Args:
        - self: manadatory reference to this object.
        - element: the element to remove from this set

        Returns:
        None
        """
        pass    

    def __iter__(self):
        """Makes this set iterable.

        There are many different ways to implement this. Choose one that works
        for you.

        Args:
        - self: manadatory reference to this object.
        """
        pass    

class ChainedSet(MySet):
    '''Overrides and implementes the methods defined in MySet. Uses a chained
    hash table to implement the set.
    '''
    def __init__(self, elements: [Any]) -> None:
        self.d = 1 #t.length = 2^d where d is an integer - dimension -> number of bits
        self.set = [[] for i in range(2 ** self.d)] #Our hash table - with a list at each element to simulate chaining of elements
        self.z = random.randrange(1, 100, 1) #Random variable z
        self.n = 0 #number of elements in the list
        for i in elements: #add the elements to the set
            self.add(i)
    
    def _hash_(self, element: Any) -> int: #Returns the hash value
        hashed_val = (self.z * hash(element) % (1 << 32)) >> (32 - self.d) #Hash value as mentioned in the book "Open Data Structures" with w value as 32
        return hashed_val
    
    def _find_(self, element: Any) -> bool: #find(x) operation
        index = self._hash_(element) #Takes the hash value of the element to jump to that index and search within the chain
        if element not in self.set[index]: 
            return False #If element not found within the chain, it returns False that the element was not found
        return True #Else returns true that the element was found

    def resize(self) -> None:
        self.d = 1 #Resets the d value to 1
        while 2 ** self.d < 3 * self.n: #While 2**self.d is less than 3 times the number of elements, we increment the d value to resize the table with the new d value. Implementation taken from the book "Open Data Structures"
            self.d += 1
        newset = [[] for i in range(2 ** self.d)] #New table with number of chain with the updated d value
        for chain in self.set: #Iterating over the list to get a single chain
            for item in chain: #Iterating over each individual chain to get single elements/items within the chain
                index = self._hash_(item[0]) #Calculating the hash value of the key stored for one element/item within the chain
                newset[index].append(item) #appending the element/item to that index in the new set
        self.set = newset #Updating our previous set to the new set

    def add(self, element: Any) -> bool:
        if self.d + 1 > len(self.set): self.resize() #Checking for the resize condition as per the book "Open Data Structures". If the d value + 1 is more than the length of our hash table, we call resize to implement a bigger hash table 
        if self._find_(element) == False: #If element does not exists within the table
            index = self._hash_(element) #calculate hash value of the element to add it to the index number
            self.set[index].append(element) #appending it to the chain at that index
            self.n += 1 #Incrementing the total elements within the hash table
            return True #Operation add(x) successful, hence returns true
        return False #else returns false - add(x) was not successful
    
    def discard(self, element: Any) -> Any:
        if 3 * self.n < len(self.set): self.resize() #Resize condition as per the book "Open Data Structures". If 3 times number of elements within the table is still less than the length of the set, we resize the table
        index = self._hash_(element) #Claculate the hash value to access that specific chain in the hash table
        for i in range(len(self.set[index])): #iterating over the chain 
            if self.set[index][i] == element: #If the item at that index in the chain is the one we want to delete
                self.set[index].pop(i) #Remove the item at that index in the chain
                self.n -= 1 #Decrease the number of elements in the table
                return True #Operation was successful hence we return True 
        return None #Else we return None value that the element did not exist within the table

    def __iter__(self) -> Any: #Iter funciton
        for chain in self.set: #For one chain in the tables/set 
            for item in chain: #For one item in the chain
                yield item #Yield the item
        #We use yield for this function rather than return as once return is called, the function generation stops and when the function is called, it starts from the beginning. With yield, we can continue from where the last function was called as the function generation does not stop

class LinearSet(MySet):
    '''Overrides and implementes the methods defined in MySet. Uses a linear
    probing hash table to implement the set.
    '''
    def __init__(self, state: [(int, int)]) -> None:
        self.d = 1 #t.length = 2^d where d is an integer - dimension
        self.set = [None] * 2**self.d #Our Linear Set
        self.n = 0 #Number of elements in the set
        self.q = 0 #Number of non-null entries in our set
        self.z = random.randrange(1, 100, 1) #Our random integer z to generate hash values
        self.delcheck = "del" #a check/flag that indicates a value has been deleted from the index in the set
        for s in state: #Add the elements in the state to the set
            self.add(s)

    def _hash_(self, element) -> int: #Returns the hash value
        hashed_val = (self.z * hash(element) % (1 << 32)) >> (32 - self.d) #Hash value as mentioned in the book "Open Data Structures" with w value as 32 
        return hashed_val

    def _find_(self, element : Any) -> Any: 
        #Implementation to the find function taken from the book "Open Data Structures"
        index = self._hash_(element) #Hash value gives index
        while self.set[index] != None: #while we don't encounter a None value, we traverse over the set
            if self.set[index] != self.delcheck and self.set[index] == element: #if element is not deleted and element is the required element
                return element #return the element
            index = (index + 1) % len(self.set) #if condition not satisfied, then increment i by 1
        return None #if loop exited, then we return False since element does not exist within the set

    def add(self, element: Any) -> bool:
        if self._find_(element) != None: return False #return false if the element already exists within the set
        if (2*(self.q + 1) > len(self.set)): self.resize() #Resize condition for when their are a certain number of null entries -> taken from "Open Data Structures"
        index = self._hash_(element) #hash value gives the index
        while self.set[index] != None and self.set[index] != self.delcheck: #while the value at the index is not None and it is not a deleted element we traverse to add the element
            index = (index + 1) % len(self.set) #index incremented as we don't have an empty value to store the element
        if self.set[index] == None: #if we encounter a None element, then the total non-null entries are incremented by 1 
            self.q += 1
        self.n += 1 #Element added so size/number of elements incremented by 1
        self.set[index] = element #The index is set to the value that had to be added
        return True #Adding successful, hence return True to indicate

    def discard(self, element: Any) -> Any: #Implementation from "Open Data Structures"
        if self._find_(element) == False: return None #If element does not exist within the set, we return None
        index = self._hash_(element) #hash value gives the index
        while self.set[index] != None: #while we don't encounter a None element
            temp_var = self.set[index] #setting a temporary variable for the value at the index
            if temp_var != self.delcheck and temp_var == element: #If it is not a deleted entry and value is the one we needed to delete 
                self.set[index] = self.delcheck #We set the value as a deleted entry
                self.n -= 1 #decrement in the number of elements in the set by 1
                if (8 * self.n < len(self.set)): self.resize() #Resize condition as per the book
                return temp_var #Return the variable
            index = (index + 1) % len(self.set) #increment index if no value returned
        return None #if loop exited then return None as element does not exist

    def __iter__(self) -> Any: #Notice that for iteration, we didn't use return value, rather we implemented it with a yield value. The reason being that once return is executed, the function execution is completed and can't be continued. However, with yield, the function generation is sort of paused and can be continued later on as well. Hence the implementation through yield rather than return
        for key in self.set:
            if key != "del" and key != None:
                yield key 

    def resize(self): #Resize function to resize the table when the maximum load factor or the minimum load factor is reached. Implementation taken from the book "Open Data Structures"
        self.d = 1 #Reset d value
        while (2 ** self.d) < 3 * self.n: self.d += 1 #while 2^d is less than 3 times the number of elements, we increase the d value, "Open Data Structures"
        told = self.set #The set is stored temporarily as an old set for reference
        self.set = [None] * (2 ** self.d) #Creating a new set with 2**self.d size
        self.q = self.n #setting the non-null entries to the number of elements in the set
        ## Insert everything from told ##
        for element in told: #for each element in told
            if element != None and element != self.delcheck: #if element is not None and is not a deleted element 
                index = self._hash_(element) #Calculate its hash value for indexing
                while self.set[index] != None: #while the index in the new set starting from the required index is not None, we traverse
                    index = (index + 1) % len(self.set) #Update index value
                self.set[index] = element #Set the value at the index to the element

class MyDict(object):
    '''An abstract class that provides a dictionary interface which is just
    sufficient for the implementation of this assignment.
    '''

    def __init__(self) -> None:
        """Initializes this dictionary.

        Args:
        - self: manadatory reference to this object.

        Returns:
        none
        """
        pass
    
    def __setitem__(self, key: Any, newvalue: Any) -> None:
        """Adds (key, newvalue) to the dictionary, overwriting any prior value.

        dunder method allows assignment using indexing syntax, e.g.
        d[key] = newvalue

        key must be hashable by pytohn.
        
        Args:
        - self: manadatory reference to this object.
        - key: the key to add to the dictionary
        - newvalue: the value to store for the key, overwriting any prior value 

        Returns:
        None
        """
        pass
    
    def get(self, key: Any, default: Any = None) -> Any:
        """Returns the value stored for key, default if no value exists.

        key must be hashable by python.
        
        Args:
        - self: manadatory reference to this object.
        - key: the key whose value is sought.
        - default: the value to return if key does not exist in this dictionary

        Returns:
        the stored value for key, default if no such value exists.
        """
        pass

    def items(self) -> [(Any, Any)]:
        """Returns the key-value pairs of the dictionary as tuples in a list.
        
        Args:
        - self: manadatory reference to this object.

        Returns:
        the key-value pairs of the dictionary as tuples in a list.
        """
        pass

    def clear(self) -> None:
        """Clears the dictionary.

        Args:
        - self: manadatory reference to this object.

        Returns:
        None.
        """
        pass

class ChainedDict(MyDict):
    '''Overrides and implementes the methods defined in MyDict. Uses a chained
    hash table to implement the dictionary.
    '''
    def __init__(self) -> None:
        self.d = 1 #t.length = 2^d where d is an integer - dimension
        self.set = [[] for i in range(2 ** self.d)] #Creating a table/set/list of chains/buckets of size 2^d
        self.n = 0 #number of elements initially set to 0
        self.z = random.randrange(1, 100, 1) #setting a random z variable
    
    def _hash_(self, element) -> int: #Our hash function same as above
        hashed_val = (self.z * hash(element) % (1 << 32)) >> (32 - self.d) #Hash value
        return hashed_val
    
    def _find_(self, key: Any) -> Any: #find function for finding an element as per the book "Open Data Structures"
        index = self._hash_(key) #hash value gives the index
        for item in self.set[index]: #traversing over the elements in the chain at the index in the list/table
            if item[0] == key: return item[1] #return the value stored with the corresponding key if we find the key
        return None #else return None if loop exits as the key does not exist

    def resize(self) -> None: #Resize implementation
        self.d = 1 #resetting the d value
        while (2 ** self.d) < 3 * self.n: #same as before
            self.d += 1 
        told = self.set #temporary table made giving the values of the previous set to the table
        self.set = [[] for i in range(2 ** self.d)] #the new set is updated to hold only empty chains in the table with size 2^d
        for chain in told: #for each item in told
            for item in chain: #for each item - (key, value) pair - in the chain
                index = self._hash_(item[0]) #calculate the key's hash value to get the index
                self.set[index].append(item) #append the item at the index in the new hash table

    def add(self, key: Any, value: Any) -> bool: #add function as per the book
        if self._find_(key) != None: return False #if the find function returns a value, then the key value already exists within the set, hence returns False
        if self.n + 1 > len(self.set): self.resize() #If number of elements + 1 is greater than the length of the set, then resize is called
        index = self._hash_(key) #hash value gives index
        self.set[index].append((key, value)) #append the key value pair to the chain 
        self.n += 1 #increment the number of elements in the table
        return True #return True as the operation is successful
    
    def __setitem__(self, key: Any, newvalue: Any) -> Any: #Sets the value of the key in the table
        index = self._hash_(key) #hash value gives index
        found = False #flag if element is found
        j = 0 #j for flag
        while not found and j < len(self.set[index]): #while flag is not True and j is less than the length of the chain at the index
            k = self.set[index][j][0] #we take the key at the jth index of the chain
            if k == key: #if it matches the required key
                self.set[index][j] = (key, newvalue) #we update the value for that key
                found = True #flag generates the exit condition to break the loop
            j += 1 #else j incremented
        if found == True: return #if operation was done successfully, we return and the function ends
        self.set[index].append((key, newvalue)) #else we append the key value pair to the chain
        self.n += 1 #number of elements incremented by 1
        if self.n > len(self.set): self.resize() #if number of elements is greater than the length of the table, then resize is called.
        
    def get(self, key: Any, default: Any = None) -> Any:
        index = self._hash_(key) #hash value - index
        for i in range(len(self.set[index])): #we iterate over the chain at the index
            if self.set[index][i][0] == key: #if key at the index in the chain is the required key
                return self.set[index][i][1] #return the value corresponding to the required key
        return default #else if it doesn't exist, then return the default value

    def items(self) -> Any:
        lst = [] #an empty list for storing the items
        for i in range(len(self.set)): #iterating over the table
            for j in range(len(self.set[i])): #iterating over each chain in the table
                lst.append(self.set[i][j]) #append the key value pair in each chain to the list
        return lst #return the list containing the key value pairs
    
    def clear(self) -> None: #Clear function resets all values
        self.d = 1
        self.set = [[] for i in range(2 ** self.d)]
        self.n = 0
        self.z = random.randrange(1, 100, 1)

class LinearDict(MyDict):
    '''Overrides and implementes the methods defined in MyDict. Uses a linear
    probing hash table to implement the dictionary.
    '''
    def __init__(self) -> None:
        self.d = 1 #t.length = 2^d where d is an integer - dimension
        self.set = [None] * 2**self.d #A table to store key value pairs as tuples to simulate a dictionary
        self.n = 0 #number of elements in the list
        self.q = 0 #number of non-null entries in the dictionry
        self.z = random.randrange(1, 100, 1) #random z variable

    def _hash_(self, key: Any) -> int: #Returns the hash value
        hashed_val = ((self.z * hash(key) % (1 << 32)) >> (32 - self.d)) #Hash value as mentioned in the book "Open Data Structures" with w value as 32 
        return hashed_val

    def _find_(self, key: Any) -> Any: #Same operation as described above for LinearSet with some small modifications
        index = self._hash_(key) #Hash value - index
        while self.set[index] != None: #while we don't encounter a None element
            if self.set[index][0] == key: #if the key is the required key -> key will be at index 0 of the tuple
                return index #return the corresponding index
            index = (index + 1) % (2 ** self.d) #else increment the index by 1
        return None #if we don't find the key, then return None as the key does not exist
    
    def resize(self) -> None: #Same operation as descrived above for LinearSet with some small modification
        prev_d = self.d #Storing the previous t.length = 2^d to traverse over the list
        self.d = 1 #Reset the d value
        while 2**self.d < 3 * self.n: self.d += 1 #Increment the d value
        told = self.set #Set the set to a temporary variable
        self.set = [None] * 2**self.d #Create the new set with the updated d value
        self.q = self.n #non-null entries become the total number of elements in the table
        for i in range(2**prev_d): #Traversing over the length of the old set
            if told[i] != None: #if the key is not None then we have a key here
                index = self._hash_(told[i][0]) #calculate the hash value for the key
                while self.set[index] != None: #while there is a None value in the set
                    index = (index + 1) % (2 ** self.d) #increment the index value 
                self.set[index] = told[i] #set the key value at the index to the key value stored in the previous set

    def add(self, key: Any, value: Any) -> Any:
        if self._find_(key) != None: return False #return false if we find the element already  
        if (2*(self.q + 1) > 2**self.d): self.resize() #Resize condition for when their are a certain number of null entries -> "Open Data Structures"
        index = self._hash_(key) #hash value - index
        while self.set[index] != None: #while there is not a None element, we traverse over the set
            index = (index + 1) % (2**self.d) #index incremented as we don't have an empty value to store the element
        if self.set[index] == None: #if we encounter a None element, then the total non-null entries are incremented by 1 
            self.q += 1
        self.n += 1 #Element added so size/number of elements incremented by 1
        self.set[index] = (key, value) #Add the key value pair to the required index
        return True #Adding successful, hence return True to indicate

    def __setitem__(self, key: Any, newvalue: Any) -> None:
        index = self._find_(key) #find required index 
        if index == None: self.add(key, newvalue) #if index is None, then the key does not exist, so we use the add function to add the key value pair to the required tables
        else: self.set[index] = (key, newvalue) #else if they key exists, then we update the newvalue at the required index

    def get(self, key: Any, default: Any = None) -> Any:
        index = self._find_(key) #get the required index
        if index != None: return self.set[index][1] #If index is not None, then the key exists, so we return the corresponding value
        return default #else we return the default value as the key does not exist

    def items(self) -> Any:
        #We iterate over the set, and if the element is not None, then there exists a key value pair, so we return the key with its value
        for item in range(2 ** self.d): 
            if self.set[item] != None:
                yield(self.set[item][0], self.set[item][1])

    def clear(self) -> None: #Reset condition -> resets all values
        self.d = 1
        self.set = [None] * 2**self.d
        self.n = 0
        self.q = 0
        self.z = random.randrange(1, 100, 1)

# A second implementation of the LinearDict that stores two different tables; one for storing keys, and one for storing values with the corresponding keys.
# One table stores keys at different indexes, and the other table for values stores values at the corresponding indexes. Apart from one additional table, there is literally no different between either of the codes, they are exactly the same nad both work perfectly fine

# class LinearDict(MyDict):
#     '''Overrides and implementes the methods defined in MyDict. Uses a linear
#     probing hash table to implement the dictionary.
#     '''
#     def __init__(self):
#         self.d = 1 #t.length = 2^d where d is an integer - dimension
#         self.set_keys = [None] * 2**self.d #a table to store the keys of the dictionary
#         self.set_values = [None] * 2**self.d #table to store the values corresponding to the keys in the dictionary
#         self.n = 0 #number of elements in the list
#         self.q = 0 #number of non-null entries in the dictionry
#         self.z = random.randrange(1, 100, 1) #random z variable

#     def _hash_(self, key: Any) -> int: #Returns the hash value
#         hashed_val = ((self.z * hash(key) % (1 << 32)) >> (32 - self.d)) #Hash value as mentioned in the book "Open Data Structures" with w value as 32 
#         return hashed_val

#     def _find_(self, key: Any): #Same operation as described above for LinearSet
#         index = self._hash_(key) #Hash value - index
#         while self.set_keys[index] != None: #while we don't encounter a None element
#             if self.set_keys[index] == key: #if the key is not a deleted key and the required key
#                 return index #return the corresponding index
#             index = (index + 1) % (2 ** self.d) #else increment the index by 1
#         return None #if we don't find the key, then return None as the key does not exist
    
#     def resize(self): #Same operation as descrived above for LinearSet
#         num = self.d
#         self.d = 1 #Reset the d value
#         while 2**self.d < 3 * self.n: self.d += 1 #Increment the d value
#         told_keys = self.set_keys #Set a temporary table for the keys
#         told_vals = self.set_values #Set a temporary table fot the values
#         self.set_keys = [None] * (2**self.d) #Renew the table of keys with the updated size
#         self.set_values = [None] * (2**self.d) #Renew the table of values with the updated size
#         self.q = self.n #non-null entries become the total number of elements in the table
#         for i in range(2**num): 
#             if told_keys[i] != None: #if the key is not None and isn't a deleted element either -> then we have a key here
#                 index = self._hash_(told_keys[i]) #calculate the hash value for the key
#                 while self.set_keys[index] != None: #while there is a None value including and after the index in the new table of keys
#                     index = (index + 1) % (2 ** self.d) #increment the index value 
#                 else:
#                     self.set_keys[index] = told_keys[i] #set the key at the index to the required key
#                     self.set_values[index] = told_vals[i] #set the corresponding value to the required value

#     def add(self, key: Any, value: Any) -> None:
#         if self._find_(key) is not None: return False #return false if we find the element already  
#         if (2*(self.q + 1) > 2**self.d): self.resize() #Resize condition for when their are a certain number of null entries -> "Open Data Structures"
#         index = self._hash_(key) #hash value - index
#         while self.set_keys[index] != None: #while the value at the index is not None and it is not a deleted element we traverse to add the element
#             index = (index + 1) % (2**self.d) #index incremented as we don't have an empty value to store the element
#         if self.set_keys[index] == None: #if we encounter a None element, then the total non-null entries are incremented by 1 
#             self.q += 1
#         self.n += 1 #Element added so size/number of elements incremented by 1
#         self.set_keys[index] = key #add the key at the index to the set of keys
#         self.set_values[index] = value #add the corresponding value to the corresponding index
#         return True #Adding successful, hence return True to indicate

#     def __setitem__(self, key: Any, newvalue: Any):
#         # if (self.q + 1) * 2 > len(self.set): self.resize() #Resize dictionary if the resize condition met
#         # index = self._hash(key) #Hash value - index
#         # while self.set[index] != None and self.set[index][0] != key: #we traverse over the values while the value is not None, and while the key at the index is not the required key
#         #     index = (index + 1) % len(self.set) #incrementing index to traverse the elements
#         # if self.set[index] == None: #If None, we increase the total Non-Null entries, and the number of elements in our set
#         #     self.q += 1; self.n += 1
#         # self.set[index] = (key, newvalue) #We set the new index with the new value
#         # return True #Operation Set Item successfull
#         index = self._find_(key) #get the required index of the key
#         if index == None: self.add(key, newvalue) #if index is None, then the key does not exist, so we use the add function to add the key value pair to the required tables
#         else: self.set_values[index] = newvalue #else if they key exists, then we just update the value at the corresponding index in the table of values

#     def get(self, key: Any, default: Any = None):
#         # index = self._hash(key) #Hash value - index
#         # while self.set[index] != None: #While index is not None we traverse
#         #     if self.set[index][0] == key: #if we have the key at the index
#         #         return self.set[index][1] #we return the value stored with that key
#         #     index = (index + 1) % len(self.set) #else we incremenet 1 to i to traverse further
#         # return default #we return the default value if loop exited as this implies the key has not been found
#         index = self._find_(key) #get the index of the key
#         if index != None: return self.set_values[index] #If index is not None, then the key exists, so we return the corresponding value from the table of values
#         return default #else we return the default value as the key does not exist

#     def items(self):
#         # for item in self.set: #We traverse over items stored in the set
#         #     if item != None: #If item is not None -> we don't have empty values
#         #         yield item #we return the item and then standby for the next value to be returned
#         # keyvals = []
#         for item in range(2 ** self.d):
#             if self.set_keys[item] != None:
#                 yield (self.set_keys[item], self.set_values[item])

#     def clear(self): #Reset condition
#         self.d = 1
#         self.set_keys = [None] * 2**self.d
#         self.set_values = [None] * 2**self.d
#         self.n = 0
#         self.q = 0
#         self.z = random.randrange(1, 100, 1)
