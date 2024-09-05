/*
Name- David Boatright
Lab - Wed 7:00 - 9:30
*/
#include "Functions.h"
using namespace std;

int main()
{
    char choice = 'q';
    while (choice != 'f') {
        choice = displayMenuAndGetSelection();
        switch (choice) {
            case 'a':
                binToDec();
                break;
            case 'b':
                binToBase();
                break;
            case 'c':
                deciToBin();
                break;
            case 'd':
                baseToBin();
                break;
            case 'e':
                baseToBase();
                break;
        }
    }
}


