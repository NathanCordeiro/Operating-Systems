## Notes on bash shell scripting

Open a text file and save the file with a `.sh` extension
```sh
filrname.sh
```

Add Shebang/Hash-bang to the script

Shebang is the entry it tells the kernel to use bash as the script not the default script which might not be bash.
```sh
#!/bin/bash

# write some code here
```

## Tips for faster and more efficient bash scripting
- Remenber bash is sensitive to white spaces
- Use regular expression for arithmetic operations rather than `expr`
  ```sh
  a=$((b + c))

  x=$((y * z))
  ```
  ```sh
  $a = expr `$a + $b`

  $x = expr `$y \* $z`
  ```
- We can auto increment and decrement using regular expression (both formats are different and work diffrently)
  ```sh
  ((++i))

  $((++i))
  ```
- To use regular expression we use the (( )) brackets now we can use this in `loops` and `if` statements
- Use Python for loops
  ```sh
  for i in {1..10};do

  done
  ```
- Bash allows UNIX commands so use them whenever possible to make scripts easier and faster to execute
