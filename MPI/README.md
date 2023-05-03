# IPPD

- Resolução do problema das N Rainhas adicionando um novo nível de paralelismo à resolução desenvolvida em OpenMP, utilizando MPI (Message Passing Interface).

## Integrantes

- Leandro Weber Tavares
- Leonardo dos Santos Guths
- Marcelo da Silva Dias
- Murillo Aleixo Mota

## Compilar e executar

1.  **Para compilar**

    Para compilar é necessário a instalação de um compilador MPI, além de possuir suporte para OpenMP instalado, através da seguinte linha de comando:

    ```console
    mpicc -fopenmp nqueens_mpi.c -o nqueens_mpi
    ```

2.  **Para executar**

    Após gerar o arquivo executável, basta rodar colocando os parâmetros de entrada conforme as instruções a seguir:

    ```console
    mpirun -np <núm. de processos MPI> ./nqueens_mpi <N (núm. de rainhas)> <núm. de threads>
    ```
    **Obs1:** para o funcionamento correto do programa, o número de processos MPI necessita ser igual a (núm. de rainhas + 1).
    
    **Obs2:** caso o número de threads não seja inserido na execução, o programa será executado de forma serial, ou seja, utilizando apenas uma thread.
