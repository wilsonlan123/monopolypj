# MonoPoly 


# Identification of Team Members:
## Team Member 1: Chan Ka Ho
## Team Member 2: Coggins Oscar Louis
## Team Member 3: Wang Man Kit
## Team Member 4: Lan Lik Wai
## Team Member 5: Yeo Kiah Huah


# Game Description and Game Rules (Problem statement)
This is a multiplayer monopoly game. 
In this game, you can play with different friends.
Each player starts the game with $1500M.
Each player places his token on the corner marked "Start", and throw the dice and move his the number of spaces indicated by the dice.
The tokens remain on the spaces occupied and proceed from that point on the player's next turn.
Two or more tokens may rest on the same space at the same time.
Depending on the space the token reaches, you may buy the property, or be obliged to pay rent, pay taxes or etc...

The game can be played with at most 4 players. After running the game code, some questions will pompt up.
By answering the questions, you can set players to either real person or NPC.
You can play with other people or play against computers if you want.

## Buying Property
When you land on an unowned property you can buy that property from the Bank at its printed price.
You receive the Title Deed card showing ownership.
Of course, you are allowed to decline the option to buy the property.

## Paying Rent
When you land on a property that is owned by another player, the owner collects rent from you.
It is more advantageous to have houses or hotels on properties because then rents become much higher.

## MiniGames
When you land on a minigame space, you will start to play a random mini game.
You will be rewarded certain amount of money if you win the game, or lose an amount of money if you lose the game.
More information about the minigames will be explained in the following sections.

### 1. Dice Rolling Game
Player will play against a bot.
In this game, both players take turn make a correct guess within 4 randomly-generated dice.
For example, Player 1 has 4 dice, he takes a guess of 3, fortunately, dice are [3,4,2,3] after the round.
Notice there are two <3> in the dice. Hence, he can eliminate 2 dice.
He still has 2 more dice to guess.
Player with 0 dice left will win the game

### 2. OneInAHundred Game
In this game, player will play against a bot.
Both player and the bot are going to keep guessing a number until either of them guess the correct GOLDEN NUMBER.
They will be given the range of the number before every guess, and the range will become smaller each time a guess is made.
Winner will be rewarded 500m!
Loser will be penalized 500m from his balance!

### 3. Hangman Game 
In this game, each player will take turns to guess a five-letter word which is related to programming.
After guessing a letter, the program will tell whether the guess is correct. 
If the guess is incorrect, one chance will be deducted.
They will have eight chances in total. The more chances left when they win, the more they can earn.

## 4. DrawnEarn Game 
In this game, each player will draw a random number ranged from 1-500. 
Players will be ranked according to their numbers.
The higher rank, the more they will get!

## Bankruptcy
You are declared bankrupt if you owe more than you can pay to another player or to the Bank.
If your debt is to another player, you must turn over all that you have to that player.
If you own houses or hotels, you must return these to the Bank in exchange for money to the extent of one-half the amount paid for them and this cash is given to the creditor.

## End of the Game
Bankrupt players must retire from the game.
Players can opt to terminate the game after each round.
The player with the highest bank balance will become the winner.

# Features
1. Generation of random game sets or events -> rolling dice by generating a random number between 1-6 and generate a random number to decide which minigame players will play when they lend on minigame boxes
2. Program codes in multiple files -> codes of the monopoly and minigames are seperated to multiple files
3. Proper indentation and naming styles -> codes are indented properly and names of the function is easy to understand e.g. Rolladice, PrintBoard, PrintBalance, bankrupt, etc.
4. In-code documentation -> there are comments in the code introducing the functions to increase the readability
5. Data structures for storing game status -> data of the player is stored in a global struct variable that helps managing
6. Dynamic memory management -> assigning the memory space during the execution time or the run time, and delete dynamic arrays to avoid memory leak.

# Non-standard libraries
There are no non-standard libraries used in the program.

# Compilation and Execution Instruction
Run "make main" to compile the file.
Run "./main" to start the game.


