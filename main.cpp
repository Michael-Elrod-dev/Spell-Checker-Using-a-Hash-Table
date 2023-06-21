#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);


int main()
{
    Stringset words;
    vector<string> alternatives;

    loadStringset(words,"wordlist.txt");
    alternatives=spellcheck(words,"lake");

    //ASSERT_EQ(alternatives.size(),18);
    cout << words.getNumElems() << endl;
    if (alternatives.size() != 18)
    {
        std::cout << "expected/correct value for alternatives.size() is 18, actual value when testing " << alternatives.size() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
    return 0;
}


void testStringset(Stringset& words)
{
    string choice;
    string word;
    do
    {
        cout << "I: insert word" << endl;
        cout << "F: find word" << endl;
        cout << "R: remove word" << endl;
        cout << "P: print words in stringset" << endl;
        cout << "Q: quit" << endl;
        cin >> choice;
        switch (choice[0])
        {
            case 'I':
            case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
            case 'F':
            case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
            case 'R':
            case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
            case 'P':
            case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
        }
    } while (choice[0] != 'Q' && choice[0] != 'q');
}

// This function will have to open a file of the given name
// and insert all the words in the file into the stringset
void loadStringset(Stringset& words, string filename)
{
    ifstream readFile(filename);
    string getWord;
    // Read all words from file into Stringset
    while(getline(readFile, getWord)) {
        words.insert(getWord);
    }
}

// This function will take the given word and return a vector of all
// the words in the stringset that are one letter away from the word
vector<string> spellcheck(const Stringset& words, string word)
{
    vector<string> misspelled;
    string wordTest = word;

    // Replace each letter of #word with every letter in the alphabet
    // one at a time to check for words off by 1 letter of #word
    for (int i=0;i<word.length();i++) {
        for (char letter='a';letter<='z'+1;letter++){
            // replace(position, sizeOfReplacement, #ofReplacements, replacementChar)
            wordTest.replace(i, 1, 1, letter);
            // If found AND unique, add to new vector and reset
            if (words.find(wordTest) && wordTest != word){
                misspelled.push_back(wordTest);
            }
            // Reset word
            wordTest = word;
        }
    }
    return misspelled;
}
