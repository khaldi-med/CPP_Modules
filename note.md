## C++ notes

* `The most important thing to do when learning C++ is to focus on concepts and not get lost in
language-technical details. The purpose of learning a programming language is to become a better
programmer; that is, to become more effective at designing and implementing new systems and at
maintaining old ones. For this, an appreciation of programming and design techniques is far more
important than an understanding of details; that understanding comes with time and practice.`

* `However, ideas must be transformed into something that fits with the general structure and type system of C++ in order to be effective in the different context.Over the basic type system of a language, only Pyrrhic victories are possible.`

* `I assume that your purpose in learning C++ is not simply to learn a new syn-
tax for doing things the way you used to, but to learn new and better ways of building systems.`

* `If you plan to use C++ seriously, I strongly suggest that you gain access to such
sources. Each has its own emphasis and bias, so use at least two. For example, see [Barton,1994],
[Booch,1994], [Henricson,1997], [Koenig,1997], [Martin,1995], [Stroustrup,1994].`

* `C++ evolved hand-in-hand with some of the key classes presented in this book. For example, I
designed complex, vector, and stack classes together with the operator overloading mechanisms.`

* `In most cases, a cast is an indication of a design error.`


* `Ideally, you approach the task of designing a program in three stages. First, you gain a clear under-
standing of the problem (analysis), then you identify the key concepts involved in a solution
(design), and finally you express that solution in a program (programming).`


* `A C++ class is a type. That is, it specifies how objects of its class behave: how they
are created, how they can be manipulated, and how they are destroyed. A class may also specify
how objects are represented, although in the early stages of the design of a program that should not
be the major concern. The key to writing good programs is to design classes so that each cleanly
represents a single concept. Often, this means that you must focus on questions such as: How are
objects of this class created? Can objects of this class be copied and/or destroyed? What opera-
tions can be applied to such objects? If there are no good answers to such questions, the concept
probably wasn’t ‘‘clean’’ in the first place. It might then be a good idea to think more about the
problem and its proposed solution instead of immediately starting to ‘‘code around’’ the problems.`

* `C++ supports inheritance. With inheritance, you can declare a new type that is an exten- sion of an existing type. This new subclass is said to derive from the existing type and is sometimes called a **derived type**.`

* `cout is an object provided by the standard library. A library is a collection of classes. The standard library is the standard collection that comes with every ANSI-compliant compiler.
You designate to the compiler that the cout object you want to use is part of the standard library by using the namespace specifier std. Because you might have objects with the same name from more than one vendor, C++ divides the world into “namespaces.” A namespace is a way to say “when I say cout, I mean the cout that is part of the standard
Some compilers let you declare main() to return void. This is no longer legal C++, and you should not get into bad habits. Have main() return int, and simply return 0 as the last line in main().
  Some operating systems enable you to test the value returned by a program. The convention is to return 0 to indicate that the program ended normally.
            
 namespace, not some other namespace.” You say that to the compiler by putting the char- acters std followed by two colons before the cout`

* `Both the increment operator (++) and the decrement operator(––) come in two varieties: prefix and postfix. The prefix variety is written before the variable name (++myAge); the postfix variety is written after the variable name (myAge++).`


###  References (T&)
* A reference is an alias (another name) for an existing object.

> Rules
 - Must be initialized
 - Cannot be reseated (once it aliases x, it always aliases x)
 - Cannot be null (in normal correct usage)
 - Best when the object is required and should always exist
