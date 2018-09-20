# Machine-Language-Simulator

This is simple simulator of machine language. All instruction write by WORD(signed four-digit decimal number), like a +1009, 
where two left characters are the code of operation, and two right characters are an address of memory cell.

Memory can keep 100 of words and these words available by numbers 00, 01, ... 99.

The following description is list of basic operations for simulation:

10 - READ word from terminal in specified memory cell
11 - WRITE word from specified memory cell in terminal
20 - LOAD word from specified memory cell in accumulator
21 - STORE word from accumulator in specified memory cell
30 - ADD word from specified memory cell and word in accumulator
31 - SUBSTRACT word from specified memory cell word in accumulator
32 - DIVIDE word from specified memory cell by word in accumulator
33 - MULTIPLY word from specified memory cell on word in accumulator
40 - transfer control to the specified memory cell
41 - transfer control to the specified memory cell if value in accumulator is negative
42 - transfer control to the specified memory cell if value in accumulator is zero
43 - HALT of program
