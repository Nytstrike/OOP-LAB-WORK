#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
using namespace std;

int main()
{
    fstream file("data.txt", ios::in | ios::out);
    if (!file)
    {
        ofstream create("data.txt");
        if (!create)
        {
            cerr << "Error creating file!" << endl;
            return 1;
        }
        create << "AI is the future. AI will transform the world. Embrace AI now.";
        create.close();
        file.open("data.txt", ios::in | ios::out);
        if (!file)
        {
            cerr << "Error reopening file!" << endl;
            return 1;
        }
    }
    string searchWord, repWord;
    cout << "Enter word to search: ";
    cin >> searchWord;
    cout << "Enter replacement word: ";
    cin >> repWord;
    if (repWord.length() > searchWord.length())
    {
        cerr << "Error: Replacement word must not be longer than the search word." << endl;
        return 1;
    }
    file.seekg(0, ios::beg);
    string buffer;
    char ch;
    bool change = false;

    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            streampos start = file.tellg() - streamoff(1); // Start of word position
            buffer = ch;
            while (file.get(ch) && isalpha(ch))
            {
                buffer += ch;
            }
            if (buffer == searchWord)
            {
                file.seekp(start); 
                file.write(repWord.c_str(), repWord.length());
                if (repWord.length() < searchWord.length())
                {
                    file.seekp(start + streamoff(repWord.length()));
                    for (size_t i = 0; i < searchWord.length() - repWord.length(); ++i)
                    {
                        file.put(' ');
                    }
                }

                change = true;
                file.seekg(file.tellp()); 
            }
            if (!isalpha(ch))
            {
                file.unget();
            }
        }
    }

    file.close();
    ifstream inFile("data.txt");
    if (!inFile)
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nFile contents after replacement:\n";
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();

    if (!change)
    {
        cout << "\nNo replacements were made (" << searchWord << " not found)." << endl;
    }

    return 0;
}