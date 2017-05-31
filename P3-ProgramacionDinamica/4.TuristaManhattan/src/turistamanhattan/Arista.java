/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package turistamanhattan;

/**
 *
 * @author Alex
 */
 public class Arista{
        private Vertice vini;
        private Vertice vfin;
        private int valor;

        public Arista(Vertice vini, Vertice vfin, int valor) {
            this.vini = vini;
            this.vfin = vfin;
            this.valor = valor;
        }

        public Vertice getVini() {
            return vini;
        }

        public Vertice getVfin() {
            return vfin;
        }

        public int getValor() {
            return valor;
        }
        
        
    }

