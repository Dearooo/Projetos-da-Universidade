package com.mycompany.trab1;

//import java.util.Arrays; // Importa a funcao para exibir Arrays
import java.util.Random; // Importa a funcao Random
import java.util.Scanner; // Importa a funcao p/ leituras

/**
 *
 * @author Lucas Araujo - Gabriel Soleira - Moises Dearo
 */
public class Trab1 {

    public static void main(String[] args) {

        int op, i;
        String name;
        int menor = 20;
        int vencedor = 0;
        System.out.println("Insira a quantidade de jogadores");
        int num_jogadores = leituraINT();

        Jogador[] jogador = new Jogador[num_jogadores];

        for (i = 0; i < num_jogadores; i++) {
            jogador[i] = new Jogador();
            System.out.println("Insira o nome do jogador " + (i + 1));
            name = leituraS();
            jogador[i].setName(name);
        }

        int contadorX = 0;

        do {

            System.out.println("Inicio jogo advinhacao dos 100\n");

            for (int vez = 0; vez < num_jogadores; vez++) {

                int[] v = criarVetor(100);

                //System.out.println(Arrays.toString(v)); // teste de exibição do vetor        
                System.out.println("Vez do " + jogador[vez].getName());
                do {
                    System.out.println("Digite o numero para tentar acertar dentre os 100:\n");

                    int x = leituraINT();

                    // Algoritmo que busca x entre os 100
                    for (i = 0; i < v.length; i++) {
                        if (x == v[i]) {
                            contadorX++;
                        }
                    }

                    if (contadorX != 0) { // Acertou o numero

                        System.out.println("Tem 5 tentativas para acertar\n");

                        for (int z = 0; z < 5; z++) { // Tentar acertar a qtd de vezes apenas 5 vezes

                            int a = 1;

                            System.out.print("Quantas vezes esse numero aparece?\n");

                            int qtd = leituraINT();

                            int classif = autoajuda(qtd, contadorX);

                            // Teste exibe Classif                    
                            //System.out.println("classif: "+classif+"\n");
                            switch (classif) {
                                case 1 -> {
                                    System.out.println("Esta congelado\n");
                                    jogador[vez].setPontuacao(a);
                                }
                                case 2 -> {
                                    System.out.println("Esta frio\n");
                                    jogador[vez].setPontuacao(a);
                                }
                                case 3 -> {
                                    System.out.println("Esta esquentando\n");
                                    jogador[vez].setPontuacao(a);
                                }
                                case 4 -> {
                                    System.out.println("Esta quente\n");
                                    jogador[vez].setPontuacao(a);
                                }
                                case 0 -> {
                                    jogador[vez].setPontuacao(a);
                                    System.out.println("Acertou! Aparece " + contadorX + " vezes\n");
                                    System.out.println("Jogo finalizado!\n");
                                    System.out.println("A pontuacao de " + jogador[vez].getName() + " foi de " + jogador[vez].getPontuacao());
                                    break;
                                }
                            }
                            if (classif == 0) {
                                break;
                            }
                        }
                        System.out.println("Jogo finalizado!\n");

                    } else if (contadorX == 0) { // Errou o numero

                        System.out.println("Numero nao esta na lista\n");
                    }
                } while (contadorX == 0);

            }
            for (int j = 0; j < num_jogadores; j++) {
                if (jogador[j].pontuacao < menor) {
                    menor = jogador[j].pontuacao;
                    vencedor = j;
                }
            }

            System.out.print("O vencedor foi: ");
            System.out.println(jogador[vencedor].name);

            System.out.println("Digite 0 se quiser sair do jogo ou 1 para tentar novamente:\n");

            op = leituraINT();

        } while (op == 1);

        System.out.println("Obrigado, tente novamnete quando quiser!!");

    } // Fim Main

    public static int leituraINT() {          // Função de leitura
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();

    }

    public static String leituraS() {   // Função de leitura
        Scanner sc = new Scanner(System.in);
        return sc.nextLine();

    }

    private static int[] criarVetor(int tam) {    // Função para criar vetor

        int[] vetor = new int[tam];
        Random criar = new Random();

        for (int i = 0; i < vetor.length; i++) {
            vetor[i] = criar.nextInt(100);
        }
        return vetor;
    }

    private static int autoajuda(int qtd, int contadorX) { // Funcao Auto Ajuda

        int classificacao = 0;

        if (qtd < contadorX) { // Chute abaixo            

            if (qtd == contadorX) {
                classificacao = 5;
            } else if ((qtd + 1) == contadorX) {
                classificacao = 4;
            } else if ((qtd + 2) == contadorX) {
                classificacao = 3;
            } else if ((qtd + 3) == contadorX) {
                classificacao = 2;
            } else if ((qtd + 4) <= contadorX) {
                classificacao = 1;
            }
        } else if (qtd > contadorX) { // Chute acima
            if (qtd == contadorX) {
                classificacao = 5;
            } else if ((qtd - 1) == contadorX) {
                classificacao = 4;
            } else if ((qtd - 2) == contadorX) {
                classificacao = 3;
            } else if ((qtd - 3) == contadorX) {
                classificacao = 2;
            } else if ((qtd - 4) >= contadorX) {
                classificacao = 1;
            }
        }

        return classificacao;
    }
}
