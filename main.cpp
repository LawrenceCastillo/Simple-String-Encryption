/* 
Title:    main.cpp
Author:   Lawrence Gabriel Castillo
Date:     2018-Nov-19
Desc:     Encrypts and decrypts user input string based on Caesar and Vigenere algorithms
Purpose:  To demonstrate a simple encryption technique
Build:    Visual Studio Code 1.31.1; compile: g++ main.cpp
*/

#include <iostream>

using namespace std;


// Prototypes

char shiftChar(char c, int rshift);                         // shift char by user-defined value; for Caesar encryption
string encryptCaesar(string userLine, int rshift);          // encrypt string with Caesar method
char shiftCharD(char c, int lshift);                        // shift char by user-defined value; for Caesar encryption
string decryptCaesar(string userLine, int lshift);          // decrypt string with Caesar method
string encryptVigenere(string userStr, string codeWord);    // encrypt string with Vigenere method
string decryptVigenere(string userStr, string codeWord);    // decrypt string with Vigenere method

// Main function

int main() {
    
    string plainText = "";
    int shiftValue = 0;
    string keyword = "";
    
    cout << "Enter plaintext: ";
    getline (cin, plainText);                               // including spaces & characters
    cout << endl;
    
    // print Caesar encryption & decryption
    cout << "= Caesar =" << endl;
    cout << "Enter shift    : ";
    cin >> shiftValue;
    cout << "Ciphertext     : " << encryptCaesar(plainText, shiftValue) << endl;
    cout << "Decrypted      : " << decryptCaesar(encryptCaesar(plainText, shiftValue), shiftValue) << "\n\n";
    
    // print Vignere encryption & decryption
    cout << "= Vigenere = " << endl;
    cout << "Enter keyword  : ";
    cin >> keyword;
    cout << "Ciphertext     : " << encryptVigenere(plainText, keyword) << endl;
    cout << "Decrypted      : " << decryptVigenere(encryptVigenere(plainText, keyword), keyword) << "\n\n";
}

// Function implementation

char shiftChar(char c, int rshift) {
    
    char cipherOutput;
    
    // capital letters
    if (c >= 65 && c <= 90) {
        
        if (c + rshift <= 90) {
            
            cipherOutput = c + rshift;
            return cipherOutput;
        }
        
        else {
            
            cipherOutput = c + rshift - 26;
            return cipherOutput;
        }
    }
    
    // lower case letters
    else if (c >= 97 && c <= 122) {
        
        if (c + rshift <= 122) {
            
            cipherOutput = c + rshift;
            return cipherOutput;
        }
        
        else {
            
            cipherOutput = c + rshift - 26;    // run loop as long as string length
            return cipherOutput;
        }
    }
    
    // non letter
    else {
        
        return c;
    }
}

char shiftCharD(char c, int lshift) {
    
    char cipherOutput;
    
    // capital letters
    if (c >= 65 && c <= 90) {
        
        if (c - lshift >= 65) {
            
            cipherOutput = c - lshift;
            return cipherOutput;
        }
        
        else {
            
            cipherOutput = c - lshift + 26;
            return cipherOutput;
        }
    }
    
    // lower case letters
    else if (c >= 97 && c <= 122) {
        
        if (c - lshift >= 97) {
            
            cipherOutput = c - lshift;
            return cipherOutput;
        }
        
        else {
            
            cipherOutput = c - lshift + 26;    // run loop as long as string length
            return cipherOutput;
        }
    }
    
    // non letter
    else {
        
        return c;
    }
}

string encryptCaesar(string userLine, int rshift) {
    
    string getCaesar = "";
    
    // run loop as long as string length
    for (int i = 0; i < userLine.length(); i++) {
        
        getCaesar += shiftChar(userLine[i], rshift); // store code
    }
    return getCaesar;
}

string decryptCaesar(string userLine, int lshift) {

    string getCaesar = "";

    // run loop as long as string length
    for (int i = 0; i < userLine.length(); i++) {
        
        getCaesar += shiftCharD(userLine[i], lshift); // store code
    }
    return getCaesar;
}

string encryptVigenere(string userStr, string codeWord) {
    
    int jCount = 0;
    int jValue = (int)codeWord[0] - 97;
    string storeEncrypt = "";
    
    for (int i = 0; i < userStr.length(); i++) {
        
        // capital letters
        if (userStr[i] >= 65 && userStr[i] <= 90) {
            
            if (userStr[i] + jValue <= 90) {
                
                storeEncrypt += userStr[i] + jValue;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
            
            else {
                
                storeEncrypt += userStr[i] + jValue - 26;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
        }
        
        // lower case letters
        else if (userStr[i] >= 97 && userStr[i] <= 122) {
            
            if (userStr[i] + jValue <= 122) {
                
                storeEncrypt += userStr[i] + jValue;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
            
            else {
                
                storeEncrypt += userStr[i] + jValue - 26;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
        }
        
        // non letter; store original value; no incrementation
        else {
            
            storeEncrypt += userStr[i];
            
            // jCount value not allowed to exceed length of string
            if (jCount <= codeWord.length() - 1) {
                
                jValue = codeWord[jCount] - 97;
            }
            else {
                
                jCount = 0;
                jValue = codeWord[jCount] - 97;
            }
        }
    }
    return storeEncrypt;                                    // return encrypted word
}

string decryptVigenere(string userStr, string codeWord) {

    int jCount = 0;
    int jValue = (int)codeWord[0] - 97;
    string storeEncrypt = "";

    for (int i = 0; i < userStr.length(); i++) {
        
        // capital letters
        if (userStr[i] >= 65 && userStr[i] <= 90) {
            
            if (userStr[i] - jValue >= 65) {
                
                storeEncrypt += userStr[i] - jValue;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
            
            else {
                
                storeEncrypt += userStr[i] - jValue + 26;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
        }
        
        // lower case letters
        else if (userStr[i] >= 97 && userStr[i] <= 122) {
            
            if (userStr[i] - jValue >= 97) {
                
                storeEncrypt += userStr[i] - jValue;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
            
            else {
                
                storeEncrypt += userStr[i] - jValue + 26;
                jCount++;
                
                // jCount value not allowed to exceed length of string
                if (jCount <= codeWord.length() - 1) {
                    
                    jValue = codeWord[jCount] - 97;
                }
                else {
                    
                    jCount = 0;
                    jValue = codeWord[jCount] - 97;
                }
            }
        }
        
        // non letter; store original value; no incrementation
        else {
            
            storeEncrypt += userStr[i];
            
            // jCount value not allowed to exceed length of string
            if (jCount <= codeWord.length() - 1) {
                
                jValue = codeWord[jCount] - 97;
            }
            else {
                
                jCount = 0;
                jValue = codeWord[jCount] - 97;
            }
        }
    }
    return storeEncrypt;                                    // return encrypted word
}