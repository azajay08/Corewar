# Corewar - Hive Helsinki (42)

![corewar_type](https://user-images.githubusercontent.com/86073849/224506544-f46c4665-5658-43bf-a609-c16889879032.gif)


Corewar is the final project of the algorithm branch at Hive Helsinki. Completing this project means completing the core studies at Hive. It is a take on the 80s programming game called Core War. It is a group project consisting of 4 team members.
### Our team:
* [Aaron](https://github.com/azajay08)
* [Elliot](https://github.com/egalibert)
* [Sam](https://github.com/Samyewel)
* [Teemu](https://github.com/tlahin)

## What is Corewar?

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode. The standards for the language and the virtual machine were initially set by the International Core Wars Society (ICWS), but later standards were determined by community consensus.

The project is split into 3 mains parts:
- [The Assembler](#assembler)
- [The Virtual Machine](#virtual-machine)
- [The Champion](#champion)

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



## Assembler

The assembler take a file with a `.s` extension and writes the contents to a file with the same name but with a `.cor` extension, in the format of hexadecimal byte code.
<details open>
<summary>Usage</summary>
<br>

```
./asm [filename.s]
```

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
