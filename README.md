# Procesos
## Cálculo paralelo de $\pi$

Expresión para calcular $\pi$ de manera paralela: 

$$\int_{0}^{1}\frac{4}{1+x^2}dx=\pi$$

Esta integral se puede aproximar de manera discreta de la siguiente manera: Sea $\Delta = \frac{1}{N}$ y $x_i = (i+0.5)\Delta$ con $i = 0, 1, 2, ..., N-1$, donde $N$ es el número de rectángulos en los que vamos a dividir el intervalo $[0,1]$. Entonces, $\pi$ se puede aproximar como 

$$\sum_{i=0}^{N-1}\frac{4}{1+x_i^2}\Delta \cong \pi$$

## Acerca del código
### ¿Cómo compilarlo?
```g++ pi.cpp -o pi```
## 
### ¿Cómo ejecutarlo?
```./pi.exe N p```  
Donde:  
N = número de rectángulos en los que vamos a dividir el intervalo $[0,1]$.  
p = número de hilos que se van a correr.
