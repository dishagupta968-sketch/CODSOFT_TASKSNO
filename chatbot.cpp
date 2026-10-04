 #include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert text to lowercase
string toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

int main() {
    string userInput;

    cout << "======================================" << endl;
    cout << "       RULE-BASED CHATBOT" << endl;
    cout << "======================================" << endl;
    cout << "Chatbot: Hello! I am your chatbot." << endl;
    cout << "Chatbot: Type 'bye' to exit." << endl;

    while (true) {

        cout << "\nYou: ";
        getline(cin, userInput);

        // Convert input to lowercase
        string input = toLowerCase(userInput);

        // Rule 1: Greeting
        if (input == "hello" || input == "hi" || input == "hey") {
            cout << "Chatbot: Hello! How are you?" << endl;
        }

        // Rule 2: Asking name
        else if (input.find("your name") != string::npos) {
            cout << "Chatbot: My name is RuleBot." << endl;
        }

        // Rule 3: Asking how chatbot is
        else if (input.find("how are you") != string::npos) {
            cout << "Chatbot: I am fine! Thanks for asking." << endl;
        }

        // Rule 4: Asking about capabilities
        else if (input.find("what can you do") != string::npos) {
            cout << "Chatbot: I can answer simple questions using predefined rules." << endl;
        }

        // Rule 5: Asking about programming
        else if (input.find("programming") != string::npos ||
                 input.find("coding") != string::npos) {
            cout << "Chatbot: Programming is the process of creating instructions for a computer." << endl;
        }

        // Rule 6: Asking about C++
        else if (input.find("c++") != string::npos) {
            cout << "Chatbot: C++ is a powerful programming language used for software, games, DSA and more." << endl;
        }

        // Rule 7: Thanks
        else if (input.find("thank") != string::npos) {
            cout << "Chatbot: You're welcome!" << endl;
        }

        // Rule 8: Goodbye
        else if (input == "bye" || input == "goodbye" ||
                 input.find("see you") != string::npos) {
            cout << "Chatbot: Goodbye! Have a nice day!" << endl;
            break;
        }

        // Rule 9: Unknown input
        else {
            cout << "Chatbot: Sorry, I don't understand that." << endl;
            cout << "Chatbot: Try asking about my name, coding, C++, or how I am." << endl;
        }
    }

    return 0;
}