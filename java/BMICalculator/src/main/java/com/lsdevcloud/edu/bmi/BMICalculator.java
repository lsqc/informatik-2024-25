package com.lsdevcloud.edu.bmi;

import java.util.Scanner;

/**
 * BMICalculator
 * Created: 2024/01/10
 *
 * @author lsdevcloud
 */
public final class BMICalculator {
    public static void main(String[] args) {

        final Scanner scanner = new Scanner(System.in);

        while (true) {
            // height in centimeters
            // weight in kilograms
            double height = 0, weight = 0;
            String name;

            try {
                System.out.print("Name? \n> ");
                name = scanner.next().trim();

                System.out.print("Gewicht in KG? \n> ");
                weight = scanner.nextDouble();

                if (weight <= 0)
                    System.exit(0);

                System.out.print("Größe im cm? \n> ");
                height = scanner.nextDouble();
            } catch (Exception e) {
                System.err.println("Ungültige Zahl für Gewicht/Größe erhalten.");
                scanner.nextLine();
                continue;
            }

            height = height / 100;

            final double bmi = Math.round((weight / (height * height)));

            System.out.println("Errechneter BMI: " + bmi);

            System.out.printf("Ergebnis für %s: ", name);
            if (bmi < 18.5) {
                System.out.print("Untergewicht");
            } else if (bmi >= 18.5 && bmi < 25) {
                System.out.print("Normalgewicht");
            } else if (bmi >= 25 && bmi <= 30) {
                System.out.print("Präadipositas");
            } else {
                System.out.print("Adipositas");
            }

            System.out.println("\n");
        }
    }
}
