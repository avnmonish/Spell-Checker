
/* Spell Checker using Trie */

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<algorithm>

#include "color.h"

#define SIZE 256
using namespace std;

int success = 0;
class Node
{
    public:
        Node *children[SIZE];  // Child pointers.
        string Word;    

        // Constructor :
        Node();

        // Destructor :
        //~Node();
};

// Constructor :
Node :: Node()
{
    for(int i = 0;i < SIZE;i++)
    {
        children[i] = NULL;  // Initialize each value to Null.
    }
    Word = "";
}

/*Node :: ~Node()
{
    cout << "\nOVER" << endl << endl;
}*/

void insert(Node *root, string word,int pos)  // Function to insert a node to Trie.
{
    if(word.length() == pos)
    {
        root->Word = word;
        return;
    }

    if(root->children[word[pos]] == NULL)
    {
        Node *newNode = new Node;
        root->children[word[pos]] = newNode;
        insert(root->children[word[pos]], word,pos+1);
    }

    else
    {
        insert(root->children[word[pos]], word,pos + 1);
    }
}

void check(Node *root, string key, int pos)  // Function to check for spelling of a word.
{
    if((key != root->Word) && (root->children[key[pos]] != NULL))
    {
        check(root->children[key[pos]], key, pos + 1);
    }

    else if(key == root->Word)
    {
        DGreen();
        cout << "\n\t\tThe spelling of the word ";
        
        DCyan();
        cout << "'" << root->Word << "'";

        DGreen();
        cout <<  " is correct." << endl << endl;
        reset();
        success = 1;
    }
}

void display(Node * root)  // Function to display word.
{
    for(int i = 0;i < SIZE;i++)
    {
        if(root->children[i] != NULL)
        {
            display(root->children[i]);
        }
    }

    if(root->Word != "")
    {
        cout << "\t\t\t" << root->Word << endl;
    }
}

void suggestion(Node * root, string key,int pos)  // Function to give suggestion regarding a word.
{
    if((key != root->Word) && (root->children[key[pos]] != NULL))
    {
        suggestion(root->children[key[pos]], key, pos + 1);
    }

    else
    {
        display(root);
    }
}


int main()
{
    Node *root = new Node();  // Root of a Trie.

    while(1)
    {
        short int choice;
        DPurple();
        cout << "\n\t\t1. Load" << endl;
        cout << "\t\t2. Check for Spelling" << endl;
        cout << "\t\t3. Suggestions" << endl;
        cout << "\t\t4. Exit" << endl;


        DYellow();
        cout << "\n\t\tYour Choice : ";
        DWhite();
        cin >> choice;
        reset();

        switch(choice)
        {
            case 1:  // Loading the words from file to Trie.
            {
                fstream fin;
                string word;
                fin.open("wordList.txt", ios :: in);  // File opened for reading.

                // Loading the Trie.
                while(!fin.eof())
                {
                    fin >> word;
                    insert(root, word, 0);
                }
                
                fin.close();
                break;
            }

            case 2:
            {
                string word;
                DYellow();
                cout << "\nEnter a word to check it's spelling: ";
                DWhite();
                cin >> word;
                reset();

                transform(word.begin(), word.end(), word.begin(), ::tolower); // Converting the word to lower case.
                check(root, word, 0);
                
                if(success == 0)
                {
                    DRed();
                    cout << "\n\t\tSuch a word doesn't exist." << endl << endl;
                    reset();
                }
                break;
            }

            case 3:
            {
                string word;
                DYellow();
                cout << "\nEnter a word to get suggestions regarding that word: ";
                DWhite();
                cin >> word;
                transform(word.begin(), word.end(), word.begin(), ::tolower); // Converting the word to lower case.

                DPurple();
                cout << "\n\n\t\tSuggestions with reference to '" << word << "' : " << endl << endl;

                DCyan();
                suggestion(root, word, 0);
                cout << endl << endl;

                reset();
                break;
            }

            case 4:
            {
                DBlue();
                cout << "\n-----------------------------------------------EXIT-------------------------------------------------------" << endl << endl;
                //root->~Node();
                reset();
                exit(0);
            }

            default:
            {
                DRed();
                cout << "\n------------------------------------Invalid input Try again !!!-------------------------------------------" << endl << endl;
                reset();
            }
        }
    }

    return 0;
}
