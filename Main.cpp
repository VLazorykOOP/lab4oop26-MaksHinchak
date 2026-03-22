#include <iostream>
using namespace std;

class VectorLong {
private:
    long* data;      // вказівник на масив
    int size;        // кількість елементів
    int codeError;   // стан помилки

public:
    VectorLong() {
        size = 1;
        data = new long[size];
        data[0] = 0;
        codeError = 0;
    }

    VectorLong(int n) {
        size = n;
        data = new long[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
        codeError = 0;
    }

    VectorLong(int n, long value) {
        size = n;
        data = new long[size];
        for (int i = 0; i < size; i++)
            data[i] = value;
        codeError = 0;
    }

    VectorLong(const VectorLong& other) {
        size = other.size;
        data = new long[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
        codeError = other.codeError;
    }

    ~VectorLong() {
        delete[] data;
    }

    VectorLong& operator++() {
        for (int i = 0; i < size; i++)
            ++data[i];
        return *this;
    }

    VectorLong operator++(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++)
            data[i]++;
        return temp;
    }

    VectorLong& operator--() {
        for (int i = 0; i < size; i++)
            --data[i];
        return *this;
    }

    VectorLong operator--(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++)
            data[i]--;
        return temp;
    }

    bool operator!() const {
        return (size != 0);
    }

    void print() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Create vector (default)\n";
        cout << "2. Create vector (size)\n";
        cout << "3. Create vector (size + value)\n";
        cout << "4. Test ++ and --\n";
        cout << "5. Test ! operator\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                VectorLong v;
                cout << "Vector: ";
                v.print();
                break;
            }

            case 2: {
                int n;
                cout << "Enter size: ";
                cin >> n;
                VectorLong v(n);
                cout << "Vector: ";
                v.print();
                break;
            }

            case 3: {
                int n;
                long val;
                cout << "Enter size: ";
                cin >> n;
                cout << "Enter value: ";
                cin >> val;
                VectorLong v(n, val);
                cout << "Vector: ";
                v.print();
                break;
            }

            case 4: {
                VectorLong v(5, 1);
                cout << "Original: ";
                v.print();

                ++v;
                cout << "After ++: ";
                v.print();

                v--;
                cout << "After --: ";
                v.print();
                break;
            }

            case 5: {
                VectorLong v(3);
                if (!v)
                    cout << "Vector is NOT empty\n";
                else
                    cout << "Vector is empty\n";
                break;
            }

            case 0:
                cout << "Exit...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}