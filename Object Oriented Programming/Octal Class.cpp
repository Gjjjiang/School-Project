#include <iostream>
#include <cmath>
#include <string>
using namespace std;
 
class Octal {
   friend ostream& operator <<(ostream&, Octal&);
   friend istream& operator >>(istream&, Octal&);
public:
   Octal(long int = 0);
   Octal operator =(long int);
   long int oct_to_dec(long int);
   long int dec_to_oct(long int);
 
   Octal operator + (Octal);
   Octal operator - (Octal);
   Octal operator * (Octal);
   Octal operator / (Octal);
   Octal operator % (Octal);
   Octal operator ++();
   Octal operator --();
 
   bool operator < (Octal);
   bool operator <= (Octal);
   bool operator > (Octal);
   bool operator >= (Octal);
   bool operator == (Octal);
   bool operator != (Octal);
 
 
private:
   long int octal_num;
};
 
Octal::Octal(long int n) {
   *this = n;
}
 
Octal Octal::operator =(long int n) {
   string s = to_string(n);
  
   bool is_octal = true;
   if (n < 0)is_octal = false;
   for (long int i = 0; i < s.length() && is_octal; i++) {
       if (s[i]-'0' >= 8)is_octal = false;
   }
   if (is_octal) {
       octal_num = n;
       return *this;
   }
   else {
       cerr << "Please enter an octal number" << endl;
       exit (0);
   }
}
 
long int Octal::oct_to_dec(long int n) {
   long int sum = 0;
   long int limit = to_string(n).length();
 
   for (long int i = 0; i < limit; i++) {
       sum += (to_string(n)[limit - 1 - i] - '0') * pow(8, i);
   }
 
   return sum;
}
 
long int Octal::dec_to_oct(long int n) {
   long int sum = 0;
   long int limit = to_string(n).length() + 1;
   long int coefficient = 1;
   for (long int i = limit; i >= 0 && n > 0;) {
 
       if ((int)(n / pow(8, i)) != 0) {
           coefficient = n / pow(8, i);
           sum += coefficient * pow(10, i);
           n -= coefficient * pow(8, i);
       }
       else {
           i--;
       }
   }
 
   return sum;
}
 
Octal Octal::operator + (Octal n) {
   Octal sum(dec_to_oct(oct_to_dec(octal_num) + oct_to_dec(n.octal_num)));
   return sum;
}
 
Octal Octal::operator -(Octal n) {
   Octal difference(dec_to_oct(oct_to_dec(octal_num) - oct_to_dec(n.octal_num)));
   return difference;
}
 
Octal Octal::operator *(Octal n) {
   Octal product(dec_to_oct(oct_to_dec(octal_num) * oct_to_dec(n.octal_num)));
   return product;
}
 
Octal Octal::operator /(Octal n) {
   Octal quotient(dec_to_oct(oct_to_dec(octal_num) / oct_to_dec(n.octal_num)));
   return quotient;
}
 
Octal Octal::operator %(Octal n) {
   Octal modulus(dec_to_oct(oct_to_dec(octal_num) % oct_to_dec(n.octal_num)));
   return modulus;
}
 
Octal Octal::operator ++() {
   octal_num = dec_to_oct(oct_to_dec(octal_num) + 1);
   return *this;
}
 
Octal Octal::operator --() {
   octal_num = dec_to_oct(oct_to_dec(octal_num) - 1);
   return *this;
}
 
bool Octal::operator <(Octal n) {
   return octal_num < n.octal_num;
}
bool Octal::operator <=(Octal n) {
   return octal_num <= n.octal_num;
}
bool Octal::operator >(Octal n) {
   return octal_num > n.octal_num;
}
bool Octal::operator >=(Octal n) {
   return octal_num >= n.octal_num;
}
bool Octal::operator ==(Octal n) {
   return octal_num == n.octal_num;
}
bool Octal::operator !=(Octal n) {
   return octal_num != n.octal_num;
}
 
ostream& operator <<(ostream& output, Octal& n) {
   output << n.octal_num;
   return output;
}
 
istream& operator >>(istream& input, Octal& n) {
   input >> n.octal_num;
   return input;
}
 
int main() {
   Octal n;
   Octal m;
   Octal output;
   cout << "Enter n" << endl;
   cin >> n;
   cout << "Enter m" << endl;
   cin >> m;
  
   output = n + m;
 
   cout << "Sum: " << output << endl;
   output = n - m;
   cout << "Difference: " << output << endl;
   output = n * m;
   cout << "Product: " << output << endl;
   output = n / m;
   cout << "Quotient: " << output << endl;
   output = n % m;
   cout << "Modulus: " << output << endl;
   ++n;
   cout<< "Increment n: " << n << endl;
   --n;
   --n;
   cout<< "Decrement n: " << n <<endl;
   ++n;
   cout << n << " < " << m << " is " << ((n < m) ? "True" : "False") << endl;
   cout << n << " <= " << m << " is " << ((n <= m) ? "True" : "False") << endl;
   cout << n << " > " << m << " is " << ((n > m) ? "True" : "False") << endl;
   cout << n << " >= " << m << " is " << ((n >= m) ? "True" : "False") << endl;
   cout << n << " == " << m << " is " << ((n == m) ? "True" : "False") << endl;
   cout << n << " != " << m << " is " << ((n != m) ? "True" : "False") << endl;
   
   return 0;
}
