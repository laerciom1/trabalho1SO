#include "algorithms.h"
#include <QTime>
#include <QVector>

Algorithms::Algorithms(QVector<int> t, int i){
    this->tamanhos = t;
    this->iteracoes = i;
};
QVector<double> Algorithms::executeQk(QProgressBar *pb){
    QVector<double> tempos;
    pb->setValue(0);
    int percentQt = 100/(tamanhos.size()*iteracoes);
    int percent = 0;
    srand(time(NULL));
    for(int tam=0; tam<tamanhos.size();tam++){                          //Para cada tamanho de vetor especificado
        for(int v=0;v<this->iteracoes;v++){                             //n iteracoes
            int vetor1[this->tamanhos[tam]];                            //Declarando vetor do tamanho especificado
            for(int l=0;l<this->tamanhos[tam];l++){                     //Enxendo o vetor com
                vetor1[l] = (rand() % (this->tamanhos[tam])) + 1;       //valores aleatorios
            }
            QTime qk;                                                   //Variavel para pegar o tempo
            qk.start();                                                 //Pegando tempo atual
            quick(vetor1, vetor1[0], vetor1[this->tamanhos[tam]-1]);    //Executa o algoritmo
            tempos.append(qk.elapsed());                                //Pega tempo em milisegundos (/ 1000 para deixar em segundos)
            percent+=percentQt;
            pb->setValue(percent);
        }
    }
    return tempos;
};

QVector<double> Algorithms::executeBb(QProgressBar *pb){
    QVector<double> tempos;
    pb->setValue(0);
    int percentQt = 100/(tamanhos.size()*iteracoes);
    int percent = 0;
    srand(time(NULL));
    for(int tam=0; tam<tamanhos.size();tam++){                          //Para cada tamanho de vetor especificado
        for(int v=0;v<this->iteracoes;v++){                             //n iteracoes
            int vetor1[this->tamanhos[tam]];                            //Declarando vetor do tamanho especificado
            for(int l=0;l<this->tamanhos[tam];l++){                     //Enxendo o vetor com
                vetor1[l] = (rand() % (this->tamanhos[tam])) + 1;       //valores aleatorios
            }
            QTime bb;                                                   //Variavel para pegar o tempo
            bb.start();                                                 //Pegando tempo atual
            bubble(vetor1, this->tamanhos[tam]);                        //Executa o algoritmo
            tempos.append(bb.elapsed());                                //Pega tempo em milisegundos (/ 1000 para deixar em segundos) e adiciona ao vetor;
            percent+=percentQt;
            pb->setValue(percent);
        }
    }
    return tempos;
};

QVector<double> Algorithms::executeAll(QProgressBar *pb){
    QVector<double> tempos;
    pb->setValue(0);
    int percentQt = 100/(tamanhos.size()*iteracoes);
    int percent = 0;
    srand(time(NULL));
    for(int tam=0; tam<tamanhos.size();tam++){                          //Para cada tamanho de vetor especificado
        for(int v=0;v<this->iteracoes;v++){                             //n iteracoes
            int vetor1[this->tamanhos[tam]];
            int vetor2[this->tamanhos[tam]];                            //Declarando vetor do tamanho especificado
            for(int l=0;l<this->tamanhos[tam];l++){                     //Enxendo os vetores
                vetor1[l] = (rand() % (this->tamanhos[tam])) + 1;       //com valores aleatorios
                vetor2[l] = vetor1[l];                                  //e iguais
            }
            QTime bb;                                                   //Variavel para pegar o tempo do bubble
            bb.start();                                                 //Pegando tempo atual
            bubble(vetor2, this->tamanhos[tam]);                        //Executa o algoritmo
            tempos.append(bb.elapsed());                                //Pega tempo em milisegundos e adiciona ao vetor (valores pares, iniciando com 0);
            QTime qk;                                                   //Variavel para pegar o tempo
            qk.start();                                                 //Pegando tempo atual
            quick(vetor1, vetor1[0], vetor1[this->tamanhos[tam]-1]);    //Executa o algoritmo
            tempos.append(qk.elapsed());                                //Pega tempo em milisegundos e adiciona ao vetor (valores impares, iniciando com 1);
            percent+=percentQt;
            pb->setValue(percent);
        }
    }
    return tempos;
};

void Algorithms::quick(int *valor, int esquerda, int direita){
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j){
        while(valor[i] < x && i < direita){
            i++;
        }
        while(valor[j] > x && j > esquerda){
            j--;
        }
        if(i <= j){
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda){
        quick(valor, esquerda, j);
    }
    if(i < direita){
        quick(valor,  i, direita);
    }
}

void Algorithms::bubble(int *list, int n){
  int aux;

  for (int c = 0 ; c < ( n - 1 ); c++)
  {
    for (int d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        aux         = list[d];
        list[d]   = list[d+1];
        list[d+1] = aux;
      }
    }
  }
}

int Algorithms::getIteracoes(){
    return this->iteracoes;
}

QVector<int> Algorithms::getTamanhos(){
    return this->tamanhos;
}
