# Simple Shell Project

This project is an implementation of a simple shell in C, providing basic command-line functionalities. The shell supports common commands, handles input/output redirection, and includes a few built-in commands.

## Features

- **Command Execution:** Execute external commands entered by the user.
- **Input/Output Redirection:** Support for redirecting input and output using `<` and `>`.
- **Built-in Commands:** Includes basic built-in commands like `cd`, `help`, and `exit`.

## Getting Started

1. **Clone the Repository:**
   ```
   git clone https://github.com/Rugwiroparfait /simple-shell.git
   ```

2. **Compile the Code:**
   ```
   gcc simple_shell.c -o simple_shell
   ```

3. **Run the Shell:**
   ```
   ./simple_shell
   ```

## Usage

- **External Commands:**
  ```
  ls -l
  ```

- **Input Redirection:**
  ```
  cat < input.txt
  ```

- **Output Redirection:**
  ```
  ls > output.txt
  ```

- **Built-in Commands:**
  - `cd`: Change directory
  - `help`: Display help information
  - `exit`: Exit the shell

## Examples

- Change directory:
  ```
  cd /path/to/directory
  ```

- Display help information:
  ```
  help
  ```

- Exit the shell:
  ```
  exit
  ```

## Contributors

- [NSANZIMANA RUGWIRO DOMINIQUE PARFAIT](https://github.com/Rugwiroparfait)
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
