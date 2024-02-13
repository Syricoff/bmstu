#include <fstream>
#include <iostream>

using namespace std;


int main() {
    ofstream fout;          
    fout.open("hello.txt");      
    if (fout.is_open())
    {
        for (int i = 0; i < 10; i++) {
            fout << i << "\tHello, student!" << std::endl;
        }        
    }
    fout.close(); 
    cout << "File has been written" << std::endl;
    fout.open("hello.txt", ios::app);
    if (fout.is_open())
    {
        fout << "--- Appended string ---" << std::endl;
    }
    fout.close(); 

    char line[255] = "";

    ifstream fin("hello.txt"); 
    if (fin.is_open())
    {
        while (fin.getline(line, 255))
        {
            cout << line << endl;
        }
    }
    fin.close();     

    return 0;
}