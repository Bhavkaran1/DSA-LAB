#include <iostream>
#include <cstring>
#include <cctype> // for tolower

using namespace std;

void convertToLowercase(char str1[], int n) {
    for (int i = 0; i < n; i++) {
        str1[i] = tolower(str1[i]); // convert each char to lowercase
    }
}

int main() {
    char str1[10] = "KRisHna";
    int n = strlen(str1);
    convertToLowercase(str1, n);
    cout << str1 << endl;
    return 0;
}
