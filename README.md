Catan-Ex3

In this project, I implemented the game of Catan. The game board contains 19 hexagons, each of which holds a resource that players can acquire if they have a settlement or city adjacent to it. The game begins with each player choosing 2 initial settlements and 2 roads, and receiving starting resources as a result of this initial selection. Then, each player takes turns rolling 2 dice, and according to the dice roll, players receive additional resources. The player whose turn it is can trade cards or resources with other players, build roads, settlements, or cities, or buy and use development cards. The game ends when a player reaches 10 victory points, which are accumulated based on the number of cities and settlements each player has, in addition to the number of victory cards they hold.
Classes and Files
Player Class

This class handles all aspects of gameplay from the player's side. It includes functions for trading between players, building settlements, roads, or cities, buying or using development cards, and more "basic" functions like printing the number of resources or cards a player has.
Board Class

This class contains a vector of hexagons, each representing a tile on the game board that holds a resource provided to players during gameplay. This class is responsible for defining and constructing the board, including creating vertices, edges, and hexagons, and assigning the necessary variables to each (e.g., neighboring vertices, neighboring edges, which vertices each edge and hexagon contain, etc.). Additionally, it includes a function to print the game board.
Catan Class

This class is responsible for rolling the dice, determining the starting player, and executing the gameplay.
Card and Development Card Classes

Here, we implement inheritance by creating a general card class, and each specific type of card inherits from the general card class, creating a new card of its unique type. When a specific card is played, the player receives the bonus that the card provides.
Demo File

In the demo file, a regular game run is executed. The game is played with 3 people, and using this file, a full game can be played.
Usage

To run the game, compile and execute the demo file. The game supports full gameplay with 3 players, allowing you to build settlements, roads, and cities, trade resources, buy and use development cards, and aim to reach 10 victory points to win.
