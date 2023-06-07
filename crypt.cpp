#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
class encrypt {
    int key;
 
    // File name to be encrypt
    string file = "secure.txt";
    char c;
 
public:
    void encry();
    void decry();
};
 
// Encrypting
void encrypt::encry()
{
    cout << "Enter the key: ";
    cin >> key;
 
    
    fstream fin, fout;
 
    
    fin.open(file, fstream::in);
    fout.open("encrypt.txt", fstream::out);
 
    
    while (fin >> noskipws >> c) {
        int temp = (c + key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
}
 
// Decrypting
void encrypt::decry()
{
    cout << "Enter the key: ";
    cin >> key;
    fstream fin;
    fstream fout;
    fin.open("encrypt.txt", fstream::in);
    fout.open("decrypt.txt", fstream::out);
 
    while (fin >> noskipws >> c) {
 
       
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
}
 
int main()
{
    encrypt enc;
    char c;
    cout << "\n";
    cout << "Enter Your Choice : -> \n";
    cout << "1. encrypt \n";
    cout << "2. decrypt \n";
    cout<<"Enter your choice: ";
    cin >> c;
    cin.ignore();
 
    switch (c) {
    case '1': {
        enc.encry();
        break;
    }
    case '2': {
        enc.decry();
        break;
    }
    }
}