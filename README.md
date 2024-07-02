# Catan-Ex3

In this project, I implemented the game of Catan. The game board contains 19 hexagons, each of which holds a resource that players can acquire if they have a settlement or city adjacent to it. The game begins with each player choosing 2 initial settlements and 2 roads, and receiving starting resources as a result of this initial selection. Then, each player takes turns rolling 2 dice, and according to the dice roll, players receive additional resources. The player whose turn it is can trade cards or resources with other players, build roads, settlements, or cities, or buy and use development cards. The game ends when a player reaches 10 victory points, which are accumulated based on the number of cities and settlements each player has, in addition to the number of victory cards they hold.
## Classes and Files
### Player Class

This class handles all aspects of gameplay from the player's side. It includes functions for trading between players, building settlements, roads, or cities, buying or using development cards, and more "basic" functions like printing the number of resources or cards a player has.
### Board Class

This class contains a vector of hexagons, each representing a tile on the game board that holds a resource provided to players during gameplay. This class is responsible for defining and constructing the board, including creating vertices, edges, and hexagons, and assigning the necessary variables to each (e.g., neighboring vertices, neighboring edges, which vertices each edge and hexagon contain, etc.). Additionally, it includes a function to print the game board.
### Catan Class

This class is responsible for rolling the dice, determining the starting player, and executing the gameplay.
### Card and Development Card Classes

Here, we implement inheritance by creating a general card class, and each specific type of card inherits from the general card class, creating a new card of its unique type. When a specific card is played, the player receives the bonus that the card provides.
### Demo File

In the demo file, a regular game run is executed. The game is played with 3 people, and using this file, a full game can be played.
### Usage

To run the game, compile and execute the demo file. The game supports full gameplay with 3 players, allowing you to build settlements, roads, and cities, trade resources, buy and use development cards, and aim to reach 10 victory points to win.
### Compiling and Running

To compile and run the project, make sure to include all necessary source files and dependencies. The provided Makefile includes the necessary setup for compiling the project with SFML for graphical visualization.
### GamePlay

    Each player chooses 2 initial settlements and 2 roads.
    Players receive starting resources based on their initial settlements.
    Players take turns rolling 2 dice and receiving resources based on the roll.
    On their turn, players can trade resources, build roads, settlements, or cities, or buy and use development cards.
    The game ends when a player reaches 10 victory points.

### Additional Information About Catan

Catan, also known as The Settlers of Catan, is a multiplayer board game designed by Klaus Teuber. It was first published in 1995 in Germany. Players assume the roles of settlers, each attempting to build and develop holdings while trading and acquiring resources. The game is known for its complex strategy, interaction between players, and a mix of luck and skill. Players earn points as they build settlements, cities, and roads, and the first player to reach a set number of points, usually 10, wins the game.
### Key Concepts:

    Resources: There are five types of resources in Catan: wood, brick, wheat, ore, and sheep. Players collect these resources to build and expand their settlements and cities.
    Settlements and Cities: Settlements and cities are the primary ways players earn victory points. Settlements are worth 1 point, and cities are worth 2 points.
    Development Cards: These cards can be purchased and provide various bonuses and abilities that can help players in the game.

### Strategy Tips:

    Diversify Resources: Try to have access to all types of resources to ensure you can build whatever you need.
    Trade Wisely: Trading with other players is a key component of the game. Always try to make trades that benefit you more than your opponent.
    Expand Quickly: Establishing settlements and cities early can help you control key areas of the board and secure more resources.

Enjoy playing Catan and may the best settler win!
