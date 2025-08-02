# Stringx

Library with strings implementation in C and functions to work with them.  

## Installation

### 1. Clone this repository:

```bash
git clone https://github.com/mittit-dev/Stringx.git
cd Stringx
```
### 2. Create a `build` directory and build the library:

```bash
mkdir build
cd build
cmake ..
make
sudo make install # Run with superuser rights if installing to system directories (e.g., /usr/local)
```
This will install:

- Library files (`libStringx.a` or `libStringx.so`) to `/usr/local/lib`
- Header files (`stringx.h`, `boolx.h`) to `/usr/local/include`

If you are installing to a custom prefix, adjust your compiler and linker flags accordingly.

## Usage

### 1. Include the header files in your source code:

```c
#include <stringx.h>
#include <boolx.h>
```

### 2. Compile your program linking with the library:

```bash
gcc main.c -lStringx -I/usr/local/include -L/usr/local/lib
```
Where:

- `-I` specifies the path to the include directory.
- `-L` specifies the path to the library directory.
- `-lStringx` links against the `libStringx.so` (Linux/macOS) or `Stringx.dll` (Windows) library.

Replace `/usr/local` with your installation prefix if different.  

For dynamic libraries, ensure the runtime linker can find the share library:
- On Linux/macOS:
  ```bash
  export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
  ```
  Replace `/usr/local` with your installation prefix if different.

- On Windows, add the directory containing the `.dll` files to your system `PATH`.



### 3. Example usage:

```c
#include <stdio.h>
#include <stringx.h>

int main() {
  str source = "I live in New York"; // Original string
  str old = "New York"; // Substring to replace
  str new = "Tokyo"; // New substring
  char result[calcx(source, old, new)]; // Allocating buffer with correct size

  replacex(source, old, new, result);

  printf("%s\n", result); // Output: I live in Tokyo
  return 0;
}
```

> [!Warning]
> Make sure that the dynamic library is accessible by your system at runtime (see environment variables in Installation).

## API Documentation

[**List of functions**](include/stringx.h)

### Types

```c
#define true 1
#define false 0
typedef int boolx;
```

> A boolean value, that can take values of `true` and `false`. Supports both short and long conditions.  
> **Usage:**

```c
boolx myVar = true;
if (myVar) {
  // ...
}
if (myVar == true) {
  // ...
}
``` 

---

```c
typedef char* str;
```

> A string type defined as a pointer to a character array (null-terminated).  
> **Usage:**

```c
str myVar = "Hello, world!";
```

---

### Functions

```c
int calcx(const str string, const str old, const str new);
```

> Calculates the required size for the `result` string before `replacex()`.

> [!IMPORTANT]
> Using `calcx()` is mandatory to correctly calculate the size of the result buffer to avoid buffer overflow and potential undefined behavior.

---

```c
boolx comparex(const str string1, const str string2); 
```

> Compares two strings and returns `true` if they are equal and `false` if not equal.  
> **Usage:**

```c
str str1 = "Hello!";
str str2 = "Bye!";
boolx equal = comparex(str1, str2);

// equal: false
```

---

```c
boolx is_substrx(const str string, const str substr);
```

> Returns true if `substr` is a substring of `string`.  
> **Usage:**

```c
str string = "abcdef";
str substr = "def";
boolx is_substr = is_substrx(string, substr);

// is_substr: true
```

---

```c
int lenx(const str string);
```

> Returns the length of the string excluding the terminating null character.  
> **Usage:**

```c
str source = "Hello!";
int length = lenx(source);

// length: 6
```

---

```c
void replacex(const str string, const str old, const str new, str result);
```

> Replaces all occurrences of `old` with `new` in `string`, storing the result into `result`.  
> **Usage:**

```c
str source = "Hello, world in worlds!";
str old = "world";
str new = "planet";

char result[calcx(source, old, new)];
replacex(source, old, new, result);

// result: "Hello, planet in planets!"
```

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

If you have any questions, suggestions, or issues, please feel free to open an issue in the repository.
