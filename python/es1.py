#!/usr/bin/env python
#-*- coding: utf-8 -*- 

while True:
    n1 = float(input("Inserire il primo numero: "))
    n2 = float(input("Inserire il secondo numero: "))

    if n1*n2 == 0.0:
        break

    if n1 >= n2:
        rapporto = n2/n1
    else :
        rapporto = n1/n2

    print(rapporto)