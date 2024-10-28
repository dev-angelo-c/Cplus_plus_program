// Crish_Project_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>


// MODEL
std::map<std::string, int> Read_File() {

    std::ifstream inFS;     // Input file stream
    std::string item;
    std::map<std::string, int> wordCount;
    std::string word;

    // Try to open file
    std::cout << "Reading from file " << std::endl;

    inFS.open("C:\\Users\\Angelo\\Documents\\Grocery_List.txt");

    if (!inFS.is_open()) {
        std::cout << "Could not open file Grocery_List.txt." << std::endl;
    }

    // Read each word from the file and count
    while (inFS >> word) {
        wordCount[word]++;
    }

    if (!inFS.eof()) {
        std::cout << "Input failure before EOF." << std::endl;
    }

    // Done with files, close
    inFS.close();

    std::cout << "Operation Complete." << std::endl;

    //Must Return Map;
    return wordCount;
}

class Data_Backup {
    private:
        void BuildBackupFile();
};

// Types
class DisplayUI {
    public:
        void DisplayGroceryMenu();
};

class Menu_Option_3 {
    public:
        void Build_Histogram(std::map<std::string, int>& data);
};

class Menu_Option_2 {
    // Read File 
    // Build A Map
    // Display Results
    public: 
        std::map<std::string, int> Controller_Perform_Count(std::map<std::string, int>& data);
        void View_Grocery_List(std::map<std::string, int>& results);
};

class Menu_Option_1 {
    public:
        void Controller_Count_Search_Results(std::string search_val, std::map<std::string, int>& data);
        std::string View_Search_Intro();
};


// Definitions - Going with a rough version of MVC for brevity and uniformity

/*
    BACKUP
*/

void Data_Backup::BuildBackupFile() {
    // Did not complete
    std:: cout << " Incomplete Back up " << std::endl;
}

/*
    MENU OPTION 1
*/
void Menu_Option_1::Controller_Count_Search_Results(std::string search_val, std::map<std::string, int>& data) {
    std::cout << "Searching for: " << search_val << std::endl;

    if (data.count(search_val) > 0) { // Check if the iterator points to a valid entry
        std::cout << "Result: " << std::endl;
        std::cout << search_val << " : " << data[search_val] << std::endl;
    } else {
        std::cout << " NOT FOUND " << std::endl;
    }

    
};

std::string Menu_Option_1::View_Search_Intro() {
    std::string searchQuery;
    std::cin >> searchQuery;
    std::cout << "Please Enter Search Term:  " << searchQuery << std::endl;

    return searchQuery;
};


/*
    MENU OPTION 2
*/
std::map<std::string, int> Menu_Option_2::Controller_Perform_Count(std::map<std::string, int>& data) {
    std::map<std::string, int> wordCount;
    std::vector<std::string> words;
    // {oranges: 2, apples: 3, ...}

    return data;
}

void Menu_Option_2::View_Grocery_List(std::map<std::string, int>& data) {
    printf("%-22s %-22s\n", "Item", "Count");

    for (const auto& items : data) {
        printf("%-22s %-22d\n", items.first.c_str(), items.second);
    }

}


/*
    MENU OPTION 3
*/

void Menu_Option_3::Build_Histogram(std::map<std::string, int>& data) {
    printf("%-22s %-22s\n", "Item", "Count");

    for (const auto& items : data) {
        std::string asterisks(items.second, '*');
        // Print item name followed by the asterisks
        printf("%-22s %-22s\n", items.first.c_str(), asterisks.c_str());    
    }
}

/*
    VIEW - Welcome Menu
*/
void DisplayUI::DisplayGroceryMenu() {
    // Check if the amount added is valid or not
    // unsigned int i;

    // Print grocery menu table;
    // Handle input in following function;
    printf("-----------------------------------------------------------\n");
    printf("%-44s\n", "Grocery Menu");
    printf("%-22s %-22s\n", "Option", "Description.");
    printf("-----------------------------------------------------------\n");

    printf("%-22s %-22s\n", "1", "Search");
    printf("%-22s %-22s\n", "2", "Count");
    printf("%-22s %-22s\n", "3", "Histogram");

    printf("-----------------------------------------------------------\n");
    
    std::cout << "Please select an option(1, 2, 3) or 'q' to quit" << std::endl;
}



int main(){
    int shallContinue = -1;
    int gatherResponse;
    std::string query;
    std::map<std::string, int> resultsReference, results;
    DisplayUI display;
    Menu_Option_1 menu1;
    Menu_Option_2 menu2;
    Menu_Option_3 menu3;

    //We're going to run this once and keep alive until the program quits.
    // Because the functionality is so similiar 
    // we're only going to need to change the view
    resultsReference = Read_File();

    do {
        display.DisplayGroceryMenu();
        std::cin >> gatherResponse;

        if (gatherResponse == 1) {
            std::cout << "You have chosen: " << "Search... " << std::endl;
            query = menu1.View_Search_Intro();
            menu1.Controller_Count_Search_Results(query, resultsReference);
            shallContinue = 0;
    
        }
        else if (gatherResponse == 2) {
            std::cout << "You have chosen: " << "Count..." << std::endl;
            results = menu2.Controller_Perform_Count(resultsReference);
            menu2.View_Grocery_List(results);
            shallContinue = 0;

        }
        else if (gatherResponse == 3) {
            std::cout << "You have chosen: " << "Histogram... " << std::endl;
            menu3.Build_Histogram(resultsReference);
            shallContinue = 0;
        }
        else {
            std::cout << "Not an option " << gatherResponse << std::endl;
            std::cout << "Quitting..." << std::endl;
            printf("-----------------------------------------------------------\n");
            shallContinue = -1;
        }
    } while (shallContinue != -1);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
