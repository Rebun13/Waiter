#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
int getNextPrime(int n)
{
    bool isPrime = false;
    while(!isPrime)
    {
        isPrime = true;
        ++n;
        for(int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return n;
}

vector<int> waiter(vector<int> number, int q)
{
    vector<int> answers;
    stack<int> A;
    int nextPrime = 2;
    // First iteration
    for(int n : number) {
        if (n % nextPrime == 0) {
            answers.push_back(n);
        } else {
            A.push(n);
        }
    }
    // The rest of itearions
    int iter = 1;
    stack<int> oldA;
    while(!A.empty() && iter++ < q) {
        A.swap(oldA);
        nextPrime = getNextPrime(nextPrime);
        while(!oldA.empty()) {
            if (oldA.top() % nextPrime == 0) {
                answers.push_back(oldA.top());
            } else {
                A.push(oldA.top());
            }
            oldA.pop();
        }
    }
    vector<int> B;
    while(!A.empty()) {
        B.insert(B.begin(), A.top());
        A.pop();
    }
    answers.insert(answers.end(), B.begin(), B.end());
    return answers;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++)
    {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c)
                { return !ispunct(c); }));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c)
                { return !ispunct(c); })
            .base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}