#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
using namespace std;

class FiniteAutomaton {
public:
    int startState;
    set<int> acceptingStates;
    unordered_map<int, unordered_map<char, int>> transitions;

    // Constructor to initialize the automaton with start state and accepting states
    FiniteAutomaton(int startState, const set<int>& acceptingStates) {
        this->startState = startState;
        this->acceptingStates = acceptingStates;
    }

    // Function to add transitions to the automaton
    void addTransition(int fromState, char symbol, int toState) {
        transitions[fromState][symbol] = toState;
    }

    // Function to validate the input string
    bool validate(const string& inputString) {
        int currentState = startState;

        for (char c : inputString) {
            // If no transition exists for this symbol from the current state, return false
            if (transitions[currentState].find(c) == transitions[currentState].end()) {
                return false; // Invalid transition
            }
            currentState = transitions[currentState][c];
        }

        // Check if the final state is an accepting state
        return acceptingStates.find(currentState) != acceptingStates.end();
    }
};

int main() {
    // Number of input symbols
    int numSymbols;
    cout << "Number of input symbols: ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    cout << "Input symbols: ";
    for (int i = 0; i < numSymbols; ++i) {
        cin >> symbols[i];
    }

    // Number of states
    int numStates;
    cout << "Enter number of states: ";
    cin >> numStates;

    // Initial state
    int startState;
    cout << "Initial state: ";
    cin >> startState;

    // Number of accepting states
    int numAcceptingStates;
    cout << "Number of accepting states: ";
    cin >> numAcceptingStates;

    set<int> acceptingStates;
    cout << "Accepting states: ";
    for (int i = 0; i < numAcceptingStates; ++i) {
        int state;
        cin >> state;
        acceptingStates.insert(state);
    }

    // Create a finite automaton
    FiniteAutomaton fa(startState, acceptingStates);

    // Transition table input
    cout << "Transition table:\n";
    for (int i = 0; i < numStates; ++i) {
        for (char symbol : symbols) {
            int toState;
            cout << i + 1 << " to " << symbol << " -> ";
            cin >> toState;
            fa.addTransition(i + 1, symbol, toState);
        }
    }

    // Input string to be validated
    string inputString;
    cout << "Input string: ";
    cin >> inputString;

    // Validate the string using the finite automaton
    if (fa.validate(inputString)) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }

    return 0;
}
