#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
int main()
{
    SetConsoleTitleA("WordLearner");
    string array[1000];
    short loop = 0;
    string line;
    ifstream myfile("words.txt");
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "WordLearner" << endl;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, line);
            array[loop] = line;
            //cout << array[loop] << endl;
            loop++;
        }
        myfile.close();
        //początek pętli
        int random;
        int half = loop / 2;
        string text;
        srand(time(NULL));
        while (1)
        {
            random = (rand() % half) * 2;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
            cout << array[random] << ": " << endl;
            getline(cin >> ws, text);
            if (text == array[random + 1])
            {
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "Poprawna odpowiedz!" << endl;
            }
            if (text != array[random + 1])
            {
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << "Zla odpowiedz! Poprawna odpowiedz to: " << array[random + 1] << endl;
            }

        }
    }
    else
    {
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Nie znaleziono pliku words.txt!" << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
        system("pause");
        system("exit");
    }
	//Autor: Kamil Błaszkiewicz
    return 0;
}