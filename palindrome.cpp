#include <iostream>
#include <deque>
#include <string>
#include <cctype>

template<class T>
class MyStack {
private:
    std::deque<T> data;
public:
    void push(T value) {
        data.push_back(value);
    }
   
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }
   
    T top() {
        if (!data.empty()) {
            return data.back();
        }
        return T();
    }
   
    bool empty() {
        return data.empty();
    }
   
    int size() {
        return data.size();
    }
};

template<class T>
class MyQueue {
private:
    std::deque<T> data;
public:
    void push(T value) {
        data.push_back(value);
    }
   
    void pop() {
        if (!data.empty()) {
            data.pop_front();
        }
    }
   
    T front() {
        if (!data.empty()) {
            return data.front();
        }
        return T();
    }
   
    bool empty() {
        return data.empty();
    }
   
    int size() {
        return data.size();
    }
};

class PalindromeChecker {
private:
    MyStack<char> stack;
    MyQueue<char> queue;
   
public:
    bool isPalindrome(std::string s) {
        // Limpiar stack y queue anteriores
        while (!stack.empty()) stack.pop();
        while (!queue.empty()) queue.pop();
        
        // Llenar el stack y el queue solo con letras (ignorar mayúsculas/minúsculas)
        for (char c : s) {
            if (std::isalpha(c)) {  // Solo letras
                char lower = std::tolower(c);
                stack.push(lower);
                queue.push(lower);
            }
        }
        
        // Comparar: stack pop (último -> primero) vs queue front (primero -> último)
        while (!stack.empty() && !queue.empty()) {
            if (stack.top() != queue.front()) {
                return false;
            }
            stack.pop();
            queue.pop();
        }
        
        return true;
    }
};

// Ejemplo simple de recorrido de string con []
void ejemploRecorridoString() {
    std::string palabra = "hola";
   
    std::cout << "=== Ejemplo: Recorrer string con [] ===" << std::endl;
    std::cout << "Palabra: " << palabra << std::endl;
    std::cout << "Caracteres:" << std::endl;
   
    for (int i = 0; i < palabra.length(); i++) {
        std::cout << " palabra[" << i << "] = " << palabra[i] << std::endl;
    }
   
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
}

int main() {
    // Mostrar ejemplo de recorrido
    ejemploRecorridoString();
   
    // Pruebas de palíndromos
    PalindromeChecker checker;
   
    std::cout << "=== Verificación de Palíndromos ===" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "oso: " << checker.isPalindrome("oso") << std::endl;
    std::cout << "reconocer: " << checker.isPalindrome("reconocer") << std::endl;
    std::cout << "neuquen: " << checker.isPalindrome("neuquen") << std::endl;
    std::cout << "radar: " << checker.isPalindrome("radar") << std::endl;
    std::cout << "salas: " << checker.isPalindrome("salas") << std::endl;
    std::cout << "somos: " << checker.isPalindrome("somos") << std::endl;
    std::cout << "anita: " << checker.isPalindrome("anita") << std::endl;
    std::cout << "python: " << checker.isPalindrome("python") << std::endl;
    std::cout << "racecar: " << checker.isPalindrome("racecar") << std::endl;
    std::cout << "hello: " << checker.isPalindrome("hello") << std::endl;
    std::cout << "level: " << checker.isPalindrome("level") << std::endl;
    std::cout << "world: " << checker.isPalindrome("world") << std::endl;
   
    return 0;
}
