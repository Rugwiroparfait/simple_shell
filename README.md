<<<<<<< HEAD
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
=======
# 0x16. C - Simple Shell

## Project Overview

This project involves the creation of a simple shell, referred to as `hsh`. The shell supports both interactive and non-interactive modes and is expected to replicate the behavior of the standard Unix shell (`/bin/sh`). The implementation should adhere to specific guidelines and constraints outlined below.

## List of Allowed Functions and System Calls

The following functions and system calls are allowed for use in this project:

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## Compilation

The shell will be compiled using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

All files should end with a new line, and the code must follow the Betty style guidelines. The shell should not have any memory leaks, and each file should contain no more than 5 functions.

## Output

The shell's output and error messages should match those of `/bin/sh`. When printing errors, the program's name must be equivalent to `argv[0]`.

Example of error with `/bin/sh`:

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
```

Same error with `hsh`:

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

## Testing

The shell should work in both interactive and non-interactive modes. Interactive mode:

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

Non-interactive mode:

```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Project Files

The project must include the following files:

- `_atoi.c`
- `builtin.c`
- `builtin1.c`
- `environ.c`
- `errors.c`
- `error1.c`
- `exits.c`
- `getLine.c`
- `getenv.c`
- `getinfo.c`
- `history.c`
- `lists.c`
- `main.c`
- `memory.c`
- `parser.c`
- `realloc.c`
- `shell.h`
- `shell_loop.c`
- `string.c`
- `string1.c`
- `tokenizer.c`
- `vars.c`

## Additional Notes

- All header files should be include guarded.
- Use system calls only when necessary.
>>>>>>> main
