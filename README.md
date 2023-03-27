![corewar_type](https://user-images.githubusercontent.com/86073849/224506544-f46c4665-5658-43bf-a609-c16889879032.gif)

# Corewar - Hive Helsinki (42)
Corewar is the final project of the algorithm branch at Hive Helsinki. Completing this project means completing the core studies at Hive. It is a take on the 80s programming game called Core War. It is a group project consisting of 4 team members.
### Our team:
* [Aaron](https://github.com/azajay08)
* [Elliot](https://github.com/egalibert)
* [Sam](https://github.com/Samyewel)
* [Teemu](https://github.com/tlahin)

As with all Hive projects, they come with restraints and limitations. We have to abide by the rules of `Norminette`. Here are some of the rules we must follow:
```
* The mandatory part must be written in C
* 25 lines maximum per function
* 5 functions maximum per file
* 80 columns wide maximum
* 5 variables per function maximum
* For loops are forbidden
* Declaration and an initialisation cannot be on the same line
* A function can take 4 named parameters maximum
* Printf is forbidden - But we can use our own version made in a previous project (ft_printf)
* Functions allowed:
  * write
  * malloc
  * realloc
  * free
  * open
  * close
  * read
  * sterror
  * perror
  * lseek
  * exit
```



## What is Corewar?

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode. The standards for the language and the virtual machine were initially set by the International Core Wars Society (ICWS), but later standards were determined by community consensus.

For our project, we must assemble the champions and build the arena in which the champions fight in.

The project is split into 3 mains parts:
- [The Assembler](#assembler)
- [The Virtual Machine](#virtual-machine)
- [The Champion](#champion)


## Assembler

<details>
<summary>Usage</summary>
<br>

```
./asm [filename.s]
```

</details>

The assembler takes a file with a `.s` extension (also known as a `champion`) and writes the contents to a file with the same name but with a `.cor` extension in the format of hexadecimal byte code. The job of the assembler is to parse through the assembly language from the input file and make sure everything is valid, ready to translate it into byte code. Of course the input file has to be formatted in a specific way to be correctly translated, so we must take care of edge cases and invalid inputs. 

The files are written in assembly language. A valid champion would have:
* Comments (Not mandatory)
* Header
* Labels (Not mandatory)
* Statements

### Comments
`Comments` can either be on an individual line anywhere in the file, or placed on the end of a line after an instruction. `Comments` are indicated using one of two comment characters `#` or `;`.

### Header
The `header` consists of the `Champion's` name and a comment. The champion's name can be anything but has to be under 128 characters. The comment is usually a cheeky comment or some trash talk, which can also be anything but has to be under 2048 characters. The order that they are in doesn't matter. All that matters is that header comes before any `labels` or `statements`.

<details>
<summary>Example</summary>
<br>

```
.name    "champions name"
.comment "champions comment"
```
</details>

### Labels
`Labels` are used as a reference to the specific `statement` that follows it immediately. A `statement` does not have to be on the same line to be linked to the `label`. The `label` itself as a name means nothing to the program, they are named for readability. If a `label` is called as an argument, it represents a value. That value is the number of bytes between the beginning of the line in which the call is made from, and the beginning of the line in which the `label` is on. The name of the `label` can only consist of these characters `abcdefghijklmnopqrstuvwxyz_0123456789`. A `label` will end with the `LABEL_CHAR` - `:`.

<details>
<summary>Example</summary>
<br>

```
example_label: <statement> <arg> <arg>

example_label2:
               <statement> <arg> <arg>
```
</details>

### Statements
`Statements` are functions that all have specific purposes (irrelevant to the assembler). There are 16 in total. `Statements` are functions so they take arguments. It is the job of the assembler to parse these `statements` and their arguments, and make sure they are valid to their respective `statements`. If so, their values will be written into byte code. The arguments must be separated by the `SEPARATOR_CHAR` - `,`.
                
<details>
<summary>Example</summary>
<br>

```
add r1, r4, r7
and 42, %:label, r3
st r10, 42  
```
</details>
                
  The arguments for the `statements` can be one of three:
* `T_REG` - __Registry__ 
  * This argument is recognised with an `r` in front of a number between 1-16 e.g. `r11`. `1` byte in size.
* `T_DIR` -  __Direct Value__ 
  * This argument is recognised with `%` before a number (positive/negative). A label can be given as an argument too as this also represents a number (number of bytes to label). To use a label as an argument, you must use the `LABEL_CHAR` `:` e.g. `%42`, `%-5`, `%:example_label`. A direct value can either be `2` or `4` bytes in size depending on the statement.
* `T_IND` -  __Indirect Value__
  * This argument doesn't have a specific character to recognise it but, it will just be a number (positive/negative). A label can be given as an argument too as this also represents a number (number of bytes to label). To use a label as an argument, you must use the `LABEL_CHAR` `:` e.g. `42`, `-5`, `:example_label`. `2` bytes in size.

<details>
<summary>Statement Table</summary>
<br>


|Statement Number|Hex Op Code|Statement Name|Argument 1|Argument 2|Argument 3|
|:-----------:|:---------:|:-------:|:--------:|:--------:|:--------:|
1	 |`01`  |`live`|	 T_DIR|	-|	-|
2  |`02`	 |`ld`|	T_DIR / T_IND|	T_REG|	-|
3  |`03` 	|`st`|	T_REG	|T_REG /T_IND	|-|
4  |`04` 	|`add`|	T_REG|	T_REG|	T_REG|
5	 |`05`  |`sub`|	T_REG	|T_REG|	T_REG|
6  |`06` 	|`and`|	T_REG / T_DIR /T_IND|	T_REG /T_DIR / T_IND|	T_REG|
7	 |`07`  |`or`|	 T_REG / T_DIR / T_IND	|T_REG /T_DIR / T_IND	|T_REG|
8  |`08` 	|`xor`|	 T_REG / T_DIR / T_IND|	T_REG / T_DIR / T_IND|	 T_REG|
9	 |`09`  |`zjmp`|	T_DIR	|-	|-|
10 |`0a` 	|`ldi`|	T_REG / T_DIR /T_IND|	T_REG /T_DIR|	T_REG|
11	|`0b`   |`sti`|	T_REG	|T_REG /T_DIR / T_IND	|T_REG / T_DIR|
12	|`0c`   |`fork`|	T_DIR	|-|	-|
13	|`0d`   |`lld`|	T_DIR / T_IND	|T_REG	|-|
14	|`0e`   |`lldi`|	T_REG / T_DIR /T_IND|	T_REG /T_DIR	|T_REG|
15	|`0f`   |`lfork`|	T_DIR	|-	|-|
16	|`10`  |`aff`|	T_REG	|-	|-|

</details>

          

<details>
<summary>Assembly - [.s]</summary>
<br>

![champ_gif](https://user-images.githubusercontent.com/86073849/227749825-26ec57a5-4422-42a9-b0f2-e549e4576f46.gif)




</details> 


<details>
<summary>Byte Code - [.cor]</summary>
<br>

The byte code written to the `.cor` file must be formatted in a specific way:
* **Magic Header** - `0xea83f3` This is so the file will be read as binary and not to be misinterpreted as a text file.
* **Champion name** - 128 bytes maximum. Unused space filled with `00`s
* **NULL** - 4 bytes of `00` representing NULL
* **Executable code size** - 4 bytes representing the size of the executable code. Must be no bigger than 682.
* **Champion comment** - 2048 bytes maximum. Unused space filled with `00`s
* **NULL** - 4 bytes of `00` representing NULL
* **Executable code** - The champions code turned into to hexadecimal bytes representing the statements and their argument values. 

![byte_code_gif](https://user-images.githubusercontent.com/86073849/227809275-937e96b8-b3fc-4bca-8a54-595a141ac069.gif)




</details> 
                
## Virtual Machine

_VM description_
                
<details>
<summary>Usage</summary>
<br>
 

```
./corewar [-flags] [champion.cor] [champion.cor] [champion.cor]
          Flags:
                -dump (n): Prints the arena with 32 bytes per line at cycle n.
                -d (n): Prints the arena with 64 bytes per line at cycle n.
                -n (n): The next player will be given the ID n.
                -a: Sets the a flag for the 'aff' statement command.
                -b: Enables debug messages.
                -f: 'lld' command reads 4 bytes instead of 2, fixing 42s bug.
```

</details>
<details>
<summary>Game board</summary>
<br>
<img width="1163" alt="Screenshot 2023-03-25 at 0 08 14" src="https://user-images.githubusercontent.com/86073849/227654036-777bc421-8840-4a09-b909-e61afe3e46e9.png">
</details>
                
               

## Champion

This part of the project was to create our own champion. The champion doesn't need to be a world beater, but it has to have some functionality and stay alive at least long enough to be considered a participant. Our champion's name is `Conman`. We could tell you a big story about `Conman's` strategy replicating traits of a con artist... but we just liked the name.


<details>
<summary>Conman</summary>
<br>


![champion_gif](https://user-images.githubusercontent.com/86073849/227750598-dd6764d0-78ae-45c0-a7ca-cc31dac356f1.gif)


</details> 


