#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class matrica {
    T** Mas;
    int We, He;
public:
    void showM();
    matrica();
    matrica(int High, int Wide);
    ~matrica();
    void firstMethod();
    void secondMethod();
    matrica(matrica& object);
};
template<typename T>
matrica<T>::~matrica() {
    delete[]Mas;
}
template<typename T>
void matrica<T>::firstMethod() {
    double sum = 0, pr = 1;
    int counter = 0;
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            if (Mas[i][j] >= 0) {
                counter++;
                sum += Mas[i][j];
                pr *= Mas[i][j];
            }
        }
    }
    if (counter != 0) {
        cout << "Sum positive elements = " << sum << endl;
        cout << "Pr positive elements = " << pr << endl;
    }
    else {
        cout << "Sum and pr positive is not found" << endl;
    }
}

template<typename T>
void matrica<T>::secondMethod() {
    double sum = 0, pr = 1;
    int nech = 0, Nech = 0, counter = 0;
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                counter++;
                sum += Mas[i][j];
                pr *= Mas[i][j];
            }
        }
    }
    if (counter != 0 && counter != 1) {
        cout << "Sum unevel positions = " << sum << endl;
        cout << "Pr unevel positions = " << pr << endl;
    }
    else {
        cout << "Sum and pr unevel positions is not found" << endl;
    }
}
template<typename T>
matrica<T>::matrica(matrica& object) {
    We = object.We;
    He = object.He;
    T** Mas;
    Mas = new T * [We];
    for (int i = 0; i < We; i++) {
        Mas[i] = new T[He];
    }
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            Mas[i][j] = object.Mas[i][j];
        }
    }
}
template<typename T>
matrica<T>::matrica(int High, int Wide) {
    We = Wide;
    He = High;
    Mas = new T * [We];
    for (int i = 0; i < We; i++) {
        Mas[i] = new T[He];
    }
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            cout << "Input [" << i << "][" << j << "] element: ";
            cin >> Mas[i][j];
        }
    }
}
ostream& manip_name(ostream& stream) {
    cout << setiosflags(ios::left) << setw(8) << setfill(' ');
    return stream;
}
template<typename T>
matrica<T>::matrica() {
    cout << "Input rows: ";
    cin >> We;
    while (cin.fail() || We <= 0) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Please, enter correct row. Size matrix is positive digit!" << endl;
        cout << "Input rows: ";
        cin >> We;
    }
    cout << "Input columns: ";
    cin >> He;
    while (cin.fail() || He <= 0) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Please, enter correct column. Size matrix is positive digit!" << endl;
        cout << "Input columns: ";
        cin >> He;
    }
    Mas = new T * [We];
    for (int i = 0; i < We; i++) {
        Mas[i] = new T[He];
    }
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            cout << "Input [" << i << "][" << j << "] element: ";
            cin >> Mas[i][j];
            while (cin.fail()) {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Please, enter correct elements. Your matrix must consists from elements!" << endl;
                cout << "Input [" << i << "][" << j << "] element: ";
                cin >> Mas[i][j];
            }
        }
    }
}
template<typename T>
void matrica<T>::showM() {
    cout << endl;
    cout << "Showing array:" << endl;
    for (int i = 0; i < We; i++) {
        for (int j = 0; j < He; j++) {
            cout << Mas[i][j] << manip_name << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "RUS");
    matrica<double> mat;
    mat.showM();
    mat.firstMethod();
    mat.secondMethod();
    return 0;
}
