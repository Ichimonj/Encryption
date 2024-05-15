#include<iostream>
#include<vector>

/*
int main() {
    string msg = "dead reckoning";
    int      p = 13;
    int		 q = 37;

    vector<int> coding = RSA::RSA(msg, p, q);
    for (auto& ex : coding) {
        cout << ex << ' ';		//380 381 119 380 2 472 381 411 386 37 184 105 184 51 d - 77
    }

    string decoding = RSA::DeRSA(coding, p, q);
    cout << decoding << endl;	//dead reckoning
}
*/

using namespace std;
namespace RSA {
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int NOD(int m) {
        int _nod = 100;
        while (_nod <= m && gcd(m, _nod) != 1) {
            _nod++;
        }
        if (_nod <= m) {
            return _nod;
        }
        else {
            return 0;
        }
    }

    int modexp(int x, int y, int N)
    {
        if (y == 0) return 1;
        int z = modexp(x, y / 2, N);
        if (y % 2 == 0)
            return (z * z) % N;
        else
            return ((x % N) * ((z * z) % N)) % N;
    }

    //secret exhibitor
    int FMI(int e, int n) {
        for (int i = 1; i < n; i++) {
            if ((e * i) % n == 1) {
                return i;
            }
        }
        return -1; // No modular inverse exists
    }

    int euq(int e, int m) {
        int d = 1;
        while ((e * d) % m != 1) {
            d++;
        }
        return d;
    }

    vector<int>RSA(string msg, int p, int q) {
        //kay
        int e, n;

        n = q * p;
        int m = (p - 1) * (q - 1);
        e = NOD(m);

        //encrypted message
        vector<int> returnMsg(msg.size(), ' ');
        for (int i = 0; i < msg.size(); i++) {
            int chId = static_cast<int>(msg[i]);
            //chId = modexp(chId, e, n);
            returnMsg[i] = modexp(chId, e, n);
        }

        return returnMsg;
    }

    string DeRSA(vector<int> msg, int p, int q) {
        //kay 
        int d, n;

        n = q * p;
        int m = (p - 1) * (q - 1);
        int e = NOD(m);
        d = euq(e, m);


        //decrypted message
        string returnMsg(msg.size(), ' ');
        for (int i = 0; i < msg.size(); i++) {
            int chId = msg[i];
            chId = modexp(chId, d, n);
            returnMsg[i] = static_cast<char>(chId);
        }

        return returnMsg;
    }
}