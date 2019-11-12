#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct Delimiter {
    char val;
    int pos;
};

// solution using stacks
int main() {

    stack<Delimiter> s;

    string input;

    cout << "Enter the sequence: ";
    getline(cin, input);

    for (size_t i = 0; i < input.size(); i++) {

        if (input[i] == '{' || input[i] == '(') {
            s.push({input[i], static_cast<int>(i)});
        }

        if (input[i] == '}' || input[i] == ')') {
            if (s.empty()) {
                cout << "Sequence invalid. '" << input[i] << "' in position " << i << endl;
                return 1;
            }
            else {
                const char ontop = s.top().val;

                if ((input[i] == ')' && ontop == '(') || (input[i] == '}' && ontop == '{')) {
                    s.pop();
                }
                else {
                    cout << "Sequence invalid. '" << input[i] << "' in position " << i << " does not match '" << ontop << "'\n";
                    return 1;
                }

            }
        }

    }

    if (s.empty()) {
        cout << "Sequence Valid!\n";
    }
    else {
        const Delimiter ontop = s.top();
        cout << "Sequence Invalid! '" << ontop.val << "' in position " << ontop.pos << " is never closed.\n";
    }

    return 0;
}

// solution not using stacks
int _main() {

    return 0;
}