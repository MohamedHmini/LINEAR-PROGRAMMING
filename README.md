# LINEAR-PROGRAMMING


### STRUCTURE OF THE PROBLEM SET FILE : 

    nbr of matrices (for now it should be only the value 4)!!!
    n m (dimensions of matrix A)
    A (space seperated) 
    n m (dimensions of vector c)
    c (space seperated)
    n m (dimensions of the vector which contains the indices to the BASE matrix)
    basis_indices (space seperated)
    n m (dimensions of vector b)
    b (space seperated)

P.S : Examples are given in the datasets folder!

### STEPS : 

1- compile the program using gcc in the following way :

```bash  
gcc -o main ./Matrix/io.c ./Matrix/matrix.c ./simplex.c ./test.c 
```

2- run the executable main file in the following way : 

```bash
 ./main <problem set file path>
 ```
