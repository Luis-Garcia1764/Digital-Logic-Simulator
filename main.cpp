#include <iostream>
#include <string>
#include "Gate.hpp"
#include <limits>

int main(void) {

    char again;

    std::cout << "Would you like to build some digital logic?" << std::endl;
    std::cout << "Type y to proceed." << std::endl;
    std::cin >> again;

    int currentOutput = 0;
    bool hasOutput = false;

    while (again == 'y' || again == 'Y') {

        int choice;
        int a;
        int b;
        int result = 0;

        std::cout << "Select a Gate choice (1-6): " << std::endl;
        std::cout << "1. AndGate\n";
        std::cout << "2. NorGate\n";
        std::cout << "3. OrGate\n";
        std::cout << "4. NotGate\n";
        std::cout << "5. NandGate\n";
        std::cout << "6. XorGate\n";

        std::cin >> choice;

        if (choice < 1 || choice > 6) {
            std::cout << "Invalid choice" << std::endl;
            continue;
        }

        if (choice == 4) {

            NotGate gate("NOT");

            while (true) {

                if (hasOutput) {

                    char usePrevious;

                    std::cout << "Use previous output as A? (y/n): ";
                    std::cin >> usePrevious;

                    if (usePrevious == 'y' || usePrevious == 'Y') {
                        a = currentOutput;
                    }
                    else if (usePrevious == 'n' || usePrevious == 'N') {

                        std::cout << "Enter A: ";

                        if (!(std::cin >> a)) {
                            std::cout << "Invalid data type.\n";

                            std::cin.clear();
                            std::cin.ignore(
                                std::numeric_limits<std::streamsize>::max(),
                                '\n'
                            );

                            continue;
                        }
                    }
                    else {
                        std::cout << "Invalid choice.\n";
                        continue;
                    }
                }
                else {

                    std::cout << "Enter A: ";

                    if (!(std::cin >> a)) {
                        std::cout << "Invalid data type. Enter 0 or 1.\n";

                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(),
                            '\n'
                        );

                        continue;
                    }
                }

                if (a != 0 && a != 1) {
                    std::cout << "Invalid binary input.\n";
                    continue;
                }

                break;
            }

            result = gate.evaluate(a, 0);

            std::cout << gate.getName()
                      << "(" << a << ") = "
                      << result
                      << std::endl;
        }

        else {

            while (true) {

                bool aSet = false;
                bool bSet = false;

                if (hasOutput) {

                    char usePrevious;

                    std::cout << "Use previous output? (y/n): ";
                    std::cin >> usePrevious;

                    if (usePrevious == 'y' || usePrevious == 'Y') {

                        char inputChoice;

                        std::cout << "Use previous output as A or B? (a/b): ";
                        std::cin >> inputChoice;

                        if (inputChoice == 'a' || inputChoice == 'A') {
                            a = currentOutput;
                            aSet = true;
                        }
                        else if (inputChoice == 'b' || inputChoice == 'B') {
                            b = currentOutput;
                            bSet = true;
                        }
                        else {
                            std::cout << "Must be A or B.\n";
                            continue;
                        }
                    }
                    else if (usePrevious != 'n' && usePrevious != 'N') {
                        std::cout << "Invalid choice.\n";
                        continue;
                    }
                }

                if (!aSet) {

                    std::cout << "Enter A: ";

                    if (!(std::cin >> a)) {
                        std::cout << "Invalid data type.\n";

                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(),
                            '\n'
                        );

                        continue;
                    }
                }

                if (!bSet) {

                    std::cout << "Enter B: ";

                    if (!(std::cin >> b)) {
                        std::cout << "Invalid data type.\n";

                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(),
                            '\n'
                        );

                        continue;
                    }
                }

                if (a != 0 && a != 1) {
                    std::cout << "Invalid input of A for binary.\n";
                    continue;
                }

                if (b != 0 && b != 1) {
                    std::cout << "Invalid input of B for binary.\n";
                    continue;
                }

                break;
            }

            if (choice == 1) {

                AndGate gate("AND");

                result = gate.evaluate(a, b);

                std::cout << gate.getName()
                          << "(" << a << "," << b << ") = "
                          << result
                          << std::endl;
            }

            else if (choice == 2) {

                NorGate gate("NOR");

                result = gate.evaluate(a, b);

                std::cout << gate.getName()
                          << "(" << a << "," << b << ") = "
                          << result
                          << std::endl;
            }

            else if (choice == 3) {

                OrGate gate("OR");

                result = gate.evaluate(a, b);

                std::cout << gate.getName()
                          << "(" << a << "," << b << ") = "
                          << result
                          << std::endl;
            }

            else if (choice == 5) {

                NandGate gate("NAND");

                result = gate.evaluate(a, b);

                std::cout << gate.getName()
                          << "(" << a << "," << b << ") = "
                          << result
                          << std::endl;
            }

            else if (choice == 6) {

                XorGate gate("XOR");

                result = gate.evaluate(a, b);

                std::cout << gate.getName()
                          << "(" << a << "," << b << ") = "
                          << result
                          << std::endl;
            }
        }

        currentOutput = result;
        hasOutput = true;

        std::cout << "\nWould you like to build another gate?" << std::endl;
        std::cout << "Type y to proceed: ";
        std::cin >> again;
    }

    return 0;
}