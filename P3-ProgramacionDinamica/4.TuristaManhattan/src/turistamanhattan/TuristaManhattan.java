/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package turistamanhattan;

import java.util.ArrayList;

/**
 *
 * @author Alex
 */
public class TuristaManhattan {

    public static Arista usadaI;
    public static Arista usadaJ;
    public static int total;
    public static ArrayList<Arista> solucion;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int m = 4;
        int n = 3;
        solucion = new ArrayList<>();
        total = 0;

        Vertice[][] vertices = new Vertice[m][n];
        Arista[] aristas = new Arista[17];

        vertices[0][0] = new Vertice(0, 0);
        vertices[0][0].setValor(0);
        vertices[0][1] = new Vertice(0, 1);
        vertices[0][2] = new Vertice(0, 2);

        vertices[1][0] = new Vertice(1, 0);
        vertices[1][1] = new Vertice(1, 1);
        vertices[1][2] = new Vertice(1, 2);

        vertices[2][0] = new Vertice(2, 0);
        vertices[2][1] = new Vertice(2, 1);
        vertices[2][2] = new Vertice(2, 2);

        vertices[3][0] = new Vertice(3, 0);
        vertices[3][1] = new Vertice(3, 1);
        vertices[3][2] = new Vertice(3, 2);

        aristas[0] = new Arista(vertices[0][0], vertices[0][1], 3);
        aristas[1] = new Arista(vertices[0][1], vertices[0][2], 2);
        aristas[2] = new Arista(vertices[0][0], vertices[1][0], 1);
        aristas[3] = new Arista(vertices[0][1], vertices[1][1], 0);
        aristas[4] = new Arista(vertices[0][2], vertices[1][2], 2);
        aristas[5] = new Arista(vertices[1][0], vertices[1][1], 3);
        aristas[6] = new Arista(vertices[1][1], vertices[1][2], 2);
        aristas[7] = new Arista(vertices[1][0], vertices[2][0], 4);
        aristas[8] = new Arista(vertices[1][1], vertices[2][1], 6);
        aristas[9] = new Arista(vertices[1][2], vertices[2][2], 5);
        aristas[10] = new Arista(vertices[2][0], vertices[2][1], 0);
        aristas[11] = new Arista(vertices[2][1], vertices[2][2], 7);

        aristas[12] = new Arista(vertices[2][0], vertices[3][0], 4);
        aristas[13] = new Arista(vertices[2][1], vertices[3][1], 4);
        aristas[14] = new Arista(vertices[2][2], vertices[3][2], 5);
        aristas[15] = new Arista(vertices[3][0], vertices[3][1], 3);
        aristas[16] = new Arista(vertices[3][1], vertices[3][2], 3);

        turista(vertices, aristas, n, m);

        //System.out.println(vertices[m - 1][n - 1].getValor());
        muestraCamino();

    }

    public static Arista devuelveArista(Arista[] a, Vertice vini, Vertice vfin) {
        for (int i = 0; i < a.length; i++) {
            if (a[i].getVini() == vini && a[i].getVfin() == vfin) {
                //System.out.println("Encuentra arista");
                return a[i];
            }
        }

        return null;
    }

    private static void turista(Vertice[][] ve, Arista[] a, int n, int m) {

        for (int i = 1; i < n; i++) {
            usadaI = devuelveArista(a, ve[0][i - 1], ve[0][i]);
            ve[0][i].setValor(ve[0][i - 1].getValor() + usadaI.getValor());
        }
        for (int j = 1; j < m; j++) {
            usadaJ = devuelveArista(a, ve[j - 1][0], ve[j][0]);
            ve[j][0].setValor(ve[j - 1][0].getValor() + usadaJ.getValor());
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                
                usadaI = devuelveArista(a, ve[j][i - 1], ve[j][i]);
                usadaJ = devuelveArista(a, ve[j - 1][i], ve[j][i]);
                if ((ve[j][i - 1].getValor() + usadaI.getValor()) > (ve[j - 1][i].getValor() + usadaJ.getValor())) {
                    ve[j][i].setValor(ve[j][i - 1].getValor() + usadaI.getValor());
                    anadeSolucion(ve[j][i], usadaI);

                } else {
                    ve[j][i].setValor(ve[j - 1][i].getValor() + usadaJ.getValor());
                   anadeSolucion(ve[j][i], usadaJ);
                }
            }
        }
    }

    
    public static void anadeSolucion(Vertice v, Arista a) {
        if (v.getValor() > total) {

            for (Arista aris : solucion) {
                if(aris.getVini() == a.getVini()){
                    if(aris.getVfin().getValor() < a.getVfin().getValor()){
                      solucion.remove(aris);
                      solucion.add(a);
                      total = v.getValor();
                       return;
                    }                        
                }               
            }

            total = v.getValor();
            solucion.add(a);
        }

    }

    public static void muestraCamino() {
        Vertice inicio, fin;

        for (int i = 0; i < solucion.size(); i++) {
            inicio = solucion.get(i).getVini();
            fin = solucion.get(i).getVfin();

            System.out.println("Desde " + inicio.getI() + "," + inicio.getJ() + " a " + fin.getI() + "," + fin.getJ()
                    + " con valor " + solucion.get(i).getValor() + " ---> Total: " + fin.getValor());
        }

    }

}
