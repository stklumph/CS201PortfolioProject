# CS201PortfolioProject
Portfolio Project for CS201 Spring 2019

## Getting Started
* Video Tutorial - https://youtu.be/BNaGMA9UlA8

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
1. Download the repository as a zip file
2. Extract the files
3. Download the dictionary file, and name it "dictionary.txt"
4. Move to the directory where the extracted files are located
5. Run the make file to compile it
6. Run ./Boggle
This will start the program.
Images here are included for clarity
![clone1](https://i.imgur.com/7XB5Ua9.png)
![clone2](https://imgur.com/2BRfmF1)
![extract](https://imgur.com/meux86N)
![dictionary1](https://imgur.com/9MGNY4b)
![dictionary2](https://imgur.com/qQVC60r)
![directory](https://imgur.com/X4hgMg8)
![make](https://imgur.com/jaYaBEk)
![run](https://imgur.com/6WTD6cV)

## Program instructions

These instructions should run through the basics of the program.
1. Once the program starts up, it will load the dictionary, and then prompt for a Board size. Enter the board size as an integer, as the program will read it in, and produce an NxN board.
2. After this, the program will prompt for a seed, any integer number will do, this only matters if you want to check the same board more than Once.
3. The board will then be generated and solved, and the game will start. There are a number of commands available to assist the testing experience, !help lists all of them.
  * !cheat will list all of the words that are found in the board, based on the dictionary
  * !print will print the board again
  * !exit will end the current game
  * !help will display the list of commands
4. Once the Game starts, enter words that are found on the board to gain points, points are awarded based on the standard boggle rules.
5. When you have finished entering words, type !exit to end the game, and the program will display your final score, the maximum possible score for the board, and what your current high score is
6. The program will then prompt you if you would like to play another game. If you do, type "yes", if you do not, type "no".
7. If you type yes, the program will prompt you for another board size and seed, and another game will be run, if you type no, the program will close.



### Dictionary File

* Found here http://boulter.com/scrabble/words/words.txt
* Using this dictionary is highly recommended as it requires no pre-processing to work with the program
* NOTE: make sure to name the file "dictionary.txt" or the program will NOT work. This goes for any dictionary file that you want to use.

## Built With

* C language
* Originally Run on Cygwin (https://www.cygwin.com/) - used for Linux environment
* Coded in Atom (https://atom.io/)


## Authors

* **Seth Klumph** - Email: stklumph@crimson.ua.edu


## Acknowledgments

* Code borrowed from geeksforgeeks for Trie implementation https://www.geeksforgeeks.org/trie-insert-and-search/
* Code base used for DFS from geeksforgeeks https://www.geeksforgeeks.org/find-number-of-islands/
* Code used for djb2 Hash Function http://www.cse.yorku.ca/~oz/hash.html
* Also thanks to Purple Booth for the formatting tips on the readme https://gist.github.com/PurpleBooth/109311bb0361f32d87a2
