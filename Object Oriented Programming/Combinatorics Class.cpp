#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
class Combinatorics {
public:
    Combinatorics(int = 0, int = 0);
    void set_Combinatorics(int, int);
    long long int nCr();

    void print_Combination();
    void print_Combination(int, string, int);

    long long int nPr();
    void print_Permutation();
    void print_Permutation(vector<int>, vector<int>);
    void print_Pascal_triangle();
private:

    int n;
    int r;
};

Combinatorics::Combinatorics(int in_n, int in_r) {
    if (in_n < in_r) {
        cerr << "n has to be larger or equal to r \n";
        exit(0);
    }

    set_Combinatorics(in_n, in_r);
}

void Combinatorics::set_Combinatorics(int in_n, int in_r) {
    n = in_n;
    r = in_r;
}

long long int Combinatorics::nCr() {
    long long int product = 1;

    for (long long int i = n; i > (n - r); i--) {

        product *= i;

    }

    for (long long int i = 1; i <= r; i++) {
        product /= i;
    }

    return product;
}
void Combinatorics::print_Combination() {
    print_Combination(0, "", 0);
}
void Combinatorics::print_Combination(int i, string output, int counter) {
    if (counter == r) {
        cout << output.substr(0, output.size() - 1) << endl;
        return;
    }
    else {
        if (i == 0) {
            for (int j = 1; j <= n; j++) {
                print_Combination(j, output + to_string(j) + " ", counter + 1);
            }
            return;
        }
        else {
            for (int j = 1; i + j <= n; j++) {
                //cout<<counter<<" "<<i<<endl;
                print_Combination(i + j, output + to_string((i + j)) + " ", counter + 1);
            }
            return;
        }
    }
    return;
}

long long int Combinatorics::nPr() {
    long long int product = 1;

    for (long long int i = n; i > n - r; i--) {
        product *= i;
    }
    return product;
}


void Combinatorics::print_Permutation() {
    vector<int>sequence, output;
    for (int i = 1; i <= n; i++) {
        sequence.push_back(i);
    }

    print_Permutation(sequence, output);
}

void Combinatorics::print_Permutation(vector<int> sequence, vector<int> output) {
    if (output.size() == r) {
        for (int i = 0; i < output.size(); i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    vector<int>temp = sequence;
    for (int i = 0; i < sequence.size(); i++) {
        output.push_back(temp[i]);
        temp.erase(temp.begin() + i);
        print_Permutation(temp, output);
        output.erase(output.begin() + output.size() - 1);
        temp = sequence;
    }
}

void Combinatorics::print_Pascal_triangle() {
    int** triangle;
    triangle = new int* [2 * (n - 1) + 1];

    for (int i = 0; i < n; i++) {
        triangle[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 2 * (n - 1) + 1; j++) {

            if (i == 0 && j == (2 * (n - 1) + 1) / 2) {
                triangle[i][j] = 1;
            }
            else {
                triangle[i][j] = 0;
            }
            if (i > 0) {
                if (j - 1 < 0) {
                    triangle[i][j] = triangle[i - 1][j + 1];
                }
                else if (j + 1 > 2 * (n - 1)) {
                    triangle[i][j] = triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j + 1];
                }
            }
        }


    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * (n - 1) + 1; j++) {
            if (triangle[i][j] == 0) cout << " ";
            else cout << triangle[i][j];
        }
        cout << endl;
    }
}
int main() {
    int n, r;
    Combinatorics a;
    cout << "Input n and r" << endl;
    cin >> n >> r;

    a.set_Combinatorics(n, r);

    cout << n << " C " << r << endl;
    cout << a.nCr()<<endl;
    a.print_Combination();

    cout << endl;

    cout << n << " P " << r << endl;
    cout << a.nPr() << endl;
    a.print_Permutation();

    cout << endl << "Pascal Triangle size" << endl;
    cin >> n;
    a.set_Combinatorics(n, r);
    a.print_Pascal_triangle();
}
