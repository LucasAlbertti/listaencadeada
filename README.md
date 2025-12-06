# Lista Encadeada - Relatório Técnico

## 📋 Descrição do Projeto

Implementação de uma estrutura de dados de **lista encadeada simples** com operações de inserção, remoção, ordenação e impressão, em linguagem C.

---

## 1️⃣ Tipo de Lista Encadeada Utilizada

### **Lista Encadeada Simples**

A implementação utiliza uma **lista encadeada simples**, onde:
- Cada nó contém um **dado** (nome) e um **ponteiro** para o próximo nó
- Apenas um sentido de navegação (início para fim)
- O último nó aponta para `NULL`

**Estrutura do Nó:**
```c
typedef struct No {
    char nome[50];      // Dado armazenado
    struct No *prox;    // Ponteiro para próximo nó
} No;
```

**Características:**
- ✅ Memória dinâmica
- ✅ Inserção e remoção eficientes no início
- ✅ Acesso sequencial aos elementos
- ✅ Uso moderado de memória (sem ponteiro anterior)

---

## 2️⃣ Estrutura Auxiliar Escolhida

### **Fila (FIFO - First In, First Out)**

A estrutura auxiliar escolhida foi a **Fila**, implementada através da operação `removerFIFO()`:

```c
No* removerFIFO(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return lista;
    }

    No *temp = lista;
    lista = lista->prox;
    free(temp);

    return lista;
}
```

**Justificativa:**
- Remove o **primeiro elemento inserido** (início da lista)
- Segue o princípio FIFO: "O primeiro que entra é o primeiro que sai"
- Oferece alternativa ao método de remoção por nome
- Útil em cenários onde há prioridade de processamento por ordem de chegada

**Alternativa:**
- O código permite remoção por **nome específico** também
- Flexibiliza o uso para diferentes necessidades

---

## 3️⃣ Algoritmo de Ordenação Escolhido

### **Selection Sort (Ordenação por Seleção)**

```c
void ordenarSelection(No *lista) {
    if (lista == NULL) return;

    No *i, *j;
    char temp[50];

    for (i = lista; i->prox != NULL; i = i->prox) {
        No *menor = i;
        for (j = i->prox; j != NULL; j = j->prox) {
            if (strcmp(j->nome, menor->nome) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            strcpy(temp, i->nome);
            strcpy(i->nome, menor->nome);
            strcpy(menor->nome, temp);
        }
    }
}
```

**Funcionamento:**
1. Percorre a lista do início ao fim
2. Para cada posição, encontra o menor elemento
3. Troca os valores (não os nós)
4. Move para a próxima posição

**Por que Selection Sort?**
- ✅ **Implementação simples** e direta para lista encadeada
- ✅ **Número reduzido de trocas** (apenas quando encontra menor)
- ✅ **Estável em memória** (não requer estruturas adicionais)
- ✅ **Adequado para listas pequenas** (escopo educacional)
- ⚠️ Não é ótimo para grandes volumes, mas suficiente para o projeto

---

## 4️⃣ Exemplos de Execução

### **Exemplo 1: Operações Básicas**

```
1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 1
Digite o nome: Carlos

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 1
Digite o nome: Alice

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 1
Digite o nome: Bruno

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 3

--- LISTA ---
Carlos
Alice
Bruno
```

### **Exemplo 2: Ordenação**

```
1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 4
Lista ordenada!

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 3

--- LISTA ---
Alice
Bruno
Carlos
```

### **Exemplo 3: Remoção por Nome**

```
1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 2
Digite o nome para remover (ENTER para FIFO): Bruno

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 3

--- LISTA ---
Alice
Carlos
```

### **Exemplo 4: Remoção FIFO**

```
1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 2
Digite o nome para remover (ENTER para FIFO): 
(pressiona ENTER)

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 3

--- LISTA ---
Carlos
```

### **Exemplo 5: Casos de Erro**

```
1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 3

Lista vazia!

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 2
Digite o nome para remover (ENTER para FIFO): Inexistente
Nome nao encontrado!

1 - Inserir nome
2 - Remover nome
3 - Imprimir lista
4 - Ordenar lista
0 - Sair
Escolha: 1
Digite o nome: 
(pressiona ENTER)

Nome invalido!
```

---

## 📝 Resumo Técnico

| Aspecto | Implementação |
|--------|---|
| **Tipo de Estrutura** | Lista Encadeada Simples |
| **Estrutura Auxiliar** | Fila (FIFO) |
| **Algoritmo de Ordenação** | Selection Sort |
| **Linguagem** | C |
| **Tipo de Dados** | String (nome) |
| **Gerenciamento de Memória** | malloc/free |

---

**Autor**: [Lucas William Albertti]  
**Data**: 05 de Dezembro 2025  
