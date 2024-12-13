./#include <iostream>

// Function to determine if a character is a lowercase vowel
bool isLowerVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

// Function to compare two integers
void compare(int x, int y) {
    if (x > y) {
        std::cout << x << " is greater than " << y << '\n'; // case 1
    } else if (x < y) {
        std::cout << x << " is less than " << y << '\n'; // case 2
    } else {
        std::cout << x << " is equal to " << y << '\n'; // case 3
    }
}

int main() {
    // Test the isLowerVowel function
    char a,b;
    cin>> a;
    cin>> b;
    std::cout << "Is 'a' a lower vowel? " << (isLowerVowel(a) ? "Yes" : "No") << '\n';
    std::cout << "Is 'q' a lower vowel? " << (isLowerVowel(b) ? "Yes" : "No") << '\n';

    // Test the compare function
    compare(a,b);

    return 0;
}
