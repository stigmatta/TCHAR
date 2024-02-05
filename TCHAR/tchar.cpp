#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE
#include <iostream>
#include <tchar.h>
using namespace std;

void changeSpacesOnTabulations(_TCHAR str[]) {
    for (int i = 0; i < _tcslen(str); i++) {
        if (str[i] == ' ')
            str[i] = '\t';
    }
}

void countSymbols(_TCHAR str[]) {
    unsigned int letters=0, digits=0, other = 0;
    for (int i = 0; i < _tcslen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            letters++;
        else if (str[i] >= '0' && str[i] <= '9')
            digits++;
        else
            other++;
    }
    cout << "Letters: " << letters<<"\n";
    cout << "Digits: " << digits << "\n";
    cout << "Other: " << other << "\n";
}

void countWords(_TCHAR str[]) {
    unsigned int words = 0;
    for (int i = 0; i < _tcslen(str); i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9') && (str[i + 1] >= 'a' && str[i + 1] <= 'z' || str[i + 1] >= 'A' && str[i + 1] <= 'Z' || str[i + 1] >= '0' && str[i + 1] <= '9'))
            words++;
    }
    cout << "Words: "<< words<<"\n";
}

void countVowels(_TCHAR str[]) {
    unsigned int vowels = 0;
    for (int i = 0; i < _tcslen(str); i++) {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U' || str[i] == 'e' || str[i] == 'E' || str[i] == 'y' || str[i] == 'Y')
            vowels++;
    }
    cout << "Vowels: " << vowels << endl;
}

bool isPalindrome(_TCHAR str[]) {
    bool breakdown = 1;
    for (int i = 0,j=_tcslen(str)-1; i < _tcslen(str) / 2; i++,j--) {
        if (str[i] == str[j])
            continue;
        else
        {
            breakdown = 0;
            break;
        }
    }
    return breakdown == 0 ? false : true;
}

_TCHAR* deleteSymbol(_TCHAR str[], int index) {
    if (_tcslen(str) != 0)
    {
        int newlen = _tcslen(str) - 1;
        int j = 0;
        _TCHAR* newstr = new _TCHAR[newlen];
        for (int i = 0; i < _tcslen(str); i++) {
            if (i == index)
                continue;
            else
                newstr[j++] = str[i];
        }
        newstr[j] = _T('\0');
        return newstr;
    }
    return NULL;
}

_TCHAR* deleteAllSymbolOccurences(_TCHAR str[], char symb) {
    unsigned int newlen = _tcslen(str);
    for (int i = 0; i < _tcslen(str); i++) {
        if (str[i] == symb)
            newlen--;
    }

    _TCHAR* newstr = new _TCHAR[newlen + 1];  
    int j = 0;
    for (int i = 0; i < _tcslen(str); i++) {
        if (str[i] != symb)
            newstr[j++] = str[i];
    }
    newstr[j] = _T('\0');  
    return newstr;
}

_TCHAR* insertASymbol(_TCHAR str[], char symb, int index) {
    _TCHAR* newstr = new _TCHAR[_tcslen(str) + 1];
    int j = 0;
    for (int i = 0; i < _tcslen(str)+1; i++) { //string strping
        if (i < index) 
            newstr[j++] = str[i];
        else if (i == index)
            newstr[j++] = symb;
        else
            newstr[j++] = str[i-1];
    }
    newstr[j] = _T('\0');
    return newstr;
}

void main()
{
    //1. Заменить пробелы в строке на табуляции
    _TCHAR str[50] = _TEXT("Hello hello hello hello");
    changeSpacesOnTabulations(str);
    wcout << str << '\n';

    //2. Подсчитать в строке количество букв, цифр и остальных символов
    _TCHAR str2[20] = _TEXT("Hello, world 12345");
    countSymbols(str2);

    //3. Подсчитать кол-во слов в предложении
    _TCHAR str3[30] = _TEXT("    Hello, world world");
    countWords(str3);

    //4. Подсчитать кол-во гласных букв (буду использовать латиницу)
    _TCHAR str4[50];
    wcin.getline(str4, 50);
    countVowels(str4);

    //5. Является ли строка палиндромом
    _TCHAR str5[50] = _TEXT("civic");
    cout << boolalpha << isPalindrome(str5) << endl;

    //6. Удалить символ по заданному индексу
    _TCHAR str6[50] = _TEXT("Hello, world");
    _TCHAR* newstr6 = deleteSymbol(str6, 3);
    wcout << newstr6 << endl;

    //7.Удалить из строки все вхождения заданного символа
    _TCHAR* newstr7 = deleteAllSymbolOccurences(str6, 'l');
    wcout << newstr7 << endl;

    //8. Вставить в строку символ по указанному индексу
    _TCHAR* newstr8 = insertASymbol(str6, 'l', 2);
    wcout << newstr8 << endl;
}


