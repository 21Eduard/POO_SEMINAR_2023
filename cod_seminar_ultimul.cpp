#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
    Person() : name(nullptr), cnp(nullptr), age(0) {}
    Person(const string& n, int a, const string& info) : age(a) {
        name = new char[n.size() + 1];
        strcpy_s(name, n.size() + 1, n.c_str());

        cnp = new char[info.size() + 1];
        strcpy_s(cnp, info.size() + 1, info.c_str());
    }
    // Destructor pentru a elibera memoria alocata dinamic
    ~Person() {
        delete[] name;
        delete[] cnp;
    }

    void Serialize(ofstream& ofs) const {
        size_t nameLength = strlen(name) + 1;
        ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        ofs.write(name, nameLength);

        size_t cnpLength = strlen(cnp) + 1;
        ofs.write(reinterpret_cast<const char*>(&cnpLength), sizeof(cnpLength));
        ofs.write(cnp, cnpLength);

        ofs.write(reinterpret_cast<const char*>(&age), sizeof(age));
    }

    void Deserialize(ifstream& ifs) {
        size_t nameLength, cnpLength;
        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        delete[] name;
        name = new char[nameLength];
        ifs.read(name, nameLength);

        ifs.read(reinterpret_cast<char*>(&cnpLength), sizeof(cnpLength));
        delete[] cnp;
        cnp = new char[cnpLength];
        ifs.read(cnp, cnpLength);

        ifs.read(reinterpret_cast<char*>(&age), sizeof(age));
    }

    void DisplayInfo() const {
        cout << "Name: " << name << ", CNP: " << cnp << ", Age: " << age << endl;
    }

private:
    char* name;
    char* cnp;
    int age;
};

int main() {
    {
        ofstream outputFile("person.dat", ios::binary);
        if (!outputFile) {
            cerr << "Error opening file for writing." << endl;
            return 1;
        }

        Person personToSave("John Doe", 25, " CNP");
        personToSave.Serialize(outputFile);

        cout << "Object saved successfully." << endl;
    }

    {
        ifstream inputFile("person.dat", ios::binary);
        if (!inputFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }

        Person restoredPerson;
        restoredPerson.Deserialize(inputFile);

        cout << "Object restored successfully." << endl;
        restoredPerson.DisplayInfo();
    }

    return 0;
}