# Spell Checker Using a Hash Table

A C++ program that implements a Stringset class utilizing a hash table with chaining to handle collisions. It is used to perform operations like inserting words, finding words, and removing words from a stringset. The program is also designed to handle spell checking, suggesting words that are only one letter away from a given word.

## Usage

```cpp
#include "stringset.h"
```

The main functions in the program are:

- insert(string word): Inserts a word into the stringset. The function also handles resizing and rehashing of the table when it becomes full.

- find(string word): Checks if a given word exists in the stringset and returns a boolean value accordingly.

- remove(string word): Removes a given word from the stringset if it exists.

- loadStringset(Stringset& words, string filename): Loads words from a specified text file into the stringset.

- spellcheck(const Stringset& words, string word): Checks if a given word is spelled correctly. If not, it suggests words that are one letter away from the given word.

Test
A test function testStringset(Stringset& words) is provided to interactively test the implemented operations. You can insert words, find words, remove words and print all words in the stringset.

Example
An example usage of this program is shown in the main() function. The loadStringset() function is used to load words from a file named "wordlist.txt" into the stringset. The spellcheck() function is then used to check the spelling of the word "lake" and suggest possible correct spellings.
