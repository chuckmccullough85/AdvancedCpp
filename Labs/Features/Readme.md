## Overview
Demonstrates new features in simple C++ code.

| | |
| --------- | --------------------------- |
| Exercise Folder | Features |
| Builds On | none |
| Time to complete | 45 minutes

> Note: This lab is a guided lab.  The instructor will lead you through the lab.  Follow along with your own code.  Feel free to ask questions at any time or ask the instructor to repeat a step.

### Starter Code
- Create a new project and paste the following code into the main.cpp file.

```cpp
#include <iostream>

using namespace std;

int prompt(string prompt, int def = 0) {
    cout << prompt << " [" << def << "]: "; // note, the default doesn't really work. The user must enter an integer.
    int value;
    cin >> value;
    return value;
}

int main() {
    int age = prompt("Enter your age");
    if (age > 0 && age < 120) {
        cout << "You would be " << age * 7 << " in dog years." << endl;
    }
    else {
        cout << "Invalid age." << endl;
    }
}
```

- The `prompt` function returns the user's choice or the default value if the user doesn't enter anything.
- If we call this method without capture the return value, the return value will be lost.  Annotate the `prompt` function with `[[nodiscard]]` to indicate that the return value should not be ignored.  Call the `prompt` function without capturing the return value to see the warning.
- The age variable declaration, initialization and the if statement can be combined into a single line.  Refactor the code to combine these lines:
```cpp
int age = prompt("Enter your age", 38);
if (age > 0 && age < 120) 
```
- Use `auto` to declare the `age` variable.  The compiler will infer the type from the return value of the `prompt` function.

### Initializer Lists
Add this code *before* the `main` function to demonstrate initializer lists:
```cpp
void convertF2C(initializer_list<int> temps) {
    auto it = temps.begin();
    while (it != temps.end()) {  // while loop
        auto temp = *it++;
        cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
    }
}
```
- Call the `convertF2C` function with an initializer list of temperatures.
- Now, modify the `convertF2C` function to be a template so that the list can be other integer types.  Use a constraint to limit the types to integral types. `integral` is a concept that represents all integral types.  Add the constraint to the template declaration:

- Now, change the iterator to a ranged-for loop.  The ranged-for loop will automatically iterate over the elements in the initializer list.  The `auto` keyword will infer the type of the elements in the list.

- Challenge:  Include the `<algorithm>` header and use the `for_each` algorithm to iterate over the elements in the initializer list.  Use a lambda function to convert the temperature from Fahrenheit to Celsius.

### Templates (CHALLENGE CHALLENGE)!

Add this code *before* the `main` function to demonstrate templates:
```cpp
void ShowF2C(auto temp) {
    cout << temp << "F is " << (temp - 32) * 5 / 9.0 << "C" << endl;
}
```
- Define a variadic template function  `convertF2C4` that takes a variable number of arguments.  
```cpp
template <typename... Args>
void convertF2C4(Args... args)
```
- Use a fold expression to call the `ShowF2C` function for each argument in the list.  The fold expression will expand the parameter pack and call the `ShowF2C` function for each argument in the list.

- Call _convertF2C4_ from the main function with a list of temperatures.