#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
[[nodiscard]]
T prompt(string prompt, T def = 0) {
    cout << prompt << " [" << def << "]: ";
    T value;
    cin >> value;
    return value;
}

void convertF2C(initializer_list<int> temps) {
    auto it = temps.begin();
    while (it != temps.end()) {  // while loop
        auto temp = *it++;
        cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
    }
}

template<std::integral T>
void convertF2C2(initializer_list<T> temps) {
    for (auto temp : temps) {  // range-based for loop
        cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
    }
}

template<std::integral T>
void convertF2C3(initializer_list<T> temps) {
    for_each(temps.begin(), temps.end(), 
        [](T temp) {  // for_each with lambda
            cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
    });
}

void ShowF2C(auto temp) {
    cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
}
template <typename... Args>
void convertF2C4(Args... args) {
    (ShowF2C(args), ...);  // fold expression
}


int main() {
    if (auto age = prompt("Enter your age", 38);  // not end of statement if-init
        age > 0 && age < 120) {
        cout << "You would be " << age * 7 << " in dog years." << endl;
    }
    else {
        cout << "Invalid age." << endl;
    }

    convertF2C({32, 212, 98, 68, 5});  // call with initializer list

    convertF2C4(-40, 0, 32, 98, 212);  // call with fold expression

    // call prompt without def value - must parameterize T
    // warning for nodiscard
    prompt<string>("Enter y or n");

}