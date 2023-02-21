#include <string>
#include <stdexcept>

struct EmptyStackError : std::runtime_error {
    EmptyStackError() : std::runtime_error("stack is empty"){};
    EmptyStackError(const std::string& msg) : std::runtime_error(msg){}; 
};

struct FullStackError : std::runtime_error {
    FullStackError() : std::runtime_error("stack is full"){};
    FullStackError(const std::string& msg) : std::runtime_error(msg){}; 
};


template<typename T, size_t S>
class Stack {

    public:

    // T peek(): returns the top item without removing it from the stack. 
    // throw EmptyStackError if stack is empty

    T peek() {
        if(top == 0) throw EmptyStackError();

        return store[top - 1];
    }

    // bool empty(): returns true if the stack is empty or false otherwise
    
    // void push(T item): push the item onto stack
    // throw FullStackError if stack is full

    // void pop(): removes the top item from the stack
    // throw EmptyStackError if stack is empty

    private:

        T store[S];
        size_t top{0}; // top = next available element


};