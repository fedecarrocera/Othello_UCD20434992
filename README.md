# Othello_UCD20434992
Project 2
For the othello Project i decided to have a 2d array of numbers where 1 was black 2 was white and 0 was a blank space.
This allowed me to write functions that could check if the values of each box lets say were black or white pieces or blank.
I created functions that check every possible way to play so left to right from bottom to top and so on
If conditions where met they would validate their move and change a second 2d array that would hold those moves until the turn was over,
this was done as i cannot run multiple functions at the same time and it would have been wrong if pieces that got flipped in the same turn then affected other moves in the same turn
after the 2d array gets copied into the board which is the array i use to validate
the game should end if there are no places left or if both players pass in a row as that means neaither could play
that is the principle i based my end game on.
