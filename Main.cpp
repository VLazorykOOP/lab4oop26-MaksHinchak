#include <iostream>
#include <string>
#include <new>
using namespace std;

// =====================================================
// TASK 1. VectorLong
// =====================================================
class VectorLong {
private:
    long* data;
    int size;
    int codeError;

public:
    VectorLong() {
        size = 1;
        data = new long[size];
        data[0] = 0;
        codeError = 0;
    }

    VectorLong(int n) {
        if (n <= 0) {
            size = 1;
            data = new long[size];
            data[0] = 0;
            codeError = 1;
        } else {
            size = n;
            data = new long[size];
            for (int i = 0; i < size; i++) data[i] = 0;
            codeError = 0;
        }
    }

    VectorLong(int n, long value) {
        if (n <= 0) {
            size = 1;
            data = new long[size];
            data[0] = value;
            codeError = 1;
        } else {
            size = n;
            data = new long[size];
            for (int i = 0; i < size; i++) data[i] = value;
            codeError = 0;
        }
    }

    VectorLong(const VectorLong& other) {
        size = other.size;
        codeError = other.codeError;
        data = new long[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    VectorLong& operator=(const VectorLong& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            codeError = other.codeError;
            data = new long[size];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this;
    }

    ~VectorLong() {
        delete[] data;
    }

    VectorLong& operator++() {
        for (int i = 0; i < size; i++) ++data[i];
        return *this;
    }

    VectorLong operator++(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++) data[i]++;
        return temp;
    }

    VectorLong& operator--() {
        for (int i = 0; i < size; i++) --data[i];
        return *this;
    }

    VectorLong operator--(int) {
        VectorLong temp(*this);
        for (int i = 0; i < size; i++) data[i]--;
        return temp;
    }

    bool operator!() const {
        return (size != 0);
    }

    void print() const {
        cout << "Vector: ";
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }

    int getSize() const { return size; }
    int getCodeError() const { return codeError; }
};

// =====================================================
// TASK 2.5. PersonEmailMap
// =====================================================
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
    PersonEmailMap() {
        data = nullptr;
        size = 0;
        CodeError = 0;
    }

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

    PersonEmailMap(const PersonEmailMap& other) {
        size = other.size;
        CodeError = other.CodeError;
        if (size > 0) {
            data = new Entry[size];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        } else {
            data = nullptr;
        }
    }

    PersonEmailMap& operator=(const PersonEmailMap& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            CodeError = other.CodeError;
            if (size > 0) {
                data = new Entry[size];
                for (int i = 0; i < size; i++) data[i] = other.data[i];
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    ~PersonEmailMap() {
        delete[] data;
    }

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

    int getCodeError() const { return CodeError; }

    friend istream& operator>>(istream& in, PersonEmailMap& obj);
    friend ostream& operator<<(ostream& out, const PersonEmailMap& obj);
};

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

// =====================================================
// TASK 3. Vector3D
// =====================================================
class Vector3D {
private:
    int v[3];
    int codeError;

public:
    Vector3D() {
        v[0] = v[1] = v[2] = 0;
        codeError = 0;
    }

    Vector3D(int value) {
        v[0] = v[1] = v[2] = value;
        codeError = 0;
    }

    Vector3D(int x, int y, int z) {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        codeError = 0;
    }

    Vector3D(const Vector3D& other) {
        v[0] = other.v[0];
        v[1] = other.v[1];
        v[2] = other.v[2];
        codeError = other.codeError;
    }

    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            v[0] = other.v[0];
            v[1] = other.v[1];
            v[2] = other.v[2];
            codeError = other.codeError;
        }
        return *this;
    }

    ~Vector3D() {}

    int getCodeError() const { return codeError; }
    int getSize() const { return 3; }

    int& operator[](int index) {
        if (index < 0 || index >= 3) {
            codeError = 2;
            return v[2];
        }
        codeError = 0;
        return v[index];
    }

    const int& operator[](int index) const {
        return v[(index < 0 || index >= 3) ? 2 : index];
    }

    Vector3D& operator++() {
        for (int i = 0; i < 3; i++) ++v[i];
        return *this;
    }

    Vector3D operator++(int) {
        Vector3D temp(*this);
        for (int i = 0; i < 3; i++) v[i]++;
        return temp;
    }

    Vector3D& operator--() {
        for (int i = 0; i < 3; i++) --v[i];
        return *this;
    }

    Vector3D operator--(int) {
        Vector3D temp(*this);
        for (int i = 0; i < 3; i++) v[i]--;
        return temp;
    }

    bool operator!() const {
        return (getSize() != 0);
    }

    Vector3D operator-() const {
        return Vector3D(-v[0], -v[1], -v[2]);
    }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
    }

    Vector3D operator*(const Vector3D& other) const {
        return Vector3D(v[0] * other.v[0], v[1] * other.v[1], v[2] * other.v[2]);
    }

    Vector3D operator+(int s) const {
        return Vector3D(v[0] + s, v[1] + s, v[2] + s);
    }

    Vector3D operator+(double s) const {
        int t = (int)s;
        return Vector3D(v[0] + t, v[1] + t, v[2] + t);
    }

    Vector3D operator+(float s) const {
        int t = (int)s;
        return Vector3D(v[0] + t, v[1] + t, v[2] + t);
    }

    Vector3D operator-(int s) const {
        return Vector3D(v[0] - s, v[1] - s, v[2] - s);
    }

    Vector3D operator-(double s) const {
        int t = (int)s;
        return Vector3D(v[0] - t, v[1] - t, v[2] - t);
    }

    Vector3D operator-(float s) const {
        int t = (int)s;
        return Vector3D(v[0] - t, v[1] - t, v[2] - t);
    }

    Vector3D operator*(double s) const {
        int t = (int)s;
        return Vector3D(v[0] * t, v[1] * t, v[2] * t);
    }

    Vector3D operator*(float s) const {
        int t = (int)s;
        return Vector3D(v[0] * t, v[1] * t, v[2] * t);
    }

    Vector3D operator/(int s) const {
        if (s == 0) return *this;
        return Vector3D(v[0] / s, v[1] / s, v[2] / s);
    }

    Vector3D operator/(double s) const {
        int t = (int)s;
        if (t == 0) return *this;
        return Vector3D(v[0] / t, v[1] / t, v[2] / t);
    }

    Vector3D operator/(float s) const {
        int t = (int)s;
        if (t == 0) return *this;
        return Vector3D(v[0] / t, v[1] / t, v[2] / t);
    }

    Vector3D operator%(int s) const {
        if (s == 0) return *this;
        return Vector3D(v[0] % s, v[1] % s, v[2] % s);
    }

    Vector3D& operator+=(const Vector3D& other) {
        for (int i = 0; i < 3; i++) v[i] += other.v[i];
        return *this;
    }

    Vector3D& operator+=(double s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] += t;
        return *this;
    }

    Vector3D& operator+=(float s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] += t;
        return *this;
    }

    Vector3D& operator-=(const Vector3D& other) {
        for (int i = 0; i < 3; i++) v[i] -= other.v[i];
        return *this;
    }

    Vector3D& operator-=(double s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] -= t;
        return *this;
    }

    Vector3D& operator-=(float s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] -= t;
        return *this;
    }

    Vector3D& operator*=(const Vector3D& other) {
        for (int i = 0; i < 3; i++) v[i] *= other.v[i];
        return *this;
    }

    Vector3D& operator*=(double s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] *= t;
        return *this;
    }

    Vector3D& operator*=(float s) {
        int t = (int)s;
        for (int i = 0; i < 3; i++) v[i] *= t;
        return *this;
    }

    Vector3D& operator/=(double s) {
        int t = (int)s;
        if (t != 0) {
            for (int i = 0; i < 3; i++) v[i] /= t;
        }
        return *this;
    }

    Vector3D& operator/=(float s) {
        int t = (int)s;
        if (t != 0) {
            for (int i = 0; i < 3; i++) v[i] /= t;
        }
        return *this;
    }

    Vector3D& operator%=(int s) {
        if (s != 0) {
            for (int i = 0; i < 3; i++) v[i] %= s;
        }
        return *this;
    }

    bool operator==(const Vector3D& other) const {
        for (int i = 0; i < 3; i++) {
            if (v[i] != other.v[i]) return false;
        }
        return true;
    }

    bool operator!=(const Vector3D& other) const {
        return !(*this == other);
    }

    bool operator>(const Vector3D& other) const {
        for (int i = 0; i < 3; i++) {
            if (!(v[i] > other.v[i])) return false;
        }
        return true;
    }

    bool operator>=(const Vector3D& other) const {
        for (int i = 0; i < 3; i++) {
            if (!(v[i] >= other.v[i])) return false;
        }
        return true;
    }

    bool operator<(const Vector3D& other) const {
        for (int i = 0; i < 3; i++) {
            if (!(v[i] < other.v[i])) return false;
        }
        return true;
    }

    bool operator<=(const Vector3D& other) const {
        for (int i = 0; i < 3; i++) {
            if (!(v[i] <= other.v[i])) return false;
        }
        return true;
    }

    friend istream& operator>>(istream& in, Vector3D& vec);
    friend ostream& operator<<(ostream& out, const Vector3D& vec);
};

istream& operator>>(istream& in, Vector3D& vec) {
    in >> vec.v[0] >> vec.v[1] >> vec.v[2];
    vec.codeError = 0;
    return in;
}

ostream& operator<<(ostream& out, const Vector3D& vec) {
    out << "(" << vec.v[0] << ", " << vec.v[1] << ", " << vec.v[2] << ")";
    return out;
}

// =====================================================
// TASK 3. Matrix3D
// =====================================================
class Matrix3D {
protected:
    Vector3D* PointArray;
    int n;
    int codeError;
    static int num_matrix;

    void setMemoryError() { codeError = 1; }
    void setIndexError() { codeError = 2; }
    void setSizeError() { codeError = 3; }
    void setDivisionError() { codeError = 4; }

public:
    Matrix3D() {
        PointArray = nullptr;
        n = 0;
        codeError = 0;
        num_matrix++;
    }

    Matrix3D(int size) {
        n = size;
        codeError = 0;
        num_matrix++;

        if (n <= 0) {
            PointArray = nullptr;
            n = 0;
            return;
        }

        try {
            PointArray = new Vector3D[n];
        } catch (...) {
            PointArray = nullptr;
            n = 0;
            setMemoryError();
        }
    }

    Matrix3D(int size, int value) {
        n = size;
        codeError = 0;
        num_matrix++;

        if (n <= 0) {
            PointArray = nullptr;
            n = 0;
            return;
        }

        try {
            PointArray = new Vector3D[n];
            for (int i = 0; i < n; i++) PointArray[i] = Vector3D(value);
        } catch (...) {
            PointArray = nullptr;
            n = 0;
            setMemoryError();
        }
    }

    Matrix3D(int size, int x, int y, int z) {
        n = size;
        codeError = 0;
        num_matrix++;

        if (n <= 0) {
            PointArray = nullptr;
            n = 0;
            return;
        }

        try {
            PointArray = new Vector3D[n];
            for (int i = 0; i < n; i++) PointArray[i] = Vector3D(x, y, z);
        } catch (...) {
            PointArray = nullptr;
            n = 0;
            setMemoryError();
        }
    }

    Matrix3D(const Matrix3D& other) {
        n = other.n;
        codeError = other.codeError;
        num_matrix++;

        if (n > 0) {
            try {
                PointArray = new Vector3D[n];
                for (int i = 0; i < n; i++) PointArray[i] = other.PointArray[i];
            } catch (...) {
                PointArray = nullptr;
                n = 0;
                setMemoryError();
            }
        } else {
            PointArray = nullptr;
        }
    }

    ~Matrix3D() {
        delete[] PointArray;
        num_matrix--;
    }

    int getN() const { return n; }
    int getCodeError() const { return codeError; }
    static int getNumMatrix() { return num_matrix; }

    Matrix3D& operator=(const Matrix3D& other) {
        if (this != &other) {
            delete[] PointArray;
            n = other.n;
            codeError = other.codeError;

            if (n > 0) {
                try {
                    PointArray = new Vector3D[n];
                    for (int i = 0; i < n; i++) PointArray[i] = other.PointArray[i];
                } catch (...) {
                    PointArray = nullptr;
                    n = 0;
                    setMemoryError();
                }
            } else {
                PointArray = nullptr;
            }
        }
        return *this;
    }

    Matrix3D& operator++() {
        for (int i = 0; i < n; i++) ++PointArray[i];
        return *this;
    }

    Matrix3D operator++(int) {
        Matrix3D temp(*this);
        for (int i = 0; i < n; i++) PointArray[i]++;
        return temp;
    }

    Matrix3D& operator--() {
        for (int i = 0; i < n; i++) --PointArray[i];
        return *this;
    }

    Matrix3D operator--(int) {
        Matrix3D temp(*this);
        for (int i = 0; i < n; i++) PointArray[i]--;
        return temp;
    }

    bool operator!() const {
        return (n != 0 && (n > 0 ? PointArray[0].getSize() != 0 : false));
    }

    Matrix3D operator-() const {
        Matrix3D temp(*this);
        for (int i = 0; i < temp.n; i++) temp.PointArray[i] = -temp.PointArray[i];
        return temp;
    }

    Vector3D& operator[](int index) {
        static Vector3D dummy;
        if (n == 0 || PointArray == nullptr) {
            setIndexError();
            return dummy;
        }
        if (index < 0 || index >= n) {
            setIndexError();
            return PointArray[n - 1];
        }
        codeError = 0;
        return PointArray[index];
    }

    const Vector3D& operator[](int index) const {
        if (n == 0 || PointArray == nullptr) {
            static Vector3D dummy;
            return dummy;
        }
        return PointArray[(index < 0 || index >= n) ? (n - 1) : index];
    }

    int& operator()(int i, int j) {
        return (*this)[i][j];
    }

    const int& operator()(int i, int j) const {
        return (*this)[i][j];
    }

    Matrix3D operator+(const Matrix3D& other) const {
        Matrix3D res(*this);
        if (n != other.n) {
            res.setSizeError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] + other.PointArray[i];
        return res;
    }

    Matrix3D operator-(const Matrix3D& other) const {
        Matrix3D res(*this);
        if (n != other.n) {
            res.setSizeError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] - other.PointArray[i];
        return res;
    }

    Matrix3D operator*(const Matrix3D& other) const {
        Matrix3D res(*this);
        if (n != other.n) {
            res.setSizeError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] * other.PointArray[i];
        return res;
    }

    Matrix3D operator*(const Vector3D& vec) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] * vec;
        return res;
    }

    Matrix3D operator+(int s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] + s;
        return res;
    }

    Matrix3D operator+(double s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] + s;
        return res;
    }

    Matrix3D operator+(float s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] + s;
        return res;
    }

    Matrix3D operator-(int s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] - s;
        return res;
    }

    Matrix3D operator-(double s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] - s;
        return res;
    }

    Matrix3D operator-(float s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] - s;
        return res;
    }

    Matrix3D operator*(double s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] * s;
        return res;
    }

    Matrix3D operator*(float s) const {
        Matrix3D res(*this);
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] * s;
        return res;
    }

    Matrix3D operator/(int s) const {
        Matrix3D res(*this);
        if (s == 0) {
            res.setDivisionError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] / s;
        return res;
    }

    Matrix3D operator/(float s) const {
        Matrix3D res(*this);
        if ((int)s == 0) {
            res.setDivisionError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] / s;
        return res;
    }

    Matrix3D operator%(int s) const {
        Matrix3D res(*this);
        if (s == 0) {
            res.setDivisionError();
            return res;
        }
        for (int i = 0; i < n; i++) res.PointArray[i] = PointArray[i] % s;
        return res;
    }

    Matrix3D& operator+=(const Matrix3D& other) {
        if (n != other.n) {
            setSizeError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] += other.PointArray[i];
        codeError = 0;
        return *this;
    }

    Matrix3D& operator+=(double s) {
        for (int i = 0; i < n; i++) PointArray[i] += s;
        return *this;
    }

    Matrix3D& operator+=(float s) {
        for (int i = 0; i < n; i++) PointArray[i] += s;
        return *this;
    }

    Matrix3D& operator-=(const Matrix3D& other) {
        if (n != other.n) {
            setSizeError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] -= other.PointArray[i];
        codeError = 0;
        return *this;
    }

    Matrix3D& operator-=(double s) {
        for (int i = 0; i < n; i++) PointArray[i] -= s;
        return *this;
    }

    Matrix3D& operator-=(float s) {
        for (int i = 0; i < n; i++) PointArray[i] -= s;
        return *this;
    }

    Matrix3D& operator*=(const Matrix3D& other) {
        if (n != other.n) {
            setSizeError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] *= other.PointArray[i];
        codeError = 0;
        return *this;
    }

    Matrix3D& operator*=(const Vector3D& vec) {
        for (int i = 0; i < n; i++) PointArray[i] *= vec;
        return *this;
    }

    Matrix3D& operator*=(double s) {
        for (int i = 0; i < n; i++) PointArray[i] *= s;
        return *this;
    }

    Matrix3D& operator*=(float s) {
        for (int i = 0; i < n; i++) PointArray[i] *= s;
        return *this;
    }

    Matrix3D& operator/=(double s) {
        if ((int)s == 0) {
            setDivisionError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] /= s;
        codeError = 0;
        return *this;
    }

    Matrix3D& operator/=(float s) {
        if ((int)s == 0) {
            setDivisionError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] /= s;
        codeError = 0;
        return *this;
    }

    Matrix3D& operator%=(int s) {
        if (s == 0) {
            setDivisionError();
            return *this;
        }
        for (int i = 0; i < n; i++) PointArray[i] %= s;
        codeError = 0;
        return *this;
    }

    bool operator==(const Matrix3D& other) const {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++) {
            if (!(PointArray[i] == other.PointArray[i])) return false;
        }
        return true;
    }

    bool operator!=(const Matrix3D& other) const {
        return !(*this == other);
    }

    bool operator>(const Matrix3D& other) const {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++) {
            if (!(PointArray[i] > other.PointArray[i])) return false;
        }
        return true;
    }

    bool operator>=(const Matrix3D& other) const {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++) {
            if (!(PointArray[i] >= other.PointArray[i])) return false;
        }
        return true;
    }

    bool operator<(const Matrix3D& other) const {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++) {
            if (!(PointArray[i] < other.PointArray[i])) return false;
        }
        return true;
    }

    bool operator<=(const Matrix3D& other) const {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++) {
            if (!(PointArray[i] <= other.PointArray[i])) return false;
        }
        return true;
    }

    static void* operator new(size_t size) {
        void* p = ::operator new(size);
        return p;
    }

    static void operator delete(void* p) {
        ::operator delete(p);
    }

    static void* operator new[](size_t size) {
        void* p = ::operator new[](size);
        return p;
    }

    static void operator delete[](void* p) {
        ::operator delete[](p);
    }

    friend istream& operator>>(istream& in, Matrix3D& m);
    friend ostream& operator<<(ostream& out, const Matrix3D& m);
};

int Matrix3D::num_matrix = 0;

istream& operator>>(istream& in, Matrix3D& m) {
    int size;
    cout << "Enter number of rows n: ";
    in >> size;

    delete[] m.PointArray;
    m.PointArray = nullptr;
    m.n = 0;
    m.codeError = 0;

    if (size <= 0) return in;

    m.n = size;
    try {
        m.PointArray = new Vector3D[m.n];
        cout << "Enter " << m.n << " vectors (x y z):\n";
        for (int i = 0; i < m.n; i++) {
            cout << "Row " << i << ": ";
            in >> m.PointArray[i];
        }
    } catch (...) {
        m.PointArray = nullptr;
        m.n = 0;
        m.codeError = 1;
    }

    return in;
}

ostream& operator<<(ostream& out, const Matrix3D& m) {
    out << "Matrix3D (" << m.n << " x 3)\n";
    for (int i = 0; i < m.n; i++) {
        out << "[" << i << "] " << m.PointArray[i] << "\n";
    }
    return out;
}

// =====================================================
// MENUS
// =====================================================
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

                if (!v) cout << "Result of !v = true\n";
                else cout << "Result of !v = false\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

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

void menuTask3() {
    int choice;

    do {
        cout << "\n===== TASK 3. Matrix3D =====\n";
        cout << "1. Default constructor\n";
        cout << "2. Constructor Matrix3D(n)\n";
        cout << "3. Constructor Matrix3D(n, value)\n";
        cout << "4. Constructor Matrix3D(n, x, y, z)\n";
        cout << "5. Input matrix and output it\n";
        cout << "6. Test ++ and --\n";
        cout << "7. Test unary ! and unary -\n";
        cout << "8. Test matrix + matrix and matrix - matrix\n";
        cout << "9. Test matrix * matrix\n";
        cout << "10. Test matrix + scalar / - scalar / * scalar / / scalar / % scalar\n";
        cout << "11. Test +=, -=, *=, /=, %=\n";
        cout << "12. Test comparisons == != > >= < <=\n";
        cout << "13. Test operator[]\n";
        cout << "14. Test operator()\n";
        cout << "15. Show number of Matrix3D objects\n";
        cout << "0. Back to main menu\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Matrix3D m;
                cout << m;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 2: {
                int n;
                cout << "Enter n: ";
                cin >> n;
                Matrix3D m(n);
                cout << m;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 3: {
                int n, val;
                cout << "Enter n and value: ";
                cin >> n >> val;
                Matrix3D m(n, val);
                cout << m;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 4: {
                int n, x, y, z;
                cout << "Enter n x y z: ";
                cin >> n >> x >> y >> z;
                Matrix3D m(n, x, y, z);
                cout << m;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 5: {
                Matrix3D m;
                cin >> m;
                cout << m;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 6: {
                Matrix3D m(3, 1, 2, 3);
                cout << "Original:\n" << m;
                ++m;
                cout << "After prefix ++:\n" << m;
                m--;
                cout << "After postfix --:\n" << m;
                break;
            }
            case 7: {
                Matrix3D m(2, 1, 2, 3);
                cout << "Matrix:\n" << m;
                cout << "Result !m = " << (!m ? "true" : "false") << endl;
                Matrix3D neg = -m;
                cout << "Unary -m:\n" << neg;
                break;
            }
            case 8: {
                Matrix3D a(2, 1, 2, 3);
                Matrix3D b(2, 4, 5, 6);
                cout << "A:\n" << a;
                cout << "B:\n" << b;
                cout << "A + B:\n" << (a + b);
                cout << "B - A:\n" << (b - a);
                break;
            }
            case 9: {
                Matrix3D a(2, 1, 2, 3);
                Matrix3D b(2, 2, 3, 4);
                cout << "A:\n" << a;
                cout << "B:\n" << b;
                cout << "A * B:\n" << (a * b);
                break;
            }
            case 10: {
                Matrix3D a(2, 3, 6, 9);
                cout << "A:\n" << a;
                cout << "A + 2:\n" << (a + 2);
                cout << "A - 1:\n" << (a - 1);
                cout << "A * 2.0:\n" << (a * 2.0);
                cout << "A / 3:\n" << (a / 3);
                cout << "A % 2:\n" << (a % 2);
                break;
            }
            case 11: {
                Matrix3D a(2, 1, 2, 3);
                Matrix3D b(2, 1, 1, 1);
                Vector3D v(2, 2, 2);

                cout << "A:\n" << a;
                cout << "B:\n" << b;

                a += b;
                cout << "A += B:\n" << a;

                a -= 1.0;
                cout << "A -= 1.0:\n" << a;

                a *= b;
                cout << "A *= B:\n" << a;

                a *= v;
                cout << "A *= Vector3D(2,2,2):\n" << a;

                a /= 2.0;
                cout << "A /= 2.0:\n" << a;

                a %= 2;
                cout << "A %= 2:\n" << a;
                break;
            }
            case 12: {
                Matrix3D a(2, 1, 2, 3);
                Matrix3D b(2, 1, 2, 3);
                Matrix3D c(2, 2, 3, 4);

                cout << "A:\n" << a;
                cout << "B:\n" << b;
                cout << "C:\n" << c;

                cout << "A == B: " << (a == b) << endl;
                cout << "A != C: " << (a != c) << endl;
                cout << "C > A: " << (c > a) << endl;
                cout << "C >= B: " << (c >= b) << endl;
                cout << "A < C: " << (a < c) << endl;
                cout << "A <= B: " << (a <= b) << endl;
                break;
            }
            case 13: {
                Matrix3D m(2, 1, 2, 3);
                cout << "Matrix:\n" << m;
                cout << "m[0] = " << m[0] << endl;
                cout << "m[10] = " << m[10] << endl;
                cout << "CodeError = " << m.getCodeError() << endl;
                break;
            }
            case 14: {
                Matrix3D m(2, 1, 2, 3);
                cout << "Matrix:\n" << m;
                cout << "m(1,2) = " << m(1, 2) << endl;
                m(1, 2) = 100;
                cout << "After m(1,2)=100:\n" << m;
                break;
            }
            case 15: {
                cout << "Number of Matrix3D objects = " << Matrix3D::getNumMatrix() << endl;
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

// =====================================================
// MAIN MENU
// =====================================================
int main() {
    int choice;

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Task 1 - VectorLong\n";
        cout << "2. Task 2.5 - Email and Full Name associative class\n";
        cout << "3. Task 3 - Matrix3D using Vector3D\n";
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
                menuTask3();
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