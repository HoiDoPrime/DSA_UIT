#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mod 1000000007
#define INF 1e9
#define LINF 1e18
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
bool kiemtrakitudacbiet(char x)
{
    if (x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '^' || x == '&' || x == '%' || x == '^' || x == '&' || x == '*' || x == '?' || x == '_' || x == '~')
    {
        return true;
    }
    return false;
}
bool kitudacbiet_khonghop_le(string &s)
{
    for (char x : s)
    {
        if (x == '.' || x == ',' || x == '\\' || x == '/' || x == '\'' || x == '‘' || x == '’')
        {
            return true;
        }
    }
    return false;
}

int tinhdiem(string &s)
{
    int BaseScore = 40, Bonus_Excess = 3, Bonus_Upper = 4, Bonus_Numbers = 5, Bonus_Symbols = 5;
    // Bonus_Combo
    int Bonus_Combo = 0, chuinhoa = 0, kitudacbiet = 0, chuso = 0;
    for (char x : s)
    {
        if (isupper(x))
            chuinhoa++;
        else if (isdigit(x))
            chuso++;
        else if (kiemtrakitudacbiet(x))
            kitudacbiet++;
    }
    if (chuinhoa > 0 && chuso > 0 && kitudacbiet > 0)
    {
        Bonus_Combo = 25;
    }
    else if (chuinhoa > 0 && chuso > 0 || chuso > 0 && kitudacbiet > 0 || chuinhoa > 0 && kitudacbiet > 0)
    {
        Bonus_Combo = 15;
    }
    else
    {
        Bonus_Combo = 0;
    }
    // Bonus_FlatLower
    int Bonus_FlatLower = 0, chucaithuong = 0;
    for (char x : s)
    {
        if (islower(x))
            chucaithuong++;
    }
    if (s.length() == chucaithuong)
    {
        Bonus_FlatLower = -15;
    }
    else
        Bonus_FlatLower = 0;
    // Bonus_FlatNumber
    int Bonus_FlatNumber = 0;
    if (s.length() == chuso)
    {
        Bonus_FlatNumber = -15;
    }
    else
        Bonus_FlatNumber = 0;

    int Number_Excess = s.length() - 8, Number_Upper = chuinhoa, Number_Numbers = chuso, Number_Symbols = kitudacbiet;
    int score = BaseScore + (Number_Excess * Bonus_Excess) + (Number_Upper * Bonus_Upper) +
                (Number_Numbers * Bonus_Numbers) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
    return score;
}
int main()
{
    string s;
    cin >> s;

    // kiem tra dieu kien mat khau hop le
    if (kitudacbiet_khonghop_le(s) || s.length() < 8 || s.length() > 100)
    {
        cout << "KhongHopLe";
        return 0;
    }
    if (tinhdiem(s) < 50)
    {
        cout << "Yeu";
    }
    else if (tinhdiem(s) >= 50 && tinhdiem(s) < 75)
    {
        cout << "Vua";
    }
    else if (tinhdiem(s) >= 75 && tinhdiem(s) < 100)
    {
        cout << "Manh";
    }
    else
    {
        cout << "RatManh";
    }
    return 0;
}