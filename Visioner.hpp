#pragma once
#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;

/*
In main
SetConsoleCP(1251);
SetConsoleOutputCP(1251)

Шифр вижинера
Vigenere cipher
*/

namespace Visioner {
    struct Alphabet {
        int first_cha;
        int last_cha;
        int character_count;
    };

    Alphabet init_alphabet(int first_cha = 32, int last_cha = 120, int character_count = 95) {
        Alphabet ret;
        ret.first_cha = first_cha;
        ret.last_cha = last_cha;
        ret.character_count = character_count;
        return ret;
    }

    string Visioner_coding(Alphabet alphabet, string message, string key) {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        string preparedKey = key;

        while (preparedKey.size() < message.size()) {
            preparedKey += key;
        }
        preparedKey = preparedKey.substr(0, message.size());

        string encryptedText;
        for (int i = 0; i < message.size(); i++) {
            int strCode = static_cast<int>(message[i]) + static_cast<int>(preparedKey[i]) - alphabet.first_cha;
            strCode = (strCode - alphabet.first_cha) % alphabet.character_count + alphabet.first_cha;
            encryptedText += static_cast<char>(strCode);
        }
        return encryptedText;
    }

    string Visioner_decoding(Alphabet alphabet, string message, string key) {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        string preparedKey = key;
   
        while (preparedKey.size() < message.size()) {
            preparedKey += key;
        }
        preparedKey = preparedKey.substr(0, message.size());

        string decryptedText;
        for (int i = 0; i < message.size(); i++) {
            int strCode = static_cast<int>(message[i]) - static_cast<int>(preparedKey[i]) + alphabet.first_cha;
            strCode = (strCode - alphabet.first_cha + alphabet.character_count) % alphabet.character_count + alphabet.first_cha;
            decryptedText += static_cast<char>(strCode);
        }

        return decryptedText;
    }
}