#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string input;

    cout << "Enter a line of text: ";
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    //regex pattern("[^a-zà-ÿ]+");
    //input = regex_replace(input, pattern, "");

    locale::global(locale(""));
    input.erase(remove_if(input.begin(), input.end(),
        [](wchar_t c) {
			return !iswalpha(c);
		}),
        input.end()
    );

    int len = input.length();
    int middle = len / 2;

    bool isPalindrome = equal(input.begin(), input.begin() + middle, input.rbegin());

    cout << "Is it a palindrome? " << boolalpha << isPalindrome << endl;
    return 0;
}