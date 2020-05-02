#include "Hangman.hpp"
using namespace std;
void print(std::vector<char> vect) {
    for (char c : vect) {
        std::cout << c << " ";
    }
    std::cout << "\n";
}
    std::vector<std::string> words = {"Awkward",
                                      "Bagpipes",
                                      "Banjo",
                                      "Bungler",
                                      "Croquet",
                                      "Crypt",
                                      "Dwarves",
                                      "Fervid",
                                      "Fishhook",
                                      "Fjord",
                                      "Gazebo",
                                      "Gypsy",
                                      "Haiku",
                                      "Haphazard",
                                      "Hyphen",
                                      "Ivory",
                                      "Jazzy",
                                      "Jiffy",
                                      "Jinx",
                                      "Jukebox",
                                      "Kayak",
                                      "Kiosk",
                                      "Klutz",
                                      "Memento",
                                      "Mystify",
                                      "Numbskull",
                                      "Ostracise",
                                      "Oxygen",
                                      "Pajama",
                                      "Phlegm",
                                      "Pixel",
                                      "Polka",
                                      "Quad",
                                      "Quip",
                                      "Rhythmic",
                                      "Rogue",
                                      "Sphinx",
                                      "Squawk",
                                      "Swivel",
                                      "Toady",
                                      "Tweflth",
                                      "Unzip",
                                      "Waxy",
                                      "Wildebeest",
                                      "Yacht",
                                      "Zealous",
                                      "Zigzag",
                                      "Zippy",
                                      "Zombie"};
    int size = words.size();
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 49);
int main() {
    std::cout << "Would you like to play a game of hangman? [y/n]\n";
    std::string answer;
    bool run = true;
    while (run) {
        std::cin >> answer;
        for (int i = 0; i < answer.size(); i++) {
            answer[i] = tolower(answer[i]);
        }
        if (answer == "n") {
            std::cout << "Maybe next time!\n";
            return 0;
        } else if (answer == "y") {
            std::cout << "Ok let's play!\n";
            run = false;
        } else {
            std::cout << "Please choose between y or n!\n";
        }
    }


    int guesses = 0;
    std::cout << "For this game of hangman, you will have 10 guesses before I win!\n";
    int rand_int = dist(mt);
    std::string word = words[rand_int];
    word[0] = tolower(word[0]);
    std::cout << "This is the word I have chosen!: " << word << "\n";
    std::cout << "I have chosen my word. Let's play!\n";
    std::cout << "** HANGMAN **\n";
    std::cout << "*************\n";
    std::cout << "Make your guess by typing in a letter. If more than one letter is found, the first letter will be the accepted one!\n";
    std::cout << "\n";
    std::vector<char> letters;
    for (int i = 0; i < word.size(); i++) {
        letters.push_back('_');
    }
    print(letters);
    std::vector<bool> correct;
    bool exit = false;
    while (guesses < 10 && !exit) {
        bool wasIn = false;
        char guess;
        std::cin >> guess;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                letters[i] = guess;
                print(letters);
                correct.push_back(1);
                wasIn = true;
            }
        }
        if (!wasIn) {
            guesses += 1;
        }
        std::cout << "This is the number of guesses you have left: " << 10 - guesses << "\n";
        if (std::accumulate(correct.begin(), correct.end(), 0) == word.size()) {
            std::cout << "Congratulations!, you have successfully completed the game!\n";
            exit = true;
        }
    }
    if (guesses == 10) {
        std::cout << "You have not finished the game! I win!";
    }
}