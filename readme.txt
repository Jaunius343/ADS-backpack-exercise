Algorithms and data structures course

Backpack exercise:
You're given N things which have their weight s1, s2, ... , sN and price k1, k2, ... , kN respectively. 
Make a set of items which have the maximum possible price, but still fit in the bag with weight S.
User inputs weights and prices of the things also the maximum weight.

The idea behind this exercise was, that a greedy algorithm won't work. Unfortunately that was my first approach, 
the given file "duom.txt" consist of test values and is a great example why greedy algorithm isn't always working.
there are four items which make a 100 in value and weight 99, but there's also an item which's price is 98 and weights
100. Obviously those four items have higher value in total, but following the greedy algorithm, you would choose
the most expensive item first and other possibilities just stay neglected. The conclusion: all possible sets have to be
created and compared (knapsack algorithm)
