# Lesson 1: Introduction to Probability and Statistics

## Probability Theory
Probability Theory is a mathematical framework for computing the probability of complex events under the assumption taht we know the probabilities of the basic events.

## Flipping coins
When flipping a fair coin, the probability of the outcome being heads is the same as of it being tails.

Say, if we flip a coin 10,000 times, the number of heads should be about 5,000. We say about 5,000 instead of equal to 5,000 because the number will never be exactly 5,000. However, the greater the amount of tosses, the closer it'll get to that number.

There is a boundary for all the probabilities; the absolute value sum of the probabilities will be bigger than or equal to 4 times the square root of the number of coin throws. Anything outside that can be seen as a biased coin.

The Python Notebook 1.What-is-Probability explains more about this concept and simulates throwing coins.

## Statistics
In statistics, we are given some data and use that to infer properties of the data. Using our coin example, we could find out whether a coin is fair by calculating the probability of, in that amount of throws, having a certain amount of heads and compare that to the sum of the probabilities. This is shown in detail in the Python Notebook 2.What-is-Statistics_

## Three card puzzle
This is simulated and further explained in notebook 4.The-Three-Card-Puzzle.

In this puzzle, there are three types of cards; Red one side and blue the other (RB), blue one side and blue the other (BB) and red one side and red the toher (RR). Everytime, we pick a card at random. If the opposite side is a different color, you win one point. Else, you lose one point. If one side is blue, the other can either be red or blue; same with red (the other side can either be blue or red), so it's a fair game; you have a 50/50 chance of getting either blue or red. Correct? (If you can, run the simulation on the notebook to check this and think a bit).

The answer is no. Even though there are only two colors, there are three types of cards, so the porbability isn't 1/2, but 1/3.

## Long term frequecies
Notebook for this section: 3.Long-term-frequencies.
The notebook will explain in more detail and allow you to visualize this.
Long term frequencies: the assumption that the frequency of a highly repetited event will converge to a fixed number; the probability.
