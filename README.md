Part 2: Coding Challenge
====================
This coding challenge involves designing and implementing an algorithm and executable for a particular use case (specified in the problem statement below).
We consider it very challenging (but possible) to create a fully working and robust solution in as little as one day, but we have designed this challenge with the assumption that most teams will not create a fully-working solution in the time allotted.

You will be delivering two things: [1] The codebase you develop for this exercise, [2] A document explaining your thinking about how you would keep going in order to reach an optimal solution.

You will be evaluated based on [A] being able to show reasonable progress towards a solution (i.e. a codebase which could be suitable for future development that would eventually arrive at a fully-working solution) and [B] providing a detailed document that shows that, given additional time, the team has strong ideas about how to continue working towards a solution, as well as clear insights about how to organize the codebase to facilitate this effort.

We will consider any submissions that strongly show [A] and [B] as a success, even when a
fully-working solution has not yet been achieved. In fact, we would rather your team allocate appropriate time to do a good job on [B] rather than just allocating the entire time to writing code. Your codebase can be implemented in whatever programming language you choose, so long as we will be able to run it successfully based on your instructions. For instance C++, Java, or other common languages are suitable choices, and we recommend picking a language your team is comfortable with so you can showcase your best work.
In addition to sending us your code, along with instructions for how to compile/run it, please also include a document which covers:
● An explanation of the best algorithms you’ve designed, and assessment of whether they
work (and if they don’t fully work, please provide comments about why you believe they don’t fully work)
● An explanation of future algorithmic ideas your team would intend to try given more time
● A commentary on the design of the codebase, including any major changes you would make
given more time (for instance, you may decide near the end of your 4 days, that you would
prefer to refactor some parts of the code -- this is your chance to explain clearly how the refactored codebase would look different if the team was given additional time).
We are more concerned about the long-term point the team and codebase would arrive at, so we will place significant weight on the ideas outlined in your document, not just the code you provide.

Problem Statement:
We have typed a passage onto a sheet of paper and then passed the sheet of paper through a linear paper shredder. The result is 19 strips of paper that are scrambled up and represented below (best viewed using a fixed width font).


|de|  | f|Cl|nf|ed|au| i|ti|  |ma|ha|or|nn|ou| S|on|nd|on|
|ry|  |is|th|is| b|eo|as|  |  |f |wh| o|ic| t|, |  |he|h |
|ab|  |la|pr|od|ge|ob| m|an|  |s |is|el|ti|ng|il|d |ua|c |
|he|  |ea|of|ho| m| t|et|ha|  | t|od|ds|e |ki| c|t |ng|br|
|wo|m,|to|yo|hi|ve|u | t|ob|  |pr|d |s |us| s|ul|le|ol|e |
| t|ca| t|wi| M|d |th|"A|ma|l |he| p|at|ap|it|he|ti|le|er|
|ry|d |un|Th|" |io|eo|n,|is|  |bl|f |pu|Co|ic| o|he|at|mm|
|hi|  |  |in|  |  | t|  |  |  |  |ye|  |ar|  |s |  |  |. |

The above text can be viewed as 19 columns, each separated by |. The order of these 19 columns have been randomly selected. It is possible, by changing the order of the columns back to the original order, to reveal the original text.

Your task is to build an executable capable of taking in scrambled data of this format, and reconstructing what it hypothesizes is the original text. Your solution should work not only for the example input above, but also for other inputs of a similar nature (i.e, we are asking you to build a general solution for English text, not just descramble this particular example case).

You may find the datasets on this page useful:
https://www.kilgarriff.co.uk/bnc-readme.html
A brute force approach is unlikely to be scalable, so we recommend implementing a greedy search or a heuristic driven search of the space of possible documents that can be constructed by reordering the columns.

Based on an honor system, we will expect that all the code you submit is your original work. Feel free to use the internet as a general reference as you would during a typical work day, but please refrain from discussing the problem with anyone outside your team, and please refrain from looking up solutions to this particular problem.

Extra credit:
Feel free to also implement a similar solution for text in your Native Language. (You can receive extra-credit for doing this, even if you do not complete a fully-working solution in either language.

For instance, can you design your codebase in such a way that it can support two or more different languages, and so that part of the code is general and language agnostic, while the language-specific code is clearly encapsulated?).
