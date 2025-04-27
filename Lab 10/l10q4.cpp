// You are testing how file pointers work in a file while reading and writing.
// Requirements:
// 1. Write the sentence "C++ is a powerful programming language." to a file named
// info.txt using ofstream in ios::out mode.
// 2. Reopen the file using fstream with both ios::in | ios::out modes.
// 3. Display the initial position of get pointer using tellg() and put pointer using tellp().
// 4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
// from there.
// 5. Use seekp(6) to move the write pointer to the same position, and overwrite
// "powerful" with "dynamic" (same length).
// 6. Use tellg() and tellp() again to show the new pointer positions.
// 7. Display the updated content of the file.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outfile("info.txt", ios::out);
    outfile << "C++ is a powerful programming laguage";
    outfile.close();

    fstream file("info.txt", ios::in | ios::out);
    cout << "Initial postion:" << file.tellg() << endl;
    cout << "Put postion:" << file.tellp() << endl;
    file.seekg(9);
    char word[8];
    file.read(word,8);
    if (file.gcount() != 8) {  // Check how many characters were actually read
        cerr << "Read failed! Only read " << file.gcount() << " characters" << endl;
        return 1; }
    word[8] = '\0';
    cout << "The word is:" <<word<< "\n" <<endl;
    file.clear();

    file.seekp(9);
    file.write("dynamic", 7);
    if (!file) {
        cerr << "Write failed!" << endl;
        return 1;
    }

    cout << "\nNew initial postion :" << file.tellg() << endl;
    cout << "\nNew put postion :" << file.tellp() << endl;
    file.seekp(0);
    string line;
    getline(file, line);
    cout <<"\nNew line:"<<line << endl;
    file.close();

    return 0;
}
