/*
Miloš Bardáč 3.CI
*/

package com.company;
import java.util.Scanner;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        //priklad1();
        //priklad2();
        priklad3();
    }
    static void priklad1(){
        System.out.println("Zadajte pocet kilometrov: ");
        Scanner myScanner = new Scanner(System.in);
        double kilometre = myScanner.nextDouble();

        System.out.println("Zadajte cielove km: ");
        double ciel = myScanner.nextDouble();
        int den = 1;

        while(ciel > kilometre){
            kilometre = kilometre + (kilometre/10);
            den++;
        }
        System.out.println("Na "+den+". den prebehne "+kilometre+" km");
    }


    static void priklad2(){
        System.out.println("Zadajte cislo: ");
        Scanner myScanner = new Scanner(System.in);
        int cislo = myScanner.nextInt();

        System.out.println("Zadajte kolko krat chcete cislo pripocitat: ");
        int pocet = myScanner.nextInt();

        int cislo2 = 0;
        int vysledok;

        for (int i = 1; i <= pocet; i++){
            vysledok = cislo+ cislo2;
            System.out.print(vysledok+" ");

            cislo = cislo2;
            cislo2 = vysledok;

        }
    }
    static void priklad3(){
boolean appIsRunning = true;

        int peniaze = 100;
        int vyhra, prehra;
        String[] pole = {"red", "black"};
        String ruleta= "";


        while(appIsRunning) {
            Scanner myScanner = new Scanner(System.in);

            System.out.println("Aktualny zostatok: "+ peniaze);
            System.out.println("Kolko chcete stavit: ");
            int velkostStavky = myScanner.nextInt();
            if(velkostStavky > peniaze){
                System.out.println("Nemas dostatok penazi na tuto stavku, zadaj novu stavku");
                System.exit(0);
            }
            peniaze = peniaze - velkostStavky;

            System.out.println();
            System.out.println("Na aku farbu chcete vsadit: ");
            System.out.println("'red' alebo 'black'");
            myScanner.nextLine();
            String farba = myScanner.nextLine();
            System.out.println();


            int random = (int) ( Math.random() * 2 + 1);
            if(random==1){
                ruleta = "red";
            } else if(random == 2) {
                ruleta = "black";
            }

            if (farba.equals(ruleta)){
                peniaze= peniaze+(velkostStavky * 2);
                System.out.println("Vyhral si! ");
                System.out.println("Aktualny zostatok: "+ peniaze);

            } else if (!farba.equals(ruleta)){
                if(peniaze==0){
                    System.out.println("Prehral si vsetko, nemas ziadne peniaze");
                    appIsRunning = false;
                }else if(peniaze>0){
                    System.out.println("Prehral si! ");
                    System.out.println("Aktualny zostatok: "+ peniaze);
                }
            }

            System.out.println("Chcete stavit znovu? ");
            String rozhodnutie = myScanner.nextLine();
            if(rozhodnutie.equals("nie")){
                appIsRunning = false;
            }

            }
        }


    }
