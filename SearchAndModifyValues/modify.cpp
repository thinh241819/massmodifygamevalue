#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string multiply(const string& str)
{
    istringstream input(str);
    ostringstream out;
    out << fixed << setprecision(2);
    char ch;
    while (input.get(ch))
    {
        out.put(ch);
        double number;
        if (ch == 'Y' && input.peek() == ':')
        {
            input.get(ch);
            out.put(ch);
            input >> number;
            number *= 2;
            out << number;
        }
    }
    return out.str();
}

void modify(ifstream& in, ofstream& out)
{
    string str;
    while (getline(in, str))
    {
        string result = multiply(str);
        out << result << endl;
    }
}

int main()
{
    ifstream in("PRICE_PLAYERSELL_NORMAL.DAT");
    ofstream out("PRICE_PLAYERSELL_NORMAL_MODIFIED.DAT");
    modify(in, out);
    
}