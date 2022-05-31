#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>


using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student
{
    char lname[100];
    int kurs;
    Spec spec;
    int physics;
    int math;
    int progr;
};


void print(string name);    //����
void create(string name);   //���
void print2(string name);   //���� ���, � ���� ������ 5 ��� 4
bool check(Student a);      //�������� �� ��������
double amount();            //������� ��������

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    bool e;

    cout << "Load(0)  Create(1)"; cin >> e; //����

    if (e) {
        create("File.txt");
    }

    print("File.txt");
    print2("File.txt");
    cout << "Percent: " << amount();
}

void print(string name) {
    ifstream f(name, ios::binary);
    Student s;
    int i = 0;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {
        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s.lname;
        cout << "| " << setw(5) << right << s.kurs;
        cout << "| " << setw(23) << left << strSpec[s.spec]; ;//strSpec[s[i].spec]
        cout << "| " << setw(7) << s.physics;
        cout << "| " << setw(11) << right << s.math;

        cout << "| " << setw(14) << right << s.progr
            << "| ";
        cout << endl;
        f.read((char*)&s, sizeof(s));
        i++;
    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << endl;



}

void create(string name) {
    ofstream f(name, ios::binary | ios::trunc | ios::out);
    int Wn;
    Student s;
    int sp;

    cout << "n: "; cin >> Wn;

    for (int i = 0; i < Wn; i++) {
        cout << "Student " << i + 1 << endl;

        cout << "Name: "; cin >> s.lname;

        cout << "Curs: "; cin >> s.kurs;

        cout << "Spec: "; cin >> sp; s.spec = (Spec)sp;

        cout << "Fis: "; cin >> s.physics;

        cout << "Math: "; cin >> s.math;

        cout << "Prog: "; cin >> s.progr;
        f.write((char*)&s, sizeof(s));
    }
}

void print2(string name) {

    ifstream f(name, ios::binary);
    Student s;
    int i = 0;

    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {

        i++;
        if (s.physics > 3) {
            cout << "| " << setw(2) << right << i << "";

            cout << "| " << setw(14) << left << s.lname;

            cout << "| " << setw(5) << right << s.kurs;

            cout << "| " << setw(23) << left << strSpec[s.spec]; ;

            cout << "| " << setw(7) << s.physics;

            cout << "| " << setw(11) << right << s.math;

            cout << "| " << setw(14) << right << s.progr
                << "| ";
            cout << endl;
        }
        f.read((char*)&s, sizeof(s));

    }
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << endl;



}

bool check(Student a) {
    if (a.math > 3 && a.physics > 3 && a.progr > 3) {
        return true;
    }
    else {
        return false;
    }


}

double amount() {
    ifstream f("File.txt", ios::binary);
    Student s;
    int k = 0;
    double w = 0;
    f.read((char*)&s, sizeof(s));
    while (!f.eof()) {
        if (check(s)) {
            k++;
        }
        w++;
        f.read((char*)&s, sizeof(s));
    }
    return (double)k / w;
}
