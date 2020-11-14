#!/usr/bin/env python3
# This takes in the c source in this dir and randomizes the problem a little bit
# randomizes the size of the buffer as well as the hex value to set
from argparse import ArgumentParser
from os import system
from random import randint

from jinja2 import Template


hex_words = [
    'ba5eba11',
    'bedabb1e',
    'be5077ed',
    'b0a710ad',
    'b01dface',
    'ca11ab1e',
    'ca55e77e',
    'deadbea7',
    'f00dab1e',
    'f005ba11',
    '5ca1ab1e',
    '7e1eca57',
]


with open('ctf-problem-1.c.j2') as fp:
    template = Template(fp.read())


with open('ctf-problem-1.c', 'w') as fp:
    fp.write(template.render({
        'hexword': hex_words[randint(0,len(hex_words)-1)],
        'buffer_size': randint(10, 512),
    }))


system('gcc -fno-stack-protector -o ctf-problem ctf-problem-1.c')

