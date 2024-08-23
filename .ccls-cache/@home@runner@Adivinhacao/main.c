#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TENTATIVAS_FACIL 20
#define TENTATIVAS_MEDIO 15
#define TENTATIVAS_DIFICIL 6

int main() {
  int jogarNovamente = 1;

  while (jogarNovamente == 1) {
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;
    double pontos = 1000;
    int menorNumero, maiorNumero;
    int ultimoChute = -1;

    srand(time(0));

    printf("Defina o intervalo para o número secreto:\n");
    printf("Digite o menor número: ");
    scanf("%d", &menorNumero);
    printf("Digite o maior número: ");
    scanf("%d", &maiorNumero);

    if (menorNumero >= maiorNumero) {
      printf("O maior número deve ser maior que o menor número.\n");
      return 1;
    }

    int numerosecreto = rand() % (maiorNumero - menorNumero + 1) + menorNumero;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel) {
      case 1:
        totaldetentativas = TENTATIVAS_FACIL;
        break;
      case 2:
        totaldetentativas = TENTATIVAS_MEDIO;
        break;
      default:
        totaldetentativas = TENTATIVAS_DIFICIL;
        break;
    }

    for(int i = 1; i <= totaldetentativas; ) {
      printf("-> Tentativa %d de %d\n", i, totaldetentativas);

      printf("\nChute um número entre %d e %d:\n\n", menorNumero, maiorNumero);
      scanf("%d", &chute);

      if(chute < menorNumero || chute > maiorNumero) {
        printf("O chute deve estar dentro do intervalo [%d, %d].\n", menorNumero, maiorNumero);
        continue;
      }

      if(chute == ultimoChute) {
        printf("Você já chutou o número %d. Tente outro número.\n", chute);
        continue;
      }

      acertou = chute == numerosecreto;

      if(acertou) {
        break;
      } else if(chute > numerosecreto) {
        printf("\nSeu chute foi maior do que o número secreto!\n\n");
      } else {
        printf("\nSeu chute foi menor do que o número secreto!\n\n");
      }

      double pontosperdidos = abs(chute - numerosecreto) / 2.0;
      pontos = pontos - pontosperdidos;

      // Atualiza o último chute
      ultimoChute = chute;

      // Incrementa o contador de tentativas apenas se o chute for válido e diferente do último
      i++;
    }

    printf("\n");
    if(acertou) {
      printf("             OOOOOOOOOOO               \n");
      printf("         OOOOOOOOOOOOOOOOOOO           \n");
      printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
      printf("    OOOOOO      OOOOO      OOOOOO      \n");
      printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
      printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
      printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
      printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
      printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
      printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
      printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
      printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
      printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
      printf("         OOOOOO         OOOOOO         \n");
      printf("             OOOOOOOOOOOO              \n");
      printf("\nParabéns! Você acertou!\n");
      printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    } else {
      printf("       \\|/ ____ \\|/    \n");
      printf("        @~/ ,. \\~@      \n");
      printf("       /_( \\__/ )_\\    \n");
      printf("          \\__U_/        \n");

      printf("\nVocê perdeu! Tente novamente!\n\n");
    }

   printf("Você quer jogar novamente? Digite 1 para sim ou 0 para não: ");
    scanf("%d", &jogarNovamente);
  }

  return 0;
}
