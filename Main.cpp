#include <iostream>
#include <string>
using namespace std;

// =========================
// Завдання 1. Клас VectorLong
// =========================
class VectorLong {
private:
    long* data;
    int size;
    int codeError;

public:
    // Конструктор без параметрів
    VectorLong() {
        size = 1;
        data = new long[size];
        data[0] = 0;
        codeError = 0;
    }

    // Конструктор з одним параметром
    VectorLong(int n) {
        if (n <= 0) {
            size = 1;
            data = new long[size];
            data[0] = 0;
            codeError = 1;
        } else {
            size = n;
            data = new long[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
            codeError = 0;
        }
    }

    // Конструктор з двома параметрами
    VectorLong(int n, long value) {
        if (n <= 0) {
            size = 1;
            data = new long[size];
            data[0] = value;
            codeError = 1;
        } else {
            size = n;
            data = new long[size];
            for (int i = 0; i < size; i++) {
                data[i] = value;
            }
            codeError = 0;
        }
    }

    // Конструктор копіювання
    VectorLong(const VectorLong& other) {
        size = other.size;
        codeError = other.codeError;
        data = new long[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Оператор присвоєння
    VectorLong& operator=(const VectorLong& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            codeError = other.codeError;
            data = new long[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~VectorLong() {
        delete[] data;
    }

    // Префіксний ++
    VectorLong& operator++() {
        for (int i = 0; i < size; i++) {
            ++data[i];
        }
        return *this;
    }

    // Постфіксний ++
    VectorLong operator++(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++) {
            data[i]++;
        }
        return temp;
    }

    // Префіксний --
    VectorLong& operator--() {
        for (int i = 0; i < size; i++) {
            --data[i];
        }
        return *this;
    }

    // Постфіксний --
    VectorLong operator--(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++) {
            data[i]--;
        }
        return temp;
    }

    // Логічне !
    bool operator!() const {
        return (size != 0);
    }

    void print() const {
        cout << "Vector: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    int getCodeError() const {
        return codeError;
    }
};

// =========================
// Завдання 2.5. Email <-> ПІБ
// =========================
class PersonEmailMap {
private:
    struct Entry {
        string email;
        string fullName;
    };

    Entry* data;
    int size;
    int CodeError;

public:
    // Конструктор без параметрів
    PersonEmailMap() {
        data = nullptr;
        size = 0;
        CodeError = 0;
    }

    // Конструктор з параметром
    PersonEmailMap(int n) {
        if (n > 0) {
            size = n;
            data = new Entry[size];
            CodeError = 0;
        } else {
            size = 0;
            data = nullptr;
            CodeError = 1;
        }
    }

    // Конструктор копіювання
    PersonEmailMap(const PersonEmailMap& other) {
        size = other.size;
        CodeError = other.CodeError;

        if (size > 0) {
            data = new Entry[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }

    // Оператор присвоєння
    PersonEmailMap& operator=(const PersonEmailMap& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            CodeError = other.CodeError;

            if (size > 0) {
                data = new Entry[size];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Деструктор
    ~PersonEmailMap() {
        delete[] data;
    }

    // Створення набору асоціативних сутностей
    void createSet() {
        int n;
        cout << "Enter number of entries: ";
        cin >> n;
        cin.ignore();

        delete[] data;

        if (n <= 0) {
            size = 0;
            data = nullptr;
            CodeError = 1;
            return;
        }

        size = n;
        data = new Entry[size];

        for (int i = 0; i < size; i++) {
            cout << "\nEntry #" << i + 1 << endl;
            cout << "Enter email: ";
            getline(cin, data[i].email);
            cout << "Enter surname, name, patronymic: ";
            getline(cin, data[i].fullName);
        }

        CodeError = 0;
    }

    // Індексація []
    string operator[](const string& email) {
        for (int i = 0; i < size; i++) {
            if (data[i].email == email) {
                CodeError = 0;
                return data[i].fullName;
            }
        }
        CodeError = 1;
        return "Not found";
    }

    // Альтернативний доступ через ()
    string operator()(const string& email) {
        for (int i = 0; i < size; i++) {
            if (data[i].email == email) {
                CodeError = 0;
                return data[i].fullName;
            }
        }
        CodeError = 1;
        return "Not found";
    }

    int getCodeError() const {
        return CodeError;
    }

    // Дружні оператори
    friend istream& operator>>(istream& in, PersonEmailMap& obj);
    friend ostream& operator<<(ostream& out, const PersonEmailMap& obj);
};

// Дружній оператор введення
istream& operator>>(istream& in, PersonEmailMap& obj) {
    int n;
    cout << "Enter number of entries: ";
    in >> n;
    in.ignore();

    delete[] obj.data;

    if (n <= 0) {
        obj.size = 0;
        obj.data = nullptr;
        obj.CodeError = 1;
        return in;
    }

    obj.size = n;
    obj.data = new PersonEmailMap::Entry[obj.size];

    for (int i = 0; i < obj.size; i++) {
        cout << "\nEntry #" << i + 1 << endl;
        cout << "Enter email: ";
        getline(in, obj.data[i].email);
        cout << "Enter surname, name, patronymic: ";
        getline(in, obj.data[i].fullName);
    }

    obj.CodeError = 0;
    return in;
}

// Дружній оператор виведення
ostream& operator<<(ostream& out, const PersonEmailMap& obj) {
    out << "\nAssociative array:\n";
    if (obj.size == 0) {
        out << "Array is empty.\n";
    } else {
        for (int i = 0; i < obj.size; i++) {
            out << obj.data[i].email << " -> " << obj.data[i].fullName << endl;
        }
    }
    return out;
}

// =========================
// Заготовка для Завдання 3
// =========================
void task3Placeholder() {
    cout << "\n===== TASK 3 =====\n";
    cout << "Place for Task 3 code.\n";
    cout << "Here you will add class/functions/menu for task 3.\n";
}

// =========================
// Меню для Завдання 1
// =========================
void menuTask1() {
    int choice;

    do {
        cout << "\n===== TASK 1. VectorLong =====\n";
        cout << "1. Create vector (default constructor)\n";
        cout << "2. Create vector (size)\n";
        cout << "3. Create vector (size + value)\n";
        cout << "4. Test prefix/postfix ++ and --\n";
        cout << "5. Test operator !\n";
        cout << "0. Back to main menu\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                VectorLong v;
                v.print();
                cout << "CodeError = " << v.getCodeError() << endl;
                break;
            }

            case 2: {
                int n;
                cout << "Enter size: ";
                cin >> n;
                VectorLong v(n);
                v.print();
                cout << "CodeError = " << v.getCodeError() << endl;
                break;
            }

            case 3: {
                int n;
                long value;
                cout << "Enter size: ";
                cin >> n;
                cout << "Enter initial value: ";
                cin >> value;
                VectorLong v(n, value);
                v.print();
                cout << "CodeError = " << v.getCodeError() << endl;
                break;
            }

            case 4: {
                int n;
                long value;
                cout << "Enter size: ";
                cin >> n;
                cout << "Enter initial value: ";
                cin >> value;

                VectorLong v(n, value);
                cout << "Original: ";
                v.print();

                ++v;
                cout << "After prefix ++: ";
                v.print();

                v++;
                cout << "After postfix ++: ";
                v.print();

                --v;
                cout << "After prefix --: ";
                v.print();

                v--;
                cout << "After postfix --: ";
                v.print();
                break;
            }

            case 5: {
                int n;
                cout << "Enter size: ";
                cin >> n;
                VectorLong v(n);

                if (!v) {
                    cout << "Result of !v = true\n";
                    cout << "Size is not equal to zero.\n";
                } else {
                    cout << "Result of !v = false\n";
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

// =========================
// Меню для Завдання 2
// =========================
void menuTask2() {
    PersonEmailMap directory;
    int choice;
    string email;

    do {
        cout << "\n===== TASK 2.5. PersonEmailMap =====\n";
        cout << "1. Create set using function createSet()\n";
        cout << "2. Create set using operator >>\n";
        cout << "3. Show all entries using operator <<\n";
        cout << "4. Search by email using operator []\n";
        cout << "5. Search by email using operator ()\n";
        cout << "0. Back to main menu\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                directory.createSet();
                break;

            case 2:
                cin >> directory;
                break;

            case 3:
                cout << directory;
                break;

            case 4:
                cout << "Enter email to search: ";
                getline(cin, email);
                cout << "Result: " << directory[email] << endl;
                cout << "CodeError = " << directory.getCodeError() << endl;
                break;

            case 5:
                cout << "Enter email to search: ";
                getline(cin, email);
                cout << "Result: " << directory(email) << endl;
                cout << "CodeError = " << directory.getCodeError() << endl;
                break;

            case 0:
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

// =========================
// Головне меню
// =========================
int main() {
    int choice;

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Task 1 - VectorLong\n";
        cout << "2. Task 2.5 - Email and Full Name associative class\n";
        cout << "3. Task 3 - Placeholder\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuTask1();
                break;

            case 2:
                menuTask2();
                break;

            case 3:
                task3Placeholder();
                break;

            case 0:
                cout << "Exit...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}