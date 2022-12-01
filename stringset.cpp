
#include "stringset.h"

Stringset::Stringset():table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

// Only inserts if the word does not already exist in the document
// This function must also double the size of the table when num_elems == size,
// where num_elems is the current number of words in the table and size is the
// current size of the table. Must also rehash existing values with new size!
// insert_location = hash("insert_word_here") % size = your_hash_key
void Stringset::insert(string word)
{
    // If word is not already in list
    if (!find(word)) {
        int index;
        string wordToSwitch;
        hash<string> wordHash;
        // If table is full, double its size
        if (num_elems >= size) {
            size = size * 2;
            vector<list<string>> resizedTable(size);
            list<string>::const_iterator iterator; // Looping variable for table
            // Re-hash all variables to place in new table
            for (int i=0;i<size/2;i++) {
                for (iterator=table[i].begin(); iterator != table[i].end(); ++iterator) {
                    wordToSwitch = *iterator; // get value at address
                    index = wordHash(wordToSwitch) % size;
                    resizedTable[index].push_back(wordToSwitch);
                    table[i].remove(word);
                }
            }
            table = resizedTable;
        }
        index = wordHash(word) % size;
        table[index].push_back(word);
        num_elems++;
    }
}

// Will return true if the word is in the list, otherwise it will return false
bool Stringset::find(string word) const
{
    hash<string> listHash;
    // Getting Hash key to find word
    int index = listHash(word) % size;

    // List iterator for looping
    list<string>::const_iterator iterator;
    // Reading through all variables until end()
    for(iterator = table[index].begin(); iterator != table[index].end(); iterator++)
    {
        // iterator is used as reference to check for word
        if (*iterator == word)
            return true;
    }
    return false;
}

/*
 * When finding and removing from the table use the same hashing technique
 * used for insertion to get the proper location within the vector, and then
 * loop through the linked list at that spot until you find your value
 * don't forget to decrease the value of size
 */
void Stringset::remove(string word)
{
    // If word is in Stringset, remove it
    if (find(word)){
        hash<string> listHash;
        // Get hash key
        int index = listHash(word) % size;
        table[index].remove(word);
        num_elems--;
    }
}