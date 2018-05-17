#include "matrix.hpp"
int main() {
  std::cout << "=== Test vector ===" << std::endl;

  Vector2D<int> v1 = {1, 1};
  Vector2D<int> v2 = {2, 2};

  std::cout << std::boolalpha << (v1 == v2) << std::endl;
  std::cout << std::boolalpha << (v1 != v2) << std::endl;

  std::cout << (v1 + v2) << std::endl;
  std::cout << (v1 - v2) << std::endl;
  std::cout << v1 * 5 << std::endl;
  std::cout << -5 * v2 << std::endl;
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;

  std::cout << "=== Test matrix ===" << std::endl;

  Matrix2D<int> m1 = Matrix2D<int>();
  m1.set_matr(0, 0, 0);
  m1.set_matr(0, 1, 1);
  m1.set_matr(1, 0, 1);
  m1.set_matr(1, 1, 2);

  Matrix2D<int> m2 = Matrix2D<int>();
  m2.set_matr(0, 0, 0);
  m2.set_matr(0, 1, 1);
  m2.set_matr(1, 0, 2);
  m2.set_matr(1, 1, 2);

  std::cout << std::boolalpha << (m1 == m2) << std::endl;
  std::cout << std::boolalpha << (m1 != m2) << std::endl;

  std::cout << (m1 + m2) << std::endl;
  std::cout << (m1 - m2) << std::endl;
  std::cout << m1 * 5 << std::endl;
  std::cout << -5 * m2 << std::endl;
  std::cout << m1 << std::endl;
  std::cout << m2 << std::endl;

  std::cout << "=== Cross test vector and matrix ===" << std::endl;

  std::cout << m1 * v1 << std::endl;

  return 0;
}
