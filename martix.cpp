#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<char, int> mci;
typedef map<int, int> mii;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define fr(i, a, b) for(int i = a; i < b; i++)
#define frr(i, b, a) for(int i = b; i > a; i--)
#define loop(i, n) for(int i = 0; i < n; i++)
#define eb emplace_back
#define mset0(x) memset(x, 0, sizeof(x))
#define mset1(x) memset(x, -1, sizeof(x))
#define len(x) x.size()
#define ump unordered_map
#define sum(x) accumulate(x.begin(), x.end(), 0)
#define out(x) cout << x << endl
#define outl(x) cout << x << " "
#define out2(x, y) cout << x << " " << y << " " << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << " " << endl
#define out4(x, y, z, w) cout << x << " " << y << " " << z << " " << w << " " << endl
int mod = 1e9 + 7;

template<typename T1, typename T2> void printmap(map<T1, T2>& m){
    cout << "{";
    for(auto& i : m){cout << i.F << " : " << i.S << ", ";}
    cout << "}\n";}

template<typename T1, typename T2> void printmaplist(map<T1, T2>& mv){
    cout << "{";
    for (auto& i : mv){
        cout << i.F << " : " << "[";
        for (auto& j : i.S){cout << j << ", ";}
        cout << "], ";}
    cout << "}\n";}

template<typename T> void printlist(vector<T>& v){
    for (T i : v){cout << i << " ";}
    cout << endl;
}

template <typename T>
class Matrix {
    public:
    vector < vector <T> > A;
    int r,c;
    Matrix(int r, int c, T val = 0){
        this->r = r;
        this->c = c;
        A.assign(r, vector<T> (c, val));
    }

    // identity matrix
    Matrix(int r){
        this->r = r;
        this->c = r;
        A.assign(r, vector<T> (c));
        loop(i, r){
            A[i][i] = 1;
        }
    }
    
    //Input called to get input
    void input(){
        loop(i, r){
            loop(j, c){
                cin >> A[i][j];
            }
        }
    }

    //Overloaded * operator to multiply 2 matrices
    Matrix operator*(const Matrix<T> &B){
        assert(c == B.r);
        int c2 = B.c;
        Matrix <T> C(r, c2);
        loop(i, r){
            loop(j, c2){
                loop(k, c){
                    C[i][j] += A[i][k]*B[k][j];
                    C[i][j] %= mod;
                }
            }
        }
        return C;
    }

    //Overloaded + operator to add 2 matrices
    Matrix operator+(const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        Matrix <T> C(r, c);
        loop(i, r){
            loop(j, c){
                C[i][j] = A[i][j] + B[i][j];
                C[i][j] %= mod;
            }
        }
        return C;
    }

    //Overloaded += operator to add 2 matrices
    void operator += (const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        loop(i, r){
            loop(j, c){
                A[i][j] += B[i][j];
                A[i][j] %= mod;
            }
        }
    }

    //Overload unary - to get negative of a matrix
    Matrix operator-(){
        Matrix <T> C(r, c);
        loop(i, r){
            loop(j, c){
                C[i][j] = -A[i][j];
            }
        }
        return C;
    }

    //Overload binary - to subtract a matrix
    Matrix operator - (const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        Matrix <T> C(r, c);
        loop(i, r){
            loop(j, c){
                C[i][j] = A[i][j] - B[i][j];
                C[i][j] %= mod;
                if(C[i][j] < 0) C[i][j] += mod;
            }
        }
        return C;
    }

    //Overload binary - to subtract a matrix
    void operator -= (const Matrix<T> &B){
        assert(r == B.r);
        assert(c == B.c);
        loop(i, r){
            loop(j, c){
                A[i][j] -= B[i][j];
                A[i][j] %= mod;
                if(A[i][j] < 0) A[i][j] += mod;
            }
        }
    }

    //Overload ^ operator to raise a square matrix to a power
    //Using binary matrix exponentiation
    Matrix operator^(ll n){
        assert(r == c);
        Matrix <T> C(r, r, 1);
        Matrix <T> X(r, c);
        loop(i, r){
            loop(j, c){
                X[i][j] = A[i][j];
            }
        }
        while(n){
            if(n&1) C = C*X;
            X = X*X;
            n /= 2;
        }
        return C;
    }

    //transpose operation
    Matrix transpose(){
        Matrix <T> C(c, r);
        loop(i, r){
            loop(j, c){
                C[j][i] = A[i][j];
            }
        }
        return C;
    }

    //Overload to access/set elements without using dot operator
    //Example :
    // Matrix m(5,3);
    // m.A[i][j] is valid to access
    // m[i][j] is valid as well
    vector<T>& operator [] (int i){
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    //Overload to access/set elements without using dot operator
    // for accessing from cosnt objects
    const vector<T>& operator [] (int i) const{
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    //outstream has been overloaded to quickly print the matrix 
    // cout << M << endl;
    friend ostream& operator << (ostream &out,const Matrix<T> &M){
        loop(i, M.r) {
            loop(j, M.c){
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }
};

int main(){
    Matrix <int> A(2,3,1);
    Matrix <int> B(3,2,2);
    Matrix <int> C =  A*B;
    cout << C << endl;

    //Example of addition
    //+
    Matrix <int> D(2,3,1);
    Matrix <int> E(2,3,2);
    Matrix <int> F = D + E;
    cout << F << endl;

    //+=
    D += E;
    cout << D << endl;


    //Example of subtraction
    //- binary
    Matrix <int> G(2,3,1);
    Matrix <int> H(2,3,2);
    Matrix <int> I = -G;
    // cout << I << endl;

    //- unary
    // I = -G;
    cout << I << endl;

    //-=
    G -= H;
    cout << G << endl;

    //Example of power
    Matrix <int> J(2,2);

    //overloaded box operator to avoid writing M.A[i][j]
    J[0][0] = 1;    //same as J.A[0][0]
    J[0][1] = 1;    //same as J.A[0][1]
    J[1][0] = 1;    //same as J.A[1][0]
    J[1][1] = 0;    //same as J.A[1][1]

    cout << J << endl;

    //^ operator
    Matrix <int> K = J^6;
    cout << K << endl;

    //example of transpose
    Matrix <int> L(2,4);
    L[1][3] = 5;
    L[1][1] = 9;
    cout << L << endl;

    //transpose the matrix
    Matrix <int> M = L.transpose();
    cout << M << endl;

    return 0;
}

// for 2*2 matrix
vi mm(vi& a, vi& b){
    vi c(4);
    c[0] = (a[0]*b[0] + a[1]*b[2])%mod;
    c[1] = (a[0]*b[1] + a[1]*b[3])%mod;
    c[2] = (a[2]*b[0] + a[3]*b[2])%mod;
    c[3] = (a[2]*b[1] + a[3]*b[3])%mod;
    return c;
}