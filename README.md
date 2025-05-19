# Scientific Calculator Application

Project Overview
-------------------
This scientific calculator is a Qt-based desktop application that provides standard arithmetic operations, advanced mathematical functions, and memory management capabilities. The calculator features a modern gray-themed user interface with a main display, tabbed history and memory panels, and multiple function buttons in a grid layout.

Key Features
--------------
Basic Operations:

  Arithmetic operations: Addition (+), subtraction (-), multiplication (×), and division (÷)
  Decimal point support with error handling
  Sign change (+/-) functionality
  Clear (C) and Clear Entry (CE) buttons for different levels of input clearing

Scientific Functions:  

  Square root calculation (√)
  Square (x²) function
  Inverse (1/x) function
  Percentage (%) calculation

Memory Management:

  Memory Clear (MC) button
  Memory Recall (MR) button
  Memory Add (M+) button
  Memory Subtract (M-) button
  Memory Store (MS) button
  Eight memory registers displayed in the right panel under the "Memory" tab

History Tracking:

  Records calculation history with inputs and results
  History Clear (HC) button
  Tabbed interface with "History" and "Memory" sections
  Eight history slots displayed in the right panel under the "History" tab

Error Handling:

  Prevents division by zero
  Handles overly large or small numbers with appropriate error messages
  Manages decimal point input intelligently (prevents multiple decimal points)

Technical Implementation
----------------------

UI Components:

  Main black display for showing current input and results
  Gray-themed interface with modern flat button design
  Numeric keypad (0-9) arranged in familiar calculator layout
  Operation buttons (+, -, ×, ÷) along the right side
  Special function buttons (√, x², 1/x, %) in the upper rows
  Backspace button for quick corrections
  Memory and History tabs in the right panel with 8 display slots each

Visual Design:

  Contemporary flat UI design with gray/black color scheme
  Fixed-size window with organized button grid
  Tabbed panel for History and Memory functions
  Large, readable display with right-aligned text
  Well-spaced buttons for easy interaction
  Consistent button sizing and layout

Code Structure:

  Event-driven architecture with button click handlers
  Expression parsing and evaluation using QJSEngine
  Number formatting with control for decimal precision
  Removal of trailing zeros for cleaner number display
  History and memory management with circular buffer implementation

Number Handling:

  Supports both integer and floating-point operations
  Handles very small numbers (with threshold detection)
  Handles very large numbers (with overflow detection)
  Scientific notation avoidance for better readability

Technical Requirements:
---------------------

C++ programming language
Qt framework for GUI components
Built as a standalone desktop application
Fixed window size for consistent UI presentation

Intended Users:
---------------
This calculator is designed for students, professionals, and anyone needing quick access to mathematical calculations beyond what a basic calculator offers, while still maintaining an intuitive and user-friendly interface.
