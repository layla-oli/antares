# Tipo de dado abstrato: heap mínimo genérico

Oi! 
Esse é o repositório da implementação de um TAD de heap mínimo genérico, trabalho feito para o Professor Dalessandro Vianna, para a disciplina Estrutura de Dados. O heap é uma estrutura de dados do tipo vetor que organiza suas casas no estilo de uma árvore binária; por se tratar de um heap mínimo, a organização é feita garantindo sempre que os "pais" sejam sempre elementos menores que os "filhos". 

# Como rodar
Nosso TAD traz ao desenvolvedor as opçoes de inicializar e destruir o heap, inserir e remover elementos e mostrar na tela o heap. Como solicitado pelo professor, a implementação foi feita de forma abstrata, o que significa que o programador pode usar as funções como quiser, contudo, elas não estarão implementadas direto no programa e não se tem acesso direto a elas. As funções úteis ao usuário que podem ser utilizadas em um programa usando o TAD minheap genérico são: 
  - void InicializarVetorHeap(ElementoHeap* heap, int tamMax);
  - ElementoHeap InicializarElem(ElementoHeap ele,int chave, void* info);
  - ElementoHeap DestruirElem(ElementoHeap ele);
  - void DestuirVetorHeap(ElementoHeap* heap, int tamMax);
  - void Inserir (ElementoHeap* heap, ElementoHeap x,int* totalElementos);
  - int Remover(ElementoHeap* heap, int *totalElementos);
  - void ImprimirChaves(ElementoHeap* heap, int totalElementos).
  
  Além disso, foi implementada uma estrutura do tipo elemento que constrói o TAD heap; trata-se de uma struct com uma chave do tipo inteiro, que será o que organizará o vetor, e um ponteiro do tipo void para as informações, que ficarão a critério do programador. Além disso, foi definido um sinônimo para ponteiros do tipo elemento chamado *ElementoHeap*.
  
  # Considerações finais 
  Toda ajuda e sugestão é muito bem-vinda! Obrigada por ler :D 
