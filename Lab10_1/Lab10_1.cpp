#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;

enum Speciality { KN, IT, ME, FI, TN };
string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

enum Kurs { I = 1, II, III, IV, V, VI };

struct Student {
    string prizv;
    Kurs kurs;
    Speciality speciality;
    int markPhysics;
    int markMathematics;
    union {
        int markProgramming;
        int markNumericalMethods;
        int markPedagogy;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void VidminnikiSearch(Student* p, const int N);
void NeVidminnikiSearch(Student* p, const int N);

int main() {
    // забезпечення відображення кирилиці:
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть N: "; cin >> N;

    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    VidminnikiSearch(p, N);
    NeVidminnikiSearch(p, N);

    delete[] p; // звільнення пам'яті
    return 0;
}

void Create(Student* p, const int N) {
    int speciality;
    int kurs;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> kurs;
        p[i].kurs = (Kurs)kurs;
        cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> speciality;
        p[i].speciality = (Speciality)speciality;
        cout << " Оцінка з фізики: "; cin >> p[i].markPhysics;
        cout << " Оцінка з математики: "; cin >> p[i].markMathematics;

        switch (p[i].speciality) {
        case KN:
            cout << " Оцінка з програмування: "; cin >> p[i].markProgramming;
            break;
        case IT:
            cout << " Оцінка з чисельних методів: "; cin >> p[i].markNumericalMethods;
            break;
        case ME:
        case FI:
        case TN:
            cout << " Оцінка з педагогіки: "; cin >> p[i].markPedagogy;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N) {
    cout << "=========================================================================================" << endl;
    cout << "| № | Прізвище      | Курс | Спеціальність            | Фізика | Математика |Інша оцінка|" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << " "
            << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(25) << left << specialityStr[p[i].speciality]
            << "| " << setw(6) << p[i].markPhysics << " "
            << "| " << setw(10) << p[i].markMathematics << " ";

        switch (p[i].speciality) {
        case KN:
            cout << "| " << setw(9) << p[i].markProgramming << " |" << endl;
            break;
        case IT:
            cout << "| " << setw(9) << p[i].markNumericalMethods << " |" << endl;
            break;
        case ME:
        case FI:
        case TN:
            cout << "| " << setw(9) << p[i].markPedagogy << " |" << endl;
            break;
        }
    }
    cout << "=========================================================================================" << endl;
    cout << endl;
}

void VidminnikiSearch(Student* p, const int N)
{
    cout << "Прізвища відмінників:" << endl;
    for (int i = 0; i < N; i++)
    {
        
        if (p[i].markPhysics > 3 && p[i].markMathematics > 3)
        {
            if(p[i].speciality == KN && p[i].markProgramming > 3)
                cout << p[i].prizv << endl;
            else if(p[i].speciality == IT && p[i].markNumericalMethods > 3)
                cout << p[i].prizv << endl;
            else if((p[i].speciality == ME || p[i].speciality == FI || p[i].speciality == TN) && p[i].markPedagogy > 3)
                cout << p[i].prizv << endl;
        }
    }
}

void NeVidminnikiSearch(Student* p, const int N) {
    cout << "Прізвища відмінників:" << endl;
    for (int i = 0; i < N; i++)
    {
        double avr = p[i].markPhysics + p[i].markMathematics;
        if (p[i].speciality == KN)
            avr += p[i].markProgramming;
        else if (p[i].speciality == IT)
            avr += p[i].markNumericalMethods;
        else if (p[i].speciality == ME || p[i].speciality == FI || p[i].speciality == TN)
            avr += p[i].markPedagogy;

        avr = avr / 3;

        if (avr < 4)
            cout << p[i].prizv << endl;
    }
}
