# tconv 

## a temperature converter with a smile !

Annoyed with people constanting using Farenheit instead of Celsius, which is
clearly the superior unit of measurement ? Inconvenienced with having to convert
temperature values on the fly when talking to your doctor who only understands
celsius ? Well, fret no more, for now if you find yourself in such a
situation, you can open your nearest terminal, start a shell session and type
the following:

```bash
echo "Doctor! I have a $(tconv 103) fever!"
```

Introducing `tconv`, a completely useless tool in your Unix toolbelt!

## Features

`tconv` (**t**emperature **conv**erter), is a command line utility that can
convert between celsius and farenheit.

read arguments (of course)

```bash
tconv -f -v 32

```

read multiple arguments

```bash
tconv -c -v -- 123 200 -99

```

read standard input 

```bash
tconv -f <(cut -d, -f2 temperature_data.csv)
```
```bash
seq 100 200 | tconv
```
```bash
for ((i = 1; i < 100; i++))
do 
	expr $RANDOM % $i
done | tconv -cv
```

## Dependencies

* glibc: even really old versions should work!
* [Pandoc](https://github.com/jgm/pandoc): optional. Required for building the
  man page (yes there is a man page!)

## Installation

Build from source! Clone this repository.

Then, if you have `pandoc` installed, run

```bash
sudo make install
```

If you don't,

```bash
sudo make install_no_man
```

Or in one go!

```bash
[ -z $(type -p pandoc) ] && sudo make install_no_man || sudo make install
```

## Bugs

There is literally no way `tconv` could crash or segfault. There also isn't any
scope for buffer overflow, as far as I know (and I clearly know a lot).

## Support us (me (us))

2 stars and we might consider adding Kelvin!
