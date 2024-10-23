# txtedit: A Custom Text Editor in C

## Overview
`txtedit` is a lightweight text editor built in C, designed to view and edit files directly from the terminal. The project is structured to support basic text editing functionalities, including navigation and editing with a cursor, and provides special commands for saving and exiting files.

## Usage
To use `txtedit`, run the following command from your terminal:
`txtedit <filename>`

## Arguments
- `<filename>`: The name of the file you want to open or edit. If the file doesn't exist, it will be created.

## Current Functionality
- View or Edit Files: You can open any text file for viewing or editing.
- Cursor Navigation: The text editor supports a cursor that allows navigation within the file.
- Save & Exit Commands: You can issue special commands to save changes or exit the editor.

## Future Features (Planned)
- Copy, Paste, and Cut: Implement basic clipboard functionalities.
- Mouse Usage: Enable mouse interaction within the terminal.
- Auto-Indentation: Add automatic indentation for code formatting.
- File Statistics: Display file statistics, such as word count, character count, and more.

## Project Structure
The project is divided into two key files:

1. `txtedit.c`
- Responsible for argument handling and file operations.
- It validates the input arguments and calls necessary functions to open and display the file.
- The core functionality is to render the text in the terminal and allow user interaction, similar to how VIM operates.

2. `filehandler.c`
- File Opening: Provides a function to open a file. If the file doesn’t exist, it will be created.
`char* openFile(const char* filename);`
- File Saving: Includes a function to save the current buffer to a file.
`int saveFile(const char* filename);`
- Buffer Management: Handles file size changes, text insertion, and deletion within the buffer.
`int insertText(char* buffer, const char* text, int position);`
`int deleteText(char* buffer, int position);`

## Work Plan
This project is distributed across two main files, `txtedit.c` and `filehandler.c`, to ensure clear separation of concerns:
1. txtedit.c:
- Parse and validate command-line arguments.
- Open the file using openFile from filehandler.c.
- Render the file contents in the terminal.
- Implement cursor navigation and user interaction commands.
2. filehandler.c:
- Manage file I/O operations, such as opening, saving, and handling file buffers.
- Handle buffer modifications, such as inserting and deleting text.

## Build and Installation
To compile the project, run the following command:
`gcc -o txtedit txtedit.c filehandler.c`
Once compiled, you can use txtedit as described in the Usage section.