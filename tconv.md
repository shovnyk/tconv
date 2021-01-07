% TCONV(1) tconv 0.0.1 
% nik
% January 2021 

# NAME

tconv - convert temperature between celsius and farenheit

# SYNOPSIS

**tconv** [*OPTION*] [*TEMPERATURE*]...

# DESCRIPTION

**tconv** is a cute little command line tool to convert any numeric temperature
value passed to it from celsius to fahrenheit and vice versa.  When no
arguments are passed to it, **tconv** will read from standard out, one line at a
time, meaning it can be used as part of pipes! It will exit on encountering the
first non numeric argument.

# OPTIONS

**-c**
: Treat argument(s) as *farenheit* and convert to *celsius*. This is the default
behaviour.

**-f**
: Treat argument(s) as *celsius* and convert to *farenheit*.

**-h**
: Display a help message (including version number) and exit.

**-v**
: Be verbose, i.e print the conversion explicitly.

# EXAMPLES

**tconv 37 89 100**
: convert 37, 89 and 100 degrees celsius to farenheit and print.

**echo "Doctor! My son has a fever of $(tconv -c 103) degrees Celsius"**
: convert from farenheit to celsius.

**seq -273 5000 | tconv -f -v > tempdata.txt**
: convert numbers read from a pipe or a file.

# EXIT VALUES

**0**
: Program executes successfully

**1**
: Invalid option or arguments passed

# BUGS

None that I know of (wink, wink). I mean its a fucking temperature converter.

# Copyright

I don't know shit about copyright law, but I'm willing to learn!
