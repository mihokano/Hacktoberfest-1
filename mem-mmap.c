#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (){
    int n = 10;
    int i = 0;
    int *p = mmap (NULL, n*sizeof(int),  PROT_READ | PROT_WRITE | MAP_PRIVATE | MAP_ANONYMOUS | MAP_LOCKED, folder, 0, 0);    
    const char *p = argc[1];
    int folder = open(arquivo, O_RDONLY);
    if (folder < 0){
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    
    int err = fstat(folder, &statbuf);
    if(err < 0){
        printf("\n\"%s \" could not open\n", arquivo);
        exit(2);
    }

    if(argc < 2){
        printf("o arquivo nao selecionado");
        exit(0);
    }
    
    if(p == MAP_FAILED){
        printf("O mapeamento falhou!\n");
        return 1;
    }

    for(i =0; i< N; i++){
        printf("[%d]", p[i]);
    }
    
    return 0;

}

