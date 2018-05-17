#include <iostream>

using namespace std;
template <typename T> class Vector2D {
public:
  Vector2D() {
    this->x = 0;
    this->y = 0;
  };

  Vector2D(T x, T y) {
    this->x = x;
    this->y = y;
  }

  ~Vector2D(){};

  T getX() const { return x; }

  T getY() const { return y; }

  void setX(T x) { this->x = x; }

  void setY(T y) { this->y = y; }

  bool operator==(const Vector2D &v2) {
    return ((this->x == v2.x) && (this->y == v2.y));
  }

  bool operator!=(const Vector2D &v2) {
    return ((this->x != v2.x) || (this->y != v2.y));
  }

  Vector2D operator+(const Vector2D &v2) {
    return Vector2D(this->x + v2.x, this->y + v2.y);
  }

  Vector2D operator-(const Vector2D &v2) {
    return Vector2D(this->x - v2.x, this->y - v2.y);
  }

  Vector2D operator*(const T a) { return Vector2D(this->x * a, this->y * a); }

  T operator*(const Vector2D &v2) { return this->x * v2.x + this->y * v2.y; }

protected:
  T x;
  T y;
};
template <typename T>
std::ostream &operator<<(std::ostream &print, const Vector2D<T> &v) {
  print << v.getX() << " " << v.getY();
  return print;
}
template <typename T> Vector2D<T> operator*(T a, const Vector2D<T> &v) {
  return Vector2D<T>(a * v.getX(), a * v.getY());
}
template <typename T>
std::istream &operator>>(std::istream &scan, Vector2D<T> &v) {
  T x, y;
  scan >> x >> y;
  v.setX(x);
  v.setY(y);
  return scan;
}

template <typename T> class Matrix2D {
public:
  Matrix2D() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        matr[i][j] = 0;
    }
  };

  Matrix2D(T values[2][2]) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        set_matr(i, j, values[i][j]);
      }
    }
  };

  ~Matrix2D(){};

  T get_matr(int i, int j) const {
    if (!(i < 0 || i > 1 || j < 0 || j > 1))
      return matr[i][j];

    return 0;
  }

  void set_matr(int i, int j, T value) {
    if (!(i < 0 || i > 1 || j < 0 || j > 1)) {
      this->matr[i][j] = value;
    }
  }

  bool operator==(const Matrix2D &v2) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (this->matr[i][j] != v2.matr[i][j])
          return 0;
      }
    }

    return 1;
  }

  bool operator!=(const Matrix2D &v2) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (this->matr[i][j] != v2.matr[i][j])
          return 1;
      }
    }

    return 0;
  }

  Matrix2D operator+(const Matrix2D &m2) {
    T values[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        values[i][j] = this->matr[i][j] + m2.matr[i][j];
    }
    return Matrix2D(values);
  }

  Matrix2D operator-(const Matrix2D &m2) {
    T values[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        values[i][j] = this->matr[i][j] - m2.matr[i][j];
    }
    return Matrix2D(values);
  }

  Matrix2D operator*(const T a) {
    T values[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        values[i][j] = this->matr[i][j] * a;
    }
    return Matrix2D(values);
  }

  Matrix2D operator*(const Matrix2D &m2) {
    T values[2][2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++)
        values[i][j] =
            this->matr[i][0] * m2.matr[0][j] + this->matr[i][1] * m2.matr[1][j];
    }
    return Matrix2D(values);
  }

  T det() {
    return this->matr[0][0] * this->matr[1][1] -
           this->matr[0][1] * this->matr[1][0];
  }

  Vector2D<T> operator*(const Vector2D<T> &v) {
    T x = this->matr[0][0] * v.getX() + this->matr[0][1] * v.getY();
    T y = this->matr[1][0] * v.getX() + this->matr[1][1] * v.getY();
    return Vector2D<T>(x, y);
  }

protected:
  T matr[2][2];
};
template <typename T> Matrix2D<T> operator*(T a, const Matrix2D<T> &m) {
  T values[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      values[i][j] = a * m.get_matr(i, j);
  }
  return Matrix2D<T>(values);
}

template <typename T>
std::ostream &operator<<(std::ostream &print, const Matrix2D<T> &m) {
  print << m.get_matr(0, 0) << " " << m.get_matr(0, 1) << endl;
  print << m.get_matr(1, 0) << " " << m.get_matr(1, 1);
  return print;
}

template <typename T>
std::istream &operator>>(std::istream &scan, Matrix2D<T> &m) {
  T values[2][2];
  scan >> values[0][0] >> values[0][1] >> values[1][0] >> values[1][1];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      m.set_matr(i, j, values[i][j]);
    }
  }
  return scan;
}
