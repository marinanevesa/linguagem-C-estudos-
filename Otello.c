#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Iniciando_tabuleiro(int tamanho, int Tabuleiro[tamanho][tamanho]) {
   int i, j;
   for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++) {
         Tabuleiro[i][j] = 0;
      }
   }
   Tabuleiro[tamanho / 2 - 1][tamanho / 2 - 1] = 4; // Branco
   Tabuleiro[tamanho / 2][tamanho / 2] = 4; // Branco
   Tabuleiro[tamanho / 2 - 1][tamanho / 2] = 3; // Preto
   Tabuleiro[tamanho / 2][tamanho / 2 - 1] = 3; // Preto
}

int movimento_valido(int tamanho, int linha, int coluna, int jogador, int Tabuleiro[tamanho][tamanho]) {
   if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho || Tabuleiro[linha][coluna] != 0) {
      return 0;
   }
   int i, j;
   int inimigo = (jogador == 3) ? 4 : 3;
   for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) continue;
         int x = linha + i;
         int y = coluna + j;
         int count = 0;
         while (x >= 0 && x < tamanho && y >= 0 && y < tamanho && Tabuleiro[x][y] == inimigo) {
            x += i;
            y += j;
            count++;
         }
         if (count > 0 && x >= 0 && x < tamanho && y >= 0 && y < tamanho && Tabuleiro[x][y] == jogador) {
            return 1;
         }
      }
   }
   return 0;
}

void captura_mais_pecas(int tamanho, int * linha, int * coluna, int jogador, int Tabuleiro[tamanho][tamanho]) {
   int i, j;
   int maximo_capturas = 0;
   int melhor_linha = -1, melhor_coluna = -1;

   for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++) {
         if (movimento_valido(tamanho, i, j, jogador, Tabuleiro)) {
            int Verificar_capturas = 0; // Renomeado conforme solicitado
            int x, y;

            for (x = -1; x <= 1; x++) {
               for (y = -1; y <= 1; y++) {
                  if (x == 0 && y == 0) continue;
                  int capturas = 0;
                  int x_atual = i + x;
                  int y_atual = j + y;

                  while (x_atual >= 0 && x_atual < tamanho && y_atual >= 0 && y_atual < tamanho && Tabuleiro[x_atual][y_atual] != jogador && Tabuleiro[x_atual][y_atual] != 0) {
                     capturas++;
                     x_atual += x;
                     y_atual += y;
                  }

                  if (x_atual >= 0 && x_atual < tamanho && y_atual >= 0 && y_atual < tamanho && Tabuleiro[x_atual][y_atual] == jogador) {
                     Verificar_capturas += capturas; // Alterado conforme solicitado
                  }
               }
            }

            if (Verificar_capturas > maximo_capturas) {
               maximo_capturas = Verificar_capturas; // Alterado conforme solicitado
               melhor_linha = i;
               melhor_coluna = j;
            }
         }
      }
   }

   * linha = melhor_linha;
   * coluna = melhor_coluna;
}

void imprimir_tabuleiro(int tamanho, int Tabuleiro[tamanho][tamanho], int ultimo_mov_linha, int ultimo_mov_coluna, int jogador_atual) {
   char c;
   int i, j;
   system("clear || cls");

   printf(" ::::::::  ::::::::::: :::    ::: :::::::::: :::        :::         ::::::::  \n");
   printf("+:+    +:+     +:+     +:+    +:+ +:+        +:+        +:+        +:+    +:+ \n");
   printf("+#+    +:+     +#+     +#++:++#++ +#++:++#   +#+        +#+        +#+    +:+ \n");
   printf("+#+    +#+     +#+     +#+    +#+ +#+        +#+        +#+        +#+    +#+ \n");
   printf("#+#    #+#     #+#     #+#    #+# #+#        #+#        #+#        #+#    #+# \n");
   printf(" ########      ###     ###    ### ########## ########## ##########  ########  \n\n");
   printf("    ");

   for (c = 'a'; c < 'a' + tamanho; c++) {
      printf("  %c ", c);
   }
   printf("\n");
   printf("   +");
   for (i = 0; i < tamanho; i++) {
      printf("---+");
   }
   printf("\n");

   for (i = 0; i < tamanho; i++) {
      printf(" %d ", i + 1);
      for (j = 0; j < tamanho; j++) {
         printf("|");
         if (Tabuleiro[i][j] == 0) {
            printf("   ");
         } else if (Tabuleiro[i][j] == 3) { // Preto
            printf(" ○ ");
         } else {
            printf(" ◉ ");
         }
      }
      printf("|\n");
      printf("   +");
      for (j = 0; j < tamanho; j++) {
         printf("---+");
      }
      printf("\n");
   }
}

void imprimir_jogadas(int tamanho, int Tabuleiro[tamanho][tamanho], int ultimo_mov_linha, int ultimo_mov_coluna, int jogador_atual) {
    printf("\nÚltimo movimento: %c%d\n", 'a' + ultimo_mov_coluna, ultimo_mov_linha + 1);
    printf("\nMovimentos válidos:");
    int m_valido = 0;
    int i, j;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            if (movimento_valido(tamanho, i, j, jogador_atual, Tabuleiro)) {
                printf("(%c%d) ", 'a' + j, i + 1);
                m_valido = 1;
            }
        }
    }

    if (!m_valido) {
        printf(" Não há movimentos válidos para o jogador %s.\n", jogador_atual == 3 ? "PRETO (○)" : "BRANCO (◉)");

        // Verifica se o próximo jogador também não tem movimentos válidos
        int proximo_jogador = (jogador_atual == 3) ? 4 : 3;
        int m_valido_proximo = 0;
        for (i = 0; i < tamanho; i++) {
            for (j = 0; j < tamanho; j++) {
                if (movimento_valido(tamanho, i, j, proximo_jogador, Tabuleiro)) {
                    m_valido_proximo = 1;
                    break;
                }
            }
            if (m_valido_proximo) break;
        }
    }
}


void movimento_pecas(int tamanho, int linha, int coluna, int jogador, int Tabuleiro[tamanho][tamanho]) {
   int i, j;
   int inimigo = (jogador == 3) ? 4 : 3;
   Tabuleiro[linha][coluna] = jogador;
   for (i = -1; i <= 1; i++) {
      for (j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) continue;
         int x = linha + i;
         int y = coluna + j;
         int count = 0;
         while (x >= 0 && x < tamanho && y >= 0 && y < tamanho && Tabuleiro[x][y] == inimigo) {
            x += i;
            y += j;
            count++;
         }
         if (count > 0 && x >= 0 && x < tamanho && y >= 0 && y < tamanho && Tabuleiro[x][y] == jogador) {
            x = linha + i;
            y = coluna + j;
            while (Tabuleiro[x][y] == inimigo) {
               Tabuleiro[x][y] = jogador;
               x += i;
               y += j;
            }
         }
      }
   }
}

void qntd_pecas(int tamanho, int * pecas_pretas, int * pecas_brancas, int Tabuleiro[tamanho][tamanho]) {
   int i, j;
   * pecas_pretas = 0;
   * pecas_brancas = 0;
   for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++) {
         if (Tabuleiro[i][j] == 3) { // Preto
            ( * pecas_pretas) ++;
         } else if (Tabuleiro[i][j] == 4) { // Branco
            ( * pecas_brancas) ++;
         }
      }
   }
}

int main() {
   int tamanho = 8; // Tamanho do tabuleiro
   int Tabuleiro[tamanho][tamanho];
   Iniciando_tabuleiro(tamanho, Tabuleiro);

   while (1) {
      system("clear || cls"); //Funcao que limpa a tela caso o jogador escolha a opcao 2 ou 3, e tenha que voltar ao menu para comecar um jogo

      //Imprime o menu inicial do jogo, que apresenta as opcoes de jogar, ver regras e autores 
      printf("   ::::::::  ::::::::::: :::    ::: :::::::::: :::        :::         ::::::::  \n");
      printf("  :+:    :+:     :+:     :+:    :+: :+:        :+:        :+:        :+:    :+: \n");
      printf("  +:+    +:+     +:+     +:+    +:+ +:+        +:+        +:+        +:+    +:+ \n");
      printf("  +#+    +:+     +#+     +#++:++#++ +#++:++#   +#+        +#+        +#+    +:+ \n");
      printf("  +#+    +#+     +#+     +#+    +#+ +#+        +#+        +#+        +#+    +#+ \n");
      printf("  #+#    #+#     #+#     #+#    #+# #+#        #+#        #+#        #+#    #+# \n");
      printf("   ########      ###     ###    ### ########## ########## ##########  ########  \n\n\n");
      printf(" __ \n");
      printf("|  | .  __  . _|_  _    _     __    /  _ _   _  _  _     |  _    _   _   _  _   _ . \n");
      printf("|  | | | _  |  |  |_   | |   |  | | | | | | |_ |  | |   _| |_|  | | |_| |  |_| | |  \n");
      printf("|__/ | |__| |  |  |_   |_|   |  | |_| | | | |_ |  |_|  |_| | |  |_| |   |_ | | |_|. \n\n");
      printf("                                                                                    \n\n");
      printf("                        .---------------------.\n");
      printf("                       |     1 - Novo Jogo     |\n");
      printf("                        `---------------------´\n\n");
      printf("                        .---------------------.\n");
      printf("                       |      2 - Regras       |\n");
      printf("                        `---------------------´\n\n");
      printf("                        .---------------------.\n");
      printf("                       |      3 - Autores      |\n");
      printf("                        `---------------------´\n\n");

      int opcao, jogador = 3, modo_jogo;
      int ultimo_mov_linha = -1, ultimo_mov_coluna = -1; // Variáveis para armazenar o último movimento

      scanf("%d", & opcao);

      if (opcao == 2) {
         system("clear || cls"); //Funcao que limpa a tela apos a escolha da opcao 2 no menu
         printf("                        .---------------------.\n");
         printf("                       |         Regras        |\n");
         printf("                        `---------------------´\n\n");
         printf("➤ O tabuleiro é inicializado com quatro peças no centro: duas peças pretas e duas brancas, formando um padrão inicial.\n➤ Os jogadores alternam fazer movimentos.\n➤ Um movimento consiste em colocar uma peça em um espaço vazio no tabuleiro de tal forma que pelo menos uma peça do oponente é capturada entre a nova peça e outra peça da mesma cor já presente no tabuleiro.\n➤ Para capturar as peças do oponente, o jogador deve posicionar uma peça de sua própria cor em uma posição que forme uma linha reta (horizontal, vertical ou diagonal) com uma ou mais peças do oponente, e a linha deve terminar em outra peça do jogador.\n➤ Todas as peças do oponente que estão entre as peças do jogador em ambas as extremidades da linha reta são capturadas e viradas para a cor do jogador.\n➤ O jogo continua até que o tabuleiro esteja completamente preenchido ou nenhum jogador possa fazer um movimento válido.\n\n");
         printf("Pressione Enter para voltar ao menu..."); //Imprime das regras do jogo
         getchar();
         getchar(); //Funcao para quando o usuario pressionar Enter, volte ao menu incial

      } else if (opcao == 3) {
         //Caso a opcao do usario for 3, o computador os autores do jogo
         system("clear || cls"); //Funcao que limpa a tela apos apos a escolha da opcao 3 no menu

         printf("                        .---------------------.\n");
         printf("                       |        Autores        |\n");
         printf("                        `---------------------´\n\n");;
         printf("\nMarina Neves Andrade               N°USP: 14748337\nVitória Aparecida Bonilha Mateus   N°USP: 14611877\n\n"); //Imprime na tela os autores do jogo 
         printf("Pressione Enter para voltar ao menu...\n");
         getchar();
         getchar(); //Funcao para quando o usuario pressionar Enter, volte ao menu inicial

      } else if (opcao == 1) {
         Iniciando_tabuleiro(tamanho, Tabuleiro);
         system("clear || cls");
         //Imprime as opcoes de jogar:
         printf(" _  __   _  _  |  |    _         _ _     _ _   _    |  _      |  _   .  _   __  _  . \n");
         printf("|- '__  |  | | |  |_  |_|   | | | | |   | | | | |  _| | |    _| |_   | | | | _ | |   \n");
         printf("|_  __' |_ |_| |_ | | | |   |_| | | |   | | | |_| |_| |_|   |_| |_   | |_| |__||_| . \n");
         printf("                                                                    /                \n\n");
         printf("                        .----------------------.\n");
         printf("                       | 1 - Jogador VS Jogador |\n");
         printf("                        `----------------------´\n\n");
         printf("                       .-------------------------.\n");
         printf("                      | 2 - Jogador VS Computador |\n");
         printf("                       `-------------------------´\n\n");

         scanf("%d", & modo_jogo);

         int linha, coluna;

         while (1) {
            imprimir_tabuleiro(tamanho, Tabuleiro, ultimo_mov_linha, ultimo_mov_coluna, jogador); // Passando informações para imprimir o tabuleiro

            imprimir_jogadas(tamanho, Tabuleiro, ultimo_mov_linha, ultimo_mov_coluna, jogador);
            int m_valido = 0;

            // Verifica a quantidade de peças pretas e brancas
            int pecas_pretas, pecas_brancas;
            qntd_pecas(tamanho, &pecas_pretas, &pecas_brancas, Tabuleiro);

            // Verifica se há movimentos válidos para ambos os jogadores
            int m_valido_preto = 0;
            int m_valido_branco = 0;
            for (i = 0; i < tamanho; i++) {
                for (j = 0; j < tamanho; j++) {
                    if (movimento_valido(tamanho, i, j, 3, Tabuleiro)) { // Preto
                        m_valido_preto = 1;
                    }
                    if (movimento_valido(tamanho, i, j, 4, Tabuleiro)) { // Branco
                        m_valido_branco = 1;
                    }
                }
            }

            printf("\n\n       .-----------------------.\n");
            printf("      |    Jogador %s", jogador == 3 ? "PRETO (○)    |\n" : "BRANCO (◉)   |\n");
            printf("       `-----------------------´\n\n");

            printf("\nDigite sua Jogada: ");
            int i, j;
            int m_valido_preto = 0;
            int m_valido_branco = 0;

            for (i = 0; i < tamanho; i++) {
               for (j = 0; j < tamanho; j++) {
                  if (movimento_valido(tamanho, i, j, 3, Tabuleiro)) { // Preto
                     m_valido_preto = 1;
                  }
                  if (movimento_valido(tamanho, i, j, 4, Tabuleiro)) { // Branco
                     m_valido_branco = 1;
                  }
               }
            }

            if (!((jogador == 3 && m_valido_preto) || (jogador == 4 && m_valido_branco))) { // Preto and Branco
               printf("\n\nJogada passada ao Jogador %s\n", jogador == 3 ? "BRANCO (◉)" : "PRETO (○)");
               printf("Pressione Enter para continuar...\n");

               while (getchar() != '\n');
               while (getchar() != '\n');

               jogador = (jogador == 3) ? 4 : 3; // Preto and Branco
               continue;
            }

            if (modo_jogo == 1 || (modo_jogo == 2 && jogador == 3)) { // Preto
               while (1) {
                  char coluna_escolhida;
                  scanf(" %c %d", & coluna_escolhida, & linha);
                  coluna = coluna_escolhida - 'a';
                  linha--;
                  if (!movimento_valido(tamanho, linha, coluna, jogador, Tabuleiro)) {
                     printf("Movimento inválido.\nTente novamente.\n");
                     printf("Jogador %s.\nRefaça sua jogada (linha coluna): ", jogador == 3 ? "PRETO (○)" : "BRANCO (◉)");
                  } else {
                     ultimo_mov_linha = linha; // Atualizando o último movimento
                     ultimo_mov_coluna = coluna;
                     break;
                  }
               }
            } else if (modo_jogo == 2 && jogador == 4) { // Branco
               srand(time(NULL));
               captura_mais_pecas(tamanho, & linha, & coluna, jogador, Tabuleiro);
               {
                  ultimo_mov_linha = linha; // Atualizando o último movimento
                  ultimo_mov_coluna = coluna;
               }
            }

            movimento_pecas(tamanho, linha, coluna, jogador, Tabuleiro);
            jogador = (jogador == 3) ? 4 : 3; // Preto and Branco

            int pecas_pretas, pecas_brancas;
            qntd_pecas(tamanho, & pecas_pretas, & pecas_brancas, Tabuleiro);
            if (!(m_valido_preto || m_valido_branco)) {
               system("clear || cls");
               imprimir_tabuleiro(tamanho, Tabuleiro, ultimo_mov_linha, ultimo_mov_coluna, jogador);
               printf(" __                                  \n");
               printf("|_  .  _ _      |  _   .  _   __  _   \n");
               printf("|   | | | |    _| |_   | | | | _ | |  \n");
               printf("|   | | | |   |_| |_   | |_| |__||_| .\n");
               printf("                      /               \n");
               printf(",---.               |\n");
               printf("|---',---.,---.,---.|---.,---.,---.,---.     \n");
               printf("|    ,---||    ,---||   ||---'|   |`---.     \n");
               printf("`    `---^`    `---^`---'`---'`   '`---'     \n");
               if (pecas_pretas > pecas_brancas) {
                  printf("                  |            |\n");
                  printf(",---.,---.,---.---|---,---.    |\n");
                  printf("|   ||    |---'   |   |   |     \n");
                  printf("|---'`    `---'   |   `---'    o\n");
                  printf("| \n");
               } else if (pecas_brancas > pecas_pretas) { //Se ha mais pecas brancas que pretas, o computador imprime que o jogador preto venceu
                  printf("|                                 |\n");
                  printf("|---.,---.,---.,---.,---.,---.    |\n");
                  printf("|   ||    ,---||   ||    |   |     \n");
                  printf("`---'`    `---^'   ``---.'---'    o\n");
               } else { //Caso tenha quantidade de pecas iguais o computador imprime empate
                  printf("                       |     o         |\n");
                  printf(",---.,---.,---.    ,---|,---..,---.    |\n");
                  printf(",---||   |`---.    |   ||   ||`---.     \n");
                  printf("`---^`---'`---'    `---'`---'``---'    o\n");
               }
               printf(" .---------------------------.\n");
               printf("|  1 - Voltar para o menu     |\n");
               printf(" `---------------------------´\n\n");
               printf(" .---------------------------.\n");
               printf("|     2 - Finalizar jogo      |\n");
               printf(" `---------------------------´\n\n");

               scanf("%d", & opcao);
               while (opcao != 1 && opcao != 2) {
                  printf("Opção inválida. Digite novamente: ");
                  scanf("%d", & opcao);
               }

               if (opcao == 1) {
                  break;
               } else if (opcao == 2) {
                  return 0;
               }

            }
         }
      }
   }
   return 0;
}