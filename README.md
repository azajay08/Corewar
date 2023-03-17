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

The project is split into 3 mains parts:
- [The Assembler](#assembler)
- [The Virtual Machine](#virtual-machine)
- [The Champion](#champion)


## Assembler

The assembler take a file with a `.s` extension and writes the contents to a file with the same name but with a `.cor` extension, in the format of hexadecimal byte code.
<details open>
<summary>Usage</summary>
<br>

```
./asm [filename.s]
```

</details>

<details open>
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

## Virtual Machine

_VM description_

<details open>
<summary>Usage</summary>
<br>

```
./corewar [-flags] [champion.cor] [champion.cor] [champion.cor]
 
Flags:
     -a   Description
     -d   ...
     -n   ...
```

## Champion

_Usage_
