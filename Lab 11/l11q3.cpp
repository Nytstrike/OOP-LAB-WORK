#include <iostream>
#include <exception>
#include <string>
using namespace std;
class FileException : public exception
{
public:
    virtual const char *what() const noexcept
    {
        return "FileException";
    }
};

class FileNotFoundException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "FileNotFoundException";
    }
};

class PermissionDeniedException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "PermissionDeniedException";
    }
};

void readFile(const string& filename) {
    cout << "Reading '" << filename << "': ";

    if (filename.find("missing") != string::npos) {
        throw FileNotFoundException();
    }
    else if (filename.find("secret") != string::npos) {
        throw PermissionDeniedException();
    }
    else {
        cout << "File read successfully!" << endl;
    }
}

int main()
{
    string fileName= "secret.txt";
    try
    {
        readFile(fileName);
    }
    catch (const FileNotFoundException &e)
    {
        cout << "Reading '" << fileName << "': " << e.what() << endl;
    }
    catch (const PermissionDeniedException &e)
    {
        cout << "Reading '" << fileName << "': " << e.what() << endl;
    }
    catch (const FileException &e)
    {
        cout << "Reading '" << fileName << "': " << e.what() << endl;
    }
    return 0;
}