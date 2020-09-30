// Полюбин Арсений Игоревич, группа М80-206Б-19
// Создание класса Vector3D


#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;



class Vector3D{
private:
    double X_;
    double Y_;
    double Z_;
public:
    Vector3D(){
        X_ = 0;
        Y_ = 0;
        Z_ = 0;
    };

    Vector3D(const double& X , const double& Y , const double& Z  ) {
        X_ = X;
        Y_ = Y;
        Z_ = Z;
    }

    double Get_X()  { // Геттеры и сеттеры
        return X_;
    }

    int Set_X(double x) {
        X_ = x;
        return 0;
    }

    double Get_Y()  { // Геттеры и сеттеры
        return Y_;
    }

    int Set_Y(double y) {
        Y_ = y;
        return 0;
    }
    double Get_Z()  { // Геттеры и сеттеры
        return Z_;
    }

    int Set_Z(double z) {
        Z_ = z;
        return 0;
    }
    void Print() {
        cout << "X = " << X_ << "  " << "Y = " << Y_ << "   "<< "Z = " << Z_ << endl;
    }
    friend Vector3D operator+(const Vector3D& first, const Vector3D& second); // все перегруженные операторы делаются дружелюбными
    friend Vector3D operator- (const Vector3D& first, const Vector3D& second);
    friend Vector3D operator* (const Vector3D& first, const double a);
    friend bool operator< (const Vector3D& first, const Vector3D& second);
    friend bool operator<= (const Vector3D& first, const Vector3D& second);
    friend bool operator>= (const Vector3D& first, const Vector3D& second);
    friend bool operator > (const Vector3D& first, const Vector3D& second);
    friend bool operator == (const Vector3D& first, const Vector3D& second);
    friend bool operator != (const Vector3D& first, const Vector3D& second);
    friend double phi(const Vector3D& a, const Vector3D& b);
    friend Vector3D vec(const Vector3D& a, const Vector3D& b);
    friend double len(const Vector3D& a);
    friend double scal(const Vector3D& a, const Vector3D& b);


    ~Vector3D ()
    {
    }; // деструктор

};
// перегрузка операторов

Vector3D operator+ (const Vector3D& first, const Vector3D& second) {
    double x,y,z;
    x = first.X_ + second.X_;
    y = first.Y_ + second.Y_;
    z = first.Z_ + second.Z_;

    return Vector3D(x, y, z);
}

Vector3D operator-(const Vector3D& first, const Vector3D& second) {
    return Vector3D(first.X_ - second.X_, first.Y_ - second.Y_, first.Z_ - second.Z_) ;
}

Vector3D operator* (const Vector3D& first, const double a) {

    return Vector3D(first.X_*a, first.Y_*a, first.Z_*a);
}

bool operator< (const Vector3D& first, const Vector3D& second) {
    return (sqrt(first.X_*first.X_ + first.Y_*first.Y_ + first.Z_*first.Z_) < sqrt(second.X_*second.X_ + second.Y_*second.Y_ + second.Z_*second.Z_));
}

bool operator<= (const Vector3D& first, const Vector3D& second) {
    return (sqrt(first.X_*first.X_ + first.Y_*first.Y_ + first.Z_*first.Z_) <= sqrt(second.X_*second.X_ + second.Y_*second.Y_ + second.Z_*second.Z_));
}

bool operator> (const Vector3D& first, const Vector3D& second) {
    return (sqrt(first.X_*first.X_ + first.Y_*first.Y_ + first.Z_*first.Z_) > sqrt(second.X_*second.X_ + second.Y_*second.Y_ + second.Z_*second.Z_));
}

bool operator>= (const Vector3D& first, const Vector3D& second) {
    return (sqrt(first.X_*first.X_ + first.Y_*first.Y_ + first.Z_*first.Z_) >= sqrt(second.X_*second.X_ + second.Y_*second.Y_ + second.Z_*second.Z_));
}

bool operator== (const Vector3D& first, const Vector3D& second) {
    return ((first.X_ == second.X_) && (first.Y_ == second.Y_) && (first.Z_ == second.Z_));
}

bool operator!= (const Vector3D& first, const Vector3D& second) {
    return ((first.X_ != second.X_) || (first.Y_ != second.Y_) || (first.Z_ != second.Z_));
}
Vector3D vec(const Vector3D& a, const  Vector3D& b){
double i,j,k;
i = a.Y_*b.Z_ - b.Y_*a.Z_;
j = a.X_*b.Z_ - b.X_*a.Z_;
k = a.X_*b.Y_ - b.X_*a.Y_;
return Vector3D(i, j, k);
}
double scal(const Vector3D& a, const Vector3D& b){
    double x,y,z;
    x = a.X_ + b.X_;
    y = a.Y_ + b.Y_;
    z = a.Z_ + b.Z_;
    return sqrt(x*x + y*y + z*z);
}

double len(const Vector3D& a){
    return sqrt(a.X_*a.X_ + a.Y_*a.Y_ + a.Z_*a.Z_);
}
double phi(const Vector3D& a, const Vector3D& b){
    double hi,x;
    x = (a.X_*b.X_ + a.Y_*b.Y_ + a.Z_*b.Z_) / (sqrt(a.X_*a.X_ + a.Y_*a.Y_ + a.Z_*a.Z_) * sqrt(b.X_*b.X_ + b.Y_*b.Y_ + b.Z_*b.Z_));
    if((sqrt(a.X_*a.X_ + a.Y_*a.Y_ + a.Z_*a.Z_) * sqrt(b.X_*b.X_ + b.Y_*b.Y_ + b.Z_*b.Z_)) == 0){
        return 0;
    }
    if(x == 1.0000000000000002){
        return 0;
    }
    hi = acos(x);
    return hi;
}
Vector3D operator ""_v(const char* str, size_t size){ // Создание пользовательского литерала
    std::stringstream ss(str);
    std::string a, b, c;
    ss >> a >> b >> c;
    double A = 0;
    double B = 0;
    double C = 0;
    try {
        A = std::stoi(a);
        B = std::stod(b);
        C = std::stod(c);
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return Vector3D(A, B, C);
}




int main(int argc, char *argv[]) {
    double x1, y1, z1, x2, y2, z2,c;

    if (argc == 1) {
        cout << "ВВедите координаты двух векторов в трехмерном пространтстве" << endl;
        cout << "x1 = ";
        if (!(cin >> x1)) {
            cout << "Ошибка";
            return 1;
        }
        cout << "y1 = ";
        cin >> y1;
        cout << "z1 = ";
        cin >> z1;
        cout << "x2 = ";
        cin >> x2;
        cout << "y2 = ";
        cin >> y2;
        cout << "z2 = ";
        cin >> z2;
        cout << "Введите число на которое нужно умножить вектор: c = ";
        cin >> c;

    } else {
        ifstream file(argv[1]);
        file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> c;
        file.close();
    }
    Vector3D a = Vector3D(x1, y1, z1);
    Vector3D b = Vector3D(x2, y2, z2);
    Vector3D res = Vector3D(0, 0, 0);
    cout << "vector a + vector b = " << endl;
    res = a + b;
    res.Print();
    res = a - b;
    cout << "vector a - vector b = " << endl;
    res.Print();
    res = a * c;
    cout << "vector a * c " << endl;
    res.Print();
    cout << "vector b * c " << endl;
    res = b * c;
    res.Print();
    if (a == b) { cout << "a = b\n"; }
    else if (a > b) { cout << "a > b\n"; }
    else { cout << "a < b\n"; }
    cout << "Angle between a and b(in rad) = ";
    cout << phi(a,b) << endl;
    cout << "[a , b] = ";
    res = vec(a , b);
    res.Print();
    cout << "(a , q) = " << scal(a, b) << endl;
    cout << "|a| = " << len(a) << endl;
    cout << "|b| = " << len(b) << endl;


    Vector3D q = "1 1 1"_v; // инициализация литерала
    cout << "vector a + vector q = " << endl;
    res = a + q;
    res.Print();
    res = a - q;
    cout << "vector a - vector q = " << endl;
    res.Print();
    res = q * c;
    cout << "vector q * c " << endl;
    res.Print();
    if (a == q) { cout << "a = q\n"; }
    else if (a > q) { cout << "a > q\n"; }
    else { cout << "a < q\n"; }
    cout << "Angle between a and q(in rad) = ";
    cout << phi(a,q) << endl;
    cout << "[a , q] = ";
    res = vec(a , q);
    res.Print();
    cout << "(a , q) = " << scal(a, q) << endl;
    cout << "|q| = " << len(q) << endl;




    return 0;
}