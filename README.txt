// Project 1 - Scanner
// README
// Tan Nguyen
// ntnhmc@umsystem.edu
// Mar 7, 2022

 
USING OPTION 2: FSA table + driver
I don't have any incomplete requests from project 1

Summary: Implement scanner for the provided lexical definitions .The scanner is embedded and thus it will return one token every time it is called by a parser

I. What I have achieved in this project

1. Use suffix rules or pattern rules in Makfile
2. Invocation
	./scanner       // read from the keyboard until simulated keyboard EOF , then CRTL + D to end.
	./scanner filename // reads from filename 
	
If user input of three or more strings on the command line should also generate this error message:
	Error: Expected 1 or no arguments
	Try './scanner -h' for more information.
	
I have provided the file to test the program: testinput.txt
WHEN YOU run the program, just enter the file name, DONT enter the prefix ".txt"

3. Command line parsing
	I add option -h: Help. It will be used to show how to run the program.
	
4. Program output
Testing file content:
	1. x1 xA2 If jfa 301{.% var1 + &<<
	2. x3+  xA  If1<-+y1+z12 Again3+ Move
	3. *commnet should be ignore*
	4. ShowFlip NameHome Do{}/
	5. There<<
	
	OUTPUT:
	TokenID: IDENTIFIER TOKEN | Instance: x1 | Line#: 1
	TokenID: IDENTIFIER TOKEN | Instance: xA2 | Line#: 1
	TokenID: IF KEYWORD | Instance: If | Line#: 1
	TokenID: IDENTIFIER TOKEN | Instance: jfa | Line#: 1
	TokenID: DIGIT TOKEN | Instance: 301 | Line#: 1
	TokenID: OPERATOR BRACKET LEFT '{' | Instance: { | Line#: 1
	TokenID: OPERATOR DOTS '.' | Instance: . | Line#: 1
	TokenID: OPERATOR MODULUS '%' | Instance: % | Line#: 1
	TokenID: IDENTIFIER TOKEN | Instance: var1 | Line#: 1
	TokenID: OPERATOR ADD '+' | Instance: + | Line#: 1
	TokenID: OPERATOR AND '&' | Instance: & | Line#: 1
	TokenID: OPERATOR LEFTSHIFT '<<' | Instance: <<  | Line#: 1
	TokenID: IDENTIFIER TOKEN | Instance: x3 | Line#: 2
	TokenID: OPERATOR ADD '+' | Instance: + | Line#: 2
	TokenID: IDENTIFIER TOKEN | Instance: xA | Line#: 2
	TokenID: IF KEYWORD | Instance: If | Line#: 2
	TokenID: DIGIT TOKEN | Instance: 1 | Line#: 2
	TokenID: OPERATOR SMALLER MINUS '<-' | Instance: <-+ | Line#: 2
	TokenID: IDENTIFIER TOKEN | Instance: y1 | Line#: 2
	TokenID: OPERATOR ADD '+' | Instance: + | Line#: 2
	TokenID: IDENTIFIER TOKEN | Instance: z12 | Line#: 2
	TokenID: AGAIN KEYWORD | Instance: Again | Line#: 2
	TokenID: DIGIT TOKEN | Instance: 3 | Line#: 2
	TokenID: OPERATOR ADD '+' | Instance: + | Line#: 2
	TokenID: MOVE KEYWORD | Instance: Move | Line#: 2
	TokenID: COMMENT - IGNORE | Instance: *commnetshouldbeignore* | Line#: 3
	TokenID: SHOW KEYWORD | Instance: Show | Line#: 4
	TokenID: FLIP KEYWORD | Instance: Flip | Line#: 4
	TokenID: NAME KEYWORD | Instance: Name | Line#: 4
	TokenID: HOME KEYWORD | Instance: Home | Line#: 4
	TokenID: DOTS KEYWORD | Instance: Do | Line#: 4
	TokenID: OPERATOR BRACKET LEFT '{' | Instance: { | Line#: 4
	TokenID: OPERATOR BRACKET RIGHT '}' | Instance: } | Line#: 4
	TokenID: OPERATOR DIVISION '/' | Instance: / | Line#: 4
	TokenID: THERE KEYWORD | Instance: There | Line#: 5
	TokenID: OPERATOR LEFTSHIFT '<<' | Instance: << | Line#: 5
	TokenID: END OF FILE | Instance: EOF | Line#: 5

5. FSA TABLE

//FSA TABLE
int FSATable[18][15] = {
// a-z   	A-Z	0-9	*	&	+	/	%	.	{	}	<	-	EOF	WS    
//----------------------------------------------------------------------------------------------------------------
  {s2,   	s4,	s5,	s6,	s8,	s9,	s10,	s11,	s12,	s13,	s14,	s15,	s18,	-1,	s1},	//s1
  {s3,	 	s3,	s3,	s2,	s2,	s2,	s2,	s2,	s2,	s2,	s2,	s2, 	s2,	s2,	s2},	//s2
  {s3,	 	s3,	s3,	1000,	1000,	1000,	1000,	1000,	1000,	1000,	1000,	1000,	1000,	1000,	1000},	//s3
  {s4,	 	1011,	1011,	1011, 	1011, 	1011, 	1011,	1011,	1011, 	1011, 	1011, 	1011, 	1011, 	1011, 	1011},	//s4
  {1001,	1001,	s5,	1001,	1001,	1001,	1001,	1001,	1001, 	1001,	1001,	1001,	1001,	1001,	1001},	//s5
  {s6,	 	s6,	s6,	s7,	s6,	s6,	s6,	s6,	s6,	s6,	s6,	s6,	s6,	s6,	s6},	//s6
  {COMFN,	COMFN,	COMFN,	COMFN,	COMFN,	COMFN,	COMFN, 	COMFN,	COMFN,	COMFN,	COMFN,	COMFN,	COMFN,	COMFN, 	COMFN},	//s7
  {1002,	1002,	1002,	1002,	1002,	1002,	1002,	1002,	1002, 	1002,	1002,	1002,	1002,	1002,	1002},	//s8
  {1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003,	1003, 	1003,	1003},	//s9
  {1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004,	1004},	//s10
  {1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005,	1005},	//s11
  {1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006,	1006},	//s12
  {1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007,	1007},	//s13
  {1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008,	1008},	//s14
  {s15,		s15,	s15,	s15,	s15,	s15,	s15,	s15,	s15,	s15,	s15,	s16,	s17,	s15,	s15},	//s15
  {1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009,	1009},	//s16
  {1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010,	1010},	//s17
  { ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR}	//s18
};


State:
	{-1, EOF_TK}, 
	{-2, ERROR_TK},
	{1000, ID_TK}, 
	{1001, DIGIT_TK}, 
	{1002, AND_TK},
	{1003, ADD_TK},
	{1004, DIVISION_TK},
	{1005, MODULUS_TK},
	{1006, DOTS_TK},
	{1007, BRACKET_RIGHT_TK},
	{1008, BRACKET_LEFT_TK},
	{1009, LEFT_SHIFT_TK},
	{1010, SMALLER_MINUS_TK},
	{1012, COMMENT_TK}

	
6. Architectural requirements
	Meet all the requirements of the project.

