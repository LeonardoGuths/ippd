# IPPD

- Resolução do problema das N Rainhas em OpenMP.

## Integrantes

- Leandro Weber Tavares
- Leonardo dos Santos Guths
- Marcelo da Silva Dias
- Murillo Aleixo Mota

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
