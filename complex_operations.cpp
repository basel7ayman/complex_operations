#include <cmath>
#include <iostream>
#include <stdexcept>

#define bl cout << "================================================" << endl

using namespace std;

class Complex {
  double real;
  double img;

 public:
  Complex(double real = 0, double img = 0) {
    this->real = real;
    this->img = img;
  }

  double getReal() const { return real; }

  double getImg() const { return img; }

  void setComplex(double real, double img) {
    this->real = real;
    this->img = img;
  }

  void getComplex() const {
    if (real == 0 && img == 0) {
      cout << 0 << endl;
      return;
    }

    if (real != 0) {
      cout << real;
    }

    if (img != 0) {
      if (img > 0 && real != 0) {
        cout << "+";
      }
      if (img == 1) {
        cout << "j";
      } else if (img == -1) {
        cout << "-j";
      } else {
        cout << img << "j";
      }
    }
    cout << endl;
  }
  //?============================================================

  //* ======================= + operator =======================

  Complex operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->img + other.img);
  }
  Complex operator+(int x) const { return Complex(this->real + x, this->img); }
  //?============================================================

  //* ======================= - operator =======================

  Complex operator-(const Complex& other) const {
    return Complex(this->real - other.real, this->img - other.img);
  }
  Complex operator-(int x) const { return Complex(this->real - x, this->img); }
  //?============================================================

  //* ======================= * operator =======================

  //! (a + bj) * (c + dj) = [ac + (-bd)]  +  (ad + bc)j

  Complex operator*(const Complex& other) const {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;

    double mulRl = (a * c) - (b * d);
    double mulImg = (a * d) + (b * c);

    return Complex(mulRl, mulImg);
  }
  Complex operator*(double x) const {
    return Complex(this->real * x, this->img * x);
  }
  //?============================================================

  //* ======================= / operator =======================

  //! (a + bj) / (c + dj) = ([ac + bd] / [c^2 + d^2])  +  ([bc - ad] / [c^2 +
  //! d^2])j

  Complex operator/(const Complex& other) const {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;
    double denominator = ((c * c) + (d * d));

    if (denominator == 0) {
      throw invalid_argument("Division by zero");
    }

    double divRl = ((a * c) + (b * d)) / denominator;
    double divImg = ((b * c) - (a * d)) / denominator;

    return Complex(divRl, divImg);
  }
  Complex operator/(double x) const {
    if (x == 0) {
      throw invalid_argument("Division by zero");
    }
    return Complex(this->real / x, this->img / x);
  }
  //?============================================================

  //* ======================= += operator =======================

  Complex operator+=(const Complex& other) {
    this->real = this->real + other.real;
    this->img = this->img + other.img;
    return Complex(this->real, this->img);
  }

  Complex operator+=(int x) {
    this->real = this->real + x;
    return Complex(this->real, this->img);
  }
  //?============================================================

  //* ======================= -= operator =======================

  Complex operator-=(const Complex& other) {
    this->real = this->real - other.real;
    this->img = this->img - other.img;
    return Complex(this->real, this->img);
  }

  Complex operator-=(int x) {
    this->real = this->real - x;
    return Complex(this->real, this->img);
  }
  //?============================================================

  //* ======================= *= operator =======================

  Complex operator*=(const Complex& other) {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;

    this->real = (a * c) - (b * d);
    this->img = (a * d) + (b * c);

    return Complex(this->real, this->img);
  }
  Complex operator*=(double x) {
    this->real = this->real * x;
    this->img = this->img * x;
    return Complex(this->real, this->img);
  }
  //?============================================================

  //* ======================= /= operator =======================

  Complex operator/=(const Complex& other) {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;
    double denominator = ((c * c) + (d * d));

    if (denominator == 0) throw invalid_argument("Division by zero");

    this->real = ((a * c) + (b * d)) / denominator;
    this->img = ((b * c) - (a * d)) / denominator;

    return Complex(this->real, this->img);
  }
  Complex& operator/=(double x) {
    if (x == 0)
      throw invalid_argument("Division by zero");
    else {
      this->real = this->real / x;
      this->img = this->img / x;
    }
    return *this;
  }
  //?============================================================

  //* ======================= == operator =======================

  bool operator==(const Complex& other) const {
    if (this->real == other.real && this->img == other.img) return true;
    return false;
  }
  //?============================================================

  //* ======================= != operator =======================

  bool operator!=(const Complex& other) const {
    if (this->real == other.real && this->img == other.img) return false;
    return true;
  }
  //?============================================================

  //* ======================= ++ operator =======================

  //! Prefix
  Complex& operator++() {
    this->real++;
    this->img++;
    return *this;
  };
  //! Postfix
  Complex operator++(int) {
    Complex old = *this;
    this->real++;
    this->img++;
    return old;
  };
  //?============================================================

  //* ======================= -- operator =======================

  //! Prefix
  Complex& operator--() {
    this->real--;
    this->img--;
    return *this;
  };
  //! Postfix
  Complex operator--(int) {
    Complex old = *this;
    this->real--;
    this->img--;
    return old;
  };
  //?============================================================

  //* ======================= [] operator =======================

  double operator[](int index) {
    if (index == 0) {
      return this->real;
    } else if (index == 1) {
      return this->img;
    } else {
      throw invalid_argument("Error kebeer Invalid index");
    }
  }
  //?============================================================

  //* ======================= () operator =======================

  // void operator()(double x, double y) { setComplex(x, y); }
  Complex operator()(Complex& c) {
    this->real = c.real;
    this->img = c.img;
    return Complex(this->real, this->img);
  }

  double operator()() const {
    double x = sqrt((this->real * this->real) + (this->img * this->img));
    return x;
  }
  //?============================================================

  //* ======================= = operator =======================

  Complex& operator=(const Complex& c) {
    this->real = c.real;
    this->img = c.img;
    return *this;
  }
  //?============================================================

  //* ======================= friend functions =======================
  friend std::istream& operator>>(std::istream&, Complex&);
  friend std::ostream& operator<<(std::ostream&, const Complex&);
  friend Complex operator+(double, const Complex&);
  friend Complex operator-(double, const Complex&);
  friend Complex operator*(double, const Complex&);
  friend Complex operator/(double, const Complex&);
};

//* ======================= + operator =======================
Complex operator+(double x, const Complex& c) {
  return Complex(c.real + x, c.img);
}
//?============================================================

//* ======================= - operator =======================
Complex operator-(double x, const Complex& c) {
  return Complex(c.real - x, c.img);
}
//?============================================================

//* ======================= * operator =======================
Complex operator*(double x, const Complex& c) {
  return Complex(c.real * x, c.img * x);
}
//?============================================================

//* ======================= / operator =======================
Complex operator/(double x, const Complex& c) {
  return Complex(c.real / x, c.img / x);
}
//?============================================================

//* ======================= << operator =======================

std::ostream& operator<<(std::ostream& output, const Complex& c) {
  if (c.real == 0 && c.img == 0) {
    output << 0 << endl;
    return output;
  }

  if (c.real != 0) {
    output << c.real;
  }

  if (c.img != 0) {
    if (c.img > 0 && c.real != 0) {
      output << "+";
    }
    if (c.img == 1) {
      output << "j";
    } else if (c.img == -1) {
      output << "-j";
    } else {
      output << c.img << "j";
    }
  }
  return output;
}
//?============================================================

//* ======================= >> operator =======================

std::istream& operator>>(std::istream& input, Complex& c) {
  cout << "Enter real: ";
  input >> c.real;
  cout << "Enter img: ";
  input >> c.img;
  return input;
}
//?============================================================

int main() {
  Complex c4;
  Complex c1(1, 2);
  Complex c2(3, 4);
  Complex c3(2, 3);
  Complex c5(0, 0);

  // bl;
  // c4.setComplex(1, -1);
  // c4.getComplex();
  // bl << endl;
  // bl;
  // c4 = c2 * c1;
  // c4.getComplex();
  // bl << endl;
  // bl;
  // c4 = c2 / c1;
  // c4.getComplex();
  // bl;

  double result = c2();
  cout << result << endl;
  bl;

  return 0;
}