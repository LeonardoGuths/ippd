# IPPD

<<<<<<< HEAD
- Resolução do problema das N Rainhas em OpenMP.
=======
- Repository containing codes and stuff from the Introduction to parallel and distributed processing class.
>>>>>>> bfd7e38c9e40f9024d285a94edfcfe8ef0752e89

## Integrantes

- Leandro Weber Tavares
- Leonardo dos Santos Guths

## Compilar e executar

1.  **Para compilar**

    Para compilar é recomendado o uso do GCC, que necessita possuir suporte para OpenMP instalado, através da seguinte linha de comando:

    ```console
    gcc -fopenmp nrainhas.c -o nrainhas
    ```

2.  **Para executar**

    Após gerar o arquivo executável, basta rodar colocando os parâmetros de entrada conforme as instruções a seguir:

    ```console
    ./nrainhas <N (núm. de rainhas)> <núm. de threads>
    ```
    **Obs:** caso o número de threads não seja inserido na execução, o programa será executado de forma serial, ou seja, utilizando apenas uma thread.