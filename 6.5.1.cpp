/*
Input
Input data to the program specifies the order in which cards are dealt from 
the pack. The input contains pairs of lines, each line containing 26 cards
 separated by single space characters. The final line of the input file 
 contains a # as its first character. Cards are represented as a two 
 character code. The first character is the face-value 
 (A=Ace, 2-9, T=10, J=Jack, Q=Queen, K=King) and the second character is 
 the suit (C=Clubs, D=Diamonds, H=Hearts, S=Spades).
 
Output
One line of output must be produced for each pair of lines (that between them 
describe a pack of 52 cards) in the input. Each line of output shows the number
 of cards in each of the piles remaining after playing ``Accordian patience''
 with the pack of cards as described by the corresponding pairs of input lines.
 
Sample Input
 
QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S

8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C

AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AD 2D 3D 4D 5D 6D 7D 8D TD 9D JD QD KD

AH 2H 3H 4H 5H 6H 7H 8H 9H KH 6S QH TH AS 2S 3S 4S 5S JH 7S 8S 9S TS JS QS KS

#

 
Sample Output
 
6 piles remaining: 40 8 1 1 1 1

1 pile remaining: 52

麻烦的模拟。手写栈，每个pile都是个栈，用pos数组来记录位置和pile编号的关系。








*/


