# C++ Templates
Templates are a powerful feature in C++ that allow for generic programming, which enables writing code that can work with different types without having to explicitly specify them. Templates provide a way to define generic classes, functions, or type aliases that can work with multiple data types, providing flexibility and reusability in code.

**Why are Templates Useful?**
Templates are useful because they allow for code reuse and reduce code duplication. With templates, you can define a generic algorithm or data structure that can be used with different types of data, without having to write multiple versions of the same code for each specific type. This can greatly improve code maintainability, as changes only need to be made in one place instead of multiple places.

Another benefit of templates is that they enable writing generic code that can adapt to different data types at compile-time, which can lead to optimized code without the overhead of runtime type checks or polymorphism.

**How do Templates Work during Compilation and Linking?**
Templates in C++ are generated at compile-time, which means that the compiler generates the appropriate code for each specific instantiation of the template. This is known as template instantiation. When a template is used with a specific type, the compiler generates the necessary code for that type by substituting the template parameters with the actual types.

Template code is usually defined in header files, as the definitions need to be available at the point of instantiation, which is where the template is used with a specific type. The compiler generates the template code during compilation, and the generated code is then linked with the rest of the program during the linking phase to produce the final executable.

It's important to note that template code is not actually compiled until it is instantiated with a specific type. This means that if a template is defined but not used in a program, it will not generate any code in the final executable, helping to keep the executable size minimal.

## Template Examples
### Function Template Example
```cpp
// Function template for finding the maximum of two values
template <typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int maxInt = findMax(5, 10);         // Template instantiated with int
    double maxDouble = findMax(3.14, 2.5); // Template instantiated with double
    return 0;
}
```
In this example, we define a function template findMax() that takes two arguments of type T (which is a template parameter representing a generic type) and returns the maximum value. The function template is then instantiated with both int and double types in the main() function.
### Class Template Example
```cpp
// Class template for a simple stack
template <typename T>
class Stack {
public:
    void push(T value) {
        // Implementation of push operation
    }

    T pop() {
        // Implementation of pop operation
        return T();
    }

private:
    // Implementation details
};

int main() {
    Stack<int> intStack;       // Template instantiated with int
    Stack<double> doubleStack; // Template instantiated with double
    return 0;
}
```
In this example, we define a class template Stack that represents a simple stack data structure. The class template has a template parameter T that represents the type of elements stored in the stack. The class template is then instantiated with both int and double types in the main() function to create two different stacks with different element types.

### Conclusion
Templates in C++ are a powerful feature that allow for generic programming, enabling code reuse and flexibility. They are compiled at compile-time, and the template code is generated during
