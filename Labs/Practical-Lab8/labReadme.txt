If your vector wasn't properly designed, it doesn't follow that you will fail the assignment. We are not taking an "all or nothing" approach in marking. But if you have not demonstrated Assignment 1 or progress on the Assignment, no marks can be given.

If you haven't completed assignment 1, you will still need to complete it. Doing badly in assignment 1 is not catastrophic. Assignment 2 is worth about double of Assignment 1, so you have an opportunity to catch up. 

The best advice is start early. See question 4 in lab 8. You will need to get multi-file reading completed now.

Assignment 2 will make use of Assignment 1 with added data structures (map and BST). These would be done in the lab work. Like assignment 1, the lab work is essential to enable completion of the assignment in the two week time frame allocated to it.

When working on the lab exercises marked as preparation for assignment, pay close attention to the SOLID principles. The amount of work that you will have to do to complete the assignment is dependent on good design and the implementation of this design.

Everything you write must be tested before use in the assignments. Test every routine/method/class before it gets used. Industry is pushing hard on us. They need graduates with particular skills.

After you have completed what is required for the assignment preparation, complete the calculator exercise.

For the exercise with the calculator: 

Suggest you write down in structured English what is happening in the Animation.
"What" not "how". 

That is what your main program will look like to keep the solution at the same level of abstraction as the problem.

You will notice that in the first row of the animation has the entire expression. An array will not store values of different types in the same array. You can't store a number and an operator in the same array. One possible solution is to derive two classes from a base type, one for numbers and the other for operators. The array then stores references or pointers of the base type. This would enable both operators and numbers in the same array. But think about this approach. Do values and operators exhibit an is-a relationship with some common (shared) base type? If the answer is no then it is misuse of the inheritance mechanism for programming convenience. So what other approach can you use?

You can keep it as the input string and parse as needed.

