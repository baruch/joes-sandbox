struct section { char *name; char *text; } sections[]=
{
  { "syntax",
    "\n"
    "Comments\n"
    "\n"
    "Ivy uses '#' to introduce comments.  Everything from an unquoted # to the\n"
    "end of the line is a comment.  '#' was chosen so that the very first line in\n"
    "an Ivy program can be '#!/usr/bin/ivy', which makes the file into a script\n"
    "in UNIX.\n"
    "\n"
    "Expression syntax\n"
    "\n"
    "Everything in Ivy is an expression, meaning that statements and function\n"
    "calls have the same syntax (new \"statements\" can be added to the language by\n"
    "defining new functions):\n"
    "\n"
    "       print(square(10))      Call square function with 10 as arg, and\n"
    "                            print result.\n"
    "\n"
    "       print(if(a==1,2,3))    If a==1, print 2.  Otherwise print 3.\n"
    "\n"
    "Lists of expressions\n"
    "\n"
    "A list of expressions is expected within parenthesis and brackets:\n"
    "\n"
    "       (list)               Argument list, parenthetical expression,\n"
    "                            or formal args for function definition.\n"
    "\n"
    "       {list}               An object.\n"
    "\n"
    "If a list is expected in the given context, the list is used as is.  If a\n"
    "single expression is expected in the given context, all of the expressions\n"
    "in the list are evaluated (left to right), and the value of the right-most\n"
    "expression is returned:\n"
    "\n"
    "       mul(2 3)              Pass two args to mul: 2 and 3\n"
    "\n"
    "       3*(2 3)              Results in the value 9\n"
    "\n"
    "The expressions within a list can be separated with whitespace, commas or\n"
    "semicolons.  These are all identical in this context:\n"
    "\n"
    "       mul(10 20 40)         3 args passed to mul\n"
    "       mul(10,20;40)         3 args passed to mul\n"
    "       mul(10;,20,,,40)       3 args passed to mul\n"
    "\n"
    "Note that successive separators with nothing between them are ignored:\n"
    "\n"
    "       mul(1,2) is exactly the same as mul(1,,,,2)\n"
    "\n"
    "Note however, that an empty set of parenthesis has meaning:\n"
    "\n"
    "       mul(() 20)     Passing two args to mul: void and 20.\n"
    "\n"
    "Note that \\ is a sequential evaluation infix operator which computes the\n"
    "left side, discards the result and then computes the right side and returns\n"
    "its result:\n"
    "\n"
    "       mul(10\\15\\20 30)       Pass two args to mul: 20 and 30.\n"
    "\n"
    "Ambiguities\n"
    "\n"
    "Since whitespace is a valid separator for expressions, ambiguities between\n"
    "symbols which can be both infix and prefix operators result.  These\n"
    "ambiguities are resolved by noting the physical distance between the\n"
    "symbol and its potential arguments.  If the distance is balanced, the\n"
    "operator is infix, otherwise it's prefix.\n"
    "\n"
    "       a - b                One expression: subtract b from a\n"
    "       a  -b                Two expressions: a and negated b\n"
    "       f (7)                Two expressions: f and 7.\n"
    "       f(7)                 One expression: a call to f with arg 7\n"
    "       f ( 7 )              One expression: a call to f with arg 7\n"
    "       f  ( 7 )              Two expressions: f and 7.\n"
    "\n"
    "Note that tabs occur every 8 spaces for this purpose.\n"
    "\n"
    "Command format function calls\n"
    "\n"
    "There is a \"command\" format for function calls:\n"
    "\n"
    "       function-name arg arg arg ; function-name arg arg arg ; ...\n"
    "\n"
    "This is available at the top-level (non-enclosed) and within square\n"
    "brackets:\n"
    "\n"
    "       [commands]\n"
    "\n"
    "In this context, semicolons and new-lines have the same low precedence: either\n"
    "can be used to separate successive commands.  Commas and whitespace can be\n"
    "used as argument separators, just as in lists.\n"
    "\n"
    "\"function-name\" must be a single simple name.  If it is a more complicated\n"
    "expression, the command is reduced to a list of expressions until the next\n"
    "new-line or semicolon.\n"
    "\n"
    "       print 10 20           # Print 10 and 20 (one command)\n"
    "\n"
    "       print(20) print(1)     # Print 20 and 1 (two expressions)\n"
    "\n"
    "Sometimes you may want to suppress the command interpretation of a single\n"
    "simple name.  This can be done by surrounding the name with parenthesis:\n"
    "\n"
    "       (print)              # Address of print function\n"
    "       print                # Call print function\n"
    "\n"
    "Blocks\n"
    "\n"
    "Arguments to commands can be given as indented blocks:\n"
    "\n"
    "       if a==1 [print 10; print 20]\n"
    "\n"
    "       if a==1\n"
    "         print 10\n"
    "         print 20\n"
    "\n"
    "Block arguments can be separated with the 'next' and 'last' keywords:\n"
    "\n"
    "       if(a==1,print(\"It's one\"),\n"
    "           a==2,print(\"It's two\"),\n"
    "           print(\"It's something else\"))\n"
    "\n"
    "       if a==1\n"
    "         print \"It's one\"\n"
    "       next a==2\n"
    "         print \"It's two\"\n"
    "       last\n"
    "         print \"It's something else\"\n"
    "\n"
    "Interactive mode\n"
    "\n"
    "When Ivy is in interactive mode, the indented block feature is disabled.  In\n"
    "this mode, you either have to use square brackets to enter blocks of\n"
    "commands or you use the expression format.\n"
    "\n"
  },
  { "values",
    "\n"
    "       Integers may be entered in a variety of bases:\n"
    "\n"
    "              x=0127        # Octal\n"
    "              x=0x80        # Hexadecimal\n"
    "              x=0b11        # Binary\n"
    "              x=123         # Decimal\n"
    "\n"
    "       Octal, binary and hexadecimal digits may be interspersed with\n"
    "       underscores (_) for enhanced readability:\n"
    "\n"
    "              x=0xADDED_FEE\n"
    "\n"
    "       Floating point:\n"
    "\n"
    "              x=.125\n"
    "              x=.125e3\n"
    "              x=0.3\n"
    "\n"
    "       Also the ASCII value of a character may be taken as an integer:\n"
    "\n"
    "              x='A'         # The value 65\n"
    "\n"
    "       The following \"escape sequences\" may also be used in place of a\n"
    "character:\n"
    "\n"
    "              x='\\n'        # New-line\n"
    "              x='\\r'        # Return\n"
    "              x='\\b'        # Backspace\n"
    "              x='\\t'        # Tab\n"
    "              x='\\a'        # Alert (bell)\n"
    "              x='\\e'        # ESC\n"
    "              x='\\f'        # Form-feed\n"
    "              x='\\^A'       # Ctrl-A (works for ^@ to ^_ and ^?)\n"
    "              x='\\010'       # Octal for 8\n"
    "              x='\\xFF'       # Hexadecimal for 255\n"
    "              x='\\\\'        # \\\n"
    "              x='\\q'        # q (undefined characters return themselves)\n"
    "\n"
    "       String constants are enclosed in double-quotes:\n"
    "\n"
    "\n"
    "              x=\"Hello there\"\n"
    "\n"
    "       Escape sequences may also be used inside of strings.\n"
    "\n"
    "\n"
    "VARIABLES\n"
    "\n"
    "       Variables set outside of functions are global variables.  They will\n"
    "be visible in any block unless 'var' is used within the block to force the\n"
    "creation of a new local variable with the same name.\n"
    "\n"
    "       If a variable is set inside of a function and there is no global\n"
    "variable of the same name, that variable will be local to the block it was\n"
    "assigned in.\n"
    "\n"
    "\n"
    "OBJECTS\n"
    "\n"
    "       Objects have members which are either numbered or named or both. \n"
    "Objects with numbered members are similar to arrays.  Objects with named\n"
    "members are similar to structures.\n"
    "\n"
    "       Objects can be created either member by member:\n"
    "\n"
    "              o.a=5\n"
    "              o.b=6\n"
    "\n"
    "       or all at once:\n"
    "\n"
    "              o={`a=5, `b=6}\n"
    "\n"
    "       Objects are assigned by reference.  This means that if you have an\n"
    "object in one variable:\n"
    "\n"
    "              x={1 2 3}\n"
    "\n"
    "       And you assign it to another:\n"
    "\n"
    "              y=x\n"
    "\n"
    "       And then change one of the members of x:\n"
    "\n"
    "              x(0)=5\n"
    "\n"
    "       Then the change will appear both in x and in y\n"
    "\n"
    "\n"
    "EXPRESSIONS\n"
    "\n"
    "       An expression is a single or dual operand operator, a constant, a\n"
    "variable, a lambda function, a block enclosed within parenthesis, a\n"
    "function call, or an object.  Examples of each of these cases follow:\n"
    "\n"
    "              ~expr                Single operand\n"
    "\n"
    "              expr+expr             Dual operand\n"
    "\n"
    "              25                   Constant\n"
    "\n"
    "              (expressions)         Precidence\n"
    "              [commands]\n"
    "\n"
    "              expr(expr ...)        Function call\n"
    "\n"
    "              {1 2 3 4}             An array object\n"
    "\n"
    "              {`next=item `value=1}  A structure object\n"
    "\n"
    "              (fn (x,y) x*y)(3,5)    Calling a lambda function\n"
    "\n"
    "\n"
  },
  { "operators",
    "\n"
    "       Ivy uses a superset of operators from C but with more intuitive\n"
    "precedence.  Here are the operators grouped from highest precedence to\n"
    "lowest:\n"
    "\n"
    "       `                           # Named argument\n"
    "\n"
    "       .                           # Member selection\n"
    "\n"
    "       ( )                         # Function call\n"
    "\n"
    "       & - ~ ! ++ -- *              # Single operand\n"
    "\n"
    "       << >>                       # Shift group\n"
    "\n"
    "       * / & %                     # Multiply group\n"
    "\n"
    "       + - | ^                     # Add group\n"
    "\n"
    "       == > < >= <= !=              # Comparison group\n"
    "\n"
    "       &&                          # Logical and\n"
    "\n"
    "       ||                          # Logical or\n"
    "\n"
    "       = <<= >>= *= /= %= += -= |= ^= .=      # Pre-assignments\n"
    "       : <<: >>: *: /: %: +: -: |: ^: .:      # Post-assignments\n"
    "\n"
    "       \\                           # Sequential evaluation: returns\n"
    "                                   # result of right side.\n"
    "\n"
    "       ,                           # Expression separation\n"
    "\n"
    "       ;                           # Command separation\n"
    "\n"
    "       A detailed description of each operator follows:\n"
    "\n"
    "       ` Named argument\n"
    "\n"
    "              This operator can be used to explicitly state the argument\n"
    "or member name in a command, function call or object.  For example:\n"
    "\n"
    "              open `name=\"joe.c\",  `mode=\"r\"\n"
    "              square(`x=5, `y=6)\n"
    "              {`1=5 `0=7}                  # Array object\n"
    "              {`x=10 `y=10}                # Structure object\n"
    "\n"
    "       . Member selection\n"
    "\n"
    "              This operator is used to select a named member from an\n"
    "object.  For example:\n"
    "\n"
    "              o={`x=5, `y=10}       # Create an object\n"
    "              pr o.x               # Print member x\n"
    "              pr o.y               # Print member y\n"
    "              pr o(\"y\")             # Same as above\n"
    "\n"
    "        ( ) Function call\n"
    "\n"
    "              This operator calls the function resulting from the\n"
    "expression on the left with the (optionally comma separated) arguments\n"
    "inside of the brackets.  This operator can also be used for object member\n"
    "selection and for string character selection and substring operations. \n"
    "Examples of each of these follow:\n"
    "\n"
    "              x.y(5)               # Call function y in object x\n"
    "\n"
    "              z(0)=1, z(1)=2        # Set numbered members of an object\n"
    "\n"
    "              z(\"foo\")=3, z(\"bar\")=4 # Set named member of an object\n"
    "\n"
    "              pr \"Hello\"(0)         # Prints 72\n"
    "\n"
    "              pr \"Hello\"(1,3)       # Prints \"el\" (selects substring\n"
    "                                   # beginning with first index and\n"
    "                                   # end before second).\n"
    "\n"
    "              a=\"Hello\"\n"
    "              a(0)='G\n"
    "              a(5)=\" there\"\n"
    "              pr a                 # Prints \"Gello there\"\n"
    "                                   # Overwrites characters in the\n"
    "                                   # destination string and space-fills\n"
    "                                   # if necessary.\n"
    "\n"
    "\n"
    "\n"
    "       - Negate\n"
    "\n"
    "       & Address of.\n"
    "\n"
    "              This operator converts its operand into a zero argument\n"
    "       function nameless function.  The function can be called with () or *.\n"
    "\n"
    "       ~ Bit-wise one's complement\n"
    "\n"
    "       ! Logical not\n"
    "\n"
    "       ++ Pre or post increment depending on whether it precedes or follows\n"
    "          a variable\n"
    "\n"
    "       -- Pre or post decrement\n"
    "\n"
    "       * Indirection\n"
    "\n"
    "              This prefix operator is used to call a zero argument\n"
    "       function.\n"
    "\n"
    "              fn set(&a b)\n"
    "                *a=b\n"
    "\n"
    "              x=3\n"
    "              set x 10       # Set x to 10\n"
    "              pr x          # Prints 10\n"
    "\n"
    "       << Bit-wise shift left\n"
    "\n"
    "       >> Bit-wise shift right\n"
    "\n"
    "       * Multiply\n"
    "\n"
    "       / Divide\n"
    "\n"
    "       & Bit-wise AND\n"
    "\n"
    "       % Modulus (Remainder)\n"
    "\n"
    "       + Add or concatenate\n"
    "\n"
    "              In addition to adding integers, this operator concatenates\n"
    "       strings if strings are passed to it.  For example:\n"
    "\n"
    "              pr \"Hello\"+\" There\"    # Prints \"Hello There\"\n"
    "\n"
    "              '+' will also append an element on the right into an\n"
    "       array object on the left:\n"
    "\n"
    "              a={1 2 3}\n"
    "              a+=4                 # a now is { 1 2 3 4 }\n"
    "\n"
    "              pr {}+1+2+3+4         # same as pr {1 2 3 4}\n"
    "              pr {}+1+2+3+{4 5}      # same as pr {1 2 3 {4 5}}\n"
    "\n"
    "       - Subtract\n"
    "\n"
    "       | Bit-wise OR or \n"
    "\n"
    "              If objects are given as arguments to OR, OR unions the\n"
    "        objects together into a single object.  If the objects have\n"
    "        numerically referenced members, OR will append the array on the\n"
    "        right to the array on the left.  For example:\n"
    "\n"
    "              a={1 2 3}\n"
    "              b={4 5 6}\n"
    "              a|=b                 # a now is {1 2 3 4 5 6}\n"
    "\n"
    "       ^ Bit-wise Exclusive OR\n"
    "\n"
    "       == Returns 1 (true) if arguments are equal or 0 (false) if arguments\n"
    "          are not equal.  Can be used for strings, numbers and objects. \n"
    "          For objects, == tests if the two arguments are the same object,\n"
    "          not if the two arguments have equivalent objects.\n"
    "\n"
    "       >  Greater than\n"
    "       >= Greater than or equal to\n"
    "       <  Less than\n"
    "        <= Less than or equal to\n"
    "        != Not equal to\n"
    "\n"
    "       && Logical and\n"
    "\n"
    "              The right argument is only evaluated if the left argument is\n"
    "       true (non-zero).\n"
    "\n"
    "       || Logical or\n"
    "\n"
    "              The right argument is evaluated only if the left argument is\n"
    "       false (zero).\n"
    "\n"
    "       = Pre-assignment\n"
    "\n"
    "              The right side is evaluated and the result is stored in the\n"
    "       variable specified on the left side.  The right side's result is\n"
    "       also returned.\n"
    "\n"
    "       : Post-assignment\n"
    "\n"
    "              The right side is evaluated and the result is stored in the\n"
    "       variable specified on the left side.  The left side's original value\n"
    "       is returned.\n"
    "\n"
    "       X= Pre-assignment group\n"
    "\n"
    "              These translate directly into: \"left = left X right\"\n"
    "\n"
    "       X: Post-assignment group\n"
    "\n"
    "              These translate directly into: \"left : left X right\"\n"
    "\n"
    "       Notes on assignment groups:\n"
    "\n"
    "              .=     translates into \"left = left . right\" and is\n"
    "                     useful for traversing linked lists.  For example:\n"
    "\n"
    "                     for list=0\\ x=0, x!=10, ++x    # Build list\n"
    "                       list={`next=list, `value=x}\n"
    "\n"
    "                     (note, this builds the list in reverse\n"
    "                     order.  9,8,7...)\n"
    "                            \n"
    "                     for a=list, a, a.=next        # Print list  (second\n"
    "                                                 # expr evals for 0)\n"
    "                       pr a.value\n"
    "\n"
    "              x+:1   Is the same as x++\n"
    "              x+=1   Is the same as ++x\n"
    "\n"
    "              a:b:c:5\n"
    "                     ':' is useful for shifting the value of variables\n"
    "                     around.  In this example, a gets b, b gets c, and\n"
    "                     c gets 5.\n"
    "\n"
    "              a:b:a\n"
    "                     ':' is also useful for swapping the values of\n"
    "                     variables.  In this example, a gets swapped with\n"
    "                     b.\n"
    "\n"
    "       \\ Sequential evaluation\n"
    "\n"
    "              The left and then the right argument are evaluated and the\n"
    "       result of the right argument is returned.\n"
    "\n"
    "       , Argument separator\n"
    "\n"
    "              When this is used in statements which require only a single\n"
    "       expression, it has the same effect as \\\n"
    "\n"
    "\n"
  },
  { "functions",
    "\n"
    "Function declaration:\n"
    "\n"
    "       Named function declarations:\n"
    "\n"
    "              fn name(args) expr\n"
    "\n"
    "              fn name(args)\n"
    "                 body\n"
    "\n"
    "       Named function declarations which look like function calls:\n"
    "\n"
    "              fn(name,(args),body-expr)\n"
    "\n"
    "       Unnamed function declaration which looks like a command:\n"
    "\n"
    "              [fn (args) body-expr]\n"
    "\n"
    "       Unnamed function declaration which looks like a function call:\n"
    "\n"
    "              fn((args),body-expr)\n"
    "\n"
    "       These are all equivalent:\n"
    "\n"
    "              fn square(x) x*x\n"
    "\n"
    "              fn square (x)\n"
    "                x*x\n"
    "\n"
    "              square=(fn (x) x*x)\n"
    "\n"
    "              square=fn((x), x*x)\n"
    "\n"
    "       The last forms define \"Lambda\" (nameless) functions.  You can\n"
    "       also use lambda functions without assigning them:\n"
    "\n"
    "              x=fn((x),x*x)(6)       # x gets assigned 36\n"
    "\n"
  },
  { "statements",
    "\n"
    "If statement\n"
    "\n"
    "       if expr\n"
    "         block\n"
    "       next expr\n"
    "         block\n"
    "       last\n"
    "         block\n"
    "\n"
    "       if(test1,expr1,test2,expr2,...,else-expr)\n"
    "\n"
    "Foreach statement\n"
    "\n"
    "       foreach variable expr block\n"
    "\n"
    "       LABEL: foreach variable expr block\n"
    "\n"
    "              Sets the variable to each element in the array resulting\n"
    "              from expr and executes the block.\n"
    "\n"
    "              'foreach' may optionally be preceded by a label for matching\n"
    "              with the argument to 'break' and 'continue'\n"
    "\n"
    "       e.g.\n"
    "       foreach a {1 2 3}\n"
    "         print a             # prints 123\n"
    "\n"
    "\n"
    "Loop statement\n"
    "\n"
    "       loop block\n"
    "       LABEL: loop block\n"
    "\n"
    "              The block gets repeatedly executed until a 'break' or\n"
    "                'until' statement within the block terminates the loop.\n"
    "\n"
    "\n"
    "              'loop' may optionally be preceded by a label for matching\n"
    "              with the argument to 'break' and 'continue'\n"
    "\n"
    "While statement\n"
    "\n"
    "       while expr block\n"
    "\n"
    "       LABEL: while expr block\n"
    "\n"
    "              The block is repeatedly executed if the expression is true.\n"
    "\n"
    "\n"
    "              'while' may optionally be preceded by a label for matching\n"
    "              with the argument to 'break' and 'continue'\n"
    "\n"
    "For statement\n"
    "\n"
    "       for expr1, expr2, expr3 block\n"
    "\n"
    "       LABEL: for expr1, expr2, expr3 block\n"
    "\n"
    "              This is a shorthand for the follow while statement:\n"
    "\n"
    "                     expr1 while expr2\n"
    "                      block\n"
    "                      expr3\n"
    "\n"
    "              Thus,\n"
    "                  expr1 is usually used as an index variable initializer\n"
    "                 expr2 is the loop test\n"
    "                  expr3 is the index variable incrementer\n"
    "\n"
    "              'for' may optionally be preceded by a label for matching\n"
    "              with the argument to 'break' and 'continue'\n"
    "\n"
    "Return statement\n"
    "\n"
    "       return\n"
    "\n"
    "       return expr\n"
    "\n"
    "              This exits the function it is executed in with the given\n"
    "                return value or with the value of the last expression\n"
    "                preceding the return.\n"
    "\n"
    "Break statement\n"
    "\n"
    "       break\n"
    "\n"
    "       break LABEL\n"
    "\n"
    "              This jumps out of the innermost or labeled loop\n"
    "\n"
    "Continue statement\n"
    "\n"
    "       continue\n"
    "\n"
    "       continue LABEL\n"
    "\n"
    "              This jumps the beginning of the innermost or labeled loop.\n"
    "\n"
    "Until statement\n"
    "\n"
    "       until expr\n"
    "\n"
    "              This exits the loop it's in if the expression is true.\n"
    "\n"
    "Var statement\n"
    "\n"
    "       var a, b, c\n"
    "\n"
    "              This declares variables which are local to the block.  The\n"
    "              variables may also have initializers:\n"
    "\n"
    "                     var a=10, b=20\n"
    "\n"
    "                     fn raise(a)\n"
    "                       var x\n"
    "                       for x=1, a, x<<=1\\ --a\n"
    "                       return x\n"
    "\n"
    "With statement\n"
    "\n"
    "       with a, b, c, ...\n"
    "\n"
    "              The members of the specified objects look like local\n"
    "              variables inside of the block.\n"
    "\n"
    "       e.g.    the following will print \"3\"\n"
    "              list={`value = 2}\n"
    "              with list\n"
    "                value = 3;\n"
    "              print list.value;\n"
    "              \n"
    "\n"
    "              \n"
    "\n"
    "Include statement\n"
    "\n"
    "       include \"string\"\n"
    "\n"
    "              Executes the file specified by the string.\n"
    "\n"
    "\n"
    "FUNCTIONS\n"
    "\n"
    "       When the block inside of a function gets control, several special\n"
    "variables becomes visible:\n"
    "\n"
    "              this   The function's local variables as an object\n"
    "\n"
    "                            print this     Prints all local variables\n"
    "\n"
    "              this.mom\n"
    "                     The function's lexical scope\n"
    "\n"
    "              this.dynamic\n"
    "                     This function's dynamic scope\n"
    "\n"
    "              argv   Contains an object containing numbered members\n"
    "                     which are each set the arguments passed to the\n"
    "                     function.\n"
    "\n"
    "       So for example, if the function:\n"
    "       \n"
    "              fn x()\n"
    "                for a=0, a!=len(argv), ++a\n"
    "                  print argv(a)\n"
    "\n"
    "       gets called as follows:\n"
    "       \n"
    "              x(1 2 3)\n"
    "       \n"
    "       The following gets printed:\n"
    "       \n"
    "       1\n"
    "       2\n"
    "       3\n"
    "\n"
    "       Default values may be specified for missing arguments in function\n"
    "calls.  For example if this function:\n"
    "\n"
    "              fn func(x=5, y=6)\n"
    "                x*y\n"
    "\n"
    "       Is called as follows:\n"
    "       \n"
    "              print func(1)         # '6' is printed\n"
    "              print func()          # '30' is printed\n"
    "              print func(`y=7)       # '35' is printed\n"
    "\n"
    "\n"
    "       Functions may be assigned to variables and passed to functions.  For\n"
    "example you can define a function 'apply' which applies a function to an\n"
    "argument:\n"
    "\n"
    "              fn apply(x y)\n"
    "                return x(y)\n"
    "\n"
    "              fn square(x)\n"
    "                return x*x\n"
    "\n"
    "              print apply(square,5)  # Prints 25\n"
    "\n"
    "\n"
    "       Functions can return other named or unnamed functions.  To return a\n"
    "named function, 'return' must be used since it forces its argument to be an\n"
    "expression (otherwise the returned function name would look like a function\n"
    "call).  For example:\n"
    "\n"
    "              fn square(x)\n"
    "                return x*x\n"
    "\n"
    "              fn foo()\n"
    "                return square\n"
    "\n"
    "              print foo()(4)        # Prints 16    () needed\n"
    "                                   # because bar is an expr\n"
    "\n"
    "              fn bar()\n"
    "                  (fn((x),x*x))       # Return lambda function\n"
    "\n"
    "              pr bar()(4)           # Prints 16    \n"
    "\n"
    "\n"
    "       Functions can be declared inside of other functions.  This is\n"
    "especially useful for manipulating the argument lists of pre-existing\n"
    "functions.  Suppose you had an averaging function:\n"
    "\n"
    "              fn avg(func from to)\n"
    "                var x, accu\n"
    "                for x=from\\ accu=0, x!=to, ++x\n"
    "                  accu+=func(x)\n"
    "                return accu/(to-from)\n"
    "\n"
    "       And suppose that you have another function which takes two arguments\n"
    "which you'd like to average, but with one argument set to a constant:\n"
    "       \n"
    "\n"
    "              fn add(a b)\n"
    "                return a+b\n"
    "\n"
    "       You could do this by using a function which creates a function\n"
    "which calls add, but with one argument set to a constant:\n"
    "\n"
    "              fn curry(y)\n"
    "                return fn((x),add(x,y))\n"
    "\n"
    "       Now 'avg' can be used on 'add':\n"
    "\n"
    "              print avg(curry(20),0,10)\n"
    "\n"
  },
  { "builtin",
    "\n"
    "\n"
    "       len(a)\n"
    "\n"
    "              Returns the length of string 'a' or number of elements in\n"
    "                array 'a'\n"
    "\n"
    "       print(...)\n"
    "\n"
    "              Prints the arguments\n"
    "\n"
    "       printf(...)\n"
    "              C printf\n"
    "\n"
    "              printf \"%d\\n\", 17\n"
    "\n"
    "       a=get()\n"
    "\n"
    "              Get a line of input as a string.  Returns void if there is\n"
    "              no more input.\n"
    "\n"
    "                # Add line numbers to input\n"
    "                n=1\n"
    "              while a=get()\n"
    "                print n++, \" \", a\n"
    "\n"
    "       x=atoi(\"2\")\n"
    "\n"
    "              Converts a string to a number\n"
    "\n"
    "       s=itoa(20)\n"
    "\n"
    "              Convert a number to a string\n"
    "\n"
    "       clear(...)\n"
    "\n"
    "              Frees the values of the listed variables and sets the\n"
    "              variables to VOID.\n"
    "\n"
    "       b=dup(a)\n"
    "\n"
    "              Make a duplicate of an array/object\n"
    "\n"
    "       match(string,pattern,result-variables...)\n"
    "\n"
    "              Regular expression pattern matching\n"
    "\n"
    "              Return true if string matches pattern (which must be a\n"
    "              regular expression string).\n"
    "\n"
    "              If there is a match, each spanned area is stored in the\n"
    "              corresponding result variable:\n"
    "\n"
    "                     match \"fooAbar\" \".*A.*\" a b\n"
    "\n"
    "              a now has \"foo\" and b has \"bar\".\n"
    "\n"
    "              It is ok to supply fewer result variables than there are\n"
    "              spanning areas.\n"
    "\n"
    "              The regular expression string may be made of:\n"
    "\n"
    "                    .      matches any character.\n"
    "                    *      matches zero or more of the previous character\n"
    "                           (generates a result string).\n"
    "                    +      matches one or more of the previous character\n"
    "                           (generates a result string).\n"
    "                    [...]  matches one character in the list ...\n"
    "                           ranges may be specified with the list, such\n"
    "                           as 0-9, a-z, etc.\n"
    "                    x      other characters match themselves only.\n"
    "\n"
    "              Note that the entire string must be spanned for a match to\n"
    "              occur:  It is as if the pattern always begins with ^ and\n"
    "              ends with $.\n"
    "\n"
  },
  { "math",
    "\n"
    "       Math functions:\n"
    "              sin() cos() tan() asin() acos() atan() atan2()\n"
    "              sinh() cosh() tanh() asinh() acosh() atanh()\n"
    "              exp() log() log10() pow() hypot() sqrt()\n"
    "              floor() ceil() int() abs() min() max() erf() erfc()\n"
    "              j0() j1() jn() y0() y1() yn()\n"
  },
  { 0, 0 }
};
