## Learning C++

* The most important thing to do when learning C++ is to focus on concepts and not get lost in language-technical details. The purpose of learning a programming language is to become a better programmer; that is, to become more effective at designing and implementing new systems and at maintaining old ones. For this, an appreciation of programming and design techniques is far more important than an understanding of details; that understanding comes with time and practice.

* However, ideas must be transformed into something that fits with the general structure and type system of C++ in order to be effective in the different context.Over the basic type system of a language, only Pyrrhic victories are possible.

* I assume that your purpose in learning C++ is not simply to learn a new syn- tax for doing things the way you used to, but to learn new and better ways of building systems.

* If you plan to use C++ seriously, I strongly suggest that you gain access to such sources. Each has its own emphasis and bias, so use at least two. For example, see [Barton,1994], [Booch,1994], [Henricson,1997], [Koenig,1997], [Martin,1995], [Stroustrup,1994].

* C++ evolved hand-in-hand with some of the key classes presented in this book. For example, I designed complex, vector, and stack classes together with the operator overloading mechanisms.

* In most cases, a cast is an indication of a design error.

* Ideally, you approach the task of designing a program in three stages. First, you gain a clear under- standing of the problem (analysis), then you identify the key concepts involved in a solution (design), and finally you express that solution in a program (programming).

* A C++ class is a type. That is, it specifies how objects of its class behave: how they are created, how they can be manipulated, and how they are destroyed. A class may also specify how objects are represented, although in the early stages of the design of a program that should not be the major concern. The key to writing good programs is to design classes so that each cleanly represents a single concept. Often, this means that you must focus on questions such as: How are objects of this class created? Can objects of this class be copied and/or destroyed? What opera- tions can be applied to such objects? If there are no good answers to such questions, the concept probably wasn’t ‘‘clean’’ in the first place. It might then be a good idea to think more about the problem and its proposed solution instead of immediately starting to ‘‘code around’’ the problems.

* C++ supports inheritance. With inheritance, you can declare a new type that is an exten- sion of an existing type. This new subclass is said to derive from the existing type and is sometimes called a **derived type**.

* `cout is an object provided by the standard library. A library is a collection of classes. The standard library is the standard collection that comes with every ANSI-compliant compiler. You designate to the compiler that the cout object you want to use is part of the standard library by using the namespace specifier std. Because you might have objects with the same name from more than one vendor, C++ divides the world into “namespaces.” A namespace is a way to say “when I say cout, I mean the cout that is part of the standard Some compilers let you declare main() to return void. This is no longer legal C++, and you should not get into bad habits. Have main() return int, and simply return 0 as the last line in main(). Some operating systems enable you to test the value returned by a program. The convention is to return 0 to indicate that the program ended normally.

> `You say “I want to use the cout object from namespace, not some other namespace.” You say that to the compiler by putting the char- acters std followed by two colons before the cout`

* Both the increment operator (++) and the decrement operator(––) come in two varieties: prefix and postfix. The prefix variety is written before the variable name (++myAge); the postfix variety is written after the variable name (myAge++).
References (T&)
A reference is an alias (another name) for an existing object.

* Rules:
- Must be initialized
- Cannot be reseated (once it aliases x, it always aliases x)
- Cannot be null (in normal correct usage)
- Best when the object is required and should always exist

* The dynamic section of memory known is called heap. This is a vast space of memory which is not being managed by the CPU.

* The static section of memory known is called stack. This is a small space of memory which is managed by the CPU.

### Components of Data Hiding

- Data hiding can be divided into two primary components:
    * Encapsulation
    * Abstraction
    * When used together, they allow us to make efficient classes for further use in our application.


### Copy constructor 
* When you copy an object that contains a pointer, by default C++ just copies the pointer address — not the data it points to. This is called a shallow copy

### assignment operator
* Assignment operator — called when copying into an already existing object


### this

* `this is a pointer to the current object (always available inside any method)
*this dereferences it — gives you the object itself, not the pointer
you return it so you can chain assignments like a = b = c`

## C++ Module 06: C++ Casts

- The module contains three exercises: scalar conversion, pointer serialization, and identifying a real derived type.
- The subject file is the source of truth; do not confuse Module 06 ex03 with the `DiamondTrap` exercise from another module.
- ex00 uses `ScalarConverter::convert` to parse a string literal and display it as `char`, `int`, `float`, and `double`.
- Scalar conversion requires first detecting the literal type, then explicitly converting to the other scalar types.
- In a decimal literal such as `42.0f`, the trailing `f` suffix identifies the value as a `float`; without it, `42.0` is treated as a `double`.
- The ex00 mental model is: read the input string -> detect and parse its literal type -> convert the parsed value to the other scalar types -> print each result or an informative error.
- The ex00 scaffold contains `Makefile`, `main.cpp`, `ScalarConverter.hpp`, and `ScalarConverter.cpp`; the implementation remains intentionally empty until the design is understood.
- `ScalarConverter` stores no object state, so its conversion function should be static and users should not create `ScalarConverter` objects.
- A static member function has no `this` pointer and cannot access object members; this matters because `ScalarConverter::convert` must not use `this->literal`.
- `static` on a member function means the function belongs to the class itself, not to an individual object; call it as `ScalarConverter::convert(input)` without constructing a `ScalarConverter`.
- A static function is appropriate when the operation needs no object state. It also explains why `convert` cannot use `this` or non-static members.
- A non-member `operator<<` cannot access private members unless it is declared `friend`; ex00 does not need an output operator because conversion is performed by the static function.
- The repaired ScalarConverter keeps all conversion work in the static function and uses private constructors to prevent user instantiation.
- `strtol` and `strtod` require a C-string from `.c_str()` and an end pointer to confirm that the complete input was consumed.
- `strtol`/`strtod` report range errors through `errno`, not through `std::invalid_argument` or `std::out_of_range` exceptions.
- Decimal notation means inputs such as `42`, `-42`, `4.2`, and `4.2f`; hexadecimal and octal inputs are outside this exercise.
- Character inputs use quotes such as `'c'` or `'a'`. If another conversion produces a character outside the displayable range, print an informative message instead of showing an invisible character.
- The subject allows standard string-to-number conversion functions. In C++98, `std::strtol` is useful for integers and `std::strtod` for decimal values; `std::stringstream` is another standard option when input validation is needed.
- `std::atoi` and similar simple functions do not report errors or overflow clearly, so they are less suitable for a robust converter.
- After parsing, use `static_cast` for the explicit scalar conversions required by the exercise.
- Invalid, overflowing, and non-displayable conversions need informative output.
- ex01 uses `reinterpret_cast` to convert a `Data*` to `uintptr_t` and back, then verifies that the pointer is unchanged.
- ex02 uses `dynamic_cast` to identify `A`, `B`, or `C` through a `Base*` or `Base&`; `<typeinfo>` is forbidden.
- The appropriate cast must be explainable during the defense.
- In ex01, `uintptr_t` is an unsigned integer type capable of representing a pointer value; use `reinterpret_cast` for the pointer/integer representation round trip, and keep the original `Data` object alive while testing it.
- Serialization here does not copy the `Data` fields. It temporarily represents the pointer address as an integer and then reconstructs the pointer; pointer equality must be checked after deserialization.
- ex01 was validated in WSL: the original pointer and deserialized pointer had the same address, and the restored pointer successfully accessed the original `Data` members.
- The subject forbids `using namespace <ns_name>`, not qualified names such as `std::cout`; to avoid any ambiguity, file-local helper functions can use `static` instead of an anonymous namespace.
- Keep this global file updated with important questions, corrections, verified commands, and lessons from each module.
